/**
 * Linux Kernel Development
 *
 * sleeping curse - GFP_ATOMIc vs GFP_KERNEL
 * July 09, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "context"

static int __init context_init(void)
{
	pr_info("context module loaded!\n");
	//TODO1: init spinlock
	
	//TODO2: grab spinlock
	
	//TODO3: allocate memory using GFP_ATOMIC or GFP_KERNEL
	
	//TODO4: release spinlock
	return 0;
}

static void __exit context_exit(void)
{
	pr_info("context module unloaded\n");
}

module_init(context_init);
module_exit(context_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - context module");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
