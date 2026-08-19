#ifndef DEVNAME
#define DEVNAME "mychardev"
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

extern unsigned int majorno; // device driver number given by the kernel
extern unsigned int minorno;
extern dev_t device_no;