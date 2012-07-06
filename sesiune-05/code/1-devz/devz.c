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

#define Z_MAJOR 42
#define Z_MINOR 0


/**
 * define file operations struct to implement
 * open and read operations
 */

static int __init devz_init(void)
{
	/* register_chrdev_region */
	
	/* init and add the cdev structure - cdev_init, cdev_add */
	
	
	return 0;
}

static void __exit devz_exit(void)
{
	/* delete cdev structure - cdev_del */
	
	/* unregister_chrdev_region */
}

module_init(devz_init);
module_exit(devz_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - Z device");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
