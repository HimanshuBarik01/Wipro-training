#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <string>

std::string getStatus(double usage);

std::string getOverallStatus(
    const std::string& cpuStatus,
    const std::string& ramStatus,
    const std::string& diskStatus
);

#endif