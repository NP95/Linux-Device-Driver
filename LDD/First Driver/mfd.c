/* mfd.c – My First Driver code */

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>

static int __init ofd_init(void) /* Constructor */
{
    printk(KERN_INFO "Hello: mfd registered");

    return 0;
}

static void __exit ofd_exit(void) /* Destructor */
{
    printk(KERN_INFO "Tschuss: mfd unregistered");
}

module_init(mfd_init);
module_exit(mfd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nishant Pani ");
MODULE_DESCRIPTION("");
