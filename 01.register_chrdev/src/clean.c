#include "headers.h"
#include "declarations.h"

static void __exit exitFunction(void)
{
    printk(KERN_INFO "Goodbye Kernel\n");

    // static inline void unregister_chrdev(unsigned int major, const char *name)
    unregister_chrdev(majorno, DEVNAME);
}

module_exit(exitFunction); // exitpoint