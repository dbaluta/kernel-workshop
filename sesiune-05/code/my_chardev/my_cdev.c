/*
    ROSEdu Workshops - Kernel Dev
    July 2013
*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/wait.h>

MODULE_DESCRIPTION("Simple charater device driver");
MODULE_AUTHOR("Kernel H4x00r");
MODULE_LICENSE("GPL");

#define LOG_LEVEL	KERN_DEBUG

#define MY_MAJOR		42
#define START_MINOR		0
#define NUM_MINORS		1
#define MODULE_NAME		"my_cdev"
#define MESSAGE			"hello\n"

#define BUFSIZE			4096

/* TODO 0: Describe device information and initate it*/
/*
struct my_device_data {
	struct cdev cdev;
	char buffer[BUFSIZE];
	size_t size;
};

struct my_device_data dev;

*/

static int my_cdev_open(struct inode *inode, struct file *file)
{
	printk(LOG_LEVEL "[my_cdev] Open\n");
	/* TODO 5: implement open handler. */
	/*
	struct my_device_data *data =
		container_of(inode->i_cdev, struct my_device_data, cdev);

	file->private_data = data;
	*/
	return 0;
}

static int my_cdev_release(struct inode *inode, struct file *file)
{
	printk(LOG_LEVEL "[my_cdev] Release\n");
	return 0;
}

static ssize_t my_cdev_read(struct file *file, char __user *user_buffer,
		size_t size, loff_t *offset)
{
	printk(LOG_LEVEL "[my_cdev] Read %d bytes\n", size);
	size_t to_read = 0;
	/* TODO 6: implement read handler. */
	/*
	struct my_device_data *data =
		(struct my_device_data *) file->private_data;


	to_read = (size > data->size - *offset) ? (data->size - *offset) : size;
	if (copy_to_user(user_buffer, data->buffer + *offset, to_read) != 0)
		return -EFAULT;
	*offset += to_read;
	*/
	return to_read;
}

static ssize_t my_cdev_write(struct file *file, const char __user *user_buffer,
		size_t size, loff_t *offset)
{
	printk(LOG_LEVEL "[my_cdev] Wirte %d bytes\n", size);
	/* TODO 7: implement write handler. */
	/*
	struct my_device_data *data =
		(struct my_device_data *) file->private_data;

	size = (*offset + size > BUFSIZE) ? (BUFSIZE - *offset) : size;

	if (copy_from_user(data->buffer + *offset, user_buffer, size) != 0)
		return -EFAULT;
	*offset += size;
	data->size = *offset;
	*/
	return size;
}

static long my_cdev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	printk(LOG_LEVEL "[my_cdev] IOCTL\n");
	return 0;
}


/* TODO 3a: associate file operations with device.*/
/*
static const struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.open = my_cdev_open,
	.release = my_cdev_release,
	.read = my_cdev_read,
	.write = my_cdev_write,
	.unlocked_ioctl = my_cdev_ioctl,
};
*/

static int my_cdev_init(void)
{
	int err;

	printk(LOG_LEVEL "[my_cdev] module init\n");
	/* TODO 1a: Register major/minor(s) to device driver. */
	/*
	err = register_chrdev_region(MKDEV(MY_MAJOR, START_MINOR),
			NUM_MINORS, MODULE_NAME);
	if (err != 0) {
		printk(KERN_ERR "register_chrdev_region");
		return err;
	}
	*/

	/* TODO 2: fill in device specific information.*/
	/*
	dev.size = sizeof MESSAGE;
	memcpy(dev.buffer, MESSAGE, sizeof MESSAGE);
	*/

	/* TODO 3b: associate file operations with device.*/
	/*
	cdev_init(&dev.cdev, &my_fops);
	*/

	/* TODO 4a: add char device.*/
	/*
	cdev_add(&dev.cdev, MKDEV(MY_MAJOR, START_MINOR), NUM_MINORS);
	*/

	return 0;
}

static void my_cdev_exit(void)
{
	/* TODO 4b: Remove char device.*/
	/*
	cdev_del(&dev.cdev);
	*/

	/* TODO 1b: Unregister major/minor(s) from device driver. */
	/*
	unregister_chrdev_region(MKDEV(MY_MAJOR, START_MINOR), NUM_MINORS);
	*/
	printk(LOG_LEVEL "[my_cdev] module exit\n");
}

module_init(my_cdev_init);
module_exit(my_cdev_exit);

