/**
 * Linux Kernel Development
 *
 * kmalloc limits 
 * July 09, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "mem"


static int __init mem_init(void)
{
	pr_info("Mem module loaded!\n");
	return 0;
}

static void __exit mem_exit(void)
{
	pr_info("Mem module unloaded\n");
}

module_init(mem_init);
module_exit(mem_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - kmalloc limits");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
