#include <linux/init.h>
#include <linux/module.h>
#include <asm/msr.h>

struct CACHE_NODE
{
	long long i_qword[4];
	unsigned int i_tag_lru_v;
	long long d_qword[4];
	unsigned int d_tag_lru_v;
};
struct CACHE_NODE node[1 << 9];

int init_module()
{
	int i, j;
	int low, high;
	long long tmp;

	/* dump icache */
	unsigned int i_config = 0x1700;
	unsigned int i_index = 0x1710;
	unsigned int i_data = 0x1711;
	unsigned int i_tag_inc = 0x1713;

	rdmsr(i_config, low, high);
	low = (0xf << 12) | low;
	wrmsr(i_config, low, high);
	for (i = 0;i < (1 << 9); i++) {
		rdmsr(i_index, low, high);
		low = high = 0;
		wrmsr(i_index, low, high);
		
		for (j=0;j<4;j++) {
			rdmsr(i_data, low, high);
			tmp = high;
			node[i].i_qword[j] = low + (tmp << 32);
		}
		
		rdmsr(i_tag_inc, low, high);
		node[i].i_tag_lru_v = low;
	}
	rdmsr(i_config, low, high);
	low = (~(0xf << 12)) & low;
	wrmsr(i_config, low, high);
	
	/* dump dcache */
	unsigned int d_config = 0x1800;
	unsigned int d_index = 0x1890;
	unsigned int d_data = 0x1891;
	unsigned int d_tag_inc = 0x1893;
	
	rdmsr(d_config, low, high);
	low = (0xf << 16) | low;
	wrmsr(d_config, low, high);
	for (i = 0; i < (1 << 9); i++)
	{
		rdmsr(d_index, low, high);
		low = high = 0;
		wrmsr(d_index, low, high);
		
		for (j = 0; j < 4; j++) {
			rdmsr(d_data, low, high);
			tmp = high;
			node[i].d_qword[j] = low + (tmp << 32);
		}
		
		rdmsr(d_tag_inc, low, high);
		node[i].d_tag_lru_v = low;
	}
	rdmsr(d_config, low, high);
	low = (~(0xf << 16)) & low;
	wrmsr(d_config, low, high);

	/* output icache content */
	printk("icache content:\n");
	for (i = 0; i < (1 << 9); i++) {
		for (j = 0; j < 4; j++) {
			printk("%p ", node[i].i_qword[j]);
		}
		printk("\n");
	}

	/* output dcache content */
	printk("dcache content:\n");
	for (i = 0; i < (1 << 9); i++) {
		for (j = 0; j < 4; j++) {
			printk("%p ", node[i].d_qword[j]);
		}
		printk("\n");
	}
	return 0;
}

void cleanup_module()
{
}
