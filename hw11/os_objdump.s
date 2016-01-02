
/Users/joeywang/Downloads/os:     file format elf64-littleriscv


Disassembly of section .text:

0000000000010000 <_ftext>:
   10000:	00002197          	auipc	gp,0x2
   10004:	cb018193          	addi	gp,gp,-848 # 11cb0 <_gp>
   10008:	00001297          	auipc	t0,0x1
   1000c:	4c028293          	addi	t0,t0,1216 # 114c8 <_fbss>
   10010:	00001317          	auipc	t1,0x1
   10014:	50830313          	addi	t1,t1,1288 # 11518 <_end>
   10018:	0002b023          	sd	zero,0(t0)
   1001c:	00828293          	addi	t0,t0,8
   10020:	fe62ece3          	bltu	t0,t1,10018 <_ftext+0x18>
   10024:	00000517          	auipc	a0,0x0
   10028:	25050513          	addi	a0,a0,592 # 10274 <__libc_fini_array>
   1002c:	164000ef          	jal	10190 <atexit>
   10030:	1a4000ef          	jal	101d4 <__libc_init_array>
   10034:	00012503          	lw	a0,0(sp)
   10038:	00810593          	addi	a1,sp,8
   1003c:	00000613          	li	a2,0
   10040:	0f8000ef          	jal	10138 <main>
   10044:	1600006f          	j	101a4 <exit>

0000000000010048 <_fini>:
   10048:	00008067          	ret

000000000001004c <deregister_tm_clones>:
   1004c:	80018713          	addi	a4,gp,-2048 # 114b0 <_edata>
   10050:	80718793          	addi	a5,gp,-2041 # 114b7 <_edata+0x7>
   10054:	40e787b3          	sub	a5,a5,a4
   10058:	00e00713          	li	a4,14
   1005c:	00f77a63          	bleu	a5,a4,10070 <deregister_tm_clones+0x24>
   10060:	00000293          	li	t0,0
   10064:	00028663          	beqz	t0,10070 <deregister_tm_clones+0x24>
   10068:	80018513          	addi	a0,gp,-2048 # 114b0 <_edata>
   1006c:	00028067          	jr	t0
   10070:	00008067          	ret

0000000000010074 <register_tm_clones>:
   10074:	80018593          	addi	a1,gp,-2048 # 114b0 <_edata>
   10078:	80018793          	addi	a5,gp,-2048 # 114b0 <_edata>
   1007c:	40b787b3          	sub	a5,a5,a1
   10080:	4037d793          	srai	a5,a5,0x3
   10084:	03f7d593          	srli	a1,a5,0x3f
   10088:	00f585b3          	add	a1,a1,a5
   1008c:	4015d593          	srai	a1,a1,0x1
   10090:	00058a63          	beqz	a1,100a4 <register_tm_clones+0x30>
   10094:	00000293          	li	t0,0
   10098:	00028663          	beqz	t0,100a4 <register_tm_clones+0x30>
   1009c:	80018513          	addi	a0,gp,-2048 # 114b0 <_edata>
   100a0:	00028067          	jr	t0
   100a4:	00008067          	ret

00000000000100a8 <__do_global_dtors_aux>:
   100a8:	ff010113          	addi	sp,sp,-16
   100ac:	00813023          	sd	s0,0(sp)
   100b0:	8201c783          	lbu	a5,-2016(gp) # 114d0 <_bss_start>
   100b4:	00113423          	sd	ra,8(sp)
   100b8:	02079263          	bnez	a5,100dc <__do_global_dtors_aux+0x34>
   100bc:	f91ff0ef          	jal	1004c <deregister_tm_clones>
   100c0:	00000793          	li	a5,0
   100c4:	00078863          	beqz	a5,100d4 <__do_global_dtors_aux+0x2c>
   100c8:	00011537          	lui	a0,0x11
   100cc:	95850513          	addi	a0,a0,-1704 # 10958 <__fini_array_end>
   100d0:	f31ef0ef          	jal	0 <_ftext-0x10000>
   100d4:	00100793          	li	a5,1
   100d8:	82f18023          	sb	a5,-2016(gp) # 114d0 <_bss_start>
   100dc:	00813083          	ld	ra,8(sp)
   100e0:	00013403          	ld	s0,0(sp)
   100e4:	01010113          	addi	sp,sp,16
   100e8:	00008067          	ret

00000000000100ec <frame_dummy>:
   100ec:	ff010113          	addi	sp,sp,-16
   100f0:	00000793          	li	a5,0
   100f4:	00113423          	sd	ra,8(sp)
   100f8:	00078a63          	beqz	a5,1010c <frame_dummy+0x20>
   100fc:	00011537          	lui	a0,0x11
   10100:	82818593          	addi	a1,gp,-2008 # 114d8 <object.3088>
   10104:	95850513          	addi	a0,a0,-1704 # 10958 <__fini_array_end>
   10108:	ef9ef0ef          	jal	0 <_ftext-0x10000>
   1010c:	00011537          	lui	a0,0x11
   10110:	d7850513          	addi	a0,a0,-648 # 10d78 <__JCR_END__>
   10114:	00053783          	ld	a5,0(a0)
   10118:	00079863          	bnez	a5,10128 <frame_dummy+0x3c>
   1011c:	00813083          	ld	ra,8(sp)
   10120:	01010113          	addi	sp,sp,16
   10124:	f51ff06f          	j	10074 <register_tm_clones>
   10128:	00000793          	li	a5,0
   1012c:	fe0788e3          	beqz	a5,1011c <frame_dummy+0x30>
   10130:	000780e7          	jalr	a5
   10134:	fe9ff06f          	j	1011c <frame_dummy+0x30>

0000000000010138 <main>:
   10138:	fe010113          	addi	sp,sp,-32
   1013c:	00813c23          	sd	s0,24(sp)
   10140:	02010413          	addi	s0,sp,32
   10144:	fe042623          	sw	zero,-20(s0)
   10148:	00a00793          	li	a5,10
   1014c:	fef42223          	sw	a5,-28(s0)
   10150:	00a00793          	li	a5,10
   10154:	fef42423          	sw	a5,-24(s0)
   10158:	fec42703          	lw	a4,-20(s0)
   1015c:	fe442783          	lw	a5,-28(s0)
   10160:	00f707bb          	addw	a5,a4,a5
   10164:	fef42623          	sw	a5,-20(s0)
   10168:	fe842783          	lw	a5,-24(s0)
   1016c:	fff7879b          	addiw	a5,a5,-1
   10170:	fef42423          	sw	a5,-24(s0)
   10174:	fe842783          	lw	a5,-24(s0)
   10178:	fef040e3          	bgtz	a5,10158 <main+0x20>
   1017c:	00000793          	li	a5,0
   10180:	00078513          	mv	a0,a5
   10184:	01813403          	ld	s0,24(sp)
   10188:	02010113          	addi	sp,sp,32
   1018c:	00008067          	ret

0000000000010190 <atexit>:
   10190:	00050593          	mv	a1,a0
   10194:	00000693          	li	a3,0
   10198:	00000613          	li	a2,0
   1019c:	00000513          	li	a0,0
   101a0:	1300006f          	j	102d0 <__register_exitproc>

00000000000101a4 <exit>:
   101a4:	ff010113          	addi	sp,sp,-16
   101a8:	00000593          	li	a1,0
   101ac:	00813023          	sd	s0,0(sp)
   101b0:	00113423          	sd	ra,8(sp)
   101b4:	00050413          	mv	s0,a0
   101b8:	218000ef          	jal	103d0 <__call_exitprocs>
   101bc:	8081b503          	ld	a0,-2040(gp) # 114b8 <_global_impure_ptr>
   101c0:	05853783          	ld	a5,88(a0)
   101c4:	00078463          	beqz	a5,101cc <exit+0x28>
   101c8:	000780e7          	jalr	a5
   101cc:	00040513          	mv	a0,s0
   101d0:	748000ef          	jal	10918 <_exit>

00000000000101d4 <__libc_init_array>:
   101d4:	fe010113          	addi	sp,sp,-32
   101d8:	00813823          	sd	s0,16(sp)
   101dc:	000117b7          	lui	a5,0x11
   101e0:	00011437          	lui	s0,0x11
   101e4:	01213023          	sd	s2,0(sp)
   101e8:	94878793          	addi	a5,a5,-1720 # 10948 <_etext>
   101ec:	94840913          	addi	s2,s0,-1720 # 10948 <_etext>
   101f0:	41278933          	sub	s2,a5,s2
   101f4:	40395913          	srai	s2,s2,0x3
   101f8:	00913423          	sd	s1,8(sp)
   101fc:	00113c23          	sd	ra,24(sp)
   10200:	94840413          	addi	s0,s0,-1720
   10204:	00000493          	li	s1,0
   10208:	00090c63          	beqz	s2,10220 <__libc_init_array+0x4c>
   1020c:	00043783          	ld	a5,0(s0)
   10210:	00148493          	addi	s1,s1,1
   10214:	00840413          	addi	s0,s0,8
   10218:	000780e7          	jalr	a5
   1021c:	fe9918e3          	bne	s2,s1,1020c <__libc_init_array+0x38>
   10220:	00011437          	lui	s0,0x11
   10224:	e25ff0ef          	jal	10048 <_fini>
   10228:	000117b7          	lui	a5,0x11
   1022c:	94840913          	addi	s2,s0,-1720 # 10948 <_etext>
   10230:	95078793          	addi	a5,a5,-1712 # 10950 <__init_array_end>
   10234:	41278933          	sub	s2,a5,s2
   10238:	40395913          	srai	s2,s2,0x3
   1023c:	94840413          	addi	s0,s0,-1720
   10240:	00000493          	li	s1,0
   10244:	00090c63          	beqz	s2,1025c <__libc_init_array+0x88>
   10248:	00043783          	ld	a5,0(s0)
   1024c:	00148493          	addi	s1,s1,1
   10250:	00840413          	addi	s0,s0,8
   10254:	000780e7          	jalr	a5
   10258:	fe9918e3          	bne	s2,s1,10248 <__libc_init_array+0x74>
   1025c:	01813083          	ld	ra,24(sp)
   10260:	01013403          	ld	s0,16(sp)
   10264:	00813483          	ld	s1,8(sp)
   10268:	00013903          	ld	s2,0(sp)
   1026c:	02010113          	addi	sp,sp,32
   10270:	00008067          	ret

0000000000010274 <__libc_fini_array>:
   10274:	fe010113          	addi	sp,sp,-32
   10278:	00813823          	sd	s0,16(sp)
   1027c:	00913423          	sd	s1,8(sp)
   10280:	00011437          	lui	s0,0x11
   10284:	000114b7          	lui	s1,0x11
   10288:	95048493          	addi	s1,s1,-1712 # 10950 <__init_array_end>
   1028c:	95840413          	addi	s0,s0,-1704 # 10958 <__fini_array_end>
   10290:	40940433          	sub	s0,s0,s1
   10294:	ff840793          	addi	a5,s0,-8
   10298:	40345413          	srai	s0,s0,0x3
   1029c:	00113c23          	sd	ra,24(sp)
   102a0:	009784b3          	add	s1,a5,s1
   102a4:	00040c63          	beqz	s0,102bc <__libc_fini_array+0x48>
   102a8:	0004b783          	ld	a5,0(s1)
   102ac:	fff40413          	addi	s0,s0,-1
   102b0:	ff848493          	addi	s1,s1,-8
   102b4:	000780e7          	jalr	a5
   102b8:	fe0418e3          	bnez	s0,102a8 <__libc_fini_array+0x34>
   102bc:	01813083          	ld	ra,24(sp)
   102c0:	01013403          	ld	s0,16(sp)
   102c4:	00813483          	ld	s1,8(sp)
   102c8:	02010113          	addi	sp,sp,32
   102cc:	d7dff06f          	j	10048 <_fini>

00000000000102d0 <__register_exitproc>:
   102d0:	fc010113          	addi	sp,sp,-64
   102d4:	02813823          	sd	s0,48(sp)
   102d8:	8081b403          	ld	s0,-2040(gp) # 114b8 <_global_impure_ptr>
   102dc:	02913423          	sd	s1,40(sp)
   102e0:	00050493          	mv	s1,a0
   102e4:	1f843503          	ld	a0,504(s0)
   102e8:	02113c23          	sd	ra,56(sp)
   102ec:	0c050863          	beqz	a0,103bc <__register_exitproc+0xec>
   102f0:	00852703          	lw	a4,8(a0)
   102f4:	01f00793          	li	a5,31
   102f8:	0017089b          	addiw	a7,a4,1
   102fc:	04e7d863          	ble	a4,a5,1034c <__register_exitproc+0x7c>
   10300:	00000793          	li	a5,0
   10304:	0c078263          	beqz	a5,103c8 <__register_exitproc+0xf8>
   10308:	31800513          	li	a0,792
   1030c:	00b13c23          	sd	a1,24(sp)
   10310:	00c13823          	sd	a2,16(sp)
   10314:	00d13423          	sd	a3,8(sp)
   10318:	ce9ef0ef          	jal	0 <_ftext-0x10000>
   1031c:	01813583          	ld	a1,24(sp)
   10320:	01013603          	ld	a2,16(sp)
   10324:	00813683          	ld	a3,8(sp)
   10328:	0a050063          	beqz	a0,103c8 <__register_exitproc+0xf8>
   1032c:	1f843783          	ld	a5,504(s0)
   10330:	00100893          	li	a7,1
   10334:	00052423          	sw	zero,8(a0)
   10338:	00f53023          	sd	a5,0(a0)
   1033c:	00000713          	li	a4,0
   10340:	1ea43c23          	sd	a0,504(s0)
   10344:	30052823          	sw	zero,784(a0)
   10348:	30052a23          	sw	zero,788(a0)
   1034c:	00070793          	mv	a5,a4
   10350:	02049863          	bnez	s1,10380 <__register_exitproc+0xb0>
   10354:	00278793          	addi	a5,a5,2
   10358:	00379793          	slli	a5,a5,0x3
   1035c:	00f507b3          	add	a5,a0,a5
   10360:	01152423          	sw	a7,8(a0)
   10364:	00000513          	li	a0,0
   10368:	00b7b023          	sd	a1,0(a5)
   1036c:	03813083          	ld	ra,56(sp)
   10370:	03013403          	ld	s0,48(sp)
   10374:	02813483          	ld	s1,40(sp)
   10378:	04010113          	addi	sp,sp,64
   1037c:	00008067          	ret
   10380:	00371813          	slli	a6,a4,0x3
   10384:	01050833          	add	a6,a0,a6
   10388:	10c83823          	sd	a2,272(a6)
   1038c:	31052283          	lw	t0,784(a0)
   10390:	00100613          	li	a2,1
   10394:	00e6173b          	sllw	a4,a2,a4
   10398:	00e2e633          	or	a2,t0,a4
   1039c:	30c52823          	sw	a2,784(a0)
   103a0:	20d83823          	sd	a3,528(a6)
   103a4:	00200693          	li	a3,2
   103a8:	fad496e3          	bne	s1,a3,10354 <__register_exitproc+0x84>
   103ac:	31452683          	lw	a3,788(a0)
   103b0:	00e6e733          	or	a4,a3,a4
   103b4:	30e52a23          	sw	a4,788(a0)
   103b8:	f9dff06f          	j	10354 <__register_exitproc+0x84>
   103bc:	20040513          	addi	a0,s0,512
   103c0:	1ea43c23          	sd	a0,504(s0)
   103c4:	f2dff06f          	j	102f0 <__register_exitproc+0x20>
   103c8:	fff00513          	li	a0,-1
   103cc:	fa1ff06f          	j	1036c <__register_exitproc+0x9c>

00000000000103d0 <__call_exitprocs>:
   103d0:	fa010113          	addi	sp,sp,-96
   103d4:	03413823          	sd	s4,48(sp)
   103d8:	8081ba03          	ld	s4,-2040(gp) # 114b8 <_global_impure_ptr>
   103dc:	03313c23          	sd	s3,56(sp)
   103e0:	04913423          	sd	s1,72(sp)
   103e4:	05213023          	sd	s2,64(sp)
   103e8:	03513423          	sd	s5,40(sp)
   103ec:	01713c23          	sd	s7,24(sp)
   103f0:	01813823          	sd	s8,16(sp)
   103f4:	04113c23          	sd	ra,88(sp)
   103f8:	04813823          	sd	s0,80(sp)
   103fc:	03613023          	sd	s6,32(sp)
   10400:	01913423          	sd	s9,8(sp)
   10404:	01a13023          	sd	s10,0(sp)
   10408:	00050913          	mv	s2,a0
   1040c:	00058b93          	mv	s7,a1
   10410:	1f8a0a93          	addi	s5,s4,504
   10414:	00100493          	li	s1,1
   10418:	fff00c13          	li	s8,-1
   1041c:	00000993          	li	s3,0
   10420:	1f8a3b03          	ld	s6,504(s4)
   10424:	0c0b0463          	beqz	s6,104ec <__call_exitprocs+0x11c>
   10428:	000a8d13          	mv	s10,s5
   1042c:	008b2403          	lw	s0,8(s6)
   10430:	fff4041b          	addiw	s0,s0,-1
   10434:	02045263          	bgez	s0,10458 <__call_exitprocs+0x88>
   10438:	08c0006f          	j	104c4 <__call_exitprocs+0xf4>
   1043c:	02040793          	addi	a5,s0,32
   10440:	00379793          	slli	a5,a5,0x3
   10444:	00fb07b3          	add	a5,s6,a5
   10448:	1107b783          	ld	a5,272(a5)
   1044c:	00fb8a63          	beq	s7,a5,10460 <__call_exitprocs+0x90>
   10450:	fff4041b          	addiw	s0,s0,-1
   10454:	07840863          	beq	s0,s8,104c4 <__call_exitprocs+0xf4>
   10458:	00040713          	mv	a4,s0
   1045c:	fe0b90e3          	bnez	s7,1043c <__call_exitprocs+0x6c>
   10460:	008b2783          	lw	a5,8(s6)
   10464:	00371713          	slli	a4,a4,0x3
   10468:	00eb0733          	add	a4,s6,a4
   1046c:	fff7879b          	addiw	a5,a5,-1
   10470:	01073683          	ld	a3,16(a4)
   10474:	0a878c63          	beq	a5,s0,1052c <__call_exitprocs+0x15c>
   10478:	00073823          	sd	zero,16(a4)
   1047c:	fc068ae3          	beqz	a3,10450 <__call_exitprocs+0x80>
   10480:	310b2783          	lw	a5,784(s6)
   10484:	0084963b          	sllw	a2,s1,s0
   10488:	008b2c83          	lw	s9,8(s6)
   1048c:	00f677b3          	and	a5,a2,a5
   10490:	08078a63          	beqz	a5,10524 <__call_exitprocs+0x154>
   10494:	314b2783          	lw	a5,788(s6)
   10498:	00f67633          	and	a2,a2,a5
   1049c:	08061c63          	bnez	a2,10534 <__call_exitprocs+0x164>
   104a0:	11073583          	ld	a1,272(a4)
   104a4:	00090513          	mv	a0,s2
   104a8:	000680e7          	jalr	a3
   104ac:	008b2783          	lw	a5,8(s6)
   104b0:	f79798e3          	bne	a5,s9,10420 <__call_exitprocs+0x50>
   104b4:	000d3783          	ld	a5,0(s10)
   104b8:	f76794e3          	bne	a5,s6,10420 <__call_exitprocs+0x50>
   104bc:	fff4041b          	addiw	s0,s0,-1
   104c0:	f9841ce3          	bne	s0,s8,10458 <__call_exitprocs+0x88>
   104c4:	02098463          	beqz	s3,104ec <__call_exitprocs+0x11c>
   104c8:	008b2783          	lw	a5,8(s6)
   104cc:	06079a63          	bnez	a5,10540 <__call_exitprocs+0x170>
   104d0:	000b3783          	ld	a5,0(s6)
   104d4:	08078063          	beqz	a5,10554 <__call_exitprocs+0x184>
   104d8:	000b0513          	mv	a0,s6
   104dc:	00fd3023          	sd	a5,0(s10)
   104e0:	b21ef0ef          	jal	0 <_ftext-0x10000>
   104e4:	000d3b03          	ld	s6,0(s10)
   104e8:	f40b12e3          	bnez	s6,1042c <__call_exitprocs+0x5c>
   104ec:	05813083          	ld	ra,88(sp)
   104f0:	05013403          	ld	s0,80(sp)
   104f4:	04813483          	ld	s1,72(sp)
   104f8:	04013903          	ld	s2,64(sp)
   104fc:	03813983          	ld	s3,56(sp)
   10500:	03013a03          	ld	s4,48(sp)
   10504:	02813a83          	ld	s5,40(sp)
   10508:	02013b03          	ld	s6,32(sp)
   1050c:	01813b83          	ld	s7,24(sp)
   10510:	01013c03          	ld	s8,16(sp)
   10514:	00813c83          	ld	s9,8(sp)
   10518:	00013d03          	ld	s10,0(sp)
   1051c:	06010113          	addi	sp,sp,96
   10520:	00008067          	ret
   10524:	000680e7          	jalr	a3
   10528:	f85ff06f          	j	104ac <__call_exitprocs+0xdc>
   1052c:	008b2423          	sw	s0,8(s6)
   10530:	f4dff06f          	j	1047c <__call_exitprocs+0xac>
   10534:	11073503          	ld	a0,272(a4)
   10538:	000680e7          	jalr	a3
   1053c:	f71ff06f          	j	104ac <__call_exitprocs+0xdc>
   10540:	000b3783          	ld	a5,0(s6)
   10544:	000b0d13          	mv	s10,s6
   10548:	00078b13          	mv	s6,a5
   1054c:	ee0b10e3          	bnez	s6,1042c <__call_exitprocs+0x5c>
   10550:	f9dff06f          	j	104ec <__call_exitprocs+0x11c>
   10554:	00000793          	li	a5,0
   10558:	fedff06f          	j	10544 <__call_exitprocs+0x174>

000000000001055c <__syscall_error>:
   1055c:	ff010113          	addi	sp,sp,-16
   10560:	00113423          	sd	ra,8(sp)
   10564:	00813023          	sd	s0,0(sp)
   10568:	00050413          	mv	s0,a0
   1056c:	3c8000ef          	jal	10934 <__errno>
   10570:	00813083          	ld	ra,8(sp)
   10574:	408007bb          	negw	a5,s0
   10578:	00f52023          	sw	a5,0(a0)
   1057c:	00013403          	ld	s0,0(sp)
   10580:	fff00513          	li	a0,-1
   10584:	01010113          	addi	sp,sp,16
   10588:	00008067          	ret

000000000001058c <open>:
   1058c:	00000693          	li	a3,0
   10590:	40000893          	li	a7,1024
   10594:	00000073          	ecall
   10598:	fc0542e3          	bltz	a0,1055c <__syscall_error>
   1059c:	0005051b          	sext.w	a0,a0
   105a0:	00008067          	ret

00000000000105a4 <openat>:
   105a4:	03800893          	li	a7,56
   105a8:	00000073          	ecall
   105ac:	fa0548e3          	bltz	a0,1055c <__syscall_error>
   105b0:	0005051b          	sext.w	a0,a0
   105b4:	00008067          	ret

00000000000105b8 <lseek>:
   105b8:	00000693          	li	a3,0
   105bc:	03e00893          	li	a7,62
   105c0:	00000073          	ecall
   105c4:	f8054ce3          	bltz	a0,1055c <__syscall_error>
   105c8:	00008067          	ret

00000000000105cc <read>:
   105cc:	00000693          	li	a3,0
   105d0:	03f00893          	li	a7,63
   105d4:	00000073          	ecall
   105d8:	f80542e3          	bltz	a0,1055c <__syscall_error>
   105dc:	0005051b          	sext.w	a0,a0
   105e0:	00008067          	ret

00000000000105e4 <write>:
   105e4:	00000693          	li	a3,0
   105e8:	04000893          	li	a7,64
   105ec:	00000073          	ecall
   105f0:	f60546e3          	bltz	a0,1055c <__syscall_error>
   105f4:	0005051b          	sext.w	a0,a0
   105f8:	00008067          	ret

00000000000105fc <fstat>:
   105fc:	00000613          	li	a2,0
   10600:	00000693          	li	a3,0
   10604:	05000893          	li	a7,80
   10608:	00000073          	ecall
   1060c:	f40548e3          	bltz	a0,1055c <__syscall_error>
   10610:	0005051b          	sext.w	a0,a0
   10614:	00008067          	ret

0000000000010618 <stat>:
   10618:	00000613          	li	a2,0
   1061c:	00000693          	li	a3,0
   10620:	40e00893          	li	a7,1038
   10624:	00000073          	ecall
   10628:	f2054ae3          	bltz	a0,1055c <__syscall_error>
   1062c:	0005051b          	sext.w	a0,a0
   10630:	00008067          	ret

0000000000010634 <lstat>:
   10634:	00000613          	li	a2,0
   10638:	00000693          	li	a3,0
   1063c:	40f00893          	li	a7,1039
   10640:	00000073          	ecall
   10644:	f0054ce3          	bltz	a0,1055c <__syscall_error>
   10648:	0005051b          	sext.w	a0,a0
   1064c:	00008067          	ret

0000000000010650 <fstatat>:
   10650:	04f00893          	li	a7,79
   10654:	00000073          	ecall
   10658:	f00542e3          	bltz	a0,1055c <__syscall_error>
   1065c:	0005051b          	sext.w	a0,a0
   10660:	00008067          	ret

0000000000010664 <access>:
   10664:	00000613          	li	a2,0
   10668:	00000693          	li	a3,0
   1066c:	40900893          	li	a7,1033
   10670:	00000073          	ecall
   10674:	ee0544e3          	bltz	a0,1055c <__syscall_error>
   10678:	0005051b          	sext.w	a0,a0
   1067c:	00008067          	ret

0000000000010680 <faccessat>:
   10680:	03000893          	li	a7,48
   10684:	00000073          	ecall
   10688:	ec054ae3          	bltz	a0,1055c <__syscall_error>
   1068c:	0005051b          	sext.w	a0,a0
   10690:	00008067          	ret

0000000000010694 <close>:
   10694:	00000593          	li	a1,0
   10698:	00000613          	li	a2,0
   1069c:	00000693          	li	a3,0
   106a0:	03900893          	li	a7,57
   106a4:	00000073          	ecall
   106a8:	ea054ae3          	bltz	a0,1055c <__syscall_error>
   106ac:	0005051b          	sext.w	a0,a0
   106b0:	00008067          	ret

00000000000106b4 <link>:
   106b4:	00000613          	li	a2,0
   106b8:	00000693          	li	a3,0
   106bc:	40100893          	li	a7,1025
   106c0:	00000073          	ecall
   106c4:	e8054ce3          	bltz	a0,1055c <__syscall_error>
   106c8:	0005051b          	sext.w	a0,a0
   106cc:	00008067          	ret

00000000000106d0 <unlink>:
   106d0:	00000593          	li	a1,0
   106d4:	00000613          	li	a2,0
   106d8:	00000693          	li	a3,0
   106dc:	40200893          	li	a7,1026
   106e0:	00000073          	ecall
   106e4:	e6054ce3          	bltz	a0,1055c <__syscall_error>
   106e8:	0005051b          	sext.w	a0,a0
   106ec:	00008067          	ret

00000000000106f0 <execve>:
   106f0:	ff010113          	addi	sp,sp,-16
   106f4:	00113423          	sd	ra,8(sp)
   106f8:	23c000ef          	jal	10934 <__errno>
   106fc:	00813083          	ld	ra,8(sp)
   10700:	00c00793          	li	a5,12
   10704:	00f52023          	sw	a5,0(a0)
   10708:	01010113          	addi	sp,sp,16
   1070c:	fff00513          	li	a0,-1
   10710:	00008067          	ret

0000000000010714 <fork>:
   10714:	ff010113          	addi	sp,sp,-16
   10718:	00113423          	sd	ra,8(sp)
   1071c:	218000ef          	jal	10934 <__errno>
   10720:	00813083          	ld	ra,8(sp)
   10724:	00b00793          	li	a5,11
   10728:	00f52023          	sw	a5,0(a0)
   1072c:	01010113          	addi	sp,sp,16
   10730:	fff00513          	li	a0,-1
   10734:	00008067          	ret

0000000000010738 <getpid>:
   10738:	00100513          	li	a0,1
   1073c:	00008067          	ret

0000000000010740 <kill>:
   10740:	ff010113          	addi	sp,sp,-16
   10744:	00113423          	sd	ra,8(sp)
   10748:	1ec000ef          	jal	10934 <__errno>
   1074c:	00813083          	ld	ra,8(sp)
   10750:	01600793          	li	a5,22
   10754:	00f52023          	sw	a5,0(a0)
   10758:	01010113          	addi	sp,sp,16
   1075c:	fff00513          	li	a0,-1
   10760:	00008067          	ret

0000000000010764 <wait>:
   10764:	ff010113          	addi	sp,sp,-16
   10768:	00113423          	sd	ra,8(sp)
   1076c:	1c8000ef          	jal	10934 <__errno>
   10770:	00813083          	ld	ra,8(sp)
   10774:	00a00793          	li	a5,10
   10778:	00f52023          	sw	a5,0(a0)
   1077c:	01010113          	addi	sp,sp,16
   10780:	fff00513          	li	a0,-1
   10784:	00008067          	ret

0000000000010788 <isatty>:
   10788:	f8010113          	addi	sp,sp,-128
   1078c:	00010593          	mv	a1,sp
   10790:	00000613          	li	a2,0
   10794:	00000693          	li	a3,0
   10798:	05000893          	li	a7,80
   1079c:	00000073          	ecall
   107a0:	da054ee3          	bltz	a0,1055c <__syscall_error>
   107a4:	fff00793          	li	a5,-1
   107a8:	0005051b          	sext.w	a0,a0
   107ac:	00f50863          	beq	a0,a5,107bc <isatty+0x34>
   107b0:	01012503          	lw	a0,16(sp)
   107b4:	40d5551b          	sraiw	a0,a0,0xd
   107b8:	00157513          	andi	a0,a0,1
   107bc:	08010113          	addi	sp,sp,128
   107c0:	00008067          	ret

00000000000107c4 <times>:
   107c4:	85818293          	addi	t0,gp,-1960 # 11508 <t0.2273>
   107c8:	0002b703          	ld	a4,0(t0)
   107cc:	ff010113          	addi	sp,sp,-16
   107d0:	00050813          	mv	a6,a0
   107d4:	02071063          	bnez	a4,107f4 <times+0x30>
   107d8:	85818513          	addi	a0,gp,-1960 # 11508 <t0.2273>
   107dc:	00000593          	li	a1,0
   107e0:	00000613          	li	a2,0
   107e4:	00000693          	li	a3,0
   107e8:	0a900893          	li	a7,169
   107ec:	00000073          	ecall
   107f0:	d60546e3          	bltz	a0,1055c <__syscall_error>
   107f4:	00010513          	mv	a0,sp
   107f8:	00000593          	li	a1,0
   107fc:	00000613          	li	a2,0
   10800:	00000693          	li	a3,0
   10804:	0a900893          	li	a7,169
   10808:	00000073          	ecall
   1080c:	d40548e3          	bltz	a0,1055c <__syscall_error>
   10810:	0002b703          	ld	a4,0(t0)
   10814:	00013783          	ld	a5,0(sp)
   10818:	fff00513          	li	a0,-1
   1081c:	00083823          	sd	zero,16(a6)
   10820:	40e786b3          	sub	a3,a5,a4
   10824:	000f47b7          	lui	a5,0xf4
   10828:	24078793          	addi	a5,a5,576 # f4240 <_gp+0xe2590>
   1082c:	02f68733          	mul	a4,a3,a5
   10830:	0082b683          	ld	a3,8(t0)
   10834:	00813783          	ld	a5,8(sp)
   10838:	00083c23          	sd	zero,24(a6)
   1083c:	00083423          	sd	zero,8(a6)
   10840:	40d787b3          	sub	a5,a5,a3
   10844:	01010113          	addi	sp,sp,16
   10848:	00f707b3          	add	a5,a4,a5
   1084c:	00f83023          	sd	a5,0(a6)
   10850:	00008067          	ret

0000000000010854 <gettimeofday>:
   10854:	00000593          	li	a1,0
   10858:	00000613          	li	a2,0
   1085c:	00000693          	li	a3,0
   10860:	0a900893          	li	a7,169
   10864:	00000073          	ecall
   10868:	ce054ae3          	bltz	a0,1055c <__syscall_error>
   1086c:	0005051b          	sext.w	a0,a0
   10870:	00008067          	ret

0000000000010874 <ftime>:
   10874:	00051423          	sh	zero,8(a0)
   10878:	00053023          	sd	zero,0(a0)
   1087c:	00000513          	li	a0,0
   10880:	00008067          	ret

0000000000010884 <utime>:
   10884:	fff00513          	li	a0,-1
   10888:	00008067          	ret

000000000001088c <chown>:
   1088c:	fff00513          	li	a0,-1
   10890:	00008067          	ret

0000000000010894 <chmod>:
   10894:	fff00513          	li	a0,-1
   10898:	00008067          	ret

000000000001089c <chdir>:
   1089c:	fff00513          	li	a0,-1
   108a0:	00008067          	ret

00000000000108a4 <getcwd>:
   108a4:	00000513          	li	a0,0
   108a8:	00008067          	ret

00000000000108ac <sysconf>:
   108ac:	00200793          	li	a5,2
   108b0:	00f51863          	bne	a0,a5,108c0 <sysconf+0x14>
   108b4:	000f4537          	lui	a0,0xf4
   108b8:	24050513          	addi	a0,a0,576 # f4240 <_gp+0xe2590>
   108bc:	00008067          	ret
   108c0:	fff00513          	li	a0,-1
   108c4:	00008067          	ret

00000000000108c8 <sbrk>:
   108c8:	8181b703          	ld	a4,-2024(gp) # 114c8 <_fbss>
   108cc:	00050793          	mv	a5,a0
   108d0:	00071663          	bnez	a4,108dc <sbrk+0x14>
   108d4:	86818713          	addi	a4,gp,-1944 # 11518 <_end>
   108d8:	80e1bc23          	sd	a4,-2024(gp) # 114c8 <_fbss>
   108dc:	00e78533          	add	a0,a5,a4
   108e0:	00000593          	li	a1,0
   108e4:	00000613          	li	a2,0
   108e8:	00000693          	li	a3,0
   108ec:	0d600893          	li	a7,214
   108f0:	00000073          	ecall
   108f4:	c60544e3          	bltz	a0,1055c <__syscall_error>
   108f8:	8181b683          	ld	a3,-2024(gp) # 114c8 <_fbss>
   108fc:	fff00713          	li	a4,-1
   10900:	00d787b3          	add	a5,a5,a3
   10904:	00f51663          	bne	a0,a5,10910 <sbrk+0x48>
   10908:	80a1bc23          	sd	a0,-2024(gp) # 114c8 <_fbss>
   1090c:	00068713          	mv	a4,a3
   10910:	00070513          	mv	a0,a4
   10914:	00008067          	ret

0000000000010918 <_exit>:
   10918:	00000593          	li	a1,0
   1091c:	00000613          	li	a2,0
   10920:	00000693          	li	a3,0
   10924:	05d00893          	li	a7,93
   10928:	00000073          	ecall
   1092c:	c20548e3          	bltz	a0,1055c <__syscall_error>
   10930:	0000006f          	j	10930 <_exit+0x18>

0000000000010934 <__errno>:
   10934:	8101b503          	ld	a0,-2032(gp) # 114c0 <_impure_ptr>
   10938:	00008067          	ret
