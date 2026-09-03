#include "headers.h"
#include "declarations.h"
#include "file_oprs.h"

unsigned int majorno;
unsigned int minorno;
unsigned int devSize, dataSize, regSize, nofReg;
dev_t device_no;
gs_scull_dev *ep_scull_dev;

module_param(devSize, uint, S_IRUGO);
module_param(regSize, uint, S_IRUGO);
module_param(nofReg, uint, S_IRUGO);

static int __init initFunction(void)
{
    printk_log("Hello Kernel");

    dataSize = DATASIZE;

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

    ep_scull_dev = kmalloc(NOD*sizeof(*ep_scull_dev), GFP_KERNEL);
    if (!ep_scull_dev)
    {
        printk(KERN_ERR "ERROR: kmalloc() failed\n");
        unregister_chrdev_region(device_no, NOD);
        return -ENOMEM;
    }
    memset(ep_scull_dev, '\0', sizeof(*ep_scull_dev));

    cdev_init(&ep_scull_dev->c_dev, &fops);

    ep_scull_dev->c_dev.ops = &fops;
    ep_scull_dev->dataSize = dataSize;
    ep_scull_dev->devSize = devSize;
    ep_scull_dev->regSize = regSize;
    ep_scull_dev->nofReg = nofReg;

    ret = cdev_add(&ep_scull_dev->c_dev, device_no, 1);
    if (ret < 0)
    {
        printk(KERN_ERR "ERROR: cdev_add() failed\n");
        return ret;
    }

    return 0;
}

module_init(initFunction);

MODULE_LICENSE("GPL"); // Open Source License
MODULE_DESCRIPTION("Linux Character Device Driver");