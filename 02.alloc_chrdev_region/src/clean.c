#include "../include/headers.h"
#include "../include/declarations.h"

static void __exit exitFunction(void)
{
    printk(KERN_INFO "Goodbye Kernel\n");

    // dev_t : device type data structure
    // unsigned : consecutive device to be released
    // extern void unregister_chrdev_region(dev_t, unsigned);

    unregister_chrdev_region(device_no, NOD);
}

module_exit(exitFunction); // exitpoint