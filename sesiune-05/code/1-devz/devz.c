/**
 * Linux Kernel Development
 *
 * Z device - /devz
 * July 06, 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "devz"


static int __init devz_init(void)
{
	return 0;
}

static void __exit devz_exit(void)
{
}

module_init(devz_init);
module_exit(devz_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Z device");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
