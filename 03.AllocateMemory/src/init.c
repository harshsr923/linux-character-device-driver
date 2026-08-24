#include "headers.h"
#include "declarations.h"
// #include "file_oprs.h"

unsigned int majorno;
unsigned int minorno;
dev_t device_no;
gs_scull_dev *scull_dev;

static int __init initFunction(void)
{
    printk(KERN_INFO "Hello Kernel\n");

    // extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
    int ret =  alloc_chrdev_region(&device_no, 0, NOD, DEVNAME); 
    if (ret < 0)
    {
        printk(KERN_ERR "ERROR: alloc_chrdev_region() failed\n");
        return ret;
    }
    majorno = MAJOR(device_no);
    minorno = MINOR(device_no);

    printk(KERN_INFO "majorno : %d\n", majorno);
    printk(KERN_INFO "minorno : %d\n", minorno);

    scull_dev = kmalloc(NOD*sizeof(*scull_dev), GFP_KERNEL);
    if (!scull_dev)
    {
        printk(KERN_ERR "ERROR: kmalloc() failed\n");
        unregister_chrdev_region(device_no, NOD);
        return -ENOMEM;
    }

    return 0;
}

module_init(initFunction);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Character Device Driver");