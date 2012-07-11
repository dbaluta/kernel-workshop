/**
 * Linux Kernel Development
 *
 * Kernel Activities
 * July 11, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "activities"


static int __init act_init(void)
{
	pr_info("Activities module loaded!\n");
	return 0;
}

static void __exit act_exit(void)
{
	pr_info("Activities module unloaded\n");
}

module_init(act_init);
module_exit(act_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Kernel Activities");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
