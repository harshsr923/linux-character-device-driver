// cat /proc/devices | grep "<DEVNAME>" - diff from name given in Makefile
#ifndef DEVNAME
#define DEVNAME "scull"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 1
#endif

#define BUF_SIZE 1024

extern unsigned int majorno; // device driver number given by the kernel
extern unsigned int minorno;
extern dev_t device_no; // major + minor

typedef struct scull_qset{
    void **data;
    struct scull_qset *next;
}gs_scull_qset;

typedef struct scull_dev{
    struct scull_qset *data;
    struct cdev c_dev;
    // char data[BUF_SIZE]
}gs_scull_dev;

extern gs_scull_dev *ep_scull_dev;