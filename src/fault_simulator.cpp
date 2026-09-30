#include <iostream>
#include "../include/fault_simulator.h"
#include "../include/diagnostic.h"

using namespace std;

void runFaultSimulation() {

    int choice;

    cout << "\n====================================\n";
    cout << "       HARD-MON FAULT SIMULATOR\n";
    cout << "====================================\n";

    cout << "\n1. CPU Warning\n";
    cout << "2. CPU Critical\n";
    cout << "3. RAM Warning\n";
    cout << "4. RAM Critical\n";
    cout << "5. Disk Warning\n";
    cout << "6. Disk Critical\n";
    cout << "7. Multiple Faults\n";
    cout << "0. Exit Simulation\n";

    cout << "\nSelect fault: ";
    cin >> choice;

    double cpu = 10.0;
    double ram = 10.0;
    double disk = 10.0;

    switch (choice) {

        case 1:
            cpu = 75.0;
            break;

        case 2:
            cpu = 95.0;
            break;

        case 3:
            ram = 75.0;
            break;

        case 4:
            ram = 95.0;
            break;

        case 5:
            disk = 75.0;
            break;

        case 6:
            disk = 95.0;
            break;

        case 7:
            cpu = 95.0;
            ram = 75.0;
            disk = 95.0;
            break;

        case 0:
            return;

        default:
            cout << "\nInvalid selection.\n";
            return;
    }

    string cpuStatus = getStatus(cpu);
    string ramStatus = getStatus(ram);
    string diskStatus = getStatus(disk);

    string overallStatus =
        getOverallStatus(
            cpuStatus,
            ramStatus,
            diskStatus
        );

    cout << "\n------------- SIMULATION RESULT -------------\n";

    cout << "CPU Usage  : " << cpu << "% ["
         << cpuStatus << "]\n";

    cout << "RAM Usage  : " << ram << "% ["
         << ramStatus << "]\n";

    cout << "Disk Usage : " << disk << "% ["
         << diskStatus << "]\n";

    cout << "\nOverall Health : "
         << overallStatus << "\n";

    cout << "---------------------------------------------\n";
}