# Stage 4: Initial Implementation & Prototype

## 4.1 Implementation Overview

The HARD-MON prototype was implemented using **C++17** on **Ubuntu 24.04 LTS through WSL2**.

The application follows a modular structure where each monitoring and diagnostic function is implemented separately and integrated through `main.cpp`.

## 4.2 Implemented Modules

| Module             | Implementation                                             |
| ------------------ | ---------------------------------------------------------- |
| CPU Monitor        | Reads `/proc/stat` and calculates CPU usage                |
| Memory Monitor     | Reads `/proc/meminfo` and calculates RAM usage             |
| Disk Monitor       | Uses `statvfs()` to calculate disk usage                   |
| System Information | Collects hostname, kernel, CPU cores, uptime and processes |
| Diagnostic Engine  | Classifies usage as NORMAL, WARNING or CRITICAL            |
| Fault Simulator    | Tests different abnormal conditions                        |
| Logger             | Stores health results in `health_log.txt`                  |
| Report Generator   | Creates `health_report.txt`                                |
| Main Controller    | Integrates all modules                                     |

## 4.3 Prototype Workflow

```text
Start
  ↓
Collect System Information
  ↓
Monitor CPU / RAM / Disk
  ↓
Diagnostic Engine
  ↓
Determine Health Status
  ↓
Display Results
  ↓
Log Health Data
  ↓
Generate Health Report
  ↓
Optional Fault Simulation
  ↓
Exit
```

## 4.4 Fault Simulation

The prototype includes controlled fault simulation for testing the diagnostic engine.

Available scenarios:

* CPU WARNING
* CPU CRITICAL
* RAM WARNING
* RAM CRITICAL
* Disk WARNING
* Disk CRITICAL
* Multiple Faults

The simulation uses predefined values and does not intentionally overload or damage the actual system.

## 4.5 Build and Execution

The complete application is compiled using G++.

```bash
g++ -std=c++17 src/main.cpp src/cpu_monitor.cpp src/memory_monitor.cpp src/disk_monitor.cpp src/diagnostic_engine.cpp src/fault_simulator.cpp src/logger.cpp src/system_info.cpp src/report_generator.cpp -o hardmon
```

Run:

```bash
./hardmon
```

## 4.6 Prototype Output

Example:

```text
------------- SYSTEM INFORMATION -------------

Hostname       : Victus
Kernel Version : 6.6.87.2-microsoft-standard-WSL2
CPU Cores      : 16
System Uptime  : 16230.1 seconds
Processes      : 46

------------- HEALTH REPORT -------------

CPU Usage  : 0.06 % [NORMAL]
RAM Usage  : 8.53 % [NORMAL]
Disk Usage : 5.42 % [NORMAL]

------------------------------------------
Overall Health : NORMAL
------------------------------------------
```

## 4.7 Issues and Solutions

| Issue                                                 | Solution                                                             |
| ----------------------------------------------------- | -------------------------------------------------------------------- |
| CPU usage required two readings                       | Implemented CPU calculation using `/proc/stat` over a short interval |
| Different Linux resources use different interfaces    | Created separate monitoring modules                                  |
| Abnormal conditions are difficult to reproduce safely | Added controlled fault simulation                                    |
| Monitoring results needed persistent storage          | Added logging module                                                 |
| Final system information needed structured output     | Added health report generator                                        |

## 4.8 Implementation Result

The initial prototype successfully integrates all major modules and can:

* Monitor real Linux system resources.
* Detect abnormal resource conditions.
* Simulate fault scenarios.
* Record health information.
* Generate a system health report.

The prototype forms the base for the testing and improvement stage.
