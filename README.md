# HARD-MON

## Linux-Based Hardware Health & Diagnostic System

HARD-MON is a Linux-based hardware health and diagnostic system developed using C++. The system collects real-time system information from Linux, monitors CPU, RAM, and disk utilization, evaluates system health using configurable thresholds, simulates hardware fault conditions, and generates health logs and reports.

---

## 1. Project Objective

The objective of HARD-MON is to provide a lightweight Linux-based system monitoring and diagnostic solution that can:

* Monitor CPU utilization
* Monitor RAM utilization
* Monitor disk utilization
* Collect Linux system information
* Detect abnormal resource conditions
* Classify system health as NORMAL, WARNING, or CRITICAL
* Simulate hardware fault conditions
* Maintain health logs
* Generate a human-readable health report

---

## 2. Problem Statement

System administrators and developers need a simple way to identify abnormal system resource conditions.

Traditional monitoring tools may provide large amounts of information without directly classifying the overall health of the system.

HARD-MON addresses this problem by collecting Linux system data and applying a diagnostic engine to convert monitoring values into understandable health states.

---

## 3. System Architecture

The system follows the architecture:

Hardware / Linux System
↓
Linux Monitoring Layer
↓
C++ Monitoring Modules
↓
Diagnostic Engine
↓
Health Status
↓
NORMAL / WARNING / CRITICAL
↓
Logging & Health Report

---

## 4. Functional Modules

### 1. CPU Monitoring

Reads CPU statistics from `/proc/stat` and calculates CPU utilization over a one-second interval.

### 2. RAM Monitoring

Reads memory information from `/proc/meminfo` and calculates RAM utilization using total and available memory.

### 3. Disk Monitoring

Uses the Linux `statvfs()` system interface to calculate disk utilization.

### 4. Diagnostic Engine

Classifies resource usage according to the following thresholds:

| Usage         | Status   |
| ------------- | -------- |
| Below 70%     | NORMAL   |
| 70%–89.99%    | WARNING  |
| 90% and above | CRITICAL |

The diagnostic engine also calculates the overall system health.

### 5. Fault Simulation

Provides controlled fault scenarios for testing the diagnostic engine:

* CPU Warning
* CPU Critical
* RAM Warning
* RAM Critical
* Disk Warning
* Disk Critical
* Multiple Faults

### 6. Health Logging

Stores monitoring results and timestamps in:

`logs/health_log.txt`

### 7. System Information

Collects:

* Hostname
* Linux kernel version
* CPU core count
* System uptime
* Running process count

### 8. Health Report Generator

Generates a readable system health report containing system information, resource utilization, individual status values, and overall health.

Report location:

`logs/health_report.txt`

---

## 5. Technologies Used

* C++
* Linux
* Ubuntu 24.04 LTS
* WSL2
* GCC / G++
* Git
* VS Code
* Linux `/proc` filesystem
* Linux system interfaces
* Standard C++ libraries

---

## 6. Linux Interfaces Used

HARD-MON demonstrates interaction with Linux system information through:

* `/proc/stat` — CPU statistics
* `/proc/meminfo` — memory statistics
* `/proc/cpuinfo` — CPU information
* `/proc/uptime` — system uptime
* `/proc/sys/kernel/osrelease` — kernel version
* `/proc` — process information
* `statvfs()` — filesystem statistics
* `gethostname()` — system hostname

---

## 7. Project Structure

```text
WiproProject/
│
├── src/
│   ├── main.cpp
│   ├── cpu_monitor.cpp
│   ├── memory_monitor.cpp
│   ├── disk_monitor.cpp
│   ├── diagnostic_engine.cpp
│   ├── fault_simulator.cpp
│   ├── logger.cpp
│   ├── system_info.cpp
│   └── report_generator.cpp
│
├── include/
│   ├── monitor.h
│   ├── diagnostic.h
│   ├── fault_simulator.h
│   ├── logger.h
│   ├── system_info.h
│   └── report_generator.h
│
├── logs/
│   ├── health_log.txt
│   └── health_report.txt
│
├── docs/
├── tests/
├── .gitignore
└── README.md
```

---

## 8. Compilation

Open an Ubuntu/WSL terminal in the project directory.

```bash
g++ -std=c++17 src/main.cpp src/cpu_monitor.cpp src/memory_monitor.cpp src/disk_monitor.cpp src/diagnostic_engine.cpp src/fault_simulator.cpp src/logger.cpp src/system_info.cpp src/report_generator.cpp -o hardmon
```

---

## 9. Running the Application

```bash
./hardmon
```

The application displays system information and the current health status.

It then provides an option to run fault simulations.

---

## 10. Example Output

```text
====================================
          HARD-MON SYSTEM
 Hardware Health & Diagnostic System
====================================

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

---

## 11. Fault Simulation Example

A simulated RAM critical condition produces:

```text
CPU Usage  : 10.00% [NORMAL]
RAM Usage  : 95.00% [CRITICAL]
Disk Usage : 10.00% [NORMAL]

Overall Health : CRITICAL
```

This allows the diagnostic engine to be tested without actually exhausting system resources.

---

## 12. Testing

The following tests were performed:

* Clean compilation
* Application execution
* CPU monitoring
* RAM monitoring
* Disk monitoring
* System information collection
* CPU WARNING simulation
* RAM CRITICAL simulation
* Multiple fault simulation
* Health logging
* Health report generation
* Five consecutive application runs
* Git working-tree verification

All implemented functional tests completed successfully.

---

## 13. Advantages

* Lightweight and fast
* Uses native Linux system information
* Written in C++
* No external database required
* No external hardware required
* Provides automated health classification
* Includes fault simulation for diagnostic testing
* Generates persistent health records
* Demonstrates Linux system programming concepts

---

## 14. Limitations

* Fault simulation does not create actual hardware failures.
* Monitoring is currently performed from a command-line application.
* Thresholds are predefined.
* The application currently monitors the primary filesystem.
* No remote monitoring capability is implemented.

---

## 15. Future Enhancements

Possible future improvements include:

* Real-time continuous monitoring
* Configurable thresholds
* Network monitoring
* Temperature monitoring
* SMART disk health monitoring
* Linux kernel module integration
* Email or notification alerts
* Web-based monitoring dashboard
* Historical health analytics
* Remote system monitoring

---

## 16. Project Outcome

HARD-MON demonstrates how Linux system interfaces and C++ programming can be combined to build a practical hardware health and diagnostic application.

The project integrates system monitoring, diagnostic logic, fault simulation, logging, reporting, testing, and Git-based version control into a single Linux-based application.
