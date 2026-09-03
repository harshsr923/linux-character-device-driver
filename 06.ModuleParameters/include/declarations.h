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

#ifndef DEVSIZE
#define DEVSIZE 1024
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef NOFREG
#define NOFREG 8
#endif

extern unsigned int majorno; // device driver number given by the kernel
extern unsigned int minorno;
extern unsigned int devSize, dataSize, regSize, nofReg;
extern dev_t device_no; // major + minor

typedef struct scull_qset{
    void **data;
    struct scull_qset *next;
}gs_scull_qset;

typedef struct scull_dev{
    struct scull_qset *data;
    struct cdev c_dev;
    unsigned int quantum;
    unsigned int qset;
    unsigned int nofReg;
    unsigned int regSize;
    unsigned int dataSize;
    unsigned int devSize;
}gs_scull_dev;

extern gs_scull_dev *ep_scull_dev;