#include "headers.h"

void printk_log(const char *message)
{
    struct tm tm;
    time64_t now = ktime_get_real_seconds();

    time64_to_tm(now, 5 * 60 * 60 + 30 * 60, &tm);

    pr_info("%s | %04ld-%02d-%02d %02d:%02d:%02d IST\n",
            message,
            tm.tm_year + 1900,
            tm.tm_mon + 1,
            tm.tm_mday,
            tm.tm_hour,
            tm.tm_min,
            tm.tm_sec);
}