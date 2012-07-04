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
#define MODULE_NAME "penguin"


struct penguin {
	int age;
	int weight;
	char name[64];
};


struct penguin *p;

noinline struct penguin* create_penguin(void)
{
	return kmalloc(sizeof(*p), GFP_KERNEL);
}

static int __init penguin_init(void)
{
	p = create_penguin();
	if (p)
		pr_info("Penguing is alive!\n");
	return 0;
}

static void __exit penguin_exit(void)
{
}

module_init(penguin_init);
module_exit(penguin_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Geeky Penguin");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
