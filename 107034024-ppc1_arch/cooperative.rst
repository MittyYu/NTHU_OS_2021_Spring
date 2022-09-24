                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Mac OS X x86_64)
                                      4 ;--------------------------------------------------------
                                      5 	.module cooperative
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
                                    109 	.globl _isAlive
                                    110 	.globl _tmp2
                                    111 	.globl _tmp
                                    112 	.globl _i
                                    113 	.globl _newThread
                                    114 	.globl _mask
                                    115 	.globl _curThread
                                    116 	.globl _savedSP
                                    117 	.globl _ThreadCreate
                                    118 	.globl _ThreadYield
                                    119 	.globl _ThreadExit
                                    120 ;--------------------------------------------------------
                                    121 ; special function registers
                                    122 ;--------------------------------------------------------
                                    123 	.area RSEG    (ABS,DATA)
      000000                        124 	.org 0x0000
                           000080   125 _P0	=	0x0080
                           000081   126 _SP	=	0x0081
                           000082   127 _DPL	=	0x0082
                           000083   128 _DPH	=	0x0083
                           000087   129 _PCON	=	0x0087
                           000088   130 _TCON	=	0x0088
                           000089   131 _TMOD	=	0x0089
                           00008A   132 _TL0	=	0x008a
                           00008B   133 _TL1	=	0x008b
                           00008C   134 _TH0	=	0x008c
                           00008D   135 _TH1	=	0x008d
                           000090   136 _P1	=	0x0090
                           000098   137 _SCON	=	0x0098
                           000099   138 _SBUF	=	0x0099
                           0000A0   139 _P2	=	0x00a0
                           0000A8   140 _IE	=	0x00a8
                           0000B0   141 _P3	=	0x00b0
                           0000B8   142 _IP	=	0x00b8
                           0000D0   143 _PSW	=	0x00d0
                           0000E0   144 _ACC	=	0x00e0
                           0000F0   145 _B	=	0x00f0
                                    146 ;--------------------------------------------------------
                                    147 ; special function bits
                                    148 ;--------------------------------------------------------
                                    149 	.area RSEG    (ABS,DATA)
      000000                        150 	.org 0x0000
                           000080   151 _P0_0	=	0x0080
                           000081   152 _P0_1	=	0x0081
                           000082   153 _P0_2	=	0x0082
                           000083   154 _P0_3	=	0x0083
                           000084   155 _P0_4	=	0x0084
                           000085   156 _P0_5	=	0x0085
                           000086   157 _P0_6	=	0x0086
                           000087   158 _P0_7	=	0x0087
                           000088   159 _IT0	=	0x0088
                           000089   160 _IE0	=	0x0089
                           00008A   161 _IT1	=	0x008a
                           00008B   162 _IE1	=	0x008b
                           00008C   163 _TR0	=	0x008c
                           00008D   164 _TF0	=	0x008d
                           00008E   165 _TR1	=	0x008e
                           00008F   166 _TF1	=	0x008f
                           000090   167 _P1_0	=	0x0090
                           000091   168 _P1_1	=	0x0091
                           000092   169 _P1_2	=	0x0092
                           000093   170 _P1_3	=	0x0093
                           000094   171 _P1_4	=	0x0094
                           000095   172 _P1_5	=	0x0095
                           000096   173 _P1_6	=	0x0096
                           000097   174 _P1_7	=	0x0097
                           000098   175 _RI	=	0x0098
                           000099   176 _TI	=	0x0099
                           00009A   177 _RB8	=	0x009a
                           00009B   178 _TB8	=	0x009b
                           00009C   179 _REN	=	0x009c
                           00009D   180 _SM2	=	0x009d
                           00009E   181 _SM1	=	0x009e
                           00009F   182 _SM0	=	0x009f
                           0000A0   183 _P2_0	=	0x00a0
                           0000A1   184 _P2_1	=	0x00a1
                           0000A2   185 _P2_2	=	0x00a2
                           0000A3   186 _P2_3	=	0x00a3
                           0000A4   187 _P2_4	=	0x00a4
                           0000A5   188 _P2_5	=	0x00a5
                           0000A6   189 _P2_6	=	0x00a6
                           0000A7   190 _P2_7	=	0x00a7
                           0000A8   191 _EX0	=	0x00a8
                           0000A9   192 _ET0	=	0x00a9
                           0000AA   193 _EX1	=	0x00aa
                           0000AB   194 _ET1	=	0x00ab
                           0000AC   195 _ES	=	0x00ac
                           0000AF   196 _EA	=	0x00af
                           0000B0   197 _P3_0	=	0x00b0
                           0000B1   198 _P3_1	=	0x00b1
                           0000B2   199 _P3_2	=	0x00b2
                           0000B3   200 _P3_3	=	0x00b3
                           0000B4   201 _P3_4	=	0x00b4
                           0000B5   202 _P3_5	=	0x00b5
                           0000B6   203 _P3_6	=	0x00b6
                           0000B7   204 _P3_7	=	0x00b7
                           0000B0   205 _RXD	=	0x00b0
                           0000B1   206 _TXD	=	0x00b1
                           0000B2   207 _INT0	=	0x00b2
                           0000B3   208 _INT1	=	0x00b3
                           0000B4   209 _T0	=	0x00b4
                           0000B5   210 _T1	=	0x00b5
                           0000B6   211 _WR	=	0x00b6
                           0000B7   212 _RD	=	0x00b7
                           0000B8   213 _PX0	=	0x00b8
                           0000B9   214 _PT0	=	0x00b9
                           0000BA   215 _PX1	=	0x00ba
                           0000BB   216 _PT1	=	0x00bb
                           0000BC   217 _PS	=	0x00bc
                           0000D0   218 _P	=	0x00d0
                           0000D1   219 _F1	=	0x00d1
                           0000D2   220 _OV	=	0x00d2
                           0000D3   221 _RS0	=	0x00d3
                           0000D4   222 _RS1	=	0x00d4
                           0000D5   223 _F0	=	0x00d5
                           0000D6   224 _AC	=	0x00d6
                           0000D7   225 _CY	=	0x00d7
                                    226 ;--------------------------------------------------------
                                    227 ; overlayable register banks
                                    228 ;--------------------------------------------------------
                                    229 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        230 	.ds 8
                                    231 ;--------------------------------------------------------
                                    232 ; internal ram data
                                    233 ;--------------------------------------------------------
                                    234 	.area DSEG    (DATA)
                           000030   235 _savedSP	=	0x0030
                           000034   236 _curThread	=	0x0034
                           000035   237 _mask	=	0x0035
                           000036   238 _newThread	=	0x0036
                           000037   239 _i	=	0x0037
                           000038   240 _tmp	=	0x0038
                           000039   241 _tmp2	=	0x0039
                           00003A   242 _isAlive	=	0x003a
                                    243 ;--------------------------------------------------------
                                    244 ; overlayable items in internal ram 
                                    245 ;--------------------------------------------------------
                                    246 	.area	OSEG    (OVR,DATA)
                                    247 ;--------------------------------------------------------
                                    248 ; indirectly addressable internal ram data
                                    249 ;--------------------------------------------------------
                                    250 	.area ISEG    (DATA)
                                    251 ;--------------------------------------------------------
                                    252 ; absolute internal ram data
                                    253 ;--------------------------------------------------------
                                    254 	.area IABS    (ABS,DATA)
                                    255 	.area IABS    (ABS,DATA)
                                    256 ;--------------------------------------------------------
                                    257 ; bit data
                                    258 ;--------------------------------------------------------
                                    259 	.area BSEG    (BIT)
                                    260 ;--------------------------------------------------------
                                    261 ; paged external ram data
                                    262 ;--------------------------------------------------------
                                    263 	.area PSEG    (PAG,XDATA)
                                    264 ;--------------------------------------------------------
                                    265 ; external ram data
                                    266 ;--------------------------------------------------------
                                    267 	.area XSEG    (XDATA)
                                    268 ;--------------------------------------------------------
                                    269 ; absolute external ram data
                                    270 ;--------------------------------------------------------
                                    271 	.area XABS    (ABS,XDATA)
                                    272 ;--------------------------------------------------------
                                    273 ; external initialized ram data
                                    274 ;--------------------------------------------------------
                                    275 	.area XISEG   (XDATA)
                                    276 	.area HOME    (CODE)
                                    277 	.area GSINIT0 (CODE)
                                    278 	.area GSINIT1 (CODE)
                                    279 	.area GSINIT2 (CODE)
                                    280 	.area GSINIT3 (CODE)
                                    281 	.area GSINIT4 (CODE)
                                    282 	.area GSINIT5 (CODE)
                                    283 	.area GSINIT  (CODE)
                                    284 	.area GSFINAL (CODE)
                                    285 	.area CSEG    (CODE)
                                    286 ;--------------------------------------------------------
                                    287 ; global & static initialisations
                                    288 ;--------------------------------------------------------
                                    289 	.area HOME    (CODE)
                                    290 	.area GSINIT  (CODE)
                                    291 	.area GSFINAL (CODE)
                                    292 	.area GSINIT  (CODE)
                                    293 ;--------------------------------------------------------
                                    294 ; Home
                                    295 ;--------------------------------------------------------
                                    296 	.area HOME    (CODE)
                                    297 	.area HOME    (CODE)
                                    298 ;--------------------------------------------------------
                                    299 ; code
                                    300 ;--------------------------------------------------------
                                    301 	.area CSEG    (CODE)
                                    302 ;------------------------------------------------------------
                                    303 ;Allocation info for local variables in function 'Bootstrap'
                                    304 ;------------------------------------------------------------
                                    305 ;	cooperative.c:80: void Bootstrap(void) {
                                    306 ;	-----------------------------------------
                                    307 ;	 function Bootstrap
                                    308 ;	-----------------------------------------
      00006C                        309 _Bootstrap:
                           000007   310 	ar7 = 0x07
                           000006   311 	ar6 = 0x06
                           000005   312 	ar5 = 0x05
                           000004   313 	ar4 = 0x04
                           000003   314 	ar3 = 0x03
                           000002   315 	ar2 = 0x02
                           000001   316 	ar1 = 0x01
                           000000   317 	ar0 = 0x00
                                    318 ;	cooperative.c:93: mask = 0b0000;
      00006C 75 35 00         [24]  319 	mov	_mask,#0x00
                                    320 ;	cooperative.c:94: isAlive[0] = 0b0001; 
      00006F 75 3A 01         [24]  321 	mov	_isAlive,#0x01
                                    322 ;	cooperative.c:95: isAlive[1] = 0b0010; 
      000072 75 3B 02         [24]  323 	mov	(_isAlive + 0x0001),#0x02
                                    324 ;	cooperative.c:96: isAlive[2] = 0b0100; 
      000075 75 3C 04         [24]  325 	mov	(_isAlive + 0x0002),#0x04
                                    326 ;	cooperative.c:97: isAlive[3] = 0b1000;
      000078 75 3D 08         [24]  327 	mov	(_isAlive + 0x0003),#0x08
                                    328 ;	cooperative.c:98: curThread = ThreadCreate(main);
      00007B 90 00 59         [24]  329 	mov	dptr,#_main
      00007E 12 00 96         [24]  330 	lcall	_ThreadCreate
      000081 85 82 34         [24]  331 	mov	_curThread,dpl
                                    332 ;	cooperative.c:99: RESTORESTATE;
      000084 E5 34            [12]  333 	mov	a,_curThread
      000086 24 30            [12]  334 	add	a,#_savedSP
      000088 F9               [12]  335 	mov	r1,a
      000089 87 81            [24]  336 	mov	_SP,@r1
      00008B D0 D0            [24]  337 	pop PSW 
      00008D D0 83            [24]  338 	pop DPH 
      00008F D0 82            [24]  339 	pop DPL 
      000091 D0 F0            [24]  340 	pop B 
      000093 D0 E0            [24]  341 	pop ACC 
                                    342 ;	cooperative.c:100: }
      000095 22               [24]  343 	ret
                                    344 ;------------------------------------------------------------
                                    345 ;Allocation info for local variables in function 'ThreadCreate'
                                    346 ;------------------------------------------------------------
                                    347 ;fp                        Allocated to registers 
                                    348 ;------------------------------------------------------------
                                    349 ;	cooperative.c:108: ThreadID ThreadCreate(FunctionPtr fp) {
                                    350 ;	-----------------------------------------
                                    351 ;	 function ThreadCreate
                                    352 ;	-----------------------------------------
      000096                        353 _ThreadCreate:
                                    354 ;	cooperative.c:114: if(mask == 0b1111) return -1;
      000096 74 0F            [12]  355 	mov	a,#0x0f
      000098 B5 35 04         [24]  356 	cjne	a,_mask,00102$
      00009B 75 82 FF         [24]  357 	mov	dpl,#0xff
      00009E 22               [24]  358 	ret
      00009F                        359 00102$:
                                    360 ;	cooperative.c:159: for(i=0; i<MAXTHREADS; i++) {
      00009F 75 37 00         [24]  361 	mov	_i,#0x00
      0000A2                        362 00107$:
      0000A2 74 FC            [12]  363 	mov	a,#0x100 - 0x04
      0000A4 25 37            [12]  364 	add	a,_i
      0000A6 40 44            [24]  365 	jc	00105$
                                    366 ;	cooperative.c:160: if(((mask) & (0b0001<<i)) == 0) {
      0000A8 AF 37            [24]  367 	mov	r7,_i
      0000AA 8F F0            [24]  368 	mov	b,r7
      0000AC 05 F0            [12]  369 	inc	b
      0000AE 7F 01            [12]  370 	mov	r7,#0x01
      0000B0 7E 00            [12]  371 	mov	r6,#0x00
      0000B2 80 06            [24]  372 	sjmp	00131$
      0000B4                        373 00130$:
      0000B4 EF               [12]  374 	mov	a,r7
      0000B5 2F               [12]  375 	add	a,r7
      0000B6 FF               [12]  376 	mov	r7,a
      0000B7 EE               [12]  377 	mov	a,r6
      0000B8 33               [12]  378 	rlc	a
      0000B9 FE               [12]  379 	mov	r6,a
      0000BA                        380 00131$:
      0000BA D5 F0 F7         [24]  381 	djnz	b,00130$
      0000BD AC 35            [24]  382 	mov	r4,_mask
      0000BF 7D 00            [12]  383 	mov	r5,#0x00
      0000C1 EC               [12]  384 	mov	a,r4
      0000C2 52 07            [12]  385 	anl	ar7,a
      0000C4 ED               [12]  386 	mov	a,r5
      0000C5 52 06            [12]  387 	anl	ar6,a
      0000C7 EF               [12]  388 	mov	a,r7
      0000C8 4E               [12]  389 	orl	a,r6
      0000C9 70 1A            [24]  390 	jnz	00108$
                                    391 ;	cooperative.c:161: mask |= (0b0001<<i);
      0000CB AF 37            [24]  392 	mov	r7,_i
      0000CD 8F F0            [24]  393 	mov	b,r7
      0000CF 05 F0            [12]  394 	inc	b
      0000D1 74 01            [12]  395 	mov	a,#0x01
      0000D3 80 02            [24]  396 	sjmp	00135$
      0000D5                        397 00133$:
      0000D5 25 E0            [12]  398 	add	a,acc
      0000D7                        399 00135$:
      0000D7 D5 F0 FB         [24]  400 	djnz	b,00133$
      0000DA FF               [12]  401 	mov	r7,a
      0000DB AE 35            [24]  402 	mov	r6,_mask
      0000DD 4E               [12]  403 	orl	a,r6
      0000DE F5 35            [12]  404 	mov	_mask,a
                                    405 ;	cooperative.c:162: newThread = i;
      0000E0 85 37 36         [24]  406 	mov	_newThread,_i
                                    407 ;	cooperative.c:163: break;
      0000E3 80 07            [24]  408 	sjmp	00105$
      0000E5                        409 00108$:
                                    410 ;	cooperative.c:159: for(i=0; i<MAXTHREADS; i++) {
      0000E5 E5 37            [12]  411 	mov	a,_i
      0000E7 04               [12]  412 	inc	a
      0000E8 F5 37            [12]  413 	mov	_i,a
      0000EA 80 B6            [24]  414 	sjmp	00107$
      0000EC                        415 00105$:
                                    416 ;	cooperative.c:168: tmp = SP;
      0000EC 85 81 38         [24]  417 	mov	_tmp,_SP
                                    418 ;	cooperative.c:169: SP = 0x3F + (i<<4);
      0000EF E5 37            [12]  419 	mov	a,_i
      0000F1 C4               [12]  420 	swap	a
      0000F2 54 F0            [12]  421 	anl	a,#0xf0
      0000F4 FF               [12]  422 	mov	r7,a
      0000F5 24 3F            [12]  423 	add	a,#0x3f
      0000F7 F5 81            [12]  424 	mov	_SP,a
                                    425 ;	cooperative.c:180: __endasm;
      0000F9 C0 82            [24]  426 	push	DPL
      0000FB C0 83            [24]  427 	push	DPH
      0000FD 74 00            [12]  428 	mov	A, #0
      0000FF C0 E0            [24]  429 	push	A
      000101 C0 E0            [24]  430 	push	A
      000103 C0 E0            [24]  431 	push	A
      000105 C0 E0            [24]  432 	push	A
                                    433 ;	cooperative.c:188: tmp2 = (i<<3);
      000107 E5 37            [12]  434 	mov	a,_i
      000109 FF               [12]  435 	mov	r7,a
      00010A C4               [12]  436 	swap	a
      00010B 03               [12]  437 	rr	a
      00010C 54 F8            [12]  438 	anl	a,#0xf8
      00010E F5 39            [12]  439 	mov	_tmp2,a
                                    440 ;	cooperative.c:192: __endasm;
      000110 C0 39            [24]  441 	push	_tmp2
                                    442 ;	cooperative.c:195: savedSP[newThread] = SP;
      000112 E5 36            [12]  443 	mov	a,_newThread
      000114 24 30            [12]  444 	add	a,#_savedSP
      000116 F8               [12]  445 	mov	r0,a
      000117 A6 81            [24]  446 	mov	@r0,_SP
                                    447 ;	cooperative.c:196: SP = tmp;
      000119 85 38 81         [24]  448 	mov	_SP,_tmp
                                    449 ;	cooperative.c:197: return newThread;
      00011C 85 36 82         [24]  450 	mov	dpl,_newThread
                                    451 ;	cooperative.c:198: }
      00011F 22               [24]  452 	ret
                                    453 ;------------------------------------------------------------
                                    454 ;Allocation info for local variables in function 'ThreadYield'
                                    455 ;------------------------------------------------------------
                                    456 ;	cooperative.c:206: void ThreadYield(void) {
                                    457 ;	-----------------------------------------
                                    458 ;	 function ThreadYield
                                    459 ;	-----------------------------------------
      000120                        460 _ThreadYield:
                                    461 ;	cooperative.c:207: SAVESTATE;
      000120 C0 E0            [24]  462 	push ACC 
      000122 C0 F0            [24]  463 	push B 
      000124 C0 82            [24]  464 	push DPL 
      000126 C0 83            [24]  465 	push DPH 
      000128 C0 D0            [24]  466 	push PSW 
      00012A E5 34            [12]  467 	mov	a,_curThread
      00012C 24 30            [12]  468 	add	a,#_savedSP
      00012E F8               [12]  469 	mov	r0,a
      00012F A6 81            [24]  470 	mov	@r0,_SP
                                    471 ;	cooperative.c:208: do {
      000131                        472 00103$:
                                    473 ;	cooperative.c:218: curThread = (curThread == MAXTHREADS-1) ? 0 : curThread+1;
      000131 74 03            [12]  474 	mov	a,#0x03
      000133 B5 34 06         [24]  475 	cjne	a,_curThread,00108$
      000136 7E 00            [12]  476 	mov	r6,#0x00
      000138 7F 00            [12]  477 	mov	r7,#0x00
      00013A 80 09            [24]  478 	sjmp	00109$
      00013C                        479 00108$:
      00013C AD 34            [24]  480 	mov	r5,_curThread
      00013E 0D               [12]  481 	inc	r5
      00013F ED               [12]  482 	mov	a,r5
      000140 FE               [12]  483 	mov	r6,a
      000141 33               [12]  484 	rlc	a
      000142 95 E0            [12]  485 	subb	a,acc
      000144 FF               [12]  486 	mov	r7,a
      000145                        487 00109$:
      000145 8E 34            [24]  488 	mov	_curThread,r6
                                    489 ;	cooperative.c:219: if(mask & isAlive[curThread]) break;
      000147 E5 34            [12]  490 	mov	a,_curThread
      000149 24 3A            [12]  491 	add	a,#_isAlive
      00014B F9               [12]  492 	mov	r1,a
      00014C E7               [12]  493 	mov	a,@r1
      00014D FF               [12]  494 	mov	r7,a
      00014E 55 35            [12]  495 	anl	a,_mask
      000150 60 DF            [24]  496 	jz	00103$
                                    497 ;	cooperative.c:221: RESTORESTATE;
      000152 E5 34            [12]  498 	mov	a,_curThread
      000154 24 30            [12]  499 	add	a,#_savedSP
      000156 F9               [12]  500 	mov	r1,a
      000157 87 81            [24]  501 	mov	_SP,@r1
      000159 D0 D0            [24]  502 	pop PSW 
      00015B D0 83            [24]  503 	pop DPH 
      00015D D0 82            [24]  504 	pop DPL 
      00015F D0 F0            [24]  505 	pop B 
      000161 D0 E0            [24]  506 	pop ACC 
                                    507 ;	cooperative.c:222: }
      000163 22               [24]  508 	ret
                                    509 ;------------------------------------------------------------
                                    510 ;Allocation info for local variables in function 'ThreadExit'
                                    511 ;------------------------------------------------------------
                                    512 ;	cooperative.c:229: void ThreadExit(void) {
                                    513 ;	-----------------------------------------
                                    514 ;	 function ThreadExit
                                    515 ;	-----------------------------------------
      000164                        516 _ThreadExit:
                                    517 ;	cooperative.c:236: mask &= ~(1<<curThread);
      000164 AF 34            [24]  518 	mov	r7,_curThread
      000166 8F F0            [24]  519 	mov	b,r7
      000168 05 F0            [12]  520 	inc	b
      00016A 74 01            [12]  521 	mov	a,#0x01
      00016C 80 02            [24]  522 	sjmp	00124$
      00016E                        523 00122$:
      00016E 25 E0            [12]  524 	add	a,acc
      000170                        525 00124$:
      000170 D5 F0 FB         [24]  526 	djnz	b,00122$
      000173 F4               [12]  527 	cpl	a
      000174 FF               [12]  528 	mov	r7,a
      000175 AE 35            [24]  529 	mov	r6,_mask
      000177 5E               [12]  530 	anl	a,r6
      000178 F5 35            [12]  531 	mov	_mask,a
                                    532 ;	cooperative.c:237: do {
      00017A                        533 00103$:
                                    534 ;	cooperative.c:238: curThread = (curThread == 3) ? 0 : curThread+1;
      00017A 74 03            [12]  535 	mov	a,#0x03
      00017C B5 34 06         [24]  536 	cjne	a,_curThread,00108$
      00017F 7E 00            [12]  537 	mov	r6,#0x00
      000181 7F 00            [12]  538 	mov	r7,#0x00
      000183 80 09            [24]  539 	sjmp	00109$
      000185                        540 00108$:
      000185 AD 34            [24]  541 	mov	r5,_curThread
      000187 0D               [12]  542 	inc	r5
      000188 ED               [12]  543 	mov	a,r5
      000189 FE               [12]  544 	mov	r6,a
      00018A 33               [12]  545 	rlc	a
      00018B 95 E0            [12]  546 	subb	a,acc
      00018D FF               [12]  547 	mov	r7,a
      00018E                        548 00109$:
      00018E 8E 34            [24]  549 	mov	_curThread,r6
                                    550 ;	cooperative.c:239: if(mask & (1<<curThread)) break;
      000190 AF 34            [24]  551 	mov	r7,_curThread
      000192 8F F0            [24]  552 	mov	b,r7
      000194 05 F0            [12]  553 	inc	b
      000196 7F 01            [12]  554 	mov	r7,#0x01
      000198 7E 00            [12]  555 	mov	r6,#0x00
      00019A 80 06            [24]  556 	sjmp	00128$
      00019C                        557 00127$:
      00019C EF               [12]  558 	mov	a,r7
      00019D 2F               [12]  559 	add	a,r7
      00019E FF               [12]  560 	mov	r7,a
      00019F EE               [12]  561 	mov	a,r6
      0001A0 33               [12]  562 	rlc	a
      0001A1 FE               [12]  563 	mov	r6,a
      0001A2                        564 00128$:
      0001A2 D5 F0 F7         [24]  565 	djnz	b,00127$
      0001A5 AC 35            [24]  566 	mov	r4,_mask
      0001A7 7D 00            [12]  567 	mov	r5,#0x00
      0001A9 EC               [12]  568 	mov	a,r4
      0001AA 52 07            [12]  569 	anl	ar7,a
      0001AC ED               [12]  570 	mov	a,r5
      0001AD 52 06            [12]  571 	anl	ar6,a
      0001AF EF               [12]  572 	mov	a,r7
      0001B0 4E               [12]  573 	orl	a,r6
      0001B1 60 C7            [24]  574 	jz	00103$
                                    575 ;	cooperative.c:241: RESTORESTATE;
      0001B3 E5 34            [12]  576 	mov	a,_curThread
      0001B5 24 30            [12]  577 	add	a,#_savedSP
      0001B7 F9               [12]  578 	mov	r1,a
      0001B8 87 81            [24]  579 	mov	_SP,@r1
      0001BA D0 D0            [24]  580 	pop PSW 
      0001BC D0 83            [24]  581 	pop DPH 
      0001BE D0 82            [24]  582 	pop DPL 
      0001C0 D0 F0            [24]  583 	pop B 
      0001C2 D0 E0            [24]  584 	pop ACC 
                                    585 ;	cooperative.c:242: }
      0001C4 22               [24]  586 	ret
                                    587 	.area CSEG    (CODE)
                                    588 	.area CONST   (CODE)
                                    589 	.area XINIT   (CODE)
                                    590 	.area CABS    (ABS,CODE)
