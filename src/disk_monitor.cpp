#include <iostream>
#include <sys/statvfs.h>
#include <iomanip>

using namespace std;

int main() {

    struct statvfs diskInfo;

    if (statvfs("/", &diskInfo) != 0) {
        cout << "Unable to read disk information." << endl;
        return 1;
    }

    unsigned long long totalBytes =
        diskInfo.f_blocks * diskInfo.f_frsize;

    unsigned long long availableBytes =
        diskInfo.f_bavail * diskInfo.f_frsize;

    unsigned long long usedBytes =
        totalBytes - availableBytes;

    double totalGB =
        totalBytes / (1024.0 * 1024.0 * 1024.0);

    double usedGB =
        usedBytes / (1024.0 * 1024.0 * 1024.0);

    double availableGB =
        availableBytes / (1024.0 * 1024.0 * 1024.0);

    double usage =
        (double)usedBytes / totalBytes * 100.0;

    cout << "====================================\n";
    cout << "         HARD-MON DISK MONITOR\n";
    cout << "====================================\n\n";

    cout << fixed << setprecision(2);

    cout << "Total Disk     : "
         << totalGB << " GB\n";

    cout << "Used Disk      : "
         << usedGB << " GB\n";

    cout << "Available Disk : "
         << availableGB << " GB\n";

    cout << "Disk Usage     : "
         << usage << " %\n";

    if (usage >= 90) {
        cout << "Disk Status    : CRITICAL\n";
    }
    else if (usage >= 70) {
        cout << "Disk Status    : WARNING\n";
    }
    else {
        cout << "Disk Status    : NORMAL\n";
    }

    return 0;
}