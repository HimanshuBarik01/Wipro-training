#include <string>

#include "../include/diagnostic.h"

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

string getOverallStatus(
    const string& cpuStatus,
    const string& ramStatus,
    const string& diskStatus
) {

    if (cpuStatus == "CRITICAL" ||
        ramStatus == "CRITICAL" ||
        diskStatus == "CRITICAL") {

        return "CRITICAL";
    }

    if (cpuStatus == "WARNING" ||
        ramStatus == "WARNING" ||
        diskStatus == "WARNING") {

        return "WARNING";
    }

    return "NORMAL";
}