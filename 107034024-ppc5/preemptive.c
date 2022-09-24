/*
 * file: preemptive.c
 */

#include <8051.h>
#include "preemptive.h"

// !! now 要換成 time
// testparking 的字串要換

//#define MAXTHREADS 4, defined in .h file
__data __at (0x20) char savedSP[MAXTHREADS];
__data __at (0x24) ThreadID curThread;
__data __at (0x25) char mask;
__data __at (0x26) ThreadID newThread;
__data __at (0x27) char i;
__data __at (0x28) char tmp;
__data __at (0x29) char tmp2;
__data __at (0x2A) char isAlive[MAXTHREADS];

// when each time myTimer0Handler(void) is called, 
// cnt will be incremented by 1. 
// Every four times myTimer0Handler(void) is called,
// now will be incremented by 1 and cnt will be flushed to 0.  
__data __at (0x2E) unsigned char count;
__data __at (0x2F) unsigned char time;

// There are four threads, so there are at most four delay()
__data __at (0x39) unsigned char delayID[MAXTHREADS];


#define SAVESTATE \
	{ \
		__asm \
			push ACC \
			push B \
			push DPL \
			push DPH \
			push PSW \
		__endasm; \
		savedSP[curThread] = SP; \
	}


#define RESTORESTATE \
	{ \
		SP = savedSP[curThread]; \
		__asm \
			pop PSW \
			pop DPH \
			pop DPL \
			pop B \
			pop ACC \
		__endasm; \
	}

/* 
  * we declare main() as an extern so we can reference its symbol
  * when creating a thread for it.
  */
extern void main(void);


/*
 * Bootstrap is jumped to by the startup code to make the thread for
 * main, and restore its context so the thread can run.
 */



void Bootstrap(void) {
	
   	count = 0;
	time = 0;

	mask = 0b0000;
	TMOD = 0;  // timer 0 mode 0
    IE = 0x82;  // enable timer 0 interrupt; keep consumer polling
                // EA  -  ET2  ES  ET1  EX1  ET0  EX0
    TR0 = 1; // set bit TR0 to start running timer 0
	
	isAlive[0] = 0b0001; 
	isAlive[1] = 0b0010; 
	isAlive[2] = 0b0100; 
	isAlive[3] = 0b1000;
	
	delayID[0] = 0;
	delayID[1] = 0;
	delayID[2] = 0;
	delayID[3] = 0;

	curThread = ThreadCreate(main);
	RESTORESTATE;
}

/*
 * ThreadCreate() creates a thread data structure so it is ready
 * to be restored (context switched in).
 * The function pointer itself should take no argument and should
 * return no argument.
 */
ThreadID ThreadCreate(FunctionPtr fp) {
	if(mask == 0b1111) return -1;	// mask = 15, four thread
	EA = 0;
		for(i = 0; i < MAXTHREADS; i++) {
			if(((mask) & (0b0001 << i)) == 0) {
				mask |= (0b0001 << i);
				newThread = i;
				break;
			}
		}
		
		tmp = SP;
		SP = 0x3F + (i << 4);

		__asm
			push DPL
			push DPH
			mov A, #0
			push A
			push A
			push A
			push A
		__endasm;
		/*
		00000000B for thread 0, 00001000B for thread 1,
		00010000B for thread 2, 00011000B for thread 3.
		==> THAT IS TO SHIFT RIGHT 3 BITS
		*/
		tmp2 = (i << 3);
		
		__asm
			push _tmp2
		__endasm;
		
		savedSP[newThread] = SP;
		SP = tmp;
	EA = 1;
	return newThread;
}

/*
 * this is called by a running thread to yield control to another
 * thread.  ThreadYield() saves the context of the current
 * running thread, picks another thread (and set the current thread
 * ID to it), if any, and then restores its state.
 */
void ThreadYield(void) {
	__critical{
		SAVESTATE;
		do {
			/*
				* @@@ [8 pts] do round-robin policy for now.
				* find the next thread that can run and 
				* set the current thread ID to it,
				* so that it can be restored (by the last line of 
				* this function).
				* there should be at least one thread, so this loop
				* will always terminate.
				*/
			curThread = (curThread == MAXTHREADS-1) ? 0 : curThread + 1;
			if(mask & isAlive[curThread]) break;
		} while (1);
		RESTORESTATE;
	}
}

/*
 * ThreadExit() is called by the thread's own code to termiate
 * itself.  It will never return; instead, it switches context
 * to another thread.
 */
void ThreadExit(void) {
	/*
	 * clear the bit for the current thread from the
	 * bit mask, decrement thread count (if any),
	 * and set current thread to another valid ID.
	 * Q: What happens if there are no more valid threads?
	 */
	EA = 0;

	__asm 
		mov A, #0
		push A 
		push A 
		push A 
		push A
		push A
		push A
		push A
		push A
	__endasm; 
	savedSP[curThread] = 0;
	//__critical{
		mask &= ~(1 << curThread);
		if(mask == 0){
			while(1){};
		}
		do {
			curThread = (curThread == 3) ? 0 : curThread + 1;
			if(mask & isAlive[curThread]) break;
		} while (1);
		RESTORESTATE;
	//}
	EA = 1;
}

void myTimer0Handler(){
	EA = 0;
	//copy threadYield
	SAVESTATE;
	// preserve the value of any such registers by 
	// copying them to registers that have been saved 
	// (e.g., B, DPH, DPL, etc., or your designated memory locations) after SAVESTATE
	__asm
			mov ACC, r1
			mov B, r2
			mov DPL, r3
			mov DPH, r4
			mov PSW, r5
			mov _tmp, r6
			mov _tmp2, r7
	__endasm;
	do {
		curThread = (curThread == MAXTHREADS - 1) ? 0 : curThread + 1;
		if(mask & isAlive[curThread]) break;
	} while (1);
	
	count ++;
	if(count == 4){
		count = 0;
		time ++;
	}
	// copy them back to those registers before the RESTORESTATE
	__asm
			mov r1, ACC
			mov r2, B
			mov r3, DPL
			mov r4, DPH
			mov r5, PSW
			mov r6, _tmp
			mov r7, _tmp2
	__endasm;
	RESTORESTATE;
	EA = 1;
	__asm
			reti
	__endasm;
}



// delay(n) function, where n is the number of time units to delay. 
void delay(unsigned char n) {
	delayID[curThread] = time + n;
	while(time != delayID[curThread]);
	delayID[curThread] = 0;
}


unsigned char now(void){
	return time;
}