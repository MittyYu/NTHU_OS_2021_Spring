                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Mac OS X x86_64)
                                      4 ;--------------------------------------------------------
                                      5 	.module preemptive
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _myTimer0Handler
                                     12 	.globl _Bootstrap
                                     13 	.globl _main
                                     14 	.globl _CY
                                     15 	.globl _AC
                                     16 	.globl _F0
                                     17 	.globl _RS1
                                     18 	.globl _RS0
                                     19 	.globl _OV
                                     20 	.globl _F1
                                     21 	.globl _P
                                     22 	.globl _PS
                                     23 	.globl _PT1
                                     24 	.globl _PX1
                                     25 	.globl _PT0
                                     26 	.globl _PX0
                                     27 	.globl _RD
                                     28 	.globl _WR
                                     29 	.globl _T1
                                     30 	.globl _T0
                                     31 	.globl _INT1
                                     32 	.globl _INT0
                                     33 	.globl _TXD
                                     34 	.globl _RXD
                                     35 	.globl _P3_7
                                     36 	.globl _P3_6
                                     37 	.globl _P3_5
                                     38 	.globl _P3_4
                                     39 	.globl _P3_3
                                     40 	.globl _P3_2
                                     41 	.globl _P3_1
                                     42 	.globl _P3_0
                                     43 	.globl _EA
                                     44 	.globl _ES
                                     45 	.globl _ET1
                                     46 	.globl _EX1
                                     47 	.globl _ET0
                                     48 	.globl _EX0
                                     49 	.globl _P2_7
                                     50 	.globl _P2_6
                                     51 	.globl _P2_5
                                     52 	.globl _P2_4
                                     53 	.globl _P2_3
                                     54 	.globl _P2_2
                                     55 	.globl _P2_1
                                     56 	.globl _P2_0
                                     57 	.globl _SM0
                                     58 	.globl _SM1
                                     59 	.globl _SM2
                                     60 	.globl _REN
                                     61 	.globl _TB8
                                     62 	.globl _RB8
                                     63 	.globl _TI
                                     64 	.globl _RI
                                     65 	.globl _P1_7
                                     66 	.globl _P1_6
                                     67 	.globl _P1_5
                                     68 	.globl _P1_4
                                     69 	.globl _P1_3
                                     70 	.globl _P1_2
                                     71 	.globl _P1_1
                                     72 	.globl _P1_0
                                     73 	.globl _TF1
                                     74 	.globl _TR1
                                     75 	.globl _TF0
                                     76 	.globl _TR0
                                     77 	.globl _IE1
                                     78 	.globl _IT1
                                     79 	.globl _IE0
                                     80 	.globl _IT0
                                     81 	.globl _P0_7
                                     82 	.globl _P0_6
                                     83 	.globl _P0_5
                                     84 	.globl _P0_4
                                     85 	.globl _P0_3
                                     86 	.globl _P0_2
                                     87 	.globl _P0_1
                                     88 	.globl _P0_0
                                     89 	.globl _B
                                     90 	.globl _ACC
                                     91 	.globl _PSW
                                     92 	.globl _IP
                                     93 	.globl _P3
                                     94 	.globl _IE
                                     95 	.globl _P2
                                     96 	.globl _SBUF
                                     97 	.globl _SCON
                                     98 	.globl _P1
                                     99 	.globl _TH1
                                    100 	.globl _TH0
                                    101 	.globl _TL1
                                    102 	.globl _TL0
                                    103 	.globl _TMOD
                                    104 	.globl _TCON
                                    105 	.globl _PCON
                                    106 	.globl _DPH
                                    107 	.globl _DPL
                                    108 	.globl _SP
                                    109 	.globl _P0
                                    110 	.globl _isAlive
                                    111 	.globl _tmp2
                                    112 	.globl _tmp
                                    113 	.globl _i
                                    114 	.globl _newThread
                                    115 	.globl _mask
                                    116 	.globl _curThread
                                    117 	.globl _savedSP
                                    118 	.globl _ThreadCreate
                                    119 	.globl _ThreadYield
                                    120 	.globl _ThreadExit
                                    121 ;--------------------------------------------------------
                                    122 ; special function registers
                                    123 ;--------------------------------------------------------
                                    124 	.area RSEG    (ABS,DATA)
      000000                        125 	.org 0x0000
                           000080   126 _P0	=	0x0080
                           000081   127 _SP	=	0x0081
                           000082   128 _DPL	=	0x0082
                           000083   129 _DPH	=	0x0083
                           000087   130 _PCON	=	0x0087
                           000088   131 _TCON	=	0x0088
                           000089   132 _TMOD	=	0x0089
                           00008A   133 _TL0	=	0x008a
                           00008B   134 _TL1	=	0x008b
                           00008C   135 _TH0	=	0x008c
                           00008D   136 _TH1	=	0x008d
                           000090   137 _P1	=	0x0090
                           000098   138 _SCON	=	0x0098
                           000099   139 _SBUF	=	0x0099
                           0000A0   140 _P2	=	0x00a0
                           0000A8   141 _IE	=	0x00a8
                           0000B0   142 _P3	=	0x00b0
                           0000B8   143 _IP	=	0x00b8
                           0000D0   144 _PSW	=	0x00d0
                           0000E0   145 _ACC	=	0x00e0
                           0000F0   146 _B	=	0x00f0
                                    147 ;--------------------------------------------------------
                                    148 ; special function bits
                                    149 ;--------------------------------------------------------
                                    150 	.area RSEG    (ABS,DATA)
      000000                        151 	.org 0x0000
                           000080   152 _P0_0	=	0x0080
                           000081   153 _P0_1	=	0x0081
                           000082   154 _P0_2	=	0x0082
                           000083   155 _P0_3	=	0x0083
                           000084   156 _P0_4	=	0x0084
                           000085   157 _P0_5	=	0x0085
                           000086   158 _P0_6	=	0x0086
                           000087   159 _P0_7	=	0x0087
                           000088   160 _IT0	=	0x0088
                           000089   161 _IE0	=	0x0089
                           00008A   162 _IT1	=	0x008a
                           00008B   163 _IE1	=	0x008b
                           00008C   164 _TR0	=	0x008c
                           00008D   165 _TF0	=	0x008d
                           00008E   166 _TR1	=	0x008e
                           00008F   167 _TF1	=	0x008f
                           000090   168 _P1_0	=	0x0090
                           000091   169 _P1_1	=	0x0091
                           000092   170 _P1_2	=	0x0092
                           000093   171 _P1_3	=	0x0093
                           000094   172 _P1_4	=	0x0094
                           000095   173 _P1_5	=	0x0095
                           000096   174 _P1_6	=	0x0096
                           000097   175 _P1_7	=	0x0097
                           000098   176 _RI	=	0x0098
                           000099   177 _TI	=	0x0099
                           00009A   178 _RB8	=	0x009a
                           00009B   179 _TB8	=	0x009b
                           00009C   180 _REN	=	0x009c
                           00009D   181 _SM2	=	0x009d
                           00009E   182 _SM1	=	0x009e
                           00009F   183 _SM0	=	0x009f
                           0000A0   184 _P2_0	=	0x00a0
                           0000A1   185 _P2_1	=	0x00a1
                           0000A2   186 _P2_2	=	0x00a2
                           0000A3   187 _P2_3	=	0x00a3
                           0000A4   188 _P2_4	=	0x00a4
                           0000A5   189 _P2_5	=	0x00a5
                           0000A6   190 _P2_6	=	0x00a6
                           0000A7   191 _P2_7	=	0x00a7
                           0000A8   192 _EX0	=	0x00a8
                           0000A9   193 _ET0	=	0x00a9
                           0000AA   194 _EX1	=	0x00aa
                           0000AB   195 _ET1	=	0x00ab
                           0000AC   196 _ES	=	0x00ac
                           0000AF   197 _EA	=	0x00af
                           0000B0   198 _P3_0	=	0x00b0
                           0000B1   199 _P3_1	=	0x00b1
                           0000B2   200 _P3_2	=	0x00b2
                           0000B3   201 _P3_3	=	0x00b3
                           0000B4   202 _P3_4	=	0x00b4
                           0000B5   203 _P3_5	=	0x00b5
                           0000B6   204 _P3_6	=	0x00b6
                           0000B7   205 _P3_7	=	0x00b7
                           0000B0   206 _RXD	=	0x00b0
                           0000B1   207 _TXD	=	0x00b1
                           0000B2   208 _INT0	=	0x00b2
                           0000B3   209 _INT1	=	0x00b3
                           0000B4   210 _T0	=	0x00b4
                           0000B5   211 _T1	=	0x00b5
                           0000B6   212 _WR	=	0x00b6
                           0000B7   213 _RD	=	0x00b7
                           0000B8   214 _PX0	=	0x00b8
                           0000B9   215 _PT0	=	0x00b9
                           0000BA   216 _PX1	=	0x00ba
                           0000BB   217 _PT1	=	0x00bb
                           0000BC   218 _PS	=	0x00bc
                           0000D0   219 _P	=	0x00d0
                           0000D1   220 _F1	=	0x00d1
                           0000D2   221 _OV	=	0x00d2
                           0000D3   222 _RS0	=	0x00d3
                           0000D4   223 _RS1	=	0x00d4
                           0000D5   224 _F0	=	0x00d5
                           0000D6   225 _AC	=	0x00d6
                           0000D7   226 _CY	=	0x00d7
                                    227 ;--------------------------------------------------------
                                    228 ; overlayable register banks
                                    229 ;--------------------------------------------------------
                                    230 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        231 	.ds 8
                                    232 ;--------------------------------------------------------
                                    233 ; internal ram data
                                    234 ;--------------------------------------------------------
                                    235 	.area DSEG    (DATA)
                           000020   236 _savedSP	=	0x0020
                           000024   237 _curThread	=	0x0024
                           000025   238 _mask	=	0x0025
                           000026   239 _newThread	=	0x0026
                           000027   240 _i	=	0x0027
                           000028   241 _tmp	=	0x0028
                           000029   242 _tmp2	=	0x0029
                           00002A   243 _isAlive	=	0x002a
                                    244 ;--------------------------------------------------------
                                    245 ; overlayable items in internal ram 
                                    246 ;--------------------------------------------------------
                                    247 	.area	OSEG    (OVR,DATA)
                                    248 ;--------------------------------------------------------
                                    249 ; indirectly addressable internal ram data
                                    250 ;--------------------------------------------------------
                                    251 	.area ISEG    (DATA)
                                    252 ;--------------------------------------------------------
                                    253 ; absolute internal ram data
                                    254 ;--------------------------------------------------------
                                    255 	.area IABS    (ABS,DATA)
                                    256 	.area IABS    (ABS,DATA)
                                    257 ;--------------------------------------------------------
                                    258 ; bit data
                                    259 ;--------------------------------------------------------
                                    260 	.area BSEG    (BIT)
                                    261 ;--------------------------------------------------------
                                    262 ; paged external ram data
                                    263 ;--------------------------------------------------------
                                    264 	.area PSEG    (PAG,XDATA)
                                    265 ;--------------------------------------------------------
                                    266 ; external ram data
                                    267 ;--------------------------------------------------------
                                    268 	.area XSEG    (XDATA)
                                    269 ;--------------------------------------------------------
                                    270 ; absolute external ram data
                                    271 ;--------------------------------------------------------
                                    272 	.area XABS    (ABS,XDATA)
                                    273 ;--------------------------------------------------------
                                    274 ; external initialized ram data
                                    275 ;--------------------------------------------------------
                                    276 	.area XISEG   (XDATA)
                                    277 	.area HOME    (CODE)
                                    278 	.area GSINIT0 (CODE)
                                    279 	.area GSINIT1 (CODE)
                                    280 	.area GSINIT2 (CODE)
                                    281 	.area GSINIT3 (CODE)
                                    282 	.area GSINIT4 (CODE)
                                    283 	.area GSINIT5 (CODE)
                                    284 	.area GSINIT  (CODE)
                                    285 	.area GSFINAL (CODE)
                                    286 	.area CSEG    (CODE)
                                    287 ;--------------------------------------------------------
                                    288 ; global & static initialisations
                                    289 ;--------------------------------------------------------
                                    290 	.area HOME    (CODE)
                                    291 	.area GSINIT  (CODE)
                                    292 	.area GSFINAL (CODE)
                                    293 	.area GSINIT  (CODE)
                                    294 ;--------------------------------------------------------
                                    295 ; Home
                                    296 ;--------------------------------------------------------
                                    297 	.area HOME    (CODE)
                                    298 	.area HOME    (CODE)
                                    299 ;--------------------------------------------------------
                                    300 ; code
                                    301 ;--------------------------------------------------------
                                    302 	.area CSEG    (CODE)
                                    303 ;------------------------------------------------------------
                                    304 ;Allocation info for local variables in function 'Bootstrap'
                                    305 ;------------------------------------------------------------
                                    306 ;	preemptive.c:84: void Bootstrap(void) {
                                    307 ;	-----------------------------------------
                                    308 ;	 function Bootstrap
                                    309 ;	-----------------------------------------
      00015F                        310 _Bootstrap:
                           000007   311 	ar7 = 0x07
                           000006   312 	ar6 = 0x06
                           000005   313 	ar5 = 0x05
                           000004   314 	ar4 = 0x04
                           000003   315 	ar3 = 0x03
                           000002   316 	ar2 = 0x02
                           000001   317 	ar1 = 0x01
                           000000   318 	ar0 = 0x00
                                    319 ;	preemptive.c:97: TMOD = 0;  // timer 0 mode 0
      00015F 75 89 00         [24]  320 	mov	_TMOD,#0x00
                                    321 ;	preemptive.c:98: IE = 0x82;  // enable timer 0 interrupt; keep consumer polling
      000162 75 A8 82         [24]  322 	mov	_IE,#0x82
                                    323 ;	preemptive.c:100: TR0 = 1; // set bit TR0 to start running timer 0
                                    324 ;	assignBit
      000165 D2 8C            [12]  325 	setb	_TR0
                                    326 ;	preemptive.c:102: mask = 0b0000;
      000167 75 25 00         [24]  327 	mov	_mask,#0x00
                                    328 ;	preemptive.c:103: isAlive[0] = 0b0001; 
      00016A 75 2A 01         [24]  329 	mov	_isAlive,#0x01
                                    330 ;	preemptive.c:104: isAlive[1] = 0b0010; 
      00016D 75 2B 02         [24]  331 	mov	(_isAlive + 0x0001),#0x02
                                    332 ;	preemptive.c:105: isAlive[2] = 0b0100; 
      000170 75 2C 04         [24]  333 	mov	(_isAlive + 0x0002),#0x04
                                    334 ;	preemptive.c:106: isAlive[3] = 0b1000;
      000173 75 2D 08         [24]  335 	mov	(_isAlive + 0x0003),#0x08
                                    336 ;	preemptive.c:107: curThread = ThreadCreate(main);
      000176 90 01 22         [24]  337 	mov	dptr,#_main
      000179 12 01 91         [24]  338 	lcall	_ThreadCreate
      00017C 85 82 24         [24]  339 	mov	_curThread,dpl
                                    340 ;	preemptive.c:108: RESTORESTATE;
      00017F E5 24            [12]  341 	mov	a,_curThread
      000181 24 20            [12]  342 	add	a,#_savedSP
      000183 F9               [12]  343 	mov	r1,a
      000184 87 81            [24]  344 	mov	_SP,@r1
      000186 D0 D0            [24]  345 	pop PSW 
      000188 D0 83            [24]  346 	pop DPH 
      00018A D0 82            [24]  347 	pop DPL 
      00018C D0 F0            [24]  348 	pop B 
      00018E D0 E0            [24]  349 	pop ACC 
                                    350 ;	preemptive.c:109: }
      000190 22               [24]  351 	ret
                                    352 ;------------------------------------------------------------
                                    353 ;Allocation info for local variables in function 'ThreadCreate'
                                    354 ;------------------------------------------------------------
                                    355 ;fp                        Allocated to registers 
                                    356 ;------------------------------------------------------------
                                    357 ;	preemptive.c:117: ThreadID ThreadCreate(FunctionPtr fp) {
                                    358 ;	-----------------------------------------
                                    359 ;	 function ThreadCreate
                                    360 ;	-----------------------------------------
      000191                        361 _ThreadCreate:
                                    362 ;	preemptive.c:123: if(mask == 0b1111) return -1;
      000191 74 0F            [12]  363 	mov	a,#0x0f
      000193 B5 25 04         [24]  364 	cjne	a,_mask,00102$
      000196 75 82 FF         [24]  365 	mov	dpl,#0xff
      000199 22               [24]  366 	ret
      00019A                        367 00102$:
                                    368 ;	preemptive.c:207: }
      00019A 7F 01            [12]  369 	mov	r7,#0x01
      00019C 10 AF 02         [24]  370 	jbc	ea,00129$
      00019F 7F 00            [12]  371 	mov	r7,#0x00
      0001A1                        372 00129$:
                                    373 ;	preemptive.c:169: for(i = 0; i < MAXTHREADS; i++) {
      0001A1 75 27 00         [24]  374 	mov	_i,#0x00
      0001A4                        375 00107$:
      0001A4 74 FC            [12]  376 	mov	a,#0x100 - 0x04
      0001A6 25 27            [12]  377 	add	a,_i
      0001A8 40 44            [24]  378 	jc	00105$
                                    379 ;	preemptive.c:170: if(((mask) & (0b0001 << i)) == 0) {
      0001AA AE 27            [24]  380 	mov	r6,_i
      0001AC 8E F0            [24]  381 	mov	b,r6
      0001AE 05 F0            [12]  382 	inc	b
      0001B0 7E 01            [12]  383 	mov	r6,#0x01
      0001B2 7D 00            [12]  384 	mov	r5,#0x00
      0001B4 80 06            [24]  385 	sjmp	00132$
      0001B6                        386 00131$:
      0001B6 EE               [12]  387 	mov	a,r6
      0001B7 2E               [12]  388 	add	a,r6
      0001B8 FE               [12]  389 	mov	r6,a
      0001B9 ED               [12]  390 	mov	a,r5
      0001BA 33               [12]  391 	rlc	a
      0001BB FD               [12]  392 	mov	r5,a
      0001BC                        393 00132$:
      0001BC D5 F0 F7         [24]  394 	djnz	b,00131$
      0001BF AB 25            [24]  395 	mov	r3,_mask
      0001C1 7C 00            [12]  396 	mov	r4,#0x00
      0001C3 EB               [12]  397 	mov	a,r3
      0001C4 52 06            [12]  398 	anl	ar6,a
      0001C6 EC               [12]  399 	mov	a,r4
      0001C7 52 05            [12]  400 	anl	ar5,a
      0001C9 EE               [12]  401 	mov	a,r6
      0001CA 4D               [12]  402 	orl	a,r5
      0001CB 70 1A            [24]  403 	jnz	00108$
                                    404 ;	preemptive.c:171: mask |= (0b0001 << i);
      0001CD AE 27            [24]  405 	mov	r6,_i
      0001CF 8E F0            [24]  406 	mov	b,r6
      0001D1 05 F0            [12]  407 	inc	b
      0001D3 74 01            [12]  408 	mov	a,#0x01
      0001D5 80 02            [24]  409 	sjmp	00136$
      0001D7                        410 00134$:
      0001D7 25 E0            [12]  411 	add	a,acc
      0001D9                        412 00136$:
      0001D9 D5 F0 FB         [24]  413 	djnz	b,00134$
      0001DC FE               [12]  414 	mov	r6,a
      0001DD AD 25            [24]  415 	mov	r5,_mask
      0001DF 4D               [12]  416 	orl	a,r5
      0001E0 F5 25            [12]  417 	mov	_mask,a
                                    418 ;	preemptive.c:172: newThread = i;
      0001E2 85 27 26         [24]  419 	mov	_newThread,_i
                                    420 ;	preemptive.c:173: break;
      0001E5 80 07            [24]  421 	sjmp	00105$
      0001E7                        422 00108$:
                                    423 ;	preemptive.c:169: for(i = 0; i < MAXTHREADS; i++) {
      0001E7 E5 27            [12]  424 	mov	a,_i
      0001E9 04               [12]  425 	inc	a
      0001EA F5 27            [12]  426 	mov	_i,a
      0001EC 80 B6            [24]  427 	sjmp	00107$
      0001EE                        428 00105$:
                                    429 ;	preemptive.c:178: tmp = SP;
      0001EE 85 81 28         [24]  430 	mov	_tmp,_SP
                                    431 ;	preemptive.c:179: SP = 0x3F + (i << 4);
      0001F1 E5 27            [12]  432 	mov	a,_i
      0001F3 C4               [12]  433 	swap	a
      0001F4 54 F0            [12]  434 	anl	a,#0xf0
      0001F6 FE               [12]  435 	mov	r6,a
      0001F7 24 3F            [12]  436 	add	a,#0x3f
      0001F9 F5 81            [12]  437 	mov	_SP,a
                                    438 ;	preemptive.c:190: __endasm;
      0001FB C0 82            [24]  439 	push	DPL
      0001FD C0 83            [24]  440 	push	DPH
      0001FF 74 00            [12]  441 	mov	A, #0
      000201 C0 E0            [24]  442 	push	A
      000203 C0 E0            [24]  443 	push	A
      000205 C0 E0            [24]  444 	push	A
      000207 C0 E0            [24]  445 	push	A
                                    446 ;	preemptive.c:198: tmp2 = (i << 3);
      000209 E5 27            [12]  447 	mov	a,_i
      00020B FE               [12]  448 	mov	r6,a
      00020C C4               [12]  449 	swap	a
      00020D 03               [12]  450 	rr	a
      00020E 54 F8            [12]  451 	anl	a,#0xf8
      000210 F5 29            [12]  452 	mov	_tmp2,a
                                    453 ;	preemptive.c:202: __endasm;
      000212 C0 29            [24]  454 	push	_tmp2
                                    455 ;	preemptive.c:205: savedSP[newThread] = SP;
      000214 E5 26            [12]  456 	mov	a,_newThread
      000216 24 20            [12]  457 	add	a,#_savedSP
      000218 F8               [12]  458 	mov	r0,a
      000219 A6 81            [24]  459 	mov	@r0,_SP
                                    460 ;	preemptive.c:206: SP = tmp;
      00021B 85 28 81         [24]  461 	mov	_SP,_tmp
      00021E EF               [12]  462 	mov	a,r7
      00021F 13               [12]  463 	rrc	a
      000220 92 AF            [24]  464 	mov	ea,c
                                    465 ;	preemptive.c:208: return newThread;
      000222 85 26 82         [24]  466 	mov	dpl,_newThread
                                    467 ;	preemptive.c:209: }
      000225 22               [24]  468 	ret
                                    469 ;------------------------------------------------------------
                                    470 ;Allocation info for local variables in function 'ThreadYield'
                                    471 ;------------------------------------------------------------
                                    472 ;	preemptive.c:217: void ThreadYield(void) {
                                    473 ;	-----------------------------------------
                                    474 ;	 function ThreadYield
                                    475 ;	-----------------------------------------
      000226                        476 _ThreadYield:
                                    477 ;	preemptive.c:234: }
      000226 7F 01            [12]  478 	mov	r7,#0x01
      000228 10 AF 02         [24]  479 	jbc	ea,00122$
      00022B 7F 00            [12]  480 	mov	r7,#0x00
      00022D                        481 00122$:
                                    482 ;	preemptive.c:219: SAVESTATE;
      00022D C0 E0            [24]  483 	push ACC 
      00022F C0 F0            [24]  484 	push B 
      000231 C0 82            [24]  485 	push DPL 
      000233 C0 83            [24]  486 	push DPH 
      000235 C0 D0            [24]  487 	push PSW 
      000237 E5 24            [12]  488 	mov	a,_curThread
      000239 24 20            [12]  489 	add	a,#_savedSP
      00023B F8               [12]  490 	mov	r0,a
      00023C A6 81            [24]  491 	mov	@r0,_SP
                                    492 ;	preemptive.c:220: do {
      00023E                        493 00103$:
                                    494 ;	preemptive.c:230: curThread = (curThread == MAXTHREADS-1) ? 0 : curThread + 1;
      00023E 74 03            [12]  495 	mov	a,#0x03
      000240 B5 24 06         [24]  496 	cjne	a,_curThread,00108$
      000243 7D 00            [12]  497 	mov	r5,#0x00
      000245 7E 00            [12]  498 	mov	r6,#0x00
      000247 80 09            [24]  499 	sjmp	00109$
      000249                        500 00108$:
      000249 AC 24            [24]  501 	mov	r4,_curThread
      00024B 0C               [12]  502 	inc	r4
      00024C EC               [12]  503 	mov	a,r4
      00024D FD               [12]  504 	mov	r5,a
      00024E 33               [12]  505 	rlc	a
      00024F 95 E0            [12]  506 	subb	a,acc
      000251 FE               [12]  507 	mov	r6,a
      000252                        508 00109$:
      000252 8D 24            [24]  509 	mov	_curThread,r5
                                    510 ;	preemptive.c:231: if(mask & isAlive[curThread]) break;
      000254 E5 24            [12]  511 	mov	a,_curThread
      000256 24 2A            [12]  512 	add	a,#_isAlive
      000258 F9               [12]  513 	mov	r1,a
      000259 E7               [12]  514 	mov	a,@r1
      00025A FE               [12]  515 	mov	r6,a
      00025B 55 25            [12]  516 	anl	a,_mask
      00025D 60 DF            [24]  517 	jz	00103$
                                    518 ;	preemptive.c:233: RESTORESTATE;
      00025F E5 24            [12]  519 	mov	a,_curThread
      000261 24 20            [12]  520 	add	a,#_savedSP
      000263 F9               [12]  521 	mov	r1,a
      000264 87 81            [24]  522 	mov	_SP,@r1
      000266 D0 D0            [24]  523 	pop PSW 
      000268 D0 83            [24]  524 	pop DPH 
      00026A D0 82            [24]  525 	pop DPL 
      00026C D0 F0            [24]  526 	pop B 
      00026E D0 E0            [24]  527 	pop ACC 
      000270 EF               [12]  528 	mov	a,r7
      000271 13               [12]  529 	rrc	a
      000272 92 AF            [24]  530 	mov	ea,c
                                    531 ;	preemptive.c:235: }
      000274 22               [24]  532 	ret
                                    533 ;------------------------------------------------------------
                                    534 ;Allocation info for local variables in function 'ThreadExit'
                                    535 ;------------------------------------------------------------
                                    536 ;	preemptive.c:242: void ThreadExit(void) {
                                    537 ;	-----------------------------------------
                                    538 ;	 function ThreadExit
                                    539 ;	-----------------------------------------
      000275                        540 _ThreadExit:
                                    541 ;	preemptive.c:256: }
      000275 7F 01            [12]  542 	mov	r7,#0x01
      000277 10 AF 02         [24]  543 	jbc	ea,00122$
      00027A 7F 00            [12]  544 	mov	r7,#0x00
      00027C                        545 00122$:
                                    546 ;	preemptive.c:250: mask &= ~(1 << curThread);
      00027C AE 24            [24]  547 	mov	r6,_curThread
      00027E 8E F0            [24]  548 	mov	b,r6
      000280 05 F0            [12]  549 	inc	b
      000282 74 01            [12]  550 	mov	a,#0x01
      000284 80 02            [24]  551 	sjmp	00125$
      000286                        552 00123$:
      000286 25 E0            [12]  553 	add	a,acc
      000288                        554 00125$:
      000288 D5 F0 FB         [24]  555 	djnz	b,00123$
      00028B F4               [12]  556 	cpl	a
      00028C FE               [12]  557 	mov	r6,a
      00028D AD 25            [24]  558 	mov	r5,_mask
      00028F 5D               [12]  559 	anl	a,r5
      000290 F5 25            [12]  560 	mov	_mask,a
                                    561 ;	preemptive.c:251: do {
      000292                        562 00103$:
                                    563 ;	preemptive.c:252: curThread = (curThread == 3) ? 0 : curThread + 1;
      000292 74 03            [12]  564 	mov	a,#0x03
      000294 B5 24 06         [24]  565 	cjne	a,_curThread,00108$
      000297 7D 00            [12]  566 	mov	r5,#0x00
      000299 7E 00            [12]  567 	mov	r6,#0x00
      00029B 80 09            [24]  568 	sjmp	00109$
      00029D                        569 00108$:
      00029D AC 24            [24]  570 	mov	r4,_curThread
      00029F 0C               [12]  571 	inc	r4
      0002A0 EC               [12]  572 	mov	a,r4
      0002A1 FD               [12]  573 	mov	r5,a
      0002A2 33               [12]  574 	rlc	a
      0002A3 95 E0            [12]  575 	subb	a,acc
      0002A5 FE               [12]  576 	mov	r6,a
      0002A6                        577 00109$:
      0002A6 8D 24            [24]  578 	mov	_curThread,r5
                                    579 ;	preemptive.c:253: if(mask & (1 << curThread)) break;
      0002A8 AE 24            [24]  580 	mov	r6,_curThread
      0002AA 8E F0            [24]  581 	mov	b,r6
      0002AC 05 F0            [12]  582 	inc	b
      0002AE 7E 01            [12]  583 	mov	r6,#0x01
      0002B0 7D 00            [12]  584 	mov	r5,#0x00
      0002B2 80 06            [24]  585 	sjmp	00129$
      0002B4                        586 00128$:
      0002B4 EE               [12]  587 	mov	a,r6
      0002B5 2E               [12]  588 	add	a,r6
      0002B6 FE               [12]  589 	mov	r6,a
      0002B7 ED               [12]  590 	mov	a,r5
      0002B8 33               [12]  591 	rlc	a
      0002B9 FD               [12]  592 	mov	r5,a
      0002BA                        593 00129$:
      0002BA D5 F0 F7         [24]  594 	djnz	b,00128$
      0002BD AB 25            [24]  595 	mov	r3,_mask
      0002BF 7C 00            [12]  596 	mov	r4,#0x00
      0002C1 EB               [12]  597 	mov	a,r3
      0002C2 52 06            [12]  598 	anl	ar6,a
      0002C4 EC               [12]  599 	mov	a,r4
      0002C5 52 05            [12]  600 	anl	ar5,a
      0002C7 EE               [12]  601 	mov	a,r6
      0002C8 4D               [12]  602 	orl	a,r5
      0002C9 60 C7            [24]  603 	jz	00103$
                                    604 ;	preemptive.c:255: RESTORESTATE;
      0002CB E5 24            [12]  605 	mov	a,_curThread
      0002CD 24 20            [12]  606 	add	a,#_savedSP
      0002CF F9               [12]  607 	mov	r1,a
      0002D0 87 81            [24]  608 	mov	_SP,@r1
      0002D2 D0 D0            [24]  609 	pop PSW 
      0002D4 D0 83            [24]  610 	pop DPH 
      0002D6 D0 82            [24]  611 	pop DPL 
      0002D8 D0 F0            [24]  612 	pop B 
      0002DA D0 E0            [24]  613 	pop ACC 
      0002DC EF               [12]  614 	mov	a,r7
      0002DD 13               [12]  615 	rrc	a
      0002DE 92 AF            [24]  616 	mov	ea,c
                                    617 ;	preemptive.c:257: }
      0002E0 22               [24]  618 	ret
                                    619 ;------------------------------------------------------------
                                    620 ;Allocation info for local variables in function 'myTimer0Handler'
                                    621 ;------------------------------------------------------------
                                    622 ;	preemptive.c:259: void myTimer0Handler(){
                                    623 ;	-----------------------------------------
                                    624 ;	 function myTimer0Handler
                                    625 ;	-----------------------------------------
      0002E1                        626 _myTimer0Handler:
                                    627 ;	preemptive.c:262: SAVESTATE;
      0002E1 C0 E0            [24]  628 	push ACC 
      0002E3 C0 F0            [24]  629 	push B 
      0002E5 C0 82            [24]  630 	push DPL 
      0002E7 C0 83            [24]  631 	push DPH 
      0002E9 C0 D0            [24]  632 	push PSW 
      0002EB E5 24            [12]  633 	mov	a,_curThread
      0002ED 24 20            [12]  634 	add	a,#_savedSP
      0002EF F8               [12]  635 	mov	r0,a
      0002F0 A6 81            [24]  636 	mov	@r0,_SP
                                    637 ;	preemptive.c:274: __endasm;
      0002F2 89 E0            [24]  638 	mov	ACC, r1
      0002F4 8A F0            [24]  639 	mov	B, r2
      0002F6 8B 82            [24]  640 	mov	DPL, r3
      0002F8 8C 83            [24]  641 	mov	DPH, r4
      0002FA 8D D0            [24]  642 	mov	PSW, r5
      0002FC 8E 28            [24]  643 	mov	_tmp, r6
      0002FE 8F 29            [24]  644 	mov	_tmp2, r7
                                    645 ;	preemptive.c:275: do {
      000300                        646 00103$:
                                    647 ;	preemptive.c:285: curThread = (curThread == MAXTHREADS - 1) ? 0 : curThread + 1;
      000300 74 03            [12]  648 	mov	a,#0x03
      000302 B5 24 06         [24]  649 	cjne	a,_curThread,00108$
      000305 7E 00            [12]  650 	mov	r6,#0x00
      000307 7F 00            [12]  651 	mov	r7,#0x00
      000309 80 09            [24]  652 	sjmp	00109$
      00030B                        653 00108$:
      00030B AD 24            [24]  654 	mov	r5,_curThread
      00030D 0D               [12]  655 	inc	r5
      00030E ED               [12]  656 	mov	a,r5
      00030F FE               [12]  657 	mov	r6,a
      000310 33               [12]  658 	rlc	a
      000311 95 E0            [12]  659 	subb	a,acc
      000313 FF               [12]  660 	mov	r7,a
      000314                        661 00109$:
      000314 8E 24            [24]  662 	mov	_curThread,r6
                                    663 ;	preemptive.c:286: if(mask & isAlive[curThread]) break;
      000316 E5 24            [12]  664 	mov	a,_curThread
      000318 24 2A            [12]  665 	add	a,#_isAlive
      00031A F9               [12]  666 	mov	r1,a
      00031B E7               [12]  667 	mov	a,@r1
      00031C FF               [12]  668 	mov	r7,a
      00031D 55 25            [12]  669 	anl	a,_mask
      00031F 60 DF            [24]  670 	jz	00103$
                                    671 ;	preemptive.c:298: __endasm;
      000321 A9 E0            [24]  672 	mov	r1, ACC
      000323 AA F0            [24]  673 	mov	r2, B
      000325 AB 82            [24]  674 	mov	r3, DPL
      000327 AC 83            [24]  675 	mov	r4, DPH
      000329 AD D0            [24]  676 	mov	r5, PSW
      00032B AE 28            [24]  677 	mov	r6, _tmp
      00032D AF 29            [24]  678 	mov	r7, _tmp2
                                    679 ;	preemptive.c:299: RESTORESTATE;
      00032F E5 24            [12]  680 	mov	a,_curThread
      000331 24 20            [12]  681 	add	a,#_savedSP
      000333 F9               [12]  682 	mov	r1,a
      000334 87 81            [24]  683 	mov	_SP,@r1
      000336 D0 D0            [24]  684 	pop PSW 
      000338 D0 83            [24]  685 	pop DPH 
      00033A D0 82            [24]  686 	pop DPL 
      00033C D0 F0            [24]  687 	pop B 
      00033E D0 E0            [24]  688 	pop ACC 
                                    689 ;	preemptive.c:302: __endasm;
      000340 32               [24]  690 	reti
                                    691 ;	preemptive.c:303: }
      000341 22               [24]  692 	ret
                                    693 	.area CSEG    (CODE)
                                    694 	.area CONST   (CODE)
                                    695 	.area XINIT   (CODE)
                                    696 	.area CABS    (ABS,CODE)
