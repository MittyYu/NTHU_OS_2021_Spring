/* 
 * file: testcoop.c 
 */
#include <8051.h>
#include "cooperative.h"

/* 
 * @@@ [2pt] 
 * declare your global variables here, for the shared buffer 
 * between the producer and consumer.  
 * Hint: you may want to manually designate the location for the 
 * variable.  you can use
 *        __data __at (0x30) type var; 
 * to declare a variable var of the type
 */ 
__data __at (0x3E) char buf;
__data __at (0x3F) char ch;

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
		/* @@@ [6 pt]
		 * wait for the buffer to be available, 
		 * and then write the new data into the buffer 
		 */
		while(buf != '\0') ThreadYield();
		buf = ch;
		ch = (ch == 'Z') ? 'A' : ch+1;
		ThreadYield();
	}
}


/* [10 pts for this function]
 * the consumer in this test program gets the next item from
 * the queue and consume it and writes it to the serial port.
 * The Consumer also does not return.
 */
void Consumer(void) {
	TMOD = 0x20;
	TH1 = -6;
	SCON = 0x50;
	TR1 = 1;
	while (1) {
		/* @@@ [2 pt] wait for new data from producer
		 * @@@ [6 pt] write data to serial port Tx, 
		 * poll for Tx to finish writing (TI),
		 * then clear the flag
		 */
		while(buf == '\0') ThreadYield();
		SBUF = buf;
		buf = '\0';
		while(!TI) ThreadYield();
		TI = 0;
		
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
	buf = '\0';
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


		
		
