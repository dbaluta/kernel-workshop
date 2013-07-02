#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/utsname.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");
extern void *sys_call_table[];

asmlinkage long my_syscall()
{
	printk(KERN_INFO "[MySyscall] Did somebody call?\n");
	return 0;
}
EXPORT_SYMBOL(my_syscall);

static int __init my_syscall_init(void)
{
	printk(KERN_INFO "[MySyscall] init module\n");
	sys_call_table[0] = my_syscall;
	return 0;
}

static void __exit my_syscall_exit(void)
{
	sys_call_table[0] = NULL;
	printk(KERN_INFO "[MySyscall] unload module\n");
}

module_init(my_syscall_init);
module_exit(my_syscall_exit);
