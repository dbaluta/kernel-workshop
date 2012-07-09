/**
 * Linux Kernel Development
 *
 * kmem cache API
 * July 09, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "cache"

struct penguin {
	char name[16];
	int age;
};


struct penguin *p;
struct kmem_cache *penguin_cachep;

static int __init cache_init(void)
{
	pr_info("kmem cache module loaded!\n");
	
	penguin_cachep = kmem_cache_create("penguin", 
				sizeof(struct penguin),
				ARCH_MIN_TASKALIGN,
				SLAB_PANIC | SLAB_NOTRACK,
				NULL);
	
	p = kmem_cache_alloc(penguin_cachep, GFP_KERNEL);
	if (!p) 
		return -ENOMEM;
	pr_info("Object penguin %p, successfully allocated from cache %p\n",
		p, penguin_cachep);

	return 0;
}

static void __exit cache_exit(void)
{
	pr_info("kmem cache module unloaded\n");
}

module_init(cache_init);
module_exit(cache_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - kmem cache API");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
