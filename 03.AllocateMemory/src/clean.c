#include "headers.h"
#include "declarations.h"

static void __exit exitFunction(void)
{
    printk(KERN_INFO "Goodbye Kernel\n");
    kfree(scull_dev);
    unregister_chrdev_region(device_no, NOD);
}

module_exit(exitFunction); // exitpoint