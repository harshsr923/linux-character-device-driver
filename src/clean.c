#include "../include/headers.h"
#include "../include/declarations.h"

static void __exit exitFunction(void)
{
    unregister_chrdev(majorno, "mychardev");

    printk(KERN_INFO "Goodbye Kernel\n");
}

module_exit(exitFunction);