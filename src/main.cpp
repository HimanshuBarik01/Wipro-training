#include <iostream>
#include <iomanip>

#include "../include/monitor.h"

using namespace std;

string getStatus(double usage) {

    if (usage >= 90) {
        return "CRITICAL";
    }
    else if (usage >= 70) {
        return "WARNING";
    }
    else {
        return "NORMAL";
    }
}

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

    string overallStatus = "NORMAL";

    if (cpuStatus == "CRITICAL" ||
        ramStatus == "CRITICAL" ||
        diskStatus == "CRITICAL") {

        overallStatus = "CRITICAL";
    }
    else if (cpuStatus == "WARNING" ||
             ramStatus == "WARNING" ||
             diskStatus == "WARNING") {

        overallStatus = "WARNING";
    }

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