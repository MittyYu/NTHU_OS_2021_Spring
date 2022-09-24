                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Mac OS X x86_64)
                                      4 ;--------------------------------------------------------
                                      5 	.module testpreempt
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _timer0_ISR
                                     12 	.globl __mcs51_genXRAMCLEAR
                                     13 	.globl __mcs51_genXINIT
                                     14 	.globl __mcs51_genRAMCLEAR
                                     15 	.globl __sdcc_gsinit_startup
                                     16 	.globl _main
                                     17 	.globl _Consumer
                                     18 	.globl _Producer
                                     19 	.globl _ThreadCreate
                                     20 	.globl _CY
                                     21 	.globl _AC
                                     22 	.globl _F0
                                     23 	.globl _RS1
                                     24 	.globl _RS0
                                     25 	.globl _OV
                                     26 	.globl _F1
                                     27 	.globl _P
                                     28 	.globl _PS
                                     29 	.globl _PT1
                                     30 	.globl _PX1
                                     31 	.globl _PT0
                                     32 	.globl _PX0
                                     33 	.globl _RD
                                     34 	.globl _WR
                                     35 	.globl _T1
                                     36 	.globl _T0
                                     37 	.globl _INT1
                                     38 	.globl _INT0
                                     39 	.globl _TXD
                                     40 	.globl _RXD
                                     41 	.globl _P3_7
                                     42 	.globl _P3_6
                                     43 	.globl _P3_5
                                     44 	.globl _P3_4
                                     45 	.globl _P3_3
                                     46 	.globl _P3_2
                                     47 	.globl _P3_1
                                     48 	.globl _P3_0
                                     49 	.globl _EA
                                     50 	.globl _ES
                                     51 	.globl _ET1
                                     52 	.globl _EX1
                                     53 	.globl _ET0
                                     54 	.globl _EX0
                                     55 	.globl _P2_7
                                     56 	.globl _P2_6
                                     57 	.globl _P2_5
                                     58 	.globl _P2_4
                                     59 	.globl _P2_3
                                     60 	.globl _P2_2
                                     61 	.globl _P2_1
                                     62 	.globl _P2_0
                                     63 	.globl _SM0
                                     64 	.globl _SM1
                                     65 	.globl _SM2
                                     66 	.globl _REN
                                     67 	.globl _TB8
                                     68 	.globl _RB8
                                     69 	.globl _TI
                                     70 	.globl _RI
                                     71 	.globl _P1_7
                                     72 	.globl _P1_6
                                     73 	.globl _P1_5
                                     74 	.globl _P1_4
                                     75 	.globl _P1_3
                                     76 	.globl _P1_2
                                     77 	.globl _P1_1
                                     78 	.globl _P1_0
                                     79 	.globl _TF1
                                     80 	.globl _TR1
                                     81 	.globl _TF0
                                     82 	.globl _TR0
                                     83 	.globl _IE1
                                     84 	.globl _IT1
                                     85 	.globl _IE0
                                     86 	.globl _IT0
                                     87 	.globl _P0_7
                                     88 	.globl _P0_6
                                     89 	.globl _P0_5
                                     90 	.globl _P0_4
                                     91 	.globl _P0_3
                                     92 	.globl _P0_2
                                     93 	.globl _P0_1
                                     94 	.globl _P0_0
                                     95 	.globl _B
                                     96 	.globl _ACC
                                     97 	.globl _PSW
                                     98 	.globl _IP
                                     99 	.globl _P3
                                    100 	.globl _IE
                                    101 	.globl _P2
                                    102 	.globl _SBUF
                                    103 	.globl _SCON
                                    104 	.globl _P1
                                    105 	.globl _TH1
                                    106 	.globl _TH0
                                    107 	.globl _TL1
                                    108 	.globl _TL0
                                    109 	.globl _TMOD
                                    110 	.globl _TCON
                                    111 	.globl _PCON
                                    112 	.globl _DPH
                                    113 	.globl _DPL
                                    114 	.globl _SP
                                    115 	.globl _P0
                                    116 	.globl _ch
                                    117 	.globl _tail
                                    118 	.globl _head
                                    119 	.globl _buf
                                    120 	.globl _empty
                                    121 	.globl _full
                                    122 	.globl _mutex
                                    123 ;--------------------------------------------------------
                                    124 ; special function registers
                                    125 ;--------------------------------------------------------
                                    126 	.area RSEG    (ABS,DATA)
      000000                        127 	.org 0x0000
                           000080   128 _P0	=	0x0080
                           000081   129 _SP	=	0x0081
                           000082   130 _DPL	=	0x0082
                           000083   131 _DPH	=	0x0083
                           000087   132 _PCON	=	0x0087
                           000088   133 _TCON	=	0x0088
                           000089   134 _TMOD	=	0x0089
                           00008A   135 _TL0	=	0x008a
                           00008B   136 _TL1	=	0x008b
                           00008C   137 _TH0	=	0x008c
                           00008D   138 _TH1	=	0x008d
                           000090   139 _P1	=	0x0090
                           000098   140 _SCON	=	0x0098
                           000099   141 _SBUF	=	0x0099
                           0000A0   142 _P2	=	0x00a0
                           0000A8   143 _IE	=	0x00a8
                           0000B0   144 _P3	=	0x00b0
                           0000B8   145 _IP	=	0x00b8
                           0000D0   146 _PSW	=	0x00d0
                           0000E0   147 _ACC	=	0x00e0
                           0000F0   148 _B	=	0x00f0
                                    149 ;--------------------------------------------------------
                                    150 ; special function bits
                                    151 ;--------------------------------------------------------
                                    152 	.area RSEG    (ABS,DATA)
      000000                        153 	.org 0x0000
                           000080   154 _P0_0	=	0x0080
                           000081   155 _P0_1	=	0x0081
                           000082   156 _P0_2	=	0x0082
                           000083   157 _P0_3	=	0x0083
                           000084   158 _P0_4	=	0x0084
                           000085   159 _P0_5	=	0x0085
                           000086   160 _P0_6	=	0x0086
                           000087   161 _P0_7	=	0x0087
                           000088   162 _IT0	=	0x0088
                           000089   163 _IE0	=	0x0089
                           00008A   164 _IT1	=	0x008a
                           00008B   165 _IE1	=	0x008b
                           00008C   166 _TR0	=	0x008c
                           00008D   167 _TF0	=	0x008d
                           00008E   168 _TR1	=	0x008e
                           00008F   169 _TF1	=	0x008f
                           000090   170 _P1_0	=	0x0090
                           000091   171 _P1_1	=	0x0091
                           000092   172 _P1_2	=	0x0092
                           000093   173 _P1_3	=	0x0093
                           000094   174 _P1_4	=	0x0094
                           000095   175 _P1_5	=	0x0095
                           000096   176 _P1_6	=	0x0096
                           000097   177 _P1_7	=	0x0097
                           000098   178 _RI	=	0x0098
                           000099   179 _TI	=	0x0099
                           00009A   180 _RB8	=	0x009a
                           00009B   181 _TB8	=	0x009b
                           00009C   182 _REN	=	0x009c
                           00009D   183 _SM2	=	0x009d
                           00009E   184 _SM1	=	0x009e
                           00009F   185 _SM0	=	0x009f
                           0000A0   186 _P2_0	=	0x00a0
                           0000A1   187 _P2_1	=	0x00a1
                           0000A2   188 _P2_2	=	0x00a2
                           0000A3   189 _P2_3	=	0x00a3
                           0000A4   190 _P2_4	=	0x00a4
                           0000A5   191 _P2_5	=	0x00a5
                           0000A6   192 _P2_6	=	0x00a6
                           0000A7   193 _P2_7	=	0x00a7
                           0000A8   194 _EX0	=	0x00a8
                           0000A9   195 _ET0	=	0x00a9
                           0000AA   196 _EX1	=	0x00aa
                           0000AB   197 _ET1	=	0x00ab
                           0000AC   198 _ES	=	0x00ac
                           0000AF   199 _EA	=	0x00af
                           0000B0   200 _P3_0	=	0x00b0
                           0000B1   201 _P3_1	=	0x00b1
                           0000B2   202 _P3_2	=	0x00b2
                           0000B3   203 _P3_3	=	0x00b3
                           0000B4   204 _P3_4	=	0x00b4
                           0000B5   205 _P3_5	=	0x00b5
                           0000B6   206 _P3_6	=	0x00b6
                           0000B7   207 _P3_7	=	0x00b7
                           0000B0   208 _RXD	=	0x00b0
                           0000B1   209 _TXD	=	0x00b1
                           0000B2   210 _INT0	=	0x00b2
                           0000B3   211 _INT1	=	0x00b3
                           0000B4   212 _T0	=	0x00b4
                           0000B5   213 _T1	=	0x00b5
                           0000B6   214 _WR	=	0x00b6
                           0000B7   215 _RD	=	0x00b7
                           0000B8   216 _PX0	=	0x00b8
                           0000B9   217 _PT0	=	0x00b9
                           0000BA   218 _PX1	=	0x00ba
                           0000BB   219 _PT1	=	0x00bb
                           0000BC   220 _PS	=	0x00bc
                           0000D0   221 _P	=	0x00d0
                           0000D1   222 _F1	=	0x00d1
                           0000D2   223 _OV	=	0x00d2
                           0000D3   224 _RS0	=	0x00d3
                           0000D4   225 _RS1	=	0x00d4
                           0000D5   226 _F0	=	0x00d5
                           0000D6   227 _AC	=	0x00d6
                           0000D7   228 _CY	=	0x00d7
                                    229 ;--------------------------------------------------------
                                    230 ; overlayable register banks
                                    231 ;--------------------------------------------------------
                                    232 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        233 	.ds 8
                                    234 ;--------------------------------------------------------
                                    235 ; internal ram data
                                    236 ;--------------------------------------------------------
                                    237 	.area DSEG    (DATA)
                           000020   238 _mutex	=	0x0020
                           000021   239 _full	=	0x0021
                           000022   240 _empty	=	0x0022
                           000023   241 _buf	=	0x0023
                           000026   242 _head	=	0x0026
                           000027   243 _tail	=	0x0027
                           000028   244 _ch	=	0x0028
                                    245 ;--------------------------------------------------------
                                    246 ; overlayable items in internal ram 
                                    247 ;--------------------------------------------------------
                                    248 ;--------------------------------------------------------
                                    249 ; Stack segment in internal ram 
                                    250 ;--------------------------------------------------------
                                    251 	.area	SSEG
      000008                        252 __start__stack:
      000008                        253 	.ds	1
                                    254 
                                    255 ;--------------------------------------------------------
                                    256 ; indirectly addressable internal ram data
                                    257 ;--------------------------------------------------------
                                    258 	.area ISEG    (DATA)
                                    259 ;--------------------------------------------------------
                                    260 ; absolute internal ram data
                                    261 ;--------------------------------------------------------
                                    262 	.area IABS    (ABS,DATA)
                                    263 	.area IABS    (ABS,DATA)
                                    264 ;--------------------------------------------------------
                                    265 ; bit data
                                    266 ;--------------------------------------------------------
                                    267 	.area BSEG    (BIT)
                                    268 ;--------------------------------------------------------
                                    269 ; paged external ram data
                                    270 ;--------------------------------------------------------
                                    271 	.area PSEG    (PAG,XDATA)
                                    272 ;--------------------------------------------------------
                                    273 ; external ram data
                                    274 ;--------------------------------------------------------
                                    275 	.area XSEG    (XDATA)
                                    276 ;--------------------------------------------------------
                                    277 ; absolute external ram data
                                    278 ;--------------------------------------------------------
                                    279 	.area XABS    (ABS,XDATA)
                                    280 ;--------------------------------------------------------
                                    281 ; external initialized ram data
                                    282 ;--------------------------------------------------------
                                    283 	.area XISEG   (XDATA)
                                    284 	.area HOME    (CODE)
                                    285 	.area GSINIT0 (CODE)
                                    286 	.area GSINIT1 (CODE)
                                    287 	.area GSINIT2 (CODE)
                                    288 	.area GSINIT3 (CODE)
                                    289 	.area GSINIT4 (CODE)
                                    290 	.area GSINIT5 (CODE)
                                    291 	.area GSINIT  (CODE)
                                    292 	.area GSFINAL (CODE)
                                    293 	.area CSEG    (CODE)
                                    294 ;--------------------------------------------------------
                                    295 ; interrupt vector 
                                    296 ;--------------------------------------------------------
                                    297 	.area HOME    (CODE)
      000000                        298 __interrupt_vect:
      000000 02 00 ED         [24]  299 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  300 	reti
      000004                        301 	.ds	7
      00000B 02 00 F4         [24]  302 	ljmp	_timer0_ISR
                                    303 ;--------------------------------------------------------
                                    304 ; global & static initialisations
                                    305 ;--------------------------------------------------------
                                    306 	.area HOME    (CODE)
                                    307 	.area GSINIT  (CODE)
                                    308 	.area GSFINAL (CODE)
                                    309 	.area GSINIT  (CODE)
                                    310 	.globl __sdcc_gsinit_startup
                                    311 	.globl __sdcc_program_startup
                                    312 	.globl __start__stack
                                    313 	.globl __mcs51_genXINIT
                                    314 	.globl __mcs51_genXRAMCLEAR
                                    315 	.globl __mcs51_genRAMCLEAR
                                    316 	.area GSFINAL (CODE)
      000011 02 00 0E         [24]  317 	ljmp	__sdcc_program_startup
                                    318 ;--------------------------------------------------------
                                    319 ; Home
                                    320 ;--------------------------------------------------------
                                    321 	.area HOME    (CODE)
                                    322 	.area HOME    (CODE)
      00000E                        323 __sdcc_program_startup:
      00000E 02 00 C1         [24]  324 	ljmp	_main
                                    325 ;	return from main will return to caller
                                    326 ;--------------------------------------------------------
                                    327 ; code
                                    328 ;--------------------------------------------------------
                                    329 	.area CSEG    (CODE)
                                    330 ;------------------------------------------------------------
                                    331 ;Allocation info for local variables in function 'Producer'
                                    332 ;------------------------------------------------------------
                                    333 ;	testpreempt.c:31: void Producer(void){
                                    334 ;	-----------------------------------------
                                    335 ;	 function Producer
                                    336 ;	-----------------------------------------
      000014                        337 _Producer:
                           000007   338 	ar7 = 0x07
                           000006   339 	ar6 = 0x06
                           000005   340 	ar5 = 0x05
                           000004   341 	ar4 = 0x04
                           000003   342 	ar3 = 0x03
                           000002   343 	ar2 = 0x02
                           000001   344 	ar1 = 0x01
                           000000   345 	ar0 = 0x00
                                    346 ;	testpreempt.c:37: ch = 'A';
      000014 75 28 41         [24]  347 	mov	_ch,#0x41
                                    348 ;	testpreempt.c:38: while (1) {
      000017                        349 00102$:
                                    350 ;	testpreempt.c:39: SemaphoreWait(empty);
      000017                        351 		0$:
      000017 85 22 E0         [24]  352 	mov ACC, _empty 
      00001A 60 FB            [24]  353 	jz 0$ 
      00001C 20 E7 F8         [24]  354 	jb ACC.7, 0$ 
      00001F 15 22            [12]  355 	dec _empty 
                                    356 ;	testpreempt.c:47: }
      000021 7F 01            [12]  357 	mov	r7,#0x01
      000023 10 AF 02         [24]  358 	jbc	ea,00122$
      000026 7F 00            [12]  359 	mov	r7,#0x00
      000028                        360 00122$:
                                    361 ;	testpreempt.c:43: SemaphoreWait(mutex);
      000028                        362 		1$:
      000028 85 20 E0         [24]  363 	mov ACC, _mutex 
      00002B 60 FB            [24]  364 	jz 1$ 
      00002D 20 E7 F8         [24]  365 	jb ACC.7, 1$ 
      000030 15 20            [12]  366 	dec _mutex 
                                    367 ;	testpreempt.c:44: buf[head] = ch;
      000032 E5 26            [12]  368 	mov	a,_head
      000034 24 23            [12]  369 	add	a,#_buf
      000036 F8               [12]  370 	mov	r0,a
      000037 A6 28            [24]  371 	mov	@r0,_ch
                                    372 ;	testpreempt.c:45: head = (head == 2) ? 0 : head + 1;
      000039 74 02            [12]  373 	mov	a,#0x02
      00003B B5 26 06         [24]  374 	cjne	a,_head,00106$
      00003E 7D 00            [12]  375 	mov	r5,#0x00
      000040 7E 00            [12]  376 	mov	r6,#0x00
      000042 80 09            [24]  377 	sjmp	00107$
      000044                        378 00106$:
      000044 AC 26            [24]  379 	mov	r4,_head
      000046 0C               [12]  380 	inc	r4
      000047 EC               [12]  381 	mov	a,r4
      000048 FD               [12]  382 	mov	r5,a
      000049 33               [12]  383 	rlc	a
      00004A 95 E0            [12]  384 	subb	a,acc
      00004C FE               [12]  385 	mov	r6,a
      00004D                        386 00107$:
      00004D 8D 26            [24]  387 	mov	_head,r5
                                    388 ;	testpreempt.c:46: SemaphoreSignal(mutex);
      00004F 05 20            [12]  389 	INC _mutex 
      000051 EF               [12]  390 	mov	a,r7
      000052 13               [12]  391 	rrc	a
      000053 92 AF            [24]  392 	mov	ea,c
                                    393 ;	testpreempt.c:49: SemaphoreSignal(full);
      000055 05 21            [12]  394 	INC _full 
                                    395 ;	testpreempt.c:50: ch = (ch == 'Z') ? 'A' : ch+1;
      000057 74 5A            [12]  396 	mov	a,#0x5a
      000059 B5 28 06         [24]  397 	cjne	a,_ch,00108$
      00005C 7E 41            [12]  398 	mov	r6,#0x41
      00005E 7F 00            [12]  399 	mov	r7,#0x00
      000060 80 09            [24]  400 	sjmp	00109$
      000062                        401 00108$:
      000062 AD 28            [24]  402 	mov	r5,_ch
      000064 0D               [12]  403 	inc	r5
      000065 ED               [12]  404 	mov	a,r5
      000066 FE               [12]  405 	mov	r6,a
      000067 33               [12]  406 	rlc	a
      000068 95 E0            [12]  407 	subb	a,acc
      00006A FF               [12]  408 	mov	r7,a
      00006B                        409 00109$:
      00006B 8E 28            [24]  410 	mov	_ch,r6
                                    411 ;	testpreempt.c:52: }
      00006D 80 A8            [24]  412 	sjmp	00102$
                                    413 ;------------------------------------------------------------
                                    414 ;Allocation info for local variables in function 'Consumer'
                                    415 ;------------------------------------------------------------
                                    416 ;	testpreempt.c:60: void Consumer(void) {
                                    417 ;	-----------------------------------------
                                    418 ;	 function Consumer
                                    419 ;	-----------------------------------------
      00006F                        420 _Consumer:
                                    421 ;	testpreempt.c:61: TMOD |= 0x20;
      00006F 43 89 20         [24]  422 	orl	_TMOD,#0x20
                                    423 ;	testpreempt.c:62: TH1 = -6;
      000072 75 8D FA         [24]  424 	mov	_TH1,#0xfa
                                    425 ;	testpreempt.c:63: SCON = 0x50;
      000075 75 98 50         [24]  426 	mov	_SCON,#0x50
                                    427 ;	testpreempt.c:64: TR1 = 1;
                                    428 ;	assignBit
      000078 D2 8E            [12]  429 	setb	_TR1
                                    430 ;	testpreempt.c:65: while (1) {
      00007A                        431 00105$:
                                    432 ;	testpreempt.c:66: SemaphoreWait(full);
      00007A                        433 		2$:
      00007A 85 21 E0         [24]  434 	mov ACC, _full 
      00007D 60 FB            [24]  435 	jz 2$ 
      00007F 20 E7 F8         [24]  436 	jb ACC.7, 2$ 
      000082 15 21            [12]  437 	dec _full 
                                    438 ;	testpreempt.c:75: }
      000084 7F 01            [12]  439 	mov	r7,#0x01
      000086 10 AF 02         [24]  440 	jbc	ea,00127$
      000089 7F 00            [12]  441 	mov	r7,#0x00
      00008B                        442 00127$:
                                    443 ;	testpreempt.c:69: SemaphoreWait(mutex);
      00008B                        444 		3$:
      00008B 85 20 E0         [24]  445 	mov ACC, _mutex 
      00008E 60 FB            [24]  446 	jz 3$ 
      000090 20 E7 F8         [24]  447 	jb ACC.7, 3$ 
      000093 15 20            [12]  448 	dec _mutex 
                                    449 ;	testpreempt.c:70: SBUF = buf[tail];
      000095 E5 27            [12]  450 	mov	a,_tail
      000097 24 23            [12]  451 	add	a,#_buf
      000099 F9               [12]  452 	mov	r1,a
      00009A 87 99            [24]  453 	mov	_SBUF,@r1
                                    454 ;	testpreempt.c:71: while(!TI);
      00009C                        455 00101$:
                                    456 ;	testpreempt.c:72: TI = 0;
                                    457 ;	assignBit
      00009C 10 99 02         [24]  458 	jbc	_TI,00128$
      00009F 80 FB            [24]  459 	sjmp	00101$
      0000A1                        460 00128$:
                                    461 ;	testpreempt.c:73: tail = (tail == 2) ? 0 : tail + 1;
      0000A1 74 02            [12]  462 	mov	a,#0x02
      0000A3 B5 27 06         [24]  463 	cjne	a,_tail,00109$
      0000A6 7D 00            [12]  464 	mov	r5,#0x00
      0000A8 7E 00            [12]  465 	mov	r6,#0x00
      0000AA 80 09            [24]  466 	sjmp	00110$
      0000AC                        467 00109$:
      0000AC AC 27            [24]  468 	mov	r4,_tail
      0000AE 0C               [12]  469 	inc	r4
      0000AF EC               [12]  470 	mov	a,r4
      0000B0 FD               [12]  471 	mov	r5,a
      0000B1 33               [12]  472 	rlc	a
      0000B2 95 E0            [12]  473 	subb	a,acc
      0000B4 FE               [12]  474 	mov	r6,a
      0000B5                        475 00110$:
      0000B5 8D 27            [24]  476 	mov	_tail,r5
                                    477 ;	testpreempt.c:74: SemaphoreSignal(mutex);
      0000B7 05 20            [12]  478 	INC _mutex 
      0000B9 EF               [12]  479 	mov	a,r7
      0000BA 13               [12]  480 	rrc	a
      0000BB 92 AF            [24]  481 	mov	ea,c
                                    482 ;	testpreempt.c:77: SemaphoreSignal(empty);
      0000BD 05 22            [12]  483 	INC _empty 
                                    484 ;	testpreempt.c:79: }
      0000BF 80 B9            [24]  485 	sjmp	00105$
                                    486 ;------------------------------------------------------------
                                    487 ;Allocation info for local variables in function 'main'
                                    488 ;------------------------------------------------------------
                                    489 ;	testpreempt.c:86: void main(void) {
                                    490 ;	-----------------------------------------
                                    491 ;	 function main
                                    492 ;	-----------------------------------------
      0000C1                        493 _main:
                                    494 ;	testpreempt.c:100: }
      0000C1 7F 01            [12]  495 	mov	r7,#0x01
      0000C3 10 AF 02         [24]  496 	jbc	ea,00103$
      0000C6 7F 00            [12]  497 	mov	r7,#0x00
      0000C8                        498 00103$:
                                    499 ;	testpreempt.c:94: buf[0] = buf[1] = buf[2] = '\0';
      0000C8 75 25 00         [24]  500 	mov	(_buf + 0x0002),#0x00
      0000CB 75 24 00         [24]  501 	mov	(_buf + 0x0001),#0x00
      0000CE 75 23 00         [24]  502 	mov	_buf,#0x00
                                    503 ;	testpreempt.c:95: head = 0;
      0000D1 75 26 00         [24]  504 	mov	_head,#0x00
                                    505 ;	testpreempt.c:96: tail = 0;
      0000D4 75 27 00         [24]  506 	mov	_tail,#0x00
                                    507 ;	testpreempt.c:97: SemaphoreCreate(mutex, 1);
      0000D7 75 20 01         [24]  508 	mov	_mutex,#0x01
                                    509 ;	testpreempt.c:98: SemaphoreCreate(full, 0);
      0000DA 75 21 00         [24]  510 	mov	_full,#0x00
                                    511 ;	testpreempt.c:99: SemaphoreCreate(empty, 3);
      0000DD 75 22 03         [24]  512 	mov	_empty,#0x03
      0000E0 EF               [12]  513 	mov	a,r7
      0000E1 13               [12]  514 	rrc	a
      0000E2 92 AF            [24]  515 	mov	ea,c
                                    516 ;	testpreempt.c:101: ThreadCreate(Producer);
      0000E4 90 00 14         [24]  517 	mov	dptr,#_Producer
      0000E7 12 01 2A         [24]  518 	lcall	_ThreadCreate
                                    519 ;	testpreempt.c:102: Consumer();
                                    520 ;	testpreempt.c:103: }
      0000EA 02 00 6F         [24]  521 	ljmp	_Consumer
                                    522 ;------------------------------------------------------------
                                    523 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                    524 ;------------------------------------------------------------
                                    525 ;	testpreempt.c:105: void _sdcc_gsinit_startup(void) {
                                    526 ;	-----------------------------------------
                                    527 ;	 function _sdcc_gsinit_startup
                                    528 ;	-----------------------------------------
      0000ED                        529 __sdcc_gsinit_startup:
                                    530 ;	testpreempt.c:108: __endasm;
      0000ED 02 00 F8         [24]  531 	ljmp	_Bootstrap
                                    532 ;	testpreempt.c:109: }
      0000F0 22               [24]  533 	ret
                                    534 ;------------------------------------------------------------
                                    535 ;Allocation info for local variables in function '_mcs51_genRAMCLEAR'
                                    536 ;------------------------------------------------------------
                                    537 ;	testpreempt.c:111: void _mcs51_genRAMCLEAR(void) {}
                                    538 ;	-----------------------------------------
                                    539 ;	 function _mcs51_genRAMCLEAR
                                    540 ;	-----------------------------------------
      0000F1                        541 __mcs51_genRAMCLEAR:
      0000F1 22               [24]  542 	ret
                                    543 ;------------------------------------------------------------
                                    544 ;Allocation info for local variables in function '_mcs51_genXINIT'
                                    545 ;------------------------------------------------------------
                                    546 ;	testpreempt.c:112: void _mcs51_genXINIT(void) {}
                                    547 ;	-----------------------------------------
                                    548 ;	 function _mcs51_genXINIT
                                    549 ;	-----------------------------------------
      0000F2                        550 __mcs51_genXINIT:
      0000F2 22               [24]  551 	ret
                                    552 ;------------------------------------------------------------
                                    553 ;Allocation info for local variables in function '_mcs51_genXRAMCLEAR'
                                    554 ;------------------------------------------------------------
                                    555 ;	testpreempt.c:113: void _mcs51_genXRAMCLEAR(void) {}
                                    556 ;	-----------------------------------------
                                    557 ;	 function _mcs51_genXRAMCLEAR
                                    558 ;	-----------------------------------------
      0000F3                        559 __mcs51_genXRAMCLEAR:
      0000F3 22               [24]  560 	ret
                                    561 ;------------------------------------------------------------
                                    562 ;Allocation info for local variables in function 'timer0_ISR'
                                    563 ;------------------------------------------------------------
                                    564 ;	testpreempt.c:116: void timer0_ISR(void) __interrupt(1) {
                                    565 ;	-----------------------------------------
                                    566 ;	 function timer0_ISR
                                    567 ;	-----------------------------------------
      0000F4                        568 _timer0_ISR:
                                    569 ;	testpreempt.c:119: __endasm;
      0000F4 02 02 7A         [24]  570 	ljmp	_myTimer0Handler
                                    571 ;	testpreempt.c:120: }	
      0000F7 32               [24]  572 	reti
                                    573 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    574 ;	eliminated unneeded push/pop psw
                                    575 ;	eliminated unneeded push/pop dpl
                                    576 ;	eliminated unneeded push/pop dph
                                    577 ;	eliminated unneeded push/pop b
                                    578 ;	eliminated unneeded push/pop acc
                                    579 	.area CSEG    (CODE)
                                    580 	.area CONST   (CODE)
                                    581 	.area XINIT   (CODE)
                                    582 	.area CABS    (ABS,CODE)
