#include "../include/headers.h"
#include "../include/file_oprs.h"
#include "../include/declarations.h"

int majorno;

static int __init initFunction(void)
{
    printk(KERN_INFO "Hello Kernel\n");

    majorno = register_chrdev(0, "mychardev", &fops);

    return 0;
}

module_init(initFunction);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Character Device Driver");