#include "../include/headers.h"
#include "../include/declarations.h"
// #include "../include/file_oprs.h"

unsigned int majorno;
unsigned int minorno;
dev_t device_no;

static int __init initFunction(void)
{
    printk(KERN_INFO "Hello Kernel\n");

    // dev_t : device type data structure
    // unsigned : base_minorno
    // unsigned : pool of minorno
    // const char * : driver name
    
    // extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
    // return 0: SUCCESS -1 : FAILURE 
    int ret =  alloc_chrdev_region(&device_no, 0, NOD, DEVNAME); 
    if (ret == -1)
    {
        printk(KERN_ERR "ERROR: alloc_chrdev_region() failed\n");
        return -1;
    }
    majorno = MAJOR(device_no); // Extract 12 bit major number from devno convert into 32 bit int and return 
    minorno = MINOR(device_no); // Extract 20 bit major number from devno convert into 32 bit int and return

    printk(KERN_INFO "majorno : %d\n", majorno);
    printk(KERN_INFO "minorno : %d\n", minorno);
    return 0;
}

module_init(initFunction); // entrypoint macro

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Character Device Driver");