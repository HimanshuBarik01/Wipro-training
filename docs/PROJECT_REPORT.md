# HARD-MON

## Linux-Based Hardware Health & Diagnostic System

**Project Type:** Individual Project
**Domain:** Linux, System Programming & C++
**Programming Language:** C++17
**Operating Environment:** Ubuntu 24.04.4 LTS on WSL2
**Compiler:** G++ 13.3.0
**Development Environment:** Visual Studio Code
**Version Control:** Git

---

# 1. Abstract

HARD-MON (Hardware Health & Diagnostic System) is a Linux-based system monitoring and diagnostic application developed using C++17.

The primary purpose of the system is to collect hardware-related system information, monitor CPU, RAM and disk utilization, identify abnormal resource conditions and provide a simple health status for the system.

The application uses Linux system interfaces such as the `/proc` filesystem and the `statvfs()` system call to obtain real system information. A C++ diagnostic engine evaluates resource utilization against predefined thresholds and classifies each resource as NORMAL, WARNING or CRITICAL.

The system also includes a fault simulation module that allows controlled abnormal conditions to be tested without intentionally damaging or overloading the real system. Health information can be stored in a log file, and a structured health report can be generated for further analysis.

The project follows a modular architecture with separate components for monitoring, diagnosis, fault simulation, logging, system information and reporting. Git was used throughout development to maintain version history and track project progress.

---

# 2. Introduction

Modern computer systems continuously utilize CPU, memory and storage resources. Monitoring these resources is important for understanding system health and identifying abnormal conditions.

Linux provides several interfaces through which applications can obtain system information. The `/proc` virtual filesystem exposes information about CPU, memory, processes, uptime and kernel details.

HARD-MON uses these Linux facilities together with C++ system programming techniques to create a lightweight command-line monitoring and diagnostic system.

Instead of displaying only raw resource statistics, HARD-MON converts the collected information into simple health states:

```text
NORMAL
WARNING
CRITICAL
```

This makes the monitoring information easier to interpret and provides a foundation for future hardware health and diagnostic extensions.

---

# 3. Problem Statement

System resource utilization can increase because of applications, processes, insufficient memory, storage consumption or other system activities.

High resource utilization may affect system performance. However, raw system statistics do not always provide an immediate indication of whether the current condition should be considered normal or requires attention.

The problem addressed by HARD-MON is therefore:

> To develop a Linux-based system that collects important hardware-related parameters, analyzes resource utilization using predefined thresholds and provides a simple diagnostic health status.

---

# 4. Project Objectives

The major objectives of HARD-MON are:

1. Monitor CPU utilization.
2. Monitor RAM utilization.
3. Monitor disk utilization.
4. Collect basic Linux system information.
5. Classify resource conditions using predefined thresholds.
6. Determine overall system health.
7. Simulate abnormal conditions for testing.
8. Maintain health logs.
9. Generate a structured health report.
10. Provide a modular and maintainable C++ implementation.
11. Demonstrate Linux system programming concepts.
12. Maintain project development history using Git.

---

# 5. Project Scope

## 5.1 In Scope

The current system supports:

* CPU utilization monitoring
* RAM utilization monitoring
* Disk utilization monitoring
* CPU core detection
* Hostname detection
* Kernel version detection
* System uptime
* Process counting
* Health classification
* Overall health calculation
* Fault simulation
* Health logging
* Health report generation
* Functional testing
* Integration testing
* Reliability testing
* Git-based version control
* Technical documentation

## 5.2 Out of Scope

The current implementation does not include:

* Actual hardware failure generation
* Physical hardware sensor integration
* Kernel driver development
* Cloud monitoring
* Database integration
* Web-based dashboard
* Machine learning prediction
* Remote monitoring
* Automated email/SMS notifications

These can be considered future extensions.

---

# 6. Proposed System

HARD-MON follows a modular monitoring and diagnostic architecture.

The overall workflow is:

```text
Linux System
     |
     v
System Data Collection
     |
     v
CPU / RAM / Disk Monitoring
     |
     v
Diagnostic Engine
     |
     v
Health Classification
     |
     +----------------------+
     |                      |
     v                      v
Health Logging        Health Report
     |
     v
Historical Information
```

The system can additionally execute a fault simulation module for controlled testing.

---

# 7. System Architecture

```text
+------------------------------------------------+
|                 Linux System                   |
|                                                |
| CPU | RAM | Disk | Kernel | Processes | Uptime |
+-----------------------+------------------------+
                        |
                        v
+------------------------------------------------+
|             Linux Monitoring Layer             |
|                                                |
| /proc/stat                                     |
| /proc/meminfo                                  |
| /proc/cpuinfo                                  |
| /proc/uptime                                   |
| /proc/sys/kernel/osrelease                     |
| Process directories                            |
| statvfs()                                      |
+-----------------------+------------------------+
                        |
                        v
+------------------------------------------------+
|               HARD-MON C++ Engine              |
+-----------------------+------------------------+
                        |
          +-------------+-------------+
          |             |             |
          v             v             v
       CPU Monitor   RAM Monitor   Disk Monitor
          |             |             |
          +-------------+-------------+
                        |
                        v
+------------------------------------------------+
|               Diagnostic Engine                |
|                                                |
|  NORMAL       WARNING       CRITICAL            |
+-----------------------+------------------------+
                        |
                        v
+------------------------------------------------+
|              Overall Health Status             |
+-----------------------+------------------------+
                        |
             +----------+----------+
             |                     |
             v                     v
       Health Logger        Report Generator
             |                     |
             v                     v
     health_log.txt       health_report.txt
```

---

# 8. System Components

## 8.1 CPU Monitoring Module

**Source:** `src/cpu_monitor.cpp`

The CPU monitoring module obtains CPU statistics from:

```text
/proc/stat
```

It calculates CPU utilization by comparing CPU statistics over a measurement interval.

### Responsibilities

* Read CPU statistics.
* Calculate CPU utilization.
* Return CPU usage percentage.

---

## 8.2 Memory Monitoring Module

**Source:** `src/memory_monitor.cpp`

The memory monitoring module reads:

```text
/proc/meminfo
```

Important values include total and available memory.

RAM utilization is calculated using the available and total memory information.

### Responsibilities

* Read memory information.
* Calculate RAM utilization.
* Return RAM usage percentage.

---

## 8.3 Disk Monitoring Module

**Source:** `src/disk_monitor.cpp`

The disk monitoring module uses the Linux `statvfs()` system call to obtain filesystem statistics.

### Responsibilities

* Obtain filesystem capacity.
* Determine used and available storage.
* Calculate disk utilization.
* Return disk usage percentage.

---

## 8.4 Diagnostic Engine

**Source:** `src/diagnostic_engine.cpp`

The diagnostic engine evaluates resource utilization against predefined thresholds.

### Diagnostic Thresholds

| Usage         | Status   |
| ------------- | -------- |
| `< 70%`       | NORMAL   |
| `70% – < 90%` | WARNING  |
| `>= 90%`      | CRITICAL |

The engine evaluates:

* CPU status
* RAM status
* Disk status

It then calculates the overall system health.

### Overall Health Logic

The highest severity determines the overall health.

```text
CRITICAL > WARNING > NORMAL
```

For example:

```text
CPU  : NORMAL
RAM  : WARNING
Disk : NORMAL

Overall : WARNING
```

---

# 9. Fault Simulation Module

**Source:** `src/fault_simulator.cpp`

The fault simulation module allows the diagnostic system to be tested with controlled resource values.

Available options include:

```text
1. CPU Warning
2. CPU Critical
3. RAM Warning
4. RAM Critical
5. Disk Warning
6. Disk Critical
7. Multiple Faults
0. Exit
```

The simulator uses predefined test values instead of intentionally consuming system resources.

For example:

```text
CPU Warning  -> 75%
CPU Critical -> 95%
```

This provides a safe and repeatable method for validating diagnostic logic.

---

# 10. Health Logging Module

**Source:** `src/logger.cpp`

The logging module records monitoring results in:

```text
logs/health_log.txt
```

The log contains information such as:

* Timestamp
* CPU usage
* RAM usage
* Disk usage
* Overall health status

Example:

```text
=============================================
Timestamp : System monitoring event
CPU       : 0.06%
RAM       : 8.53%
Disk      : 5.42%
Overall   : NORMAL
=============================================
```

The logging mechanism allows health information from multiple executions to be retained.

---

# 11. System Information Module

**Source:** `src/system_info.cpp`

The system information module collects general Linux system information.

It provides:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count

Example:

```text
Hostname       : Victus
Kernel Version : 6.6.87.2-microsoft-standard-WSL2
CPU Cores      : 16
System Uptime  : 16230.1 seconds
Processes      : 46
```

Values can change depending on the system state and execution time.

---

# 12. Health Report Generator

**Source:** `src/report_generator.cpp`

The health report generator combines system information and diagnostic results into a structured report.

Output file:

```text
logs/health_report.txt
```

Example structure:

```text
=============================================
          HARD-MON HEALTH REPORT
=============================================

SYSTEM INFORMATION
---------------------------------------------
Hostname       : Victus
Kernel Version : 6.6.87.2-microsoft-standard-WSL2
CPU Cores      : 16
System Uptime  : 16230.1 seconds
Processes      : 46

HEALTH STATUS
---------------------------------------------
CPU Usage      : 0.06% [NORMAL]
RAM Usage      : 8.53% [NORMAL]
Disk Usage     : 5.42% [NORMAL]

Overall Health : NORMAL
=============================================
```

---

# 13. Linux System Interfaces

HARD-MON demonstrates the use of Linux system interfaces for system monitoring.

| Interface                    | Purpose               |
| ---------------------------- | --------------------- |
| `/proc/stat`                 | CPU statistics        |
| `/proc/meminfo`              | Memory information    |
| `/proc/cpuinfo`              | CPU information       |
| `/proc/uptime`               | System uptime         |
| `/proc/sys/kernel/osrelease` | Kernel version        |
| `/proc/` numeric directories | Process counting      |
| `statvfs()`                  | Filesystem statistics |

These interfaces allow the application to collect system information without requiring external monitoring software.

---

# 14. Data Flow

The system follows this data flow:

```text
Linux Operating System
          |
          v
   Data Collection
          |
    +-----+-----+
    |     |     |
    v     v     v
   CPU   RAM   Disk
    |     |     |
    +-----+-----+
          |
          v
  Diagnostic Engine
          |
          v
 Individual Status
          |
          v
 Overall Health
       /     \
      /       \
     v         v
  Logger     Reporter
     |         |
     v         v
 Health Log  Health Report
```

---

# 15. Program Execution Flow

```text
START
  |
  v
Initialize HARD-MON
  |
  v
Collect System Information
  |
  v
Collect CPU/RAM/Disk Usage
  |
  v
Evaluate Resource Usage
  |
  v
Determine Individual Status
  |
  v
Calculate Overall Health
  |
  +-----------> Write Health Log
  |
  +-----------> Generate Health Report
  |
  v
Ask for Fault Simulation
  |
  +---- YES ----> Run Simulation
  |
  +---- NO -----> EXIT
  |
  v
END
```

---

# 16. Project Structure

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
├── tests/
│
├── logs/
│   ├── health_log.txt
│   └── health_report.txt
│
├── docs/
│   ├── PROJECT_PLAN.md
│   ├── SYSTEM_DESIGN.md
│   ├── TESTING.md
│   └── PROJECT_REPORT.md
│
├── .gitignore
└── README.md
```

---

# 17. Development Environment

| Component       | Configuration               |
| --------------- | --------------------------- |
| OS              | Ubuntu 24.04.4 LTS          |
| Environment     | WSL2                        |
| Kernel          | Microsoft WSL2 Linux Kernel |
| Language        | C++17                       |
| Compiler        | G++ 13.3.0                  |
| IDE             | Visual Studio Code          |
| Version Control | Git                         |
| Shell           | Bash                        |

---

# 18. Build and Execution

## Compilation

The complete application is compiled using:

```bash
g++ -std=c++17 src/main.cpp src/cpu_monitor.cpp src/memory_monitor.cpp src/disk_monitor.cpp src/diagnostic_engine.cpp src/fault_simulator.cpp src/logger.cpp src/system_info.cpp src/report_generator.cpp -o hardmon
```

This generates:

```text
hardmon
```

## Execution

Run the application using:

```bash
./hardmon
```

---

# 19. Example Application Output

A typical execution produces output similar to:

```text
====================================
          HARD-MON SYSTEM
 Hardware Health & Diagnostic System
====================================

Collecting hardware information...

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

Run fault simulation? (y/n):
```

Actual values vary depending on the system at runtime.

---

# 20. Fault Simulation Results

The fault simulation module was tested using different conditions.

### CPU Warning

```text
CPU Usage : 75%
Status    : WARNING
```

### CPU Critical

```text
CPU Usage : 95%
Status    : CRITICAL
```

### RAM Warning

```text
RAM Usage : 75%
Status    : WARNING
```

### RAM Critical

```text
RAM Usage : 95%
Status    : CRITICAL
```

### Multiple Faults

Example:

```text
CPU  : 95% -> CRITICAL
RAM  : 75% -> WARNING
Disk : 95% -> CRITICAL

Overall : CRITICAL
```

These simulations verify that the diagnostic engine correctly identifies different severity levels.

---

# 21. Testing Strategy

Testing was performed at multiple levels.

## 21.1 Unit-Level Testing

Individual monitoring and processing modules were tested separately.

Modules tested include:

* CPU monitor
* RAM monitor
* Disk monitor
* Diagnostic engine
* Fault simulator
* System information
* Logger
* Report generator

## 21.2 Integration Testing

All modules were integrated through `main.cpp` and executed as a complete application.

## 21.3 Fault Simulation Testing

Controlled WARNING and CRITICAL values were used to verify diagnostic behavior.

## 21.4 Reliability Testing

The complete application was executed repeatedly to verify stable execution.

A five-run reliability test was performed using:

```bash
for i in {1..5}; do echo "===== TEST RUN $i ====="; ./hardmon <<< n; done
```

The application completed the repeated execution test successfully.

---

# 22. Testing Results

| Test Area                 | Result |
| ------------------------- | ------ |
| Project Compilation       | PASS   |
| Program Execution         | PASS   |
| CPU Monitoring            | PASS   |
| RAM Monitoring            | PASS   |
| Disk Monitoring           | PASS   |
| System Information        | PASS   |
| NORMAL Diagnosis          | PASS   |
| WARNING Diagnosis         | PASS   |
| CRITICAL Diagnosis        | PASS   |
| CPU Fault Simulation      | PASS   |
| RAM Fault Simulation      | PASS   |
| Disk Fault Simulation     | PASS   |
| Multiple Fault Simulation | PASS   |
| Health Logging            | PASS   |
| Health Report             | PASS   |
| Module Integration        | PASS   |
| Repeated Execution        | PASS   |

Detailed test information is maintained in:

```text
docs/TESTING.md
```

---

# 23. Results

The completed HARD-MON system successfully demonstrates Linux-based resource monitoring and diagnostic processing.

The application can:

* Obtain real CPU utilization.
* Obtain real RAM utilization.
* Obtain real disk utilization.
* Collect Linux system information.
* Classify resource utilization.
* Calculate overall system health.
* Simulate abnormal conditions.
* Record monitoring results.
* Generate health reports.
* Execute repeatedly without unexpected termination.

The implementation demonstrates how Linux system information can be accessed and processed using C++.

---

# 24. Advantages

The current implementation provides several practical advantages:

* Lightweight command-line application
* Modular architecture
* Linux-native monitoring
* No external database requirement
* No cloud dependency
* Controlled fault simulation
* Simple diagnostic logic
* Human-readable reports
* Persistent health logging
* Easy source-code maintenance
* Git-based development history

---

# 25. Limitations

The current version has some limitations.

### 25.1 Limited Hardware Parameters

The application currently focuses primarily on CPU, RAM and disk utilization.

### 25.2 No Physical Sensor Integration

Physical temperature, fan-speed and other hardware sensor data are not currently integrated.

### 25.3 Static Thresholds

Diagnostic thresholds are predefined in the application and are not configurable through an external configuration file.

### 25.4 Command-Line Interface

The current application uses a command-line interface rather than a graphical dashboard.

### 25.5 Fault Simulation

Fault conditions are simulated using predefined values rather than being generated by actual hardware failures.

### 25.6 No Historical Database

Health information is stored in text logs rather than a structured database.

---

# 26. Future Enhancements

Future versions of HARD-MON could include:

## Hardware Monitoring

* CPU temperature
* GPU temperature
* Fan speed
* Battery health
* Sensor monitoring

## System Monitoring

* Network bandwidth
* Network connectivity
* Process-level CPU and memory usage
* Service monitoring

## Visualization

* Real-time dashboard
* Resource utilization graphs
* Historical trend visualization

## Alerting

* Desktop notifications
* Email notifications
* Configurable warning thresholds
* Configurable critical thresholds

## Advanced Diagnostics

* Historical trend analysis
* Anomaly detection
* Predictive maintenance
* Machine learning-based diagnosis

## Linux System Integration

* Kernel-level monitoring
* Device-driver integration
* Hardware sensor interfaces
* Remote Linux monitoring

---

# 27. Version Control

Git was used throughout development to maintain the project source and documentation history.

The project uses:

```text
master
```

as the primary branch.

Major components were committed incrementally during development.

The repository contains the source code, header files, documentation and configuration files required for the project.

Generated binaries, object files and runtime log files are excluded using `.gitignore`.

---

# 28. Development Roadmap

The project followed a five-day development roadmap.

| Day   | Focus                   | Deliverable                                |
| ----- | ----------------------- | ------------------------------------------ |
| Day 1 | Setup & Requirements    | Project foundation                         |
| Day 2 | Monitoring              | CPU/RAM/Disk monitoring                    |
| Day 3 | Diagnosis               | Diagnostic engine + fault simulation       |
| Day 4 | Integration             | Logging + reporting + complete application |
| Day 5 | Testing & Documentation | Final tested project                       |

Detailed planning information is available in:

```text
docs/PROJECT_PLAN.md
```

---

# 29. Documentation

The project documentation is divided into multiple files.

| Document            | Purpose                              |
| ------------------- | ------------------------------------ |
| `README.md`         | Project introduction and usage       |
| `PROJECT_PLAN.md`   | Requirements and development roadmap |
| `SYSTEM_DESIGN.md`  | Architecture and system design       |
| `TESTING.md`        | Testing strategy and results         |
| `PROJECT_REPORT.md` | Complete technical project report    |

---

# 30. Key Learning Outcomes

The development of HARD-MON provided practical experience in:

### Linux

* Linux `/proc` filesystem
* Linux system information
* Process inspection
* Filesystem statistics
* WSL2 environment

### C++

* Modular C++ programming
* Header/source separation
* File handling
* String processing
* System-level programming
* Function-based module design
* C++ compilation and linking

### System Programming

* Reading Linux virtual files
* CPU utilization calculation
* Memory utilization calculation
* Filesystem statistics
* Process counting
* Kernel information retrieval

### Software Engineering

* Modular architecture
* Incremental development
* Testing
* Documentation
* Version control
* Git commits
* Project planning

---

# 31. Project Achievements

The completed HARD-MON project demonstrates:

* Successful Linux system monitoring
* Successful C++ implementation
* Modular system architecture
* Controlled fault simulation
* Diagnostic status classification
* Health logging
* Automated report generation
* Functional testing
* Integration testing
* Reliability testing
* Git-based version control
* Complete technical documentation

---

# 32. Conclusion

HARD-MON successfully implements a Linux-based hardware health and diagnostic system using C++17.

The application collects real system information through Linux interfaces, monitors CPU, RAM and disk utilization, evaluates resource conditions using predefined thresholds and produces an overall system health status.

The addition of controlled fault simulation provides a safe mechanism for validating diagnostic behavior. Health logging and report generation further extend the usefulness of the system by providing persistent monitoring information.

The modular design makes the application easier to test, maintain and extend. The project also demonstrates practical concepts from Linux, system programming, C++, software testing and Git-based development.

Future versions can extend th
