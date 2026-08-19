#include "../include/headers.h"
#include "../include/declarations.h"
#include "../include/file_oprs.h"

int majorno; // range 1-255

static int __init initFunction(void)
{
    printk(KERN_INFO "Hello Kernel\n");

    // register_chrdev insert entry in Device Table - majorno, minorno, devicename and file_operations 
    // static inline int register_chrdev(unsigned int major, const char *name, const struct file_operations *fops)
    majorno = register_chrdev(MAJORNO, DEVNAME, &fops); // majorno: 0 - kernel will choose available major number

    if (majorno == -1)
    {
        printk(KERN_ERR "ERROR register_chrdev() failed\n");
        return -1;
    }
    printk(KERN_INFO "majorno : %d\n", majorno);
    return 0;
}

module_init(initFunction); // entrypoint macro

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Character Device Driver");