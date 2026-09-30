#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

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

int main() {

    MemoryInfo memory = getMemoryInfo();

    if (memory.total == 0) {
        cout << "Unable to read memory information." << endl;
        return 1;
    }

    long long used =
        memory.total - memory.available;

    double usage =
        (double)used / memory.total * 100.0;

    double totalGB =
        memory.total / (1024.0 * 1024.0);

    double usedGB =
        used / (1024.0 * 1024.0);

    double availableGB =
        memory.available / (1024.0 * 1024.0);

    cout << "====================================\n";
    cout << "        HARD-MON MEMORY MONITOR\n";
    cout << "====================================\n\n";

    cout << fixed << setprecision(2);

    cout << "Total RAM     : "
         << totalGB << " GB\n";

    cout << "Used RAM      : "
         << usedGB << " GB\n";

    cout << "Available RAM : "
         << availableGB << " GB\n";

    cout << "RAM Usage     : "
         << usage << " %\n";

    if (usage >= 90) {
        cout << "RAM Status    : CRITICAL\n";
    }
    else if (usage >= 70) {
        cout << "RAM Status    : WARNING\n";
    }
    else {
        cout << "RAM Status    : NORMAL\n";
    }

    return 0;
}