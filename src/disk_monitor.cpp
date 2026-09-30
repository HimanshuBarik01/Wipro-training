#include <iostream>
#include <sys/statvfs.h>

#include "../include/monitor.h"

using namespace std;

double getDiskUsage() {

    struct statvfs diskInfo;

    if (statvfs("/", &diskInfo) != 0) {
        return 0.0;
    }

    unsigned long long totalBytes =
        diskInfo.f_blocks * diskInfo.f_frsize;

    unsigned long long availableBytes =
        diskInfo.f_bavail * diskInfo.f_frsize;

    if (totalBytes == 0) {
        return 0.0;
    }

    unsigned long long usedBytes =
        totalBytes - availableBytes;

    double usage =
        (double)usedBytes / totalBytes * 100.0;

    return usage;
}