#include <fstream>
#include <string>
#include <unistd.h>
#include <dirent.h>

#include "../include/system_info.h"

using namespace std;

string getHostname() {

    char hostname[256];

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        return string(hostname);
    }

    return "Unknown";
}

string getKernelVersion() {

    ifstream file("/proc/sys/kernel/osrelease");

    string version;

    if (file) {
        getline(file, version);
    }

    return version;
}

int getCPUCoreCount() {

    ifstream file("/proc/cpuinfo");

    if (!file) {
        return 0;
    }

    string line;
    int cores = 0;

    while (getline(file, line)) {

        if (line.find("processor") == 0) {
            cores++;
        }
    }

    return cores;
}

double getSystemUptime() {

    ifstream file("/proc/uptime");

    double uptime = 0.0;

    if (file) {
        file >> uptime;
    }

    return uptime;
}

int getProcessCount() {

    DIR* directory = opendir("/proc");

    if (!directory) {
        return 0;
    }

    int count = 0;

    struct dirent* entry;

    while ((entry = readdir(directory)) != nullptr) {

        string name = entry->d_name;

        if (!name.empty() &&
            name.find_first_not_of("0123456789") == string::npos) {

            count++;
        }
    }

    closedir(directory);

    return count;
}