
float.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <init_module>:
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int init_module(void)
{
   0:	e8 00 00 00 00       	callq  5 <init_module+0x5>
   5:	55                   	push   %rbp
   6:	48 89 e5             	mov    %rsp,%rbp
   9:	48 83 ec 10          	sub    $0x10,%rsp
	float a = 2.718;
   d:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 13 <init_module+0x13>
  13:	89 45 fc             	mov    %eax,-0x4(%rbp)
	printk(KERN_INFO "float: %lf\n", a);
  16:	f3 0f 10 45 fc       	movss  -0x4(%rbp),%xmm0
  1b:	e8 00 00 00 00       	callq  20 <init_module+0x20>
  20:	48 c7 c7 00 00 00 00 	mov    $0x0,%rdi
  27:	b8 01 00 00 00       	mov    $0x1,%eax
  2c:	e8 00 00 00 00       	callq  31 <init_module+0x31>
        return 0;
  31:	b8 00 00 00 00       	mov    $0x0,%eax
}
  36:	c9                   	leaveq 
  37:	c3                   	retq   

0000000000000038 <cleanup_module>:

void cleanup_module(void)
{
  38:	e8 00 00 00 00       	callq  3d <cleanup_module+0x5>
  3d:	55                   	push   %rbp
  3e:	48 89 e5             	mov    %rsp,%rbp
}
  41:	5d                   	pop    %rbp
  42:	c3                   	retq   
