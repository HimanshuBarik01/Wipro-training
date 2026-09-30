#include <iostream>
#include <iomanip>

#include "../include/monitor.h"
#include "../include/diagnostic.h"

using namespace std;


int main() {

    cout << "====================================\n";
    cout << "          HARD-MON SYSTEM\n";
    cout << " Hardware Health & Diagnostic System\n";
    cout << "====================================\n\n";

    cout << "Collecting hardware information...\n\n";

    double cpuUsage = getCPUUsage();
    double ramUsage = getRAMUsage();
    double diskUsage = getDiskUsage();

    string cpuStatus = getStatus(cpuUsage);
    string ramStatus = getStatus(ramUsage);
    string diskStatus = getStatus(diskUsage);

 string overallStatus =
    getOverallStatus(
        cpuStatus,
        ramStatus,
        diskStatus
    );

    cout << "------------- HEALTH REPORT -------------\n\n";

    cout << fixed << setprecision(2);

    cout << "CPU Usage  : "
         << cpuUsage << " %"
         << " [" << cpuStatus << "]\n";

    cout << "RAM Usage  : "
         << ramUsage << " %"
         << " [" << ramStatus << "]\n";

    cout << "Disk Usage : "
         << diskUsage << " %"
         << " [" << diskStatus << "]\n";

    cout << "\n------------------------------------------\n";

    cout << "Overall Health : "
         << overallStatus << "\n";

    cout << "------------------------------------------\n";

    return 0;
}