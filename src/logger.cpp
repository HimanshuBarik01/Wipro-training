#include <iostream>
#include <fstream>
#include <ctime>

#include "../include/logger.h"

using namespace std;

void logHealthData(
    double cpu,
    double ram,
    double disk,
    const string& overallStatus
) {
    ofstream file("logs/health_log.txt", ios::app);

    if (!file) {
        cout << "Error: Unable to open health log file.\n";
        return;
    }

    time_t currentTime = time(nullptr);

    file << "---------------------------------------------\n";
    file << "Health Check\n";
    file << "Time: " << ctime(&currentTime);
    file << "CPU Usage  : " << cpu << "%\n";
    file << "RAM Usage  : " << ram << "%\n";
    file << "Disk Usage : " << disk << "%\n";
    file << "Overall Health : " << overallStatus << "\n";
    file << "---------------------------------------------\n\n";

    file.close();
}