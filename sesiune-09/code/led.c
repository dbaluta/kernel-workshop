#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
 
MODULE_DESCRIPTION("Led module");
MODULE_AUTHOR("Rosedu");
MODULE_LICENSE("GPL");
 
static int __init init(void)
{
	printk(KERN_ALERT "Hello!\n");
 
	return 0;
}
 
 
static void exit(void)
{
	printk(KERN_ALERT "Goodbye!\n");
}
 
 
module_init(init);
module_exit(exit);
