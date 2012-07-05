#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "simplet"

extern int myvar;

/**
 * Init module
 */
static int __init simplet_init(void)
{
	printk(KERN_INFO "[SimpleT] module loaded myvar=%i\n", myvar);
	myvar = 7;
	printk(KERN_INFO "[SimpleT] modified myvar=%i\n",  myvar);
	return 0;
}

/**
 * Unload module
 */
static void __exit simplet_exit(void)
{
	printk(KERN_INFO "[SimpleT] module unloaded\n");
}

module_init(simplet_init);
module_exit(simplet_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);

