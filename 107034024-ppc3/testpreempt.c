/* 
 * file: testpreempt.c 
 */
#include <8051.h>
#include "preemptive.h"

/* 
 * @@@ [2pt] 
 * declare your global variables here, for the shared buffer 
 * between the producer and consumer.  
 * Hint: you may want to manually designate the location for the 
 * variable.  you can use
 *        __data __at (0x30) type var; 
 * to declare a variable var of the type
 */ 

__data __at (0x20) Semaphore mutex;
__data __at (0x21) Semaphore full;
__data __at (0x22) Semaphore empty;
__data __at (0x23) char buf[3];	//3 deep char buffer
__data __at (0x26) char head; //keep track of the head and tail for this circular queue
__data __at (0x27) char tail;
__data __at (0x28) char ch;


/* [8 pts] for this function
 * the producer in this test program generates one characters at a
 * time from 'A' to 'Z' and starts from 'A' again. The shared buffer
 * must be empty in order for the Producer to write.
 */
void Producer(void){
	/*
	 * @@@ [2 pt]
	 * initialize producer data structure, and then enter
	 * an infinite loop (does not return)
	 */
	ch = 'A';
	while (1) {
		SemaphoreWait(empty);

		//while(buf != '\0');
		__critical{
			SemaphoreWait(mutex);
			buf[head] = ch;
			head = (head == 2) ? 0 : head + 1;
			SemaphoreSignal(mutex);
		}
		
		SemaphoreSignal(full);
		ch = (ch == 'Z') ? 'A' : ch+1;
	}
}


/* [10 pts for this function]
 * the consumer in this test program gets the next item from
 * the queue and consume it and writes it to the serial port.
 * The Consumer also does not return.
 */
void Consumer(void) {
	TMOD |= 0x20;
	TH1 = -6;
	SCON = 0x50;
	TR1 = 1;
	while (1) {
		SemaphoreWait(full);
		
		__critical{
			SemaphoreWait(mutex);
			SBUF = buf[tail];
			while(!TI);
			TI = 0;
			tail = (tail == 2) ? 0 : tail + 1;
			SemaphoreSignal(mutex);
		}
		
		SemaphoreSignal(empty);
	}
}

/* [5 pts for this function]
 * main() is started by the thread bootstrapper as thread-0.
 * It can create more thread(s) as needed:
 * one thread can acts as producer and another as consumer.
 */
void main(void) {
	/* 
     * @@@ [1 pt] initialize globals 
     * @@@ [4 pt] set up Producer and Consumer.
     * Because both are infinite loops, there is no loop
     * in this function and no return.
     */
	__critical{
		buf[0] = buf[1] = buf[2] = '\0';
		head = 0;
		tail = 0;
		SemaphoreCreate(mutex, 1);
		SemaphoreCreate(full, 0);
		SemaphoreCreate(empty, 3);
	}
	ThreadCreate(Producer);
	Consumer();
}

void _sdcc_gsinit_startup(void) {
    __asm
        ljmp  _Bootstrap
    __endasm;
}

void _mcs51_genRAMCLEAR(void) {}
void _mcs51_genXINIT(void) {}
void _mcs51_genXRAMCLEAR(void) {}

// This allows ISR to call your routine '_myTimer0Handler'
void timer0_ISR(void) __interrupt(1) {
	__asm
		ljmp _myTimer0Handler
	__endasm;
}	
		
