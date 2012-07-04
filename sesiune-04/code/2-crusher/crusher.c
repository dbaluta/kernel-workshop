/**
 * Linux Kernel Development
 *
 * memory 'crusher' demo :)
 * July 05, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/list.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "crusher"

#define USE_BEFORE_INIT 1
#define USE_AFTER_FREE  2
#define CRUSH_MODE USE_AFTER_FREE

struct crush {
	int random_bits;
	struct list_head list;
};

noinline void use_before_init(void)
{
	struct crush *c = kmalloc(sizeof(*c), GFP_KERNEL);
	pr_info("%s\n", __func__);

	list_del(&c->list);
}

noinline void use_after_free(void)
{
	struct crush *c = kmalloc(sizeof(*c), GFP_KERNEL);
	pr_info("%s\n", __func__);
	kfree(c);
	list_del(&c->list);
}

static int __init crusher_init(void)
{
#if CRUSH_MODE==USE_BEFORE_INIT
	use_before_init();
#endif

#if CRUSH_MODE==USE_AFTER_FREE
	use_after_free();
#endif
	pr_info("Yellow! ...crusher survied!\n");
	return 0;
}

static void __exit crusher_exit(void)
{
}

module_init(crusher_init);
module_exit(crusher_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Geeky Penguin");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
