/**
 * Linux Kernel Development
 *
 * Procfs Demo
 * 04 July 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <linux/proc_fs.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "MYPROC"

/** Procfs directory */
static struct proc_dir_entry* mproc_pde;
/** Procfs file */
static struct proc_dir_entry* entry;

static int myproc_read(char* page, char** start, off_t off,
		int count, int* eof, void* data)
{
	int written = 0;

	//TODO: print the pid of the current process instead of the string
	written = sprintf(page, "var = %s\n", "Insert pid here :)\n");
	*start = page+off;
	if(strlen(page) == written)
		*eof = 1;

	printk(KERN_INFO "[Myproc] myproc_read done.\n");
	return written-off;
}

/**
 * Init module and create /proc/myproc/fis file
 */
static int __init myproc_init(void)
{
	mproc_pde = proc_mkdir("myproc", NULL);
	if(!mproc_pde)
	{
		printk(KERN_ERR "%s: error creating proc_dir_entry!\n", MODULE_NAME);
		goto err;
	}
	printk(KERN_INFO "[Myproc] proc dir created\n");

	entry = create_proc_entry("fis", 0444, mproc_pde);
	if(!entry)
	{
		printk(KERN_ERR "%s: error creating proc_entry!\n", MODULE_NAME);
		goto err_dir;
	}

	entry->data = NULL;
	entry->read_proc = myproc_read;
	entry->write_proc = NULL;
	printk(KERN_INFO "[Myproc] proc entry created\n");

	printk(KERN_INFO "[Myproc] module loaded\n");
	return 0;

err_dir:
	remove_proc_entry("myproc", NULL);
	printk(KERN_INFO "[Myproc] proc dir removed\n");
err:
	return -1;
}

/**
 * Unload module and delete /proc/myproc/fis file
 */
static void __exit myproc_exit(void)
{
	remove_proc_entry("fis", mproc_pde);
	printk(KERN_INFO "[Myproc] proc entry removed\n");

	remove_proc_entry("myproc", NULL);
	printk(KERN_INFO "[Myproc] proc dir removed\n");

	printk(KERN_INFO "[Myproc] module unloaded\n");
}

module_init(myproc_init);
module_exit(myproc_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - My Proc");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
