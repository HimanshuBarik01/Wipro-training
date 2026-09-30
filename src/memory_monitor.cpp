#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/monitor.h"

using namespace std;

struct MemoryInfo {
    long long total;
    long long available;
};

MemoryInfo getMemoryInfo() {

    ifstream file("/proc/meminfo");

    if (!file) {
        return {0, 0};
    }

    string line;
    long long total = 0;
    long long available = 0;

    while (getline(file, line)) {

        string key;
        long long value;
        string unit;

        stringstream ss(line);

        ss >> key >> value >> unit;

        if (key == "MemTotal:") {
            total = value;
        }

        if (key == "MemAvailable:") {
            available = value;
        }
    }

    file.close();

    return {total, available};
}

double getRAMUsage() {

    MemoryInfo memory = getMemoryInfo();

    if (memory.total == 0) {
        return 0.0;
    }

    long long used =
        memory.total - memory.available;

    double usage =
        (double)used / memory.total * 100.0;

    return usage;
}