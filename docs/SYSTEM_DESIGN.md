# HARD-MON — System Design & Architecture

## 1. System Overview

HARD-MON (Hardware Health & Diagnostic System) is a Linux-based system monitoring and diagnostic application developed using C++.

The system collects real-time hardware and system information from Linux, analyzes resource usage against predefined thresholds, determines the health status, records monitoring results, and generates a health report.

---

## 2. System Architecture

```text
+---------------------------+
|       Linux System        |
|                           |
| CPU | RAM | Disk | Kernel |
+-------------+-------------+
              |
              v
+---------------------------+
|   Linux Monitoring Layer  |
|                           |
| /proc/stat                |
| /proc/meminfo             |
| /proc/cpuinfo             |
| /proc/uptime              |
| /proc/sys/kernel          |
| statvfs()                 |
+-------------+-------------+
              |
              v
+---------------------------+
|   HARD-MON C++ Engine     |
+---------------------------+
              |
      +-------+-------+
      |       |       |
      v       v       v
    CPU     Memory    Disk
  Monitor   Monitor  Monitor
      |       |       |
      +-------+-------+
              |
              v
+---------------------------+
|    Diagnostic Engine      |
|                           |
| NORMAL                    |
| WARNING                   |
| CRITICAL                  |
+-------------+-------------+
              |
       +------+------+
       |             |
       v             v
+-------------+ +-------------+
| Health Log  | | Health      |
|             | | Report      |
+-------------+ +-------------+
```

---

## 3. Major Components

### 3.1 CPU Monitor

**File:** `src/cpu_monitor.cpp`

Responsibilities:

* Read CPU statistics from `/proc/stat`
* Calculate CPU utilization
* Return CPU usage percentage

---

### 3.2 Memory Monitor

**File:** `src/memory_monitor.cpp`

Responsibilities:

* Read memory information from `/proc/meminfo`
* Obtain total and available memory
* Calculate RAM utilization percentage

---

### 3.3 Disk Monitor

**File:** `src/disk_monitor.cpp`

Responsibilities:

* Check filesystem statistics using `statvfs()`
* Calculate disk utilization
* Return disk usage percentage

---

### 3.4 Diagnostic Engine

**File:** `src/diagnostic_engine.cpp`

Responsibilities:

* Analyze CPU, RAM and disk utilization
* Apply predefined thresholds
* Generate individual health states
* Calculate overall system health

### Diagnostic Thresholds

| Usage          | Status   |
| -------------- | -------- |
| `< 70%`        | NORMAL   |
| `70% – 89.99%` | WARNING  |
| `>= 90%`       | CRITICAL |

Overall system status follows the highest detected severity.

---

### 3.5 Fault Simulator

**File:** `src/fault_simulator.cpp`

Responsibilities:

* Simulate abnormal hardware conditions
* Test diagnostic logic without damaging the real system
* Verify WARNING and CRITICAL detection

Supported simulations:

1. CPU Warning
2. CPU Critical
3. RAM Warning
4. RAM Critical
5. Disk Warning
6. Disk Critical
7. Multiple Faults

---

### 3.6 Logger

**File:** `src/logger.cpp`

Responsibilities:

* Record health monitoring results
* Store timestamped measurements
* Maintain historical health information

**Output:**

`logs/health_log.txt`

---

### 3.7 System Information Module

**File:** `src/system_info.cpp`

Collects:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count

---

### 3.8 Health Report Generator

**File:** `src/report_generator.cpp`

Responsibilities:

* Combine system information and health results
* Generate a readable health report
* Store the report for later inspection

**Output:**

`logs/health_report.txt`

---

## 4. Data Flow

```text
Linux System
     |
     v
Data Collection
     |
     +---- CPU Usage
     |
     +---- RAM Usage
     |
     +---- Disk Usage
     |
     +---- System Information
     |
     v
Diagnostic Engine
     |
     v
Threshold Evaluation
     |
     +---- NORMAL
     |
     +---- WARNING
     |
     +---- CRITICAL
     |
     v
Overall Health Status
     |
     +-------------------+
     |                   |
     v                   v
Health Logger      Report Generator
     |                   |
     v                   v
health_log.txt    health_report.txt
```

---

## 5. Module Relationship

```text
                    main.cpp
                       |
        +--------------+--------------+
        |              |              |
        v              v              v
   Monitoring     System Info    Diagnostic
     Modules         Module         Engine
        |              |              |
        +--------------+--------------+
                       |
                       v
                 Overall Status
                       |
              +--------+--------+
              |                 |
              v                 v
            Logger          Report Generator
```

---

## 6. Data Structures and Interfaces

HARD-MON uses simple C++ functions and standard data types.

### Monitoring Data

```text
CPU Usage  -> double
RAM Usage  -> double
Disk Usage -> double
```

### Health Status

```text
"NORMAL"
"WARNING"
"CRITICAL"
```

### System Information

```text
Hostname       -> string
Kernel Version -> string
CPU Cores      -> int
Uptime         -> double
Processes      -> int
```

The project uses function-based modular design rather than a complex object hierarchy because the primary goal is reliable system monitoring and diagnostic processing.

---

## 7. Linux Interfaces Used

| Linux Interface              | Purpose                    |
| ---------------------------- | -------------------------- |
| `/proc/stat`                 | CPU statistics             |
| `/proc/meminfo`              | Memory information         |
| `/proc/cpuinfo`              | CPU core information       |
| `/proc/uptime`               | System uptime              |
| `/proc/sys/kernel/osrelease` | Kernel version             |
| `/proc/` process directories | Process counting           |
| `statvfs()`                  | Disk/filesystem statistics |

---

## 8. Program Execution Flow

```text
Start
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
Evaluate Health Status
  |
  v
Calculate Overall Health
  |
  +-------> Write Health Log
  |
  +-------> Generate Health Report
  |
  v
Ask for Fault Simulation
  |
  +---- Yes ----> Run Simulation
  |
  +---- No
  |
  v
Exit
```

---

## 9. Development Environment

### Operating System

Ubuntu 24.04.4 LTS running through WSL2.

### Programming Language

C++17

### Compiler

G++ 13.3.0

### Development Environment

Visual Studio Code

### Version Control

Git

---

## 10. Build Architecture

The project uses multiple C++ source files that are compiled and linked into a single executable.

```text
main.cpp
cpu_monitor.cpp
memory_monitor.cpp
disk_monitor.cpp
diagnostic_engine.cpp
fault_simulator.cpp
logger.cpp
system_info.cpp
report_generator.cpp
        |
        v
      g++
        |
        v
    hardmon
```

---

## 11. Implementation Strategy

The project was developed incrementally:

1. Project structure creation
2. CPU monitoring implementation
3. RAM monitoring implementation
4. Disk monitoring implementation
5. Diagnostic engine implementation
6. Fault simulation
7. Health logging
8. System information collection
9. Health report generation
10. Module integration
11. Functional testing
12. Reliability testing
13. Documentation

This incremental approach allowed each module to be compiled and tested before complete system integration.

---

## 12. Design Goals

The system was designed with the following goals:

* Modular implementation
* Low system overhead
* Linux-native monitoring
* Simple diagnostic logic
* Reliable execution
* Easy testing
* Maintainable source code
* Clear health reporting
* Future extensibility

---

## 13. Future Architecture Extensions

Future versions can extend the architecture with:

* Real-time monitoring dashboard
* Additional hardware sensors
* Temperature monitoring
* Network health monitoring
* Configurable thresholds
* Historical data visualization
* Email or notification alerts
* Kernel-level monitoring
* Device-driver integration
* Remote monitoring
