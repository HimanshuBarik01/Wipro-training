#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

#include "../include/monitor.h"

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

double getCPUUsage() {

    CPUStats first = getCPUStats();

    this_thread::sleep_for(
        chrono::seconds(1)
    );

    CPUStats second = getCPUStats();

    return calculateCPUUsage(first, second);
}