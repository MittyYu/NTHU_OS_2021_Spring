/*
 * file: preemptive.c
 */

#include <8051.h>
#include "preemptive.h"

/*
 * @@@ [2 pts] declare the static globals here using 
 *        __data __at (address) type name; syntax
 * manually allocate the addresses of these variables, for
 * - saved stack pointers (MAXTHREADS)
 * - current thread ID
 * - a bitmap for which thread ID is a valid thread; 
 *   maybe also a count, but strictly speaking not necessary
 * - plus any temporaries that you need.
 */

//#define MAXTHREADS 4, defined in .h file
__data __at (0x30) char savedSP[MAXTHREADS];
__data __at (0x34) ThreadID curThread;
__data __at (0x35) char mask;
__data __at (0x36) ThreadID newThread;
__data __at (0x37) char i;
__data __at (0x38) char tmp;
__data __at (0x39) char tmp2;
__data __at (0x3A) char isAlive[MAXTHREADS];

/*
 * @@@ [8 pts]
 * define a macro for saving the context of the current thread by
 * 1) push ACC, B register, Data pointer registers (DPL, DPH), PSW
 * 2) save SP into the saved Stack Pointers array
 *   as indexed by the current thread ID.
 * Note that 1) should be written in assembly, 
 *     while 2) can be written in either assembly or C
 */
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


/*
 * @@@ [8 pts]
 * define a macro for restoring the context of the current thread by
 * essentially doing the reverse of SAVESTATE:
 * 1) assign SP to the saved SP from the saved stack pointer array
 * 2) pop the registers PSW, data pointer registers, B reg, and ACC
 * Again, popping must be done in assembly but restoring SP can be
 * done in either C or assembly.
 */
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
	/*
    * @@@ [2 pts] 
    * initialize data structures for threads (e.g., mask)
    *
    * optional: move the stack pointer to some known location
    * only during bootstrapping. by default, SP is 0x07.
    *
    * @@@ [2 pts]
    *     create a thread for main; be sure current thread is
    *     set to this thread ID, and restore its context,
    *     so that it starts running main().
    */
   	TMOD = 0;  // timer 0 mode 0
    IE = 0x82;  // enable timer 0 interrupt; keep consumer polling
                // EA  -  ET2  ES  ET1  EX1  ET0  EX0
    TR0 = 1; // set bit TR0 to start running timer 0

	mask = 0b0000;
	isAlive[0] = 0b0001; 
	isAlive[1] = 0b0010; 
	isAlive[2] = 0b0100; 
	isAlive[3] = 0b1000;
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
	/*
	* @@@ [2 pts] 
	* check to see we have not reached the max #threads.
	* if so, return -1, which is not a valid thread ID.
	*/
	if(mask == 0b1111) return -1;

	/*
	* @@@ [5 pts]
	*     otherwise, find a thread ID that is not in use,
	*     and grab it. (can check the bit mask for threads),
	* 
	* @@@ [18 pts] below
	* a. update the bit mask 
		(and increment thread count, if you use a thread count, 
		but it is optional)
	b. calculate the starting stack location for new thread
	c. save the current SP in a temporary
		set SP to the starting location for the new thread
	d. push the return address fp (2-byte parameter to
		ThreadCreate) onto stack so it can be the return
		address to resume the thread. Note that in SDCC
		convention, 2-byte ptr is passed in DPTR.  but
		push instruction can only push it as two separate
		registers, DPL and DPH.
	e. we want to initialize the registers to 0, so we
		assign a register to 0 and push it four times
		for ACC, B, DPL, DPH.  Note: push #0 will not work
		because push takes only direct address as its operand,
		but it does not take an immediate (literal) operand.
	f. finally, we need to push PSW (processor status word)
		register, which consist of bits
		CY AC F0 RS1 RS0 OV UD P
		all bits can be initialized to zero, except <RS1:RS0>
		which selects the register bank.  
		Thread 0 uses bank 0, Thread 1 uses bank 1, etc.
		Setting the bits to 00B, 01B, 10B, 11B will select 
		the register bank so no need to push/pop registers
		R0-R7.  So, set PSW to 
		00000000B for thread 0, 00001000B for thread 1,
		00010000B for thread 2, 00011000B for thread 3.
	g. write the current stack pointer to the saved stack
		pointer array for this newly created thread ID
	h. set SP to the saved SP in step c.
	i. finally, return the newly created thread ID.
	*/

	//find a thread ID that is not in use, and grab it.
	// A. B. 
	//Do __critical before the entire function body
	__critical{
		for(i = 0; i < MAXTHREADS; i++) {
			if(((mask) & (0b0001 << i)) == 0) {
				mask |= (0b0001 << i);
				newThread = i;
				break;
			}
		}

		// C.
		tmp = SP;
		SP = 0x3F + (i << 4);

		// D. E.
		__asm
			push DPL
			push DPH
			mov A, #0
			push A
			push A
			push A
			push A
		__endasm;

		// F.
		/*
		00000000B for thread 0, 00001000B for thread 1,
		00010000B for thread 2, 00011000B for thread 3.
		==> THAT IS TO SHIFT RIGHT 3 BITS
		*/
		tmp2 = (i << 3);
		
		__asm
			push _tmp2
		__endasm;
		
		//G. H. I.
		savedSP[newThread] = SP;
		SP = tmp;
	}
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
	__critical{
		mask &= ~(1 << curThread);
		do {
			curThread = (curThread == 3) ? 0 : curThread + 1;
			if(mask & (1 << curThread)) break;
		} while (1);
		RESTORESTATE;
	}
}

void myTimer0Handler(){

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
		/*
			* @@@ [8 pts] do round-robin policy for now.
			* find the next thread that can run and 
			* set the current thread ID to it,
			* so that it can be restored (by the last line of 
			* this function).
			* there should be at least one thread, so this loop
			* will always terminate.
			*/
		curThread = (curThread == MAXTHREADS - 1) ? 0 : curThread + 1;
		if(mask & isAlive[curThread]) break;
	} while (1);
	
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
	__asm
			reti
	__endasm;
}

