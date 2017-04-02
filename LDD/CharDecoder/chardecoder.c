#include <asm/uaccess.h>

static char c;

static ssize_t my_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "Driver: read()\n");
    if (copy_to_user(buf, &c, 1) != 0)
        return -EFAULT;
    else
        return 1;
}
static ssize_t my_write(
        struct file *f, const char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "Driver: write()\n");
    if (copy_from_user(&c, buf + len – 1, 1) != 0)
        return -EFAULT;
    else
        return len;
}
