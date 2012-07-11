/*
 * Linux Kernel Development 
 *
 * kbd IRQ
 * July 11, 2012 
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/slab.h>

MODULE_DESCRIPTION("Simple kbd demo");
MODULE_AUTHOR("Student");
MODULE_LICENSE("GPL");

#define MODULE_NAME		"kbd"

#define I8042_KBD_IRQ		1
#define I8042_STATUS_REG	0x64
#define I8042_DATA_REG		0x60

#define SCANCODE_RELEASED_MASK	0x80


/**
 * is_key_press() -- checks if a scancode corresponds to a key press or releaase
 *
 * scancode - value read from the DATA register
 * returns non-zero for a key press and 0 otherwise
 */
static int is_key_press(int scancode)
{
	return !(scancode & SCANCODE_RELEASED_MASK);
}

/**
 * get_ascii() -- returns the character of the given scancode
 * Only works for alfanumeric/space/enter; returns '?' for other chars.
 *
 * scancode - value read from the DATA register
 */
static char get_ascii(int scancode)
{
	static char *row1 = "1234567890";
	static char *row2 = "qwertyuiop";
	static char *row3 = "asdfghjkl";
	static char *row4 = "zxcvbnm";

	scancode &= ~SCANCODE_RELEASED_MASK;
	if (scancode >= 0x02 && scancode <= 0x0b)
		return *(row1 + scancode - 0x02);
	if (scancode >= 0x10 && scancode <= 0x19)
		return *(row2 + scancode - 0x10);
	if (scancode >= 0x1e && scancode <= 0x26)
		return *(row3 + scancode - 0x1e);
	if (scancode >= 0x2c && scancode <= 0x32)
		return *(row4 + scancode - 0x2c);
	if (scancode == 0x39)
		return ' ';
	if (scancode == 0x1c)
		return '\n';
	return '?';
}

/**
 * i8042_read_data() -- returns the value of the DATA register
 */
static u8 i8042_read_data(void)
{
	u8 val;
	/* TODO 3: read DATA register (8 bits) */
	val = 0;
	return val;
}

/* TODO 2: implement interrupt handler */
irqreturn_t so2_kbd_interrupt_handle(int irq_no, void *dev_id);


static int kbd_init(void)
{
	/* TODO 1: request IRQ */

	
	pr_info("Driver %s loaded\n", MODULE_NAME);
	return 0;

}

static void kbd_exit(void)
{

	/* TODO 1: free IRQ */

	pr_info("Driver %s unloaded\n", MODULE_NAME);
}

module_init(kbd_init);
module_exit(kbd_exit);

