#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static dev_t first; // Global variable for the first device number

static int __init mfcd_init(void) /* Constructor */
{
    int ret;

    printk(KERN_INFO "Hallo: mfcd registered");
    if ((ret = alloc_chrdev_region(&first, 0, 3, "Nishant")) < 0)
    {
        return ret;
    }
    printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));
    return 0;
}

static void __exit mfcd_exit(void) /* Destructor */
{
    unregister_chrdev_region(first, 3);
    printk(KERN_INFO "Tschuss: mfcd unregistered");
}

module_init(mfcd_init);
module_exit(mfcd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nishant  Pani");
MODULE_DESCRIPTION("My First Character Driver");
