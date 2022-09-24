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
                                     11 	.globl _Bootstrap
                                     12 	.globl _main
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _delayID
                                    110 	.globl _time
                                    111 	.globl _count
                                    112 	.globl _isAlive
                                    113 	.globl _tmp2
                                    114 	.globl _tmp
                                    115 	.globl _i
                                    116 	.globl _newThread
                                    117 	.globl _mask
                                    118 	.globl _curThread
                                    119 	.globl _savedSP
                                    120 	.globl _ThreadCreate
                                    121 	.globl _ThreadYield
                                    122 	.globl _ThreadExit
                                    123 	.globl _myTimer0Handler
                                    124 	.globl _delay
                                    125 	.globl _now
                                    126 ;--------------------------------------------------------
                                    127 ; special function registers
                                    128 ;--------------------------------------------------------
                                    129 	.area RSEG    (ABS,DATA)
      000000                        130 	.org 0x0000
                           000080   131 _P0	=	0x0080
                           000081   132 _SP	=	0x0081
                           000082   133 _DPL	=	0x0082
                           000083   134 _DPH	=	0x0083
                           000087   135 _PCON	=	0x0087
                           000088   136 _TCON	=	0x0088
                           000089   137 _TMOD	=	0x0089
                           00008A   138 _TL0	=	0x008a
                           00008B   139 _TL1	=	0x008b
                           00008C   140 _TH0	=	0x008c
                           00008D   141 _TH1	=	0x008d
                           000090   142 _P1	=	0x0090
                           000098   143 _SCON	=	0x0098
                           000099   144 _SBUF	=	0x0099
                           0000A0   145 _P2	=	0x00a0
                           0000A8   146 _IE	=	0x00a8
                           0000B0   147 _P3	=	0x00b0
                           0000B8   148 _IP	=	0x00b8
                           0000D0   149 _PSW	=	0x00d0
                           0000E0   150 _ACC	=	0x00e0
                           0000F0   151 _B	=	0x00f0
                                    152 ;--------------------------------------------------------
                                    153 ; special function bits
                                    154 ;--------------------------------------------------------
                                    155 	.area RSEG    (ABS,DATA)
      000000                        156 	.org 0x0000
                           000080   157 _P0_0	=	0x0080
                           000081   158 _P0_1	=	0x0081
                           000082   159 _P0_2	=	0x0082
                           000083   160 _P0_3	=	0x0083
                           000084   161 _P0_4	=	0x0084
                           000085   162 _P0_5	=	0x0085
                           000086   163 _P0_6	=	0x0086
                           000087   164 _P0_7	=	0x0087
                           000088   165 _IT0	=	0x0088
                           000089   166 _IE0	=	0x0089
                           00008A   167 _IT1	=	0x008a
                           00008B   168 _IE1	=	0x008b
                           00008C   169 _TR0	=	0x008c
                           00008D   170 _TF0	=	0x008d
                           00008E   171 _TR1	=	0x008e
                           00008F   172 _TF1	=	0x008f
                           000090   173 _P1_0	=	0x0090
                           000091   174 _P1_1	=	0x0091
                           000092   175 _P1_2	=	0x0092
                           000093   176 _P1_3	=	0x0093
                           000094   177 _P1_4	=	0x0094
                           000095   178 _P1_5	=	0x0095
                           000096   179 _P1_6	=	0x0096
                           000097   180 _P1_7	=	0x0097
                           000098   181 _RI	=	0x0098
                           000099   182 _TI	=	0x0099
                           00009A   183 _RB8	=	0x009a
                           00009B   184 _TB8	=	0x009b
                           00009C   185 _REN	=	0x009c
                           00009D   186 _SM2	=	0x009d
                           00009E   187 _SM1	=	0x009e
                           00009F   188 _SM0	=	0x009f
                           0000A0   189 _P2_0	=	0x00a0
                           0000A1   190 _P2_1	=	0x00a1
                           0000A2   191 _P2_2	=	0x00a2
                           0000A3   192 _P2_3	=	0x00a3
                           0000A4   193 _P2_4	=	0x00a4
                           0000A5   194 _P2_5	=	0x00a5
                           0000A6   195 _P2_6	=	0x00a6
                           0000A7   196 _P2_7	=	0x00a7
                           0000A8   197 _EX0	=	0x00a8
                           0000A9   198 _ET0	=	0x00a9
                           0000AA   199 _EX1	=	0x00aa
                           0000AB   200 _ET1	=	0x00ab
                           0000AC   201 _ES	=	0x00ac
                           0000AF   202 _EA	=	0x00af
                           0000B0   203 _P3_0	=	0x00b0
                           0000B1   204 _P3_1	=	0x00b1
                           0000B2   205 _P3_2	=	0x00b2
                           0000B3   206 _P3_3	=	0x00b3
                           0000B4   207 _P3_4	=	0x00b4
                           0000B5   208 _P3_5	=	0x00b5
                           0000B6   209 _P3_6	=	0x00b6
                           0000B7   210 _P3_7	=	0x00b7
                           0000B0   211 _RXD	=	0x00b0
                           0000B1   212 _TXD	=	0x00b1
                           0000B2   213 _INT0	=	0x00b2
                           0000B3   214 _INT1	=	0x00b3
                           0000B4   215 _T0	=	0x00b4
                           0000B5   216 _T1	=	0x00b5
                           0000B6   217 _WR	=	0x00b6
                           0000B7   218 _RD	=	0x00b7
                           0000B8   219 _PX0	=	0x00b8
                           0000B9   220 _PT0	=	0x00b9
                           0000BA   221 _PX1	=	0x00ba
                           0000BB   222 _PT1	=	0x00bb
                           0000BC   223 _PS	=	0x00bc
                           0000D0   224 _P	=	0x00d0
                           0000D1   225 _F1	=	0x00d1
                           0000D2   226 _OV	=	0x00d2
                           0000D3   227 _RS0	=	0x00d3
                           0000D4   228 _RS1	=	0x00d4
                           0000D5   229 _F0	=	0x00d5
                           0000D6   230 _AC	=	0x00d6
                           0000D7   231 _CY	=	0x00d7
                                    232 ;--------------------------------------------------------
                                    233 ; overlayable register banks
                                    234 ;--------------------------------------------------------
                                    235 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        236 	.ds 8
                                    237 ;--------------------------------------------------------
                                    238 ; internal ram data
                                    239 ;--------------------------------------------------------
                                    240 	.area DSEG    (DATA)
                           000020   241 _savedSP	=	0x0020
                           000024   242 _curThread	=	0x0024
                           000025   243 _mask	=	0x0025
                           000026   244 _newThread	=	0x0026
                           000027   245 _i	=	0x0027
                           000028   246 _tmp	=	0x0028
                           000029   247 _tmp2	=	0x0029
                           00002A   248 _isAlive	=	0x002a
                           00002E   249 _count	=	0x002e
                           00002F   250 _time	=	0x002f
                           000039   251 _delayID	=	0x0039
                                    252 ;--------------------------------------------------------
                                    253 ; overlayable items in internal ram 
                                    254 ;--------------------------------------------------------
                                    255 	.area	OSEG    (OVR,DATA)
                                    256 	.area	OSEG    (OVR,DATA)
                                    257 ;--------------------------------------------------------
                                    258 ; indirectly addressable internal ram data
                                    259 ;--------------------------------------------------------
                                    260 	.area ISEG    (DATA)
                                    261 ;--------------------------------------------------------
                                    262 ; absolute internal ram data
                                    263 ;--------------------------------------------------------
                                    264 	.area IABS    (ABS,DATA)
                                    265 	.area IABS    (ABS,DATA)
                                    266 ;--------------------------------------------------------
                                    267 ; bit data
                                    268 ;--------------------------------------------------------
                                    269 	.area BSEG    (BIT)
                                    270 ;--------------------------------------------------------
                                    271 ; paged external ram data
                                    272 ;--------------------------------------------------------
                                    273 	.area PSEG    (PAG,XDATA)
                                    274 ;--------------------------------------------------------
                                    275 ; external ram data
                                    276 ;--------------------------------------------------------
                                    277 	.area XSEG    (XDATA)
                                    278 ;--------------------------------------------------------
                                    279 ; absolute external ram data
                                    280 ;--------------------------------------------------------
                                    281 	.area XABS    (ABS,XDATA)
                                    282 ;--------------------------------------------------------
                                    283 ; external initialized ram data
                                    284 ;--------------------------------------------------------
                                    285 	.area XISEG   (XDATA)
                                    286 	.area HOME    (CODE)
                                    287 	.area GSINIT0 (CODE)
                                    288 	.area GSINIT1 (CODE)
                                    289 	.area GSINIT2 (CODE)
                                    290 	.area GSINIT3 (CODE)
                                    291 	.area GSINIT4 (CODE)
                                    292 	.area GSINIT5 (CODE)
                                    293 	.area GSINIT  (CODE)
                                    294 	.area GSFINAL (CODE)
                                    295 	.area CSEG    (CODE)
                                    296 ;--------------------------------------------------------
                                    297 ; global & static initialisations
                                    298 ;--------------------------------------------------------
                                    299 	.area HOME    (CODE)
                                    300 	.area GSINIT  (CODE)
                                    301 	.area GSFINAL (CODE)
                                    302 	.area GSINIT  (CODE)
                                    303 ;--------------------------------------------------------
                                    304 ; Home
                                    305 ;--------------------------------------------------------
                                    306 	.area HOME    (CODE)
                                    307 	.area HOME    (CODE)
                                    308 ;--------------------------------------------------------
                                    309 ; code
                                    310 ;--------------------------------------------------------
                                    311 	.area CSEG    (CODE)
                                    312 ;------------------------------------------------------------
                                    313 ;Allocation info for local variables in function 'Bootstrap'
                                    314 ;------------------------------------------------------------
                                    315 ;	preemptive.c:71: void Bootstrap(void) {
                                    316 ;	-----------------------------------------
                                    317 ;	 function Bootstrap
                                    318 ;	-----------------------------------------
      000407                        319 _Bootstrap:
                           000007   320 	ar7 = 0x07
                           000006   321 	ar6 = 0x06
                           000005   322 	ar5 = 0x05
                           000004   323 	ar4 = 0x04
                           000003   324 	ar3 = 0x03
                           000002   325 	ar2 = 0x02
                           000001   326 	ar1 = 0x01
                           000000   327 	ar0 = 0x00
                                    328 ;	preemptive.c:73: count = 0;
      000407 75 2E 00         [24]  329 	mov	_count,#0x00
                                    330 ;	preemptive.c:74: time = 0;
      00040A 75 2F 00         [24]  331 	mov	_time,#0x00
                                    332 ;	preemptive.c:76: mask = 0b0000;
      00040D 75 25 00         [24]  333 	mov	_mask,#0x00
                                    334 ;	preemptive.c:77: TMOD = 0;  // timer 0 mode 0
      000410 75 89 00         [24]  335 	mov	_TMOD,#0x00
                                    336 ;	preemptive.c:78: IE = 0x82;  // enable timer 0 interrupt; keep consumer polling
      000413 75 A8 82         [24]  337 	mov	_IE,#0x82
                                    338 ;	preemptive.c:80: TR0 = 1; // set bit TR0 to start running timer 0
                                    339 ;	assignBit
      000416 D2 8C            [12]  340 	setb	_TR0
                                    341 ;	preemptive.c:82: isAlive[0] = 0b0001; 
      000418 75 2A 01         [24]  342 	mov	_isAlive,#0x01
                                    343 ;	preemptive.c:83: isAlive[1] = 0b0010; 
      00041B 75 2B 02         [24]  344 	mov	(_isAlive + 0x0001),#0x02
                                    345 ;	preemptive.c:84: isAlive[2] = 0b0100; 
      00041E 75 2C 04         [24]  346 	mov	(_isAlive + 0x0002),#0x04
                                    347 ;	preemptive.c:85: isAlive[3] = 0b1000;
      000421 75 2D 08         [24]  348 	mov	(_isAlive + 0x0003),#0x08
                                    349 ;	preemptive.c:87: delayID[0] = 0;
      000424 75 39 00         [24]  350 	mov	_delayID,#0x00
                                    351 ;	preemptive.c:88: delayID[1] = 0;
      000427 75 3A 00         [24]  352 	mov	(_delayID + 0x0001),#0x00
                                    353 ;	preemptive.c:89: delayID[2] = 0;
      00042A 75 3B 00         [24]  354 	mov	(_delayID + 0x0002),#0x00
                                    355 ;	preemptive.c:90: delayID[3] = 0;
      00042D 75 3C 00         [24]  356 	mov	(_delayID + 0x0003),#0x00
                                    357 ;	preemptive.c:92: curThread = ThreadCreate(main);
      000430 90 03 84         [24]  358 	mov	dptr,#_main
      000433 12 04 4B         [24]  359 	lcall	_ThreadCreate
      000436 85 82 24         [24]  360 	mov	_curThread,dpl
                                    361 ;	preemptive.c:93: RESTORESTATE;
      000439 E5 24            [12]  362 	mov	a,_curThread
      00043B 24 20            [12]  363 	add	a,#_savedSP
      00043D F9               [12]  364 	mov	r1,a
      00043E 87 81            [24]  365 	mov	_SP,@r1
      000440 D0 D0            [24]  366 	pop PSW 
      000442 D0 83            [24]  367 	pop DPH 
      000444 D0 82            [24]  368 	pop DPL 
      000446 D0 F0            [24]  369 	pop B 
      000448 D0 E0            [24]  370 	pop ACC 
                                    371 ;	preemptive.c:94: }
      00044A 22               [24]  372 	ret
                                    373 ;------------------------------------------------------------
                                    374 ;Allocation info for local variables in function 'ThreadCreate'
                                    375 ;------------------------------------------------------------
                                    376 ;fp                        Allocated to registers 
                                    377 ;------------------------------------------------------------
                                    378 ;	preemptive.c:102: ThreadID ThreadCreate(FunctionPtr fp) {
                                    379 ;	-----------------------------------------
                                    380 ;	 function ThreadCreate
                                    381 ;	-----------------------------------------
      00044B                        382 _ThreadCreate:
                                    383 ;	preemptive.c:103: if(mask == 0b1111) return -1;	// mask = 15, four thread
      00044B 74 0F            [12]  384 	mov	a,#0x0f
      00044D B5 25 04         [24]  385 	cjne	a,_mask,00102$
      000450 75 82 FF         [24]  386 	mov	dpl,#0xff
      000453 22               [24]  387 	ret
      000454                        388 00102$:
                                    389 ;	preemptive.c:104: EA = 0;
                                    390 ;	assignBit
      000454 C2 AF            [12]  391 	clr	_EA
                                    392 ;	preemptive.c:105: for(i = 0; i < MAXTHREADS; i++) {
      000456 75 27 00         [24]  393 	mov	_i,#0x00
      000459                        394 00107$:
      000459 74 FC            [12]  395 	mov	a,#0x100 - 0x04
      00045B 25 27            [12]  396 	add	a,_i
      00045D 40 44            [24]  397 	jc	00105$
                                    398 ;	preemptive.c:106: if(((mask) & (0b0001 << i)) == 0) {
      00045F AF 27            [24]  399 	mov	r7,_i
      000461 8F F0            [24]  400 	mov	b,r7
      000463 05 F0            [12]  401 	inc	b
      000465 7F 01            [12]  402 	mov	r7,#0x01
      000467 7E 00            [12]  403 	mov	r6,#0x00
      000469 80 06            [24]  404 	sjmp	00131$
      00046B                        405 00130$:
      00046B EF               [12]  406 	mov	a,r7
      00046C 2F               [12]  407 	add	a,r7
      00046D FF               [12]  408 	mov	r7,a
      00046E EE               [12]  409 	mov	a,r6
      00046F 33               [12]  410 	rlc	a
      000470 FE               [12]  411 	mov	r6,a
      000471                        412 00131$:
      000471 D5 F0 F7         [24]  413 	djnz	b,00130$
      000474 AC 25            [24]  414 	mov	r4,_mask
      000476 7D 00            [12]  415 	mov	r5,#0x00
      000478 EC               [12]  416 	mov	a,r4
      000479 52 07            [12]  417 	anl	ar7,a
      00047B ED               [12]  418 	mov	a,r5
      00047C 52 06            [12]  419 	anl	ar6,a
      00047E EF               [12]  420 	mov	a,r7
      00047F 4E               [12]  421 	orl	a,r6
      000480 70 1A            [24]  422 	jnz	00108$
                                    423 ;	preemptive.c:107: mask |= (0b0001 << i);
      000482 AF 27            [24]  424 	mov	r7,_i
      000484 8F F0            [24]  425 	mov	b,r7
      000486 05 F0            [12]  426 	inc	b
      000488 74 01            [12]  427 	mov	a,#0x01
      00048A 80 02            [24]  428 	sjmp	00135$
      00048C                        429 00133$:
      00048C 25 E0            [12]  430 	add	a,acc
      00048E                        431 00135$:
      00048E D5 F0 FB         [24]  432 	djnz	b,00133$
      000491 FF               [12]  433 	mov	r7,a
      000492 AE 25            [24]  434 	mov	r6,_mask
      000494 4E               [12]  435 	orl	a,r6
      000495 F5 25            [12]  436 	mov	_mask,a
                                    437 ;	preemptive.c:108: newThread = i;
      000497 85 27 26         [24]  438 	mov	_newThread,_i
                                    439 ;	preemptive.c:109: break;
      00049A 80 07            [24]  440 	sjmp	00105$
      00049C                        441 00108$:
                                    442 ;	preemptive.c:105: for(i = 0; i < MAXTHREADS; i++) {
      00049C E5 27            [12]  443 	mov	a,_i
      00049E 04               [12]  444 	inc	a
      00049F F5 27            [12]  445 	mov	_i,a
      0004A1 80 B6            [24]  446 	sjmp	00107$
      0004A3                        447 00105$:
                                    448 ;	preemptive.c:113: tmp = SP;
      0004A3 85 81 28         [24]  449 	mov	_tmp,_SP
                                    450 ;	preemptive.c:114: SP = 0x3F + (i << 4);
      0004A6 E5 27            [12]  451 	mov	a,_i
      0004A8 C4               [12]  452 	swap	a
      0004A9 54 F0            [12]  453 	anl	a,#0xf0
      0004AB FF               [12]  454 	mov	r7,a
      0004AC 24 3F            [12]  455 	add	a,#0x3f
      0004AE F5 81            [12]  456 	mov	_SP,a
                                    457 ;	preemptive.c:124: __endasm;
      0004B0 C0 82            [24]  458 	push	DPL
      0004B2 C0 83            [24]  459 	push	DPH
      0004B4 74 00            [12]  460 	mov	A, #0
      0004B6 C0 E0            [24]  461 	push	A
      0004B8 C0 E0            [24]  462 	push	A
      0004BA C0 E0            [24]  463 	push	A
      0004BC C0 E0            [24]  464 	push	A
                                    465 ;	preemptive.c:130: tmp2 = (i << 3);
      0004BE E5 27            [12]  466 	mov	a,_i
      0004C0 FF               [12]  467 	mov	r7,a
      0004C1 C4               [12]  468 	swap	a
      0004C2 03               [12]  469 	rr	a
      0004C3 54 F8            [12]  470 	anl	a,#0xf8
      0004C5 F5 29            [12]  471 	mov	_tmp2,a
                                    472 ;	preemptive.c:134: __endasm;
      0004C7 C0 29            [24]  473 	push	_tmp2
                                    474 ;	preemptive.c:136: savedSP[newThread] = SP;
      0004C9 E5 26            [12]  475 	mov	a,_newThread
      0004CB 24 20            [12]  476 	add	a,#_savedSP
      0004CD F8               [12]  477 	mov	r0,a
      0004CE A6 81            [24]  478 	mov	@r0,_SP
                                    479 ;	preemptive.c:137: SP = tmp;
      0004D0 85 28 81         [24]  480 	mov	_SP,_tmp
                                    481 ;	preemptive.c:138: EA = 1;
                                    482 ;	assignBit
      0004D3 D2 AF            [12]  483 	setb	_EA
                                    484 ;	preemptive.c:139: return newThread;
      0004D5 85 26 82         [24]  485 	mov	dpl,_newThread
                                    486 ;	preemptive.c:140: }
      0004D8 22               [24]  487 	ret
                                    488 ;------------------------------------------------------------
                                    489 ;Allocation info for local variables in function 'ThreadYield'
                                    490 ;------------------------------------------------------------
                                    491 ;	preemptive.c:148: void ThreadYield(void) {
                                    492 ;	-----------------------------------------
                                    493 ;	 function ThreadYield
                                    494 ;	-----------------------------------------
      0004D9                        495 _ThreadYield:
                                    496 ;	preemptive.c:165: }
      0004D9 7F 01            [12]  497 	mov	r7,#0x01
      0004DB 10 AF 02         [24]  498 	jbc	ea,00122$
      0004DE 7F 00            [12]  499 	mov	r7,#0x00
      0004E0                        500 00122$:
                                    501 ;	preemptive.c:150: SAVESTATE;
      0004E0 C0 E0            [24]  502 	push ACC 
      0004E2 C0 F0            [24]  503 	push B 
      0004E4 C0 82            [24]  504 	push DPL 
      0004E6 C0 83            [24]  505 	push DPH 
      0004E8 C0 D0            [24]  506 	push PSW 
      0004EA E5 24            [12]  507 	mov	a,_curThread
      0004EC 24 20            [12]  508 	add	a,#_savedSP
      0004EE F8               [12]  509 	mov	r0,a
      0004EF A6 81            [24]  510 	mov	@r0,_SP
                                    511 ;	preemptive.c:151: do {
      0004F1                        512 00103$:
                                    513 ;	preemptive.c:161: curThread = (curThread == MAXTHREADS-1) ? 0 : curThread + 1;
      0004F1 74 03            [12]  514 	mov	a,#0x03
      0004F3 B5 24 06         [24]  515 	cjne	a,_curThread,00108$
      0004F6 7D 00            [12]  516 	mov	r5,#0x00
      0004F8 7E 00            [12]  517 	mov	r6,#0x00
      0004FA 80 09            [24]  518 	sjmp	00109$
      0004FC                        519 00108$:
      0004FC AC 24            [24]  520 	mov	r4,_curThread
      0004FE 0C               [12]  521 	inc	r4
      0004FF EC               [12]  522 	mov	a,r4
      000500 FD               [12]  523 	mov	r5,a
      000501 33               [12]  524 	rlc	a
      000502 95 E0            [12]  525 	subb	a,acc
      000504 FE               [12]  526 	mov	r6,a
      000505                        527 00109$:
      000505 8D 24            [24]  528 	mov	_curThread,r5
                                    529 ;	preemptive.c:162: if(mask & isAlive[curThread]) break;
      000507 E5 24            [12]  530 	mov	a,_curThread
      000509 24 2A            [12]  531 	add	a,#_isAlive
      00050B F9               [12]  532 	mov	r1,a
      00050C E7               [12]  533 	mov	a,@r1
      00050D FE               [12]  534 	mov	r6,a
      00050E 55 25            [12]  535 	anl	a,_mask
      000510 60 DF            [24]  536 	jz	00103$
                                    537 ;	preemptive.c:164: RESTORESTATE;
      000512 E5 24            [12]  538 	mov	a,_curThread
      000514 24 20            [12]  539 	add	a,#_savedSP
      000516 F9               [12]  540 	mov	r1,a
      000517 87 81            [24]  541 	mov	_SP,@r1
      000519 D0 D0            [24]  542 	pop PSW 
      00051B D0 83            [24]  543 	pop DPH 
      00051D D0 82            [24]  544 	pop DPL 
      00051F D0 F0            [24]  545 	pop B 
      000521 D0 E0            [24]  546 	pop ACC 
      000523 EF               [12]  547 	mov	a,r7
      000524 13               [12]  548 	rrc	a
      000525 92 AF            [24]  549 	mov	ea,c
                                    550 ;	preemptive.c:166: }
      000527 22               [24]  551 	ret
                                    552 ;------------------------------------------------------------
                                    553 ;Allocation info for local variables in function 'ThreadExit'
                                    554 ;------------------------------------------------------------
                                    555 ;	preemptive.c:173: void ThreadExit(void) {
                                    556 ;	-----------------------------------------
                                    557 ;	 function ThreadExit
                                    558 ;	-----------------------------------------
      000528                        559 _ThreadExit:
                                    560 ;	preemptive.c:180: EA = 0;
                                    561 ;	assignBit
      000528 C2 AF            [12]  562 	clr	_EA
                                    563 ;	preemptive.c:192: __endasm; 
      00052A 74 00            [12]  564 	mov	A, #0
      00052C C0 E0            [24]  565 	push	A
      00052E C0 E0            [24]  566 	push	A
      000530 C0 E0            [24]  567 	push	A
      000532 C0 E0            [24]  568 	push	A
      000534 C0 E0            [24]  569 	push	A
      000536 C0 E0            [24]  570 	push	A
      000538 C0 E0            [24]  571 	push	A
      00053A C0 E0            [24]  572 	push	A
                                    573 ;	preemptive.c:193: savedSP[curThread] = 0;
      00053C E5 24            [12]  574 	mov	a,_curThread
      00053E 24 20            [12]  575 	add	a,#_savedSP
      000540 F8               [12]  576 	mov	r0,a
      000541 76 00            [12]  577 	mov	@r0,#0x00
                                    578 ;	preemptive.c:195: mask &= ~(1 << curThread);
      000543 AF 24            [24]  579 	mov	r7,_curThread
      000545 8F F0            [24]  580 	mov	b,r7
      000547 05 F0            [12]  581 	inc	b
      000549 74 01            [12]  582 	mov	a,#0x01
      00054B 80 02            [24]  583 	sjmp	00133$
      00054D                        584 00131$:
      00054D 25 E0            [12]  585 	add	a,acc
      00054F                        586 00133$:
      00054F D5 F0 FB         [24]  587 	djnz	b,00131$
      000552 F4               [12]  588 	cpl	a
      000553 FF               [12]  589 	mov	r7,a
      000554 AE 25            [24]  590 	mov	r6,_mask
      000556 5E               [12]  591 	anl	a,r6
      000557 F5 25            [12]  592 	mov	_mask,a
                                    593 ;	preemptive.c:196: if(mask == 0){
      000559 E5 25            [12]  594 	mov	a,_mask
      00055B 70 02            [24]  595 	jnz	00108$
                                    596 ;	preemptive.c:197: while(1){};
      00055D                        597 00102$:
                                    598 ;	preemptive.c:199: do {
      00055D 80 FE            [24]  599 	sjmp	00102$
      00055F                        600 00108$:
                                    601 ;	preemptive.c:200: curThread = (curThread == 3) ? 0 : curThread + 1;
      00055F 74 03            [12]  602 	mov	a,#0x03
      000561 B5 24 06         [24]  603 	cjne	a,_curThread,00113$
      000564 7E 00            [12]  604 	mov	r6,#0x00
      000566 7F 00            [12]  605 	mov	r7,#0x00
      000568 80 09            [24]  606 	sjmp	00114$
      00056A                        607 00113$:
      00056A AD 24            [24]  608 	mov	r5,_curThread
      00056C 0D               [12]  609 	inc	r5
      00056D ED               [12]  610 	mov	a,r5
      00056E FE               [12]  611 	mov	r6,a
      00056F 33               [12]  612 	rlc	a
      000570 95 E0            [12]  613 	subb	a,acc
      000572 FF               [12]  614 	mov	r7,a
      000573                        615 00114$:
      000573 8E 24            [24]  616 	mov	_curThread,r6
                                    617 ;	preemptive.c:201: if(mask & isAlive[curThread]) break;
      000575 E5 24            [12]  618 	mov	a,_curThread
      000577 24 2A            [12]  619 	add	a,#_isAlive
      000579 F9               [12]  620 	mov	r1,a
      00057A E7               [12]  621 	mov	a,@r1
      00057B FF               [12]  622 	mov	r7,a
      00057C 55 25            [12]  623 	anl	a,_mask
      00057E 60 DF            [24]  624 	jz	00108$
                                    625 ;	preemptive.c:203: RESTORESTATE;
      000580 E5 24            [12]  626 	mov	a,_curThread
      000582 24 20            [12]  627 	add	a,#_savedSP
      000584 F9               [12]  628 	mov	r1,a
      000585 87 81            [24]  629 	mov	_SP,@r1
      000587 D0 D0            [24]  630 	pop PSW 
      000589 D0 83            [24]  631 	pop DPH 
      00058B D0 82            [24]  632 	pop DPL 
      00058D D0 F0            [24]  633 	pop B 
      00058F D0 E0            [24]  634 	pop ACC 
                                    635 ;	preemptive.c:205: EA = 1;
                                    636 ;	assignBit
      000591 D2 AF            [12]  637 	setb	_EA
                                    638 ;	preemptive.c:206: }
      000593 22               [24]  639 	ret
                                    640 ;------------------------------------------------------------
                                    641 ;Allocation info for local variables in function 'myTimer0Handler'
                                    642 ;------------------------------------------------------------
                                    643 ;	preemptive.c:208: void myTimer0Handler(){
                                    644 ;	-----------------------------------------
                                    645 ;	 function myTimer0Handler
                                    646 ;	-----------------------------------------
      000594                        647 _myTimer0Handler:
                                    648 ;	preemptive.c:209: EA = 0;
                                    649 ;	assignBit
      000594 C2 AF            [12]  650 	clr	_EA
                                    651 ;	preemptive.c:211: SAVESTATE;
      000596 C0 E0            [24]  652 	push ACC 
      000598 C0 F0            [24]  653 	push B 
      00059A C0 82            [24]  654 	push DPL 
      00059C C0 83            [24]  655 	push DPH 
      00059E C0 D0            [24]  656 	push PSW 
      0005A0 E5 24            [12]  657 	mov	a,_curThread
      0005A2 24 20            [12]  658 	add	a,#_savedSP
      0005A4 F8               [12]  659 	mov	r0,a
      0005A5 A6 81            [24]  660 	mov	@r0,_SP
                                    661 ;	preemptive.c:223: __endasm;
      0005A7 89 E0            [24]  662 	mov	ACC, r1
      0005A9 8A F0            [24]  663 	mov	B, r2
      0005AB 8B 82            [24]  664 	mov	DPL, r3
      0005AD 8C 83            [24]  665 	mov	DPH, r4
      0005AF 8D D0            [24]  666 	mov	PSW, r5
      0005B1 8E 28            [24]  667 	mov	_tmp, r6
      0005B3 8F 29            [24]  668 	mov	_tmp2, r7
                                    669 ;	preemptive.c:224: do {
      0005B5                        670 00103$:
                                    671 ;	preemptive.c:225: curThread = (curThread == MAXTHREADS - 1) ? 0 : curThread + 1;
      0005B5 74 03            [12]  672 	mov	a,#0x03
      0005B7 B5 24 06         [24]  673 	cjne	a,_curThread,00110$
      0005BA 7E 00            [12]  674 	mov	r6,#0x00
      0005BC 7F 00            [12]  675 	mov	r7,#0x00
      0005BE 80 09            [24]  676 	sjmp	00111$
      0005C0                        677 00110$:
      0005C0 AD 24            [24]  678 	mov	r5,_curThread
      0005C2 0D               [12]  679 	inc	r5
      0005C3 ED               [12]  680 	mov	a,r5
      0005C4 FE               [12]  681 	mov	r6,a
      0005C5 33               [12]  682 	rlc	a
      0005C6 95 E0            [12]  683 	subb	a,acc
      0005C8 FF               [12]  684 	mov	r7,a
      0005C9                        685 00111$:
      0005C9 8E 24            [24]  686 	mov	_curThread,r6
                                    687 ;	preemptive.c:226: if(mask & isAlive[curThread]) break;
      0005CB E5 24            [12]  688 	mov	a,_curThread
      0005CD 24 2A            [12]  689 	add	a,#_isAlive
      0005CF F9               [12]  690 	mov	r1,a
      0005D0 E7               [12]  691 	mov	a,@r1
      0005D1 FF               [12]  692 	mov	r7,a
      0005D2 55 25            [12]  693 	anl	a,_mask
      0005D4 60 DF            [24]  694 	jz	00103$
                                    695 ;	preemptive.c:229: count ++;
      0005D6 E5 2E            [12]  696 	mov	a,_count
      0005D8 04               [12]  697 	inc	a
      0005D9 F5 2E            [12]  698 	mov	_count,a
                                    699 ;	preemptive.c:230: if(count == 4){
      0005DB 74 04            [12]  700 	mov	a,#0x04
      0005DD B5 2E 08         [24]  701 	cjne	a,_count,00107$
                                    702 ;	preemptive.c:231: count = 0;
      0005E0 75 2E 00         [24]  703 	mov	_count,#0x00
                                    704 ;	preemptive.c:232: time ++;
      0005E3 E5 2F            [12]  705 	mov	a,_time
      0005E5 04               [12]  706 	inc	a
      0005E6 F5 2F            [12]  707 	mov	_time,a
      0005E8                        708 00107$:
                                    709 ;	preemptive.c:243: __endasm;
      0005E8 A9 E0            [24]  710 	mov	r1, ACC
      0005EA AA F0            [24]  711 	mov	r2, B
      0005EC AB 82            [24]  712 	mov	r3, DPL
      0005EE AC 83            [24]  713 	mov	r4, DPH
      0005F0 AD D0            [24]  714 	mov	r5, PSW
      0005F2 AE 28            [24]  715 	mov	r6, _tmp
      0005F4 AF 29            [24]  716 	mov	r7, _tmp2
                                    717 ;	preemptive.c:244: RESTORESTATE;
      0005F6 E5 24            [12]  718 	mov	a,_curThread
      0005F8 24 20            [12]  719 	add	a,#_savedSP
      0005FA F9               [12]  720 	mov	r1,a
      0005FB 87 81            [24]  721 	mov	_SP,@r1
      0005FD D0 D0            [24]  722 	pop PSW 
      0005FF D0 83            [24]  723 	pop DPH 
      000601 D0 82            [24]  724 	pop DPL 
      000603 D0 F0            [24]  725 	pop B 
      000605 D0 E0            [24]  726 	pop ACC 
                                    727 ;	preemptive.c:245: EA = 1;
                                    728 ;	assignBit
      000607 D2 AF            [12]  729 	setb	_EA
                                    730 ;	preemptive.c:248: __endasm;
      000609 32               [24]  731 	reti
                                    732 ;	preemptive.c:249: }
      00060A 22               [24]  733 	ret
                                    734 ;------------------------------------------------------------
                                    735 ;Allocation info for local variables in function 'delay'
                                    736 ;------------------------------------------------------------
                                    737 ;n                         Allocated to registers r7 
                                    738 ;------------------------------------------------------------
                                    739 ;	preemptive.c:254: void delay(unsigned char n) {
                                    740 ;	-----------------------------------------
                                    741 ;	 function delay
                                    742 ;	-----------------------------------------
      00060B                        743 _delay:
      00060B AF 82            [24]  744 	mov	r7,dpl
                                    745 ;	preemptive.c:255: delayID[curThread] = time + n;
      00060D E5 24            [12]  746 	mov	a,_curThread
      00060F 24 39            [12]  747 	add	a,#_delayID
      000611 F9               [12]  748 	mov	r1,a
      000612 EF               [12]  749 	mov	a,r7
      000613 25 2F            [12]  750 	add	a,_time
      000615 F7               [12]  751 	mov	@r1,a
                                    752 ;	preemptive.c:256: while(time != delayID[curThread]);
      000616                        753 00101$:
      000616 E5 24            [12]  754 	mov	a,_curThread
      000618 24 39            [12]  755 	add	a,#_delayID
      00061A F9               [12]  756 	mov	r1,a
      00061B E7               [12]  757 	mov	a,@r1
      00061C B5 2F F7         [24]  758 	cjne	a,_time,00101$
                                    759 ;	preemptive.c:257: delayID[curThread] = 0;
      00061F E5 24            [12]  760 	mov	a,_curThread
      000621 24 39            [12]  761 	add	a,#_delayID
      000623 F8               [12]  762 	mov	r0,a
      000624 76 00            [12]  763 	mov	@r0,#0x00
                                    764 ;	preemptive.c:258: }
      000626 22               [24]  765 	ret
                                    766 ;------------------------------------------------------------
                                    767 ;Allocation info for local variables in function 'now'
                                    768 ;------------------------------------------------------------
                                    769 ;	preemptive.c:261: unsigned char now(void){
                                    770 ;	-----------------------------------------
                                    771 ;	 function now
                                    772 ;	-----------------------------------------
      000627                        773 _now:
                                    774 ;	preemptive.c:262: return time;
      000627 85 2F 82         [24]  775 	mov	dpl,_time
                                    776 ;	preemptive.c:263: }
      00062A 22               [24]  777 	ret
                                    778 	.area CSEG    (CODE)
                                    779 	.area CONST   (CODE)
                                    780 	.area XINIT   (CODE)
                                    781 	.area CABS    (ABS,CODE)
