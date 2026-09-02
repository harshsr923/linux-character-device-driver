// header sequence never change because of depenedency
#ifndef HEADERS_H
#define HEADERS_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/timekeeping.h>
#include <linux/time64.h>

void printk_log(const char *message);

#endif