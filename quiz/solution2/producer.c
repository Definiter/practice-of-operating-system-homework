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
#include <linux/mutex.h>
#include <linux/kthread.h>

#define ST_LEN 100
#define QUEUE_LEN 1000

char queue[QUEUE_LEN][ST_LEN]; // buffer
int queue_head;
int queue_tail;
int queue_size;

DEFINE_MUTEX(lock);

EXPORT_SYMBOL(queue);
EXPORT_SYMBOL(queue_head);
EXPORT_SYMBOL(queue_tail);
EXPORT_SYMBOL(queue_size);
EXPORT_SYMBOL(lock);

static struct task_struct *task;

static int producer(void *data)
{
	int sleep;
	int count = 0;
	s64 ns_before, ns_after;
	struct timeval tv;

	queue_size = QUEUE_LEN;
	queue_head = 0;
	queue_tail = 0;

	while (1) {
		do_gettimeofday(&tv);
		ns_before = timeval_to_ns(&tv);
		sleep = get_random_int() % 1000 + 1;

		if (kthread_should_stop())
			break;

		count++;

		/* critical area */
		mutex_lock(&lock);
		sprintf(queue[queue_tail], "%s (%d): count %d random %d\n",
			__func__, __LINE__, count, sleep);
		queue_tail = (queue_tail + 1) % queue_size;
		printk(KERN_INFO "Producer produces %d th message. queue[%d..%d]\n", 
			count, queue_head, queue_tail);
		mutex_unlock(&lock);

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
	printk(KERN_INFO "Producer kthread starts.");
	task = kthread_run(&producer, NULL, "producer");
	return 0;
}

/* 
 * Cleanup - unregister the appropriate file from /proc 
 */
void cleanup_module()
{
	printk(KERN_INFO "Producer kthread stops.");
	kthread_stop(task);
}

