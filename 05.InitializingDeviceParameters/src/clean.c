#include "headers.h"
#include "declarations.h"

static void __exit exitFunction(void)
{
    printk_log("Goodbye Kernel");
    cdev_del(&ep_scull_dev->c_dev);
    kfree(ep_scull_dev);
    unregister_chrdev_region(device_no, NOD);
}

module_exit(exitFunction); // exitpoint