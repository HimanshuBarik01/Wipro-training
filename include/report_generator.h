#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>

void generateHealthReport(
    const std::string& hostname,
    const std::string& kernelVersion,
    int cpuCores,
    double uptime,
    int processCount,
    double cpuUsage,
    double ramUsage,
    double diskUsage,
    const std::string& cpuStatus,
    const std::string& ramStatus,
    const std::string& diskStatus,
    const std::string& overallStatus
);

#endif