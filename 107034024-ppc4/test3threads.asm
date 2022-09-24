;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Mac OS X x86_64)
;--------------------------------------------------------
	.module test3threads
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _timer0_ISR
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genXINIT
	.globl __mcs51_genRAMCLEAR
	.globl __sdcc_gsinit_startup
	.globl _main
	.globl _Consumer
	.globl _Producer2
	.globl _Producer1
	.globl _ThreadYield
	.globl _ThreadCreate
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _val
	.globl _ch
	.globl _tail
	.globl _head
	.globl _buf
	.globl _empty
	.globl _full
	.globl _mutex
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_mutex	=	0x0030
_full	=	0x0031
_empty	=	0x0032
_buf	=	0x0033
_head	=	0x0036
_tail	=	0x0037
_ch	=	0x0038
_val	=	0x0039
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	ljmp	_timer0_ISR
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Producer1'
;------------------------------------------------------------
;	test3threads.c:35: void Producer1(void){
;	-----------------------------------------
;	 function Producer1
;	-----------------------------------------
_Producer1:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	test3threads.c:36: ch = 'A';
	mov	_ch,#0x41
;	test3threads.c:37: while (1) {
00102$:
;	test3threads.c:38: SemaphoreWait(empty);
		0$:
	mov ACC, _empty 
	jz 0$ 
	jb ACC.7, 0$ 
	dec _empty 
;	test3threads.c:46: }
	mov	r7,#0x01
	jbc	ea,00122$
	mov	r7,#0x00
00122$:
;	test3threads.c:42: SemaphoreWait(mutex);
		1$:
	mov ACC, _mutex 
	jz 1$ 
	jb ACC.7, 1$ 
	dec _mutex 
;	test3threads.c:43: buf[head] = ch;
	mov	a,_head
	add	a,#_buf
	mov	r0,a
	mov	@r0,_ch
;	test3threads.c:44: head = (head == 2) ? 0 : head + 1;
	mov	a,#0x02
	cjne	a,_head,00106$
	mov	r5,#0x00
	mov	r6,#0x00
	sjmp	00107$
00106$:
	mov	r4,_head
	inc	r4
	mov	a,r4
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
00107$:
	mov	_head,r5
;	test3threads.c:45: SemaphoreSignal(mutex);
	INC _mutex 
	mov	a,r7
	rrc	a
	mov	ea,c
;	test3threads.c:48: SemaphoreSignal(full);
	INC _full 
;	test3threads.c:49: ch = (ch == 'Z') ? 'A' : ch+1;
	mov	a,#0x5a
	cjne	a,_ch,00108$
	mov	r6,#0x41
	mov	r7,#0x00
	sjmp	00109$
00108$:
	mov	r5,_ch
	inc	r5
	mov	a,r5
	mov	r6,a
	rlc	a
	subb	a,acc
	mov	r7,a
00109$:
	mov	_ch,r6
;	test3threads.c:50: ThreadYield();
	lcall	_ThreadYield
;	test3threads.c:52: }
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'Producer2'
;------------------------------------------------------------
;	test3threads.c:55: void Producer2(void){
;	-----------------------------------------
;	 function Producer2
;	-----------------------------------------
_Producer2:
;	test3threads.c:56: val = '0';
	mov	_val,#0x30
;	test3threads.c:57: while (1) {
00102$:
;	test3threads.c:58: SemaphoreWait(empty);
		2$:
	mov ACC, _empty 
	jz 2$ 
	jb ACC.7, 2$ 
	dec _empty 
;	test3threads.c:66: }
	mov	r7,#0x01
	jbc	ea,00122$
	mov	r7,#0x00
00122$:
;	test3threads.c:62: SemaphoreWait(mutex);
		3$:
	mov ACC, _mutex 
	jz 3$ 
	jb ACC.7, 3$ 
	dec _mutex 
;	test3threads.c:63: buf[head] = val;
	mov	a,_head
	add	a,#_buf
	mov	r0,a
	mov	@r0,_val
;	test3threads.c:64: head = (head == 2) ? 0 : head + 1;
	mov	a,#0x02
	cjne	a,_head,00106$
	mov	r5,#0x00
	mov	r6,#0x00
	sjmp	00107$
00106$:
	mov	r4,_head
	inc	r4
	mov	a,r4
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
00107$:
	mov	_head,r5
;	test3threads.c:65: SemaphoreSignal(mutex);
	INC _mutex 
	mov	a,r7
	rrc	a
	mov	ea,c
;	test3threads.c:68: SemaphoreSignal(full);
	INC _full 
;	test3threads.c:69: val = (val == '9') ? '0' : val + 1;
	mov	a,#0x39
	cjne	a,_val,00108$
	mov	r6,#0x30
	mov	r7,#0x00
	sjmp	00109$
00108$:
	mov	r5,_val
	inc	r5
	mov	a,r5
	mov	r6,a
	rlc	a
	subb	a,acc
	mov	r7,a
00109$:
	mov	_val,r6
;	test3threads.c:70: ThreadYield();
	lcall	_ThreadYield
;	test3threads.c:72: }
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'Consumer'
;------------------------------------------------------------
;	test3threads.c:79: void Consumer(void) {
;	-----------------------------------------
;	 function Consumer
;	-----------------------------------------
_Consumer:
;	test3threads.c:80: TMOD |= 0x20;
	orl	_TMOD,#0x20
;	test3threads.c:81: TH1 = -6;
	mov	_TH1,#0xfa
;	test3threads.c:82: SCON = 0x50;
	mov	_SCON,#0x50
;	test3threads.c:83: TR1 = 1;
;	assignBit
	setb	_TR1
;	test3threads.c:84: while (1) {
00105$:
;	test3threads.c:85: SemaphoreWait(full);
		4$:
	mov ACC, _full 
	jz 4$ 
	jb ACC.7, 4$ 
	dec _full 
;	test3threads.c:94: }
	mov	r7,#0x01
	jbc	ea,00127$
	mov	r7,#0x00
00127$:
;	test3threads.c:88: SemaphoreWait(mutex);
		5$:
	mov ACC, _mutex 
	jz 5$ 
	jb ACC.7, 5$ 
	dec _mutex 
;	test3threads.c:89: SBUF = buf[tail];
	mov	a,_tail
	add	a,#_buf
	mov	r1,a
	mov	_SBUF,@r1
;	test3threads.c:90: while(!TI);
00101$:
;	test3threads.c:91: TI = 0;
;	assignBit
	jbc	_TI,00128$
	sjmp	00101$
00128$:
;	test3threads.c:92: tail = (tail == 2) ? 0 : tail + 1;
	mov	a,#0x02
	cjne	a,_tail,00109$
	mov	r5,#0x00
	mov	r6,#0x00
	sjmp	00110$
00109$:
	mov	r4,_tail
	inc	r4
	mov	a,r4
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
00110$:
	mov	_tail,r5
;	test3threads.c:93: SemaphoreSignal(mutex);
	INC _mutex 
	mov	a,r7
	rrc	a
	mov	ea,c
;	test3threads.c:96: SemaphoreSignal(empty);
	INC _empty 
;	test3threads.c:98: }
	sjmp	00105$
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	test3threads.c:105: void main(void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	test3threads.c:119: }
	mov	r7,#0x01
	jbc	ea,00103$
	mov	r7,#0x00
00103$:
;	test3threads.c:113: buf[0] = buf[1] = buf[2] = '\0';
	mov	(_buf + 0x0002),#0x00
	mov	(_buf + 0x0001),#0x00
	mov	_buf,#0x00
;	test3threads.c:114: head = 0;
	mov	_head,#0x00
;	test3threads.c:115: tail = 0;
	mov	_tail,#0x00
;	test3threads.c:116: SemaphoreCreate(mutex, 1);
	mov	_mutex,#0x01
;	test3threads.c:117: SemaphoreCreate(full, 0);
	mov	_full,#0x00
;	test3threads.c:118: SemaphoreCreate(empty, 3);                      
	mov	_empty,#0x03
	mov	a,r7
	rrc	a
	mov	ea,c
;	test3threads.c:122: ThreadCreate(Producer1);
	mov	dptr,#_Producer1
	lcall	_ThreadCreate
;	test3threads.c:123: ThreadCreate(Producer2); 
	mov	dptr,#_Producer2
	lcall	_ThreadCreate
;	test3threads.c:124: Consumer();
;	test3threads.c:125: }                 
	ljmp	_Consumer
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_gsinit_startup'
;------------------------------------------------------------
;	test3threads.c:127: void _sdcc_gsinit_startup(void) {
;	-----------------------------------------
;	 function _sdcc_gsinit_startup
;	-----------------------------------------
__sdcc_gsinit_startup:
;	test3threads.c:130: __endasm;
	ljmp	_Bootstrap
;	test3threads.c:131: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
;------------------------------------------------------------
;	test3threads.c:133: void _mcs51_genRAMCLEAR(void) {}
;	-----------------------------------------
;	 function _mcs51_genRAMCLEAR
;	-----------------------------------------
__mcs51_genRAMCLEAR:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genXINIT'
;------------------------------------------------------------
;	test3threads.c:134: void _mcs51_genXINIT(void) {}
;	-----------------------------------------
;	 function _mcs51_genXINIT
;	-----------------------------------------
__mcs51_genXINIT:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
;------------------------------------------------------------
;	test3threads.c:135: void _mcs51_genXRAMCLEAR(void) {}
;	-----------------------------------------
;	 function _mcs51_genXRAMCLEAR
;	-----------------------------------------
__mcs51_genXRAMCLEAR:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_ISR'
;------------------------------------------------------------
;	test3threads.c:138: void timer0_ISR(void) __interrupt(1) {
;	-----------------------------------------
;	 function timer0_ISR
;	-----------------------------------------
_timer0_ISR:
;	test3threads.c:141: __endasm;
	ljmp	_myTimer0Handler
;	test3threads.c:142: }	
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop psw
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;	eliminated unneeded push/pop acc
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
