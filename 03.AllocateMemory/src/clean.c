#include "headers.h"
#include "declarations.h"

static void __exit exitFunction(void)
{
    printk(KERN_INFO "Goodbye Kernel\n");
    unregister_chrdev_region(device_no, NOD);
}

module_exit(exitFunction); // exitpoint