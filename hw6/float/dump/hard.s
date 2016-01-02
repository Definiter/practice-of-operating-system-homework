
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
  16:	d9 45 fc             	flds   -0x4(%rbp)
  19:	dd 1c 24             	fstpl  (%rsp)
  1c:	48 c7 c7 00 00 00 00 	mov    $0x0,%rdi
  23:	b8 00 00 00 00       	mov    $0x0,%eax
  28:	e8 00 00 00 00       	callq  2d <init_module+0x2d>
        return 0;
  2d:	b8 00 00 00 00       	mov    $0x0,%eax
}
  32:	c9                   	leaveq 
  33:	c3                   	retq   

0000000000000034 <cleanup_module>:

void cleanup_module(void)
{
  34:	e8 00 00 00 00       	callq  39 <cleanup_module+0x5>
  39:	55                   	push   %rbp
  3a:	48 89 e5             	mov    %rsp,%rbp
}
  3d:	5d                   	pop    %rbp
  3e:	c3                   	retq   
