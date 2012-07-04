/**
 * Linux Kernel Development
 *
 * penguin memory leak demo
 * July 05, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "eat-stack"

void eat_stack(void)
{
}

static int __init eat_stack_init(void)
{
	eat_stack();
	return 0;
}

static void __exit eat_stack_exit(void)
{
}

module_init(eat_stack_init);
module_exit(eat_stack_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Stack size");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
