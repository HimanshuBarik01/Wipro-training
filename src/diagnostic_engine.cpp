#include <iostream>
#include <string>

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

    double cpuUsage;
    double ramUsage;
    double diskUsage;

    cout << "====================================\n";
    cout << "       HARD-MON DIAGNOSTIC ENGINE\n";
    cout << "====================================\n\n";

    cout << "Enter CPU Usage (%): ";
    cin >> cpuUsage;

    cout << "Enter RAM Usage (%): ";
    cin >> ramUsage;

    cout << "Enter Disk Usage (%): ";
    cin >> diskUsage;

    string cpuStatus = getStatus(cpuUsage);
    string ramStatus = getStatus(ramUsage);
    string diskStatus = getStatus(diskUsage);

    cout << "\n------------- DIAGNOSIS -------------\n";

    cout << "CPU Status  : " << cpuStatus << "\n";
    cout << "RAM Status  : " << ramStatus << "\n";
    cout << "Disk Status : " << diskStatus << "\n";

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

    cout << "--------------------------------------\n";
    cout << "Overall Health : " << overallStatus << "\n";
    cout << "--------------------------------------\n";

    return 0;
}