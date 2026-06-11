
bin:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 e1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fe1]        # 3ff0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 92 2f 00 00    	push   QWORD PTR [rip+0x2f92]        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 94 2f 00 00    	jmp    QWORD PTR [rip+0x2f94]        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	push   0x0
    1039:	e9 e2 ff ff ff       	jmp    1020 <_init+0x20>
    103e:	66 90                	xchg   ax,ax
    1040:	f3 0f 1e fa          	endbr64
    1044:	68 01 00 00 00       	push   0x1
    1049:	e9 d2 ff ff ff       	jmp    1020 <_init+0x20>
    104e:	66 90                	xchg   ax,ax

Disassembly of section .plt.got:

0000000000001050 <__cxa_finalize@plt>:
    1050:	f3 0f 1e fa          	endbr64
    1054:	ff 25 7e 2f 00 00    	jmp    QWORD PTR [rip+0x2f7e]        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    105a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

Disassembly of section .plt.sec:

0000000000001060 <__stack_chk_fail@plt>:
    1060:	f3 0f 1e fa          	endbr64
    1064:	ff 25 5e 2f 00 00    	jmp    QWORD PTR [rip+0x2f5e]        # 3fc8 <__stack_chk_fail@GLIBC_2.4>
    106a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000001070 <_ZNSo9_M_insertIdEERSoT_@plt>:
    1070:	f3 0f 1e fa          	endbr64
    1074:	ff 25 56 2f 00 00    	jmp    QWORD PTR [rip+0x2f56]        # 3fd0 <_ZNSo9_M_insertIdEERSoT_@GLIBCXX_3.4.9>
    107a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

0000000000001080 <main>:
    1080:	f3 0f 1e fa          	endbr64
    1084:	48 83 ec 08          	sub    rsp,0x8
    1088:	f2 0f 10 05 78 0f 00 	movsd  xmm0,QWORD PTR [rip+0xf78]        # 2008 <_IO_stdin_used+0x8>
    108f:	00 
    1090:	48 8d 3d a9 2f 00 00 	lea    rdi,[rip+0x2fa9]        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    1097:	e8 d4 ff ff ff       	call   1070 <_ZNSo9_M_insertIdEERSoT_@plt>
    109c:	31 c0                	xor    eax,eax
    109e:	48 83 c4 08          	add    rsp,0x8
    10a2:	c3                   	ret
    10a3:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    10aa:	00 00 00 
    10ad:	0f 1f 00             	nop    DWORD PTR [rax]

00000000000010b0 <_start>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	31 ed                	xor    ebp,ebp
    10b6:	49 89 d1             	mov    r9,rdx
    10b9:	5e                   	pop    rsi
    10ba:	48 89 e2             	mov    rdx,rsp
    10bd:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    10c1:	50                   	push   rax
    10c2:	54                   	push   rsp
    10c3:	45 31 c0             	xor    r8d,r8d
    10c6:	31 c9                	xor    ecx,ecx
    10c8:	48 8d 3d b1 ff ff ff 	lea    rdi,[rip+0xffffffffffffffb1]        # 1080 <main>
    10cf:	ff 15 0b 2f 00 00    	call   QWORD PTR [rip+0x2f0b]        # 3fe0 <__libc_start_main@GLIBC_2.34>
    10d5:	f4                   	hlt
    10d6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    10dd:	00 00 00 

00000000000010e0 <deregister_tm_clones>:
    10e0:	48 8d 3d 29 2f 00 00 	lea    rdi,[rip+0x2f29]        # 4010 <__TMC_END__>
    10e7:	48 8d 05 22 2f 00 00 	lea    rax,[rip+0x2f22]        # 4010 <__TMC_END__>
    10ee:	48 39 f8             	cmp    rax,rdi
    10f1:	74 15                	je     1108 <deregister_tm_clones+0x28>
    10f3:	48 8b 05 ee 2e 00 00 	mov    rax,QWORD PTR [rip+0x2eee]        # 3fe8 <_ITM_deregisterTMCloneTable@Base>
    10fa:	48 85 c0             	test   rax,rax
    10fd:	74 09                	je     1108 <deregister_tm_clones+0x28>
    10ff:	ff e0                	jmp    rax
    1101:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1108:	c3                   	ret
    1109:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001110 <register_tm_clones>:
    1110:	48 8d 3d f9 2e 00 00 	lea    rdi,[rip+0x2ef9]        # 4010 <__TMC_END__>
    1117:	48 8d 35 f2 2e 00 00 	lea    rsi,[rip+0x2ef2]        # 4010 <__TMC_END__>
    111e:	48 29 fe             	sub    rsi,rdi
    1121:	48 89 f0             	mov    rax,rsi
    1124:	48 c1 ee 3f          	shr    rsi,0x3f
    1128:	48 c1 f8 03          	sar    rax,0x3
    112c:	48 01 c6             	add    rsi,rax
    112f:	48 d1 fe             	sar    rsi,1
    1132:	74 14                	je     1148 <register_tm_clones+0x38>
    1134:	48 8b 05 bd 2e 00 00 	mov    rax,QWORD PTR [rip+0x2ebd]        # 3ff8 <_ITM_registerTMCloneTable@Base>
    113b:	48 85 c0             	test   rax,rax
    113e:	74 08                	je     1148 <register_tm_clones+0x38>
    1140:	ff e0                	jmp    rax
    1142:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1148:	c3                   	ret
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001150 <__do_global_dtors_aux>:
    1150:	f3 0f 1e fa          	endbr64
    1154:	80 3d f5 2f 00 00 00 	cmp    BYTE PTR [rip+0x2ff5],0x0        # 4150 <completed.0>
    115b:	75 2b                	jne    1188 <__do_global_dtors_aux+0x38>
    115d:	55                   	push   rbp
    115e:	48 83 3d 72 2e 00 00 	cmp    QWORD PTR [rip+0x2e72],0x0        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    1165:	00 
    1166:	48 89 e5             	mov    rbp,rsp
    1169:	74 0c                	je     1177 <__do_global_dtors_aux+0x27>
    116b:	48 8b 3d 96 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2e96]        # 4008 <__dso_handle>
    1172:	e8 d9 fe ff ff       	call   1050 <__cxa_finalize@plt>
    1177:	e8 64 ff ff ff       	call   10e0 <deregister_tm_clones>
    117c:	c6 05 cd 2f 00 00 01 	mov    BYTE PTR [rip+0x2fcd],0x1        # 4150 <completed.0>
    1183:	5d                   	pop    rbp
    1184:	c3                   	ret
    1185:	0f 1f 00             	nop    DWORD PTR [rax]
    1188:	c3                   	ret
    1189:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001190 <frame_dummy>:
    1190:	f3 0f 1e fa          	endbr64
    1194:	e9 77 ff ff ff       	jmp    1110 <register_tm_clones>
    1199:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000011a0 <_Z3miniz>:
    11a0:	f3 0f 1e fa          	endbr64
    11a4:	48 83 ec 58          	sub    rsp,0x58
    11a8:	4c 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],r9
    11ad:	4c 8d 4c 24 20       	lea    r9,[rsp+0x20]
    11b2:	48 89 74 24 28       	mov    QWORD PTR [rsp+0x28],rsi
    11b7:	48 89 54 24 30       	mov    QWORD PTR [rsp+0x30],rdx
    11bc:	48 89 4c 24 38       	mov    QWORD PTR [rsp+0x38],rcx
    11c1:	4c 89 44 24 40       	mov    QWORD PTR [rsp+0x40],r8
    11c6:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    11cd:	00 00 
    11cf:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    11d4:	48 8d 44 24 60       	lea    rax,[rsp+0x60]
    11d9:	4c 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],r9
    11de:	c7 04 24 10 00 00 00 	mov    DWORD PTR [rsp],0x10
    11e5:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    11ea:	41 8b 41 08          	mov    eax,DWORD PTR [r9+0x8]
    11ee:	85 ff                	test   edi,edi
    11f0:	7e 26                	jle    1218 <_Z3miniz+0x78>
    11f2:	b9 10 00 00 00       	mov    ecx,0x10
    11f7:	4c 8d 44 24 60       	lea    r8,[rsp+0x60]
    11fc:	31 d2                	xor    edx,edx
    11fe:	83 f9 2f             	cmp    ecx,0x2f
    1201:	77 2d                	ja     1230 <_Z3miniz+0x90>
    1203:	89 ce                	mov    esi,ecx
    1205:	83 c1 08             	add    ecx,0x8
    1208:	41 8b 34 31          	mov    esi,DWORD PTR [r9+rsi*1]
    120c:	39 f0                	cmp    eax,esi
    120e:	0f 4f c6             	cmovg  eax,esi
    1211:	83 c2 01             	add    edx,0x1
    1214:	39 d7                	cmp    edi,edx
    1216:	75 e6                	jne    11fe <_Z3miniz+0x5e>
    1218:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
    121d:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
    1224:	00 00 
    1226:	75 32                	jne    125a <_Z3miniz+0xba>
    1228:	48 83 c4 58          	add    rsp,0x58
    122c:	c3                   	ret
    122d:	0f 1f 00             	nop    DWORD PTR [rax]
    1230:	41 8b 30             	mov    esi,DWORD PTR [r8]
    1233:	49 8d 48 08          	lea    rcx,[r8+0x8]
    1237:	39 f0                	cmp    eax,esi
    1239:	0f 4f c6             	cmovg  eax,esi
    123c:	83 c2 01             	add    edx,0x1
    123f:	39 d7                	cmp    edi,edx
    1241:	74 d5                	je     1218 <_Z3miniz+0x78>
    1243:	48 89 ce             	mov    rsi,rcx
    1246:	48 83 c1 08          	add    rcx,0x8
    124a:	8b 36                	mov    esi,DWORD PTR [rsi]
    124c:	39 f0                	cmp    eax,esi
    124e:	0f 4f c6             	cmovg  eax,esi
    1251:	83 c2 01             	add    edx,0x1
    1254:	39 d7                	cmp    edi,edx
    1256:	7f eb                	jg     1243 <_Z3miniz+0xa3>
    1258:	eb be                	jmp    1218 <_Z3miniz+0x78>
    125a:	e8 01 fe ff ff       	call   1060 <__stack_chk_fail@plt>

Disassembly of section .fini:

0000000000001260 <_fini>:
    1260:	f3 0f 1e fa          	endbr64
    1264:	48 83 ec 08          	sub    rsp,0x8
    1268:	48 83 c4 08          	add    rsp,0x8
    126c:	c3                   	ret
