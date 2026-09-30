#ifndef LOGGER_H
#define LOGGER_H

#include <string>

void logHealthData(
    double cpu,
    double ram,
    double disk,
    const std::string& overallStatus
);

#endif