#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <string>

std::string getHostname();
std::string getKernelVersion();
int getCPUCoreCount();
double getSystemUptime();
int getProcessCount();

#endif