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

__data __at (0x30) Semaphore mutex;
__data __at (0x31) Semaphore full;
__data __at (0x32) Semaphore empty;
__data __at (0x33) char buf[3];	//3 deep char buffer
__data __at (0x36) char head; //keep track of the head and tail for this circular queue
__data __at (0x37) char tail;
__data __at (0x38) char ch;
__data __at (0x39) char val;


/* Instead of Producer() function, 
 * make Producer1() and Producer2() functions.  
 * Producer1 should output letters 'A' to 'Z' 
 * and repeat forever; 
 * Producer2 should output '0' to '9' and 
 * repeat forever.
 */

void Producer1(void){
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
		ThreadYield();
	}
}


void Producer2(void){
	val = '0';
	while (1) {
		SemaphoreWait(empty);

		//while(buf != '\0');
		__critical{
			SemaphoreWait(mutex);
			buf[head] = val;
			head = (head == 2) ? 0 : head + 1;
			SemaphoreSignal(mutex);
		}
		
		SemaphoreSignal(full);
		val = (val == '9') ? '0' : val + 1;
		ThreadYield();
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

	// spawn Producer1 first then Producer2
	ThreadCreate(Producer1);
	ThreadCreate(Producer2); 
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
		
