# Linux Character Device Driver

Linux character device driver development and kernel module experiments.

## Kernel Build Directory

Check the kernel build/source symlink:

```bash
ls -l /lib/modules/$(uname -r)/build
```

Example:

```text
/lib/modules/6.17.10-experiment/build ->
/home/harshsr923/kernel/linux-6.17.10
```

## `register_chrdev()` / `unregister_chrdev()`

Declarations are available in:

```bash
vim /home/harshsr923/kernel/linux-6.17.10/include/linux/fs.h
```

## Build & Load

```bash
make clean
make
make install
```

`make install` loads:

```bash
sudo insmod build/scull.ko
```

Check logs:

```bash
sudo dmesg | tail -20
```

Check module:

```bash
lsmod | grep scull
```

Example:

```text
scull                  12288  0
```

## Module Info

```bash
modinfo build/scull.ko
```

Example:

```text
description: Linux Character Device Driver
license: GPL
name: scull
vermagic: 6.17.10-experiment SMP preempt mod_unload
```

## Unload

```bash
make uninstall
lsmod | grep scull
```

Expected:

```text
<no output>
```

## Kernel Log

Example:

```text
scull: loading out-of-tree module taints kernel.
scull: module verification failed: signature and/or required key missing
Hello Kernel
```

The taint/signature messages are expected for an unsigned out-of-tree module.

## Commit

```text
<commit-hash>
```
