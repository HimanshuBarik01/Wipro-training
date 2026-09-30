#include <iostream>
#include <fstream>
#include <iomanip>

#include "../include/report_generator.h"

using namespace std;

void generateHealthReport(
    const string& hostname,
    const string& kernelVersion,
    int cpuCores,
    double uptime,
    int processCount,
    double cpuUsage,
    double ramUsage,
    double diskUsage,
    const string& cpuStatus,
    const string& ramStatus,
    const string& diskStatus,
    const string& overallStatus
) {
    ofstream file("logs/health_report.txt");

    if (!file) {
        cout << "Error: Unable to create health report.\n";
        return;
    }

    file << "=============================================\n";
    file << "          HARD-MON HEALTH REPORT\n";
    file << "=============================================\n\n";

    file << "SYSTEM INFORMATION\n";
    file << "---------------------------------------------\n";

    file << "Hostname       : " << hostname << "\n";
    file << "Kernel Version : " << kernelVersion << "\n";
    file << "CPU Cores      : " << cpuCores << "\n";
    file << "System Uptime  : " << uptime << " seconds\n";
    file << "Processes      : " << processCount << "\n\n";

    file << "HEALTH STATUS\n";
    file << "---------------------------------------------\n";

    file << fixed << setprecision(2);

    file << "CPU Usage      : " << cpuUsage
         << "% [" << cpuStatus << "]\n";

    file << "RAM Usage      : " << ramUsage
         << "% [" << ramStatus << "]\n";

    file << "Disk Usage     : " << diskUsage
         << "% [" << diskStatus << "]\n\n";

    file << "Overall Health : " << overallStatus << "\n";

    file << "=============================================\n";

    file.close();

    cout << "\nHealth report generated successfully.\n";
}