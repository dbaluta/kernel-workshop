/**
 * Linux Kernel Development
 *
 * Seq Operations Demo
 * 04 July 2012
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <linux/pid_namespace.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

#define PROC_NAME	"mytop"

/**
 * Gets module parameters
 */
int mypid;
module_param(mypid, int, 0);

/**
 * Called at the beginning of a sequence.
 * the /proc file is read for the first time or
 * after the function stop
 */
static void *my_seq_start(struct seq_file *s, loff_t *pos)
{
	static unsigned long counter = 0;

	if (*pos == 0) //start sequence
		return &counter;

	else { //end sequence
		*pos = 0;
		return NULL;
	}
}

/**
 * Called after the beginning of a sequence.
 * Called until returns NULL (end of seq).
 *
 */
static void *my_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
	(*(unsigned long *)v)++;
	(*pos)++;
	return NULL;
}

/**
 * Called at the end of a sequence
 */
static void my_seq_stop(struct seq_file *s, void *v)
{
}

/**
 * Called at each "step" of a sequence
 */
static int my_seq_show(struct seq_file *s, void *v)
{
	struct task_struct *task;

	seq_printf(s, "Time count: %Ld\n\n", *(loff_t *)v);
	seq_printf(s, "%s\n", "Pid    Comm   Nice");

	rcu_read_lock();
	for_each_process(task) {
		task_lock(task);

		//TODO: replace "1 comm 1" with the task's "pid name nice"
		if (task->pid == mypid)
			seq_printf(s, "%-6d %-6s %-d\n", 1, "comm", 1);

		task_unlock(task);
	}
	rcu_read_unlock();

	return 0;
}

/**
 * Functions that manage the sequence
 */
static struct seq_operations my_seq_ops = {
	.start = my_seq_start,
	.next  = my_seq_next,
	.stop  = my_seq_stop,
	.show  = my_seq_show
};

/**
 * Called when the /proc file is opened.
 */
static int my_open(struct inode *inode, struct file *file)
{
	return seq_open(file, &my_seq_ops);
};

/**
 * Functions that manage the /proc file
 */
static struct file_operations my_file_ops = {
	.owner   = THIS_MODULE,
	.open    = my_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = seq_release
};

/**
 * Init module and create /proc/mytop file
 */
int init_module(void)
{
	struct proc_dir_entry *entry;

	entry = create_proc_entry(PROC_NAME, 0, NULL);
	if (entry)
		entry->proc_fops = &my_file_ops;

	return 0;
}

/**
 * Unload module and delete /proc/mytop file
 */
void cleanup_module(void)
{
	remove_proc_entry(PROC_NAME, NULL);
}

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Seq Demo");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
