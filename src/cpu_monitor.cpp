#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

struct CPUStats {
    long long idle;
    long long total;
};

CPUStats getCPUStats() {

    ifstream file("/proc/stat");

    string line;
    getline(file, line);

    stringstream ss(line);

    string cpu;
    long long user, nice, system, idle, iowait;
    long long irq, softirq, steal;

    ss >> cpu
       >> user
       >> nice
       >> system
       >> idle
       >> iowait
       >> irq
       >> softirq
       >> steal;

    long long idleTime = idle + iowait;

    long long totalTime =
        user + nice + system + idle +
        iowait + irq + softirq + steal;

    return {idleTime, totalTime};
}

double calculateCPUUsage(CPUStats first, CPUStats second) {

    long long idleDifference =
        second.idle - first.idle;

    long long totalDifference =
        second.total - first.total;

    if (totalDifference == 0) {
        return 0.0;
    }

    double usage =
        100.0 *
        (1.0 - (double)idleDifference / totalDifference);

    return usage;
}

int main() {

    CPUStats first = getCPUStats();

    this_thread::sleep_for(
        chrono::seconds(1)
    );

    CPUStats second = getCPUStats();

    double cpuUsage =
        calculateCPUUsage(first, second);

    cout << "====================================\n";
    cout << "          HARD-MON CPU MONITOR\n";
    cout << "====================================\n\n";

    cout << fixed << setprecision(2);
    cout << "CPU Usage : " << cpuUsage << " %\n";

    if (cpuUsage >= 90) {
        cout << "CPU Status: CRITICAL\n";
    }
    else if (cpuUsage >= 70) {
        cout << "CPU Status: WARNING\n";
    }
    else {
        cout << "CPU Status: NORMAL\n";
    }

    return 0;
}