#include <iostream>
#include <iomanip>

#include "../include/monitor.h"
#include "../include/diagnostic.h"
#include "../include/fault_simulator.h"
#include "../include/logger.h"
#include "../include/system_info.h"

using namespace std;

int main() {

    cout << "====================================\n";
    cout << "          HARD-MON SYSTEM\n";
    cout << " Hardware Health & Diagnostic System\n";
    cout << "====================================\n\n";

    cout << "Collecting hardware information...\n\n";

    string hostname = getHostname();
    string kernelVersion = getKernelVersion();
    int cpuCores = getCPUCoreCount();
    double uptime = getSystemUptime();
    int processCount = getProcessCount();

    cout << "------------- SYSTEM INFORMATION -------------\n\n";

    cout << "Hostname       : " << hostname << "\n";
    cout << "Kernel Version : " << kernelVersion << "\n";
    cout << "CPU Cores      : " << cpuCores << "\n";
    cout << "System Uptime  : " << uptime << " seconds\n";
    cout << "Processes      : " << processCount << "\n\n";

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

    logHealthData(
        cpuUsage,
        ramUsage,
        diskUsage,
        overallStatus
    );

    char choice;

    cout << "\nRun fault simulation? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        runFaultSimulation();
    }

    return 0;
}