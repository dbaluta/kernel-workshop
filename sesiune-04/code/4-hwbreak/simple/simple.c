#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "simple"

int myvar = 3;
EXPORT_SYMBOL(myvar);

/**
 * Init module
 */
static int __init simple_init(void)
{
	printk(KERN_INFO "[Simple] module loaded with myvar=%i\n", myvar);
	return 0;
}

/**
 * Unload module
 */
static void __exit simple_exit(void)
{
	printk(KERN_INFO "[Simple] module unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);

