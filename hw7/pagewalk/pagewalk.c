#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/mm.h>

extern int walk_page_range(unsigned long addr, unsigned long end,
	struct mm_walk *walk);

int print_pgd(pgd_t *pgd, unsigned long addr,
        unsigned long next, struct mm_walk *walk)
{
	printk(KERN_DEBUG "pgd_entry %lx @ %lx\n", *(unsigned long *)(pgd), addr);
	return 0;
}

int print_pud(pud_t *pud, unsigned long addr,
        unsigned long next, struct mm_walk *walk)
{
	printk(KERN_DEBUG "pud_entry %lx @ %lx\n", *(unsigned long *)(pud), addr);
	return 0;
}

int print_pmd(pmd_t *pmd, unsigned long addr,
        unsigned long next, struct mm_walk *walk)
{
	printk(KERN_DEBUG "pmd_entry %lx @ %lx\n", *(unsigned long *)(pmd), addr);
	return 0;
}

int print_pte(pte_t *pte, unsigned long addr,
        unsigned long next, struct mm_walk *walk)
{
	printk(KERN_DEBUG "pte_entry %lx @ %lx\n", *(unsigned long *)(pte), addr);
	return 0;
}

static int pid = 1;
module_param(pid, int, 0644);

static struct mm_walk walk;

int init_module(void)
{
	struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
	walk.pgd_entry = print_pgd;
	walk.pud_entry = print_pud;
	walk.pmd_entry = print_pmd;
	walk.pte_entry = print_pte;
	walk.mm = task->mm;
	walk_page_range(0, 0x7fffffffffff, &walk);	
        return 0;
}

void cleanup_module(void)
{
}

MODULE_LICENSE("GPL");
