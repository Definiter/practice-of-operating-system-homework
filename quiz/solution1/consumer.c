#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module, */
#include <linux/moduleparam.h>	/* which will have params */
#include <linux/unistd.h>	/* The list of system calls */
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/random.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>

#define ST_LEN 100

/* Import queue from producer.c. */
extern char **queue;
extern int queue_head;
extern int queue_tail;
extern int queue_size;

/* Import spinlock from producer.c. */
extern spinlock_t lock;

/* kthread task struct */
static struct task_struct *task;

static int consumer(void *data)
{
	int sleep;
	int count = 0;
	s64 ns_before, ns_after;
	struct timeval tv;

	while (1) {
		/* Prepare for sleeping. */
		do_gettimeofday(&tv);
		ns_before = timeval_to_ns(&tv);
		sleep = 1000;

		if (kthread_should_stop())
			break;

		/* critical area */
		spin_lock(&lock);
		if (queue_head != queue_tail) {
			printk(KERN_INFO "%s", queue[queue_head]);
			queue_head = (queue_head + 1) % queue_size;
			count++;
		}
		printk(KERN_INFO "Consumer receives %d th message. queue[%d..%d]\n", 
			count, queue_head, queue_tail);
		spin_unlock(&lock);

		/* Sleep for random time. */
		do_gettimeofday(&tv);
		ns_after = timeval_to_ns(&tv);
		usleep_range(sleep * 1000 - (ns_after - ns_before) / 1000 - 10,
			sleep * 1000 - (ns_after - ns_before) / 1000 + 10);
	}
	return 0;
}

/* 
 * Initialize the module - replace the system call 
 */
int init_module()
{
	printk(KERN_INFO "Consumer kthread starts.");
	task = kthread_run(&consumer, NULL, "consumer");
	return 0;
}

/* 
 * Cleanup - unregister the appropriate file from /proc 
 */
void cleanup_module()
{
	printk(KERN_INFO "Consumer kthread stops.");
	kthread_stop(task);
}

