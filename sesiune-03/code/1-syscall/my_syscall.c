/**
 * Linux Kernel Development
 *
 * Syscall Demo
 * 04 July 2012
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/sched.h> 
#include <linux/utsname.h>

#define MODULE_VERS "1.0"
#define MODULE_NAME "my_syscall"
#define HOSTNAME_LEN 5

extern void *sys_call_table[];

/**
 * Syscall that changes the hostname
 * @param name: new hostname
 */
asmlinkage long my_syscall(char __user * name)
{
	char tmp[__NEW_UTS_LEN];
	struct new_utsname *u;

	memcpy(tmp, name, HOSTNAME_LEN);
	u = utsname();
	memcpy(u->nodename, tmp, HOSTNAME_LEN);
	memset(u->nodename + HOSTNAME_LEN, 0, sizeof(u->nodename) - HOSTNAME_LEN);

	return 0;
}
EXPORT_SYMBOL(my_syscall);

/**
 * Init module and insert my_syscall in the syscall table
 */
static int __init my_syscall_init(void)
{
	printk(KERN_INFO "[MySyscall] init module\n");
	sys_call_table[0] = my_syscall;
	return 0;
}

/**
 * Unload module
 */
static void __exit my_syscall_exit(void)
{
	sys_call_table[0] = NULL;
	printk(KERN_INFO "[MySyscall] unload module\n");
}

module_init(my_syscall_init);
module_exit(my_syscall_exit);

MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Linux Kernel Development - My Syscall");
MODULE_LICENSE("GPL");
MODULE_VERSION(MODULE_VERS);
