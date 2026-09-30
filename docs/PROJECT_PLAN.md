# HARD-MON — Project Requirements & Development Plan

## 1. Project Overview

**Project Name:** HARD-MON
**Full Name:** Hardware Health & Diagnostic System
**Application:** Linux-based C++ system monitoring and diagnostic application

HARD-MON is a Linux-based system monitoring and diagnostic application developed using C++17.

The system collects real-time system information from Linux, monitors CPU, RAM and disk utilization, evaluates resource usage against predefined thresholds, identifies abnormal conditions, records health information and generates a system health report.

---

## 2. Project Objective

The primary objective of HARD-MON is to provide a lightweight command-line system that can monitor important hardware-related parameters and identify abnormal resource utilization.

The system is designed to:

* Monitor CPU utilization
* Monitor RAM utilization
* Monitor disk utilization
* Collect system information
* Diagnose abnormal resource conditions
* Simulate fault conditions for testing
* Record health information
* Generate a health report

### One-Line Objective

> To monitor Linux system resources and use a C++ diagnostic engine to identify abnormal system conditions.

---

## 3. Problem Statement

Modern computer systems continuously use CPU, memory and storage resources. Excessive resource utilization can affect system performance and may indicate an abnormal system condition.

Raw system statistics alone may not provide a simple indication of whether the system is operating normally.

HARD-MON addresses this problem by collecting Linux system information and converting resource utilization into simple health states:

* NORMAL
* WARNING
* CRITICAL

The application also provides fault simulation, logging and report generation so that the diagnostic functionality can be tested without intentionally damaging the system.

---

## 4. Project Scope

### 4.1 In Scope

The project includes:

* CPU utilization monitoring
* RAM utilization monitoring
* Disk utilization monitoring
* CPU core detection
* Kernel version detection
* System uptime monitoring
* Process counting
* Health status classification
* Overall health calculation
* Fault simulation
* Health logging
* Health report generation
* Functional testing
* Integration testing
* Reliability testing
* Git-based version control
* Technical documentation

### 4.2 Out of Scope

The current version does not include:

* Actual hardware failure generation
* Physical hardware sensor integration
* Kernel driver development
* Cloud monitoring
* Database integration
* Web-based dashboard
* Artificial intelligence or machine learning prediction
* Remote system monitoring
* Automated email/SMS notifications

These features can be considered as future enhancements.

---

## 5. Functional Requirements

### FR-01 — CPU Monitoring

The system shall collect CPU utilization information from the Linux operating system and display CPU usage as a percentage.

### FR-02 — RAM Monitoring

The system shall obtain memory information from Linux and calculate RAM utilization.

### FR-03 — Disk Monitoring

The system shall obtain filesystem information and calculate disk utilization.

### FR-04 — System Information

The system shall collect and display:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count

### FR-05 — Health Classification

The system shall classify resource utilization into three health states:

* NORMAL
* WARNING
* CRITICAL

### FR-06 — Overall Health

The system shall calculate the overall system health based on CPU, RAM and disk health states.

### FR-07 — Fault Simulation

The system shall provide controlled simulation of abnormal CPU, RAM and disk conditions.

### FR-08 — Health Logging

The system shall record health measurements and overall status in a log file.

### FR-09 — Health Report

The system shall generate a readable health report containing system information, resource utilization and diagnostic status.

---

## 6. Non-Functional Requirements

### 6.1 Performance

The application should collect and process system information with minimal resource overhead.

### 6.2 Reliability

The application should execute repeatedly without unexpected termination.

### 6.3 Maintainability

The system should use separate modules for monitoring, diagnosis, logging, reporting and system information.

### 6.4 Portability

The application should operate on Linux environments that provide the required `/proc` interfaces and system calls.

### 6.5 Usability

The command-line interface should clearly display system information, resource usage and health status.

### 6.6 Testability

The system should provide controlled fault simulation so that diagnostic conditions can be tested without creating actual hardware problems.

### 6.7 Extensibility

The modular architecture should allow additional monitoring features to be added in future versions.

---

## 7. Product Requirements

### Inputs

HARD-MON obtains information from:

* Linux `/proc` filesystem
* Linux filesystem statistics
* System process information
* Simulated fault values

### Processing

The application:

1. Collects system information.
2. Calculates resource utilization.
3. Evaluates utilization against thresholds.
4. Determines individual health states.
5. Calculates overall system health.
6. Records the results.
7. Generates a health report.

### Outputs

The application produces:

* Console health information
* Health log
* Health report
* Fault simulation results

---

## 8. Diagnostic Requirements

The diagnostic engine uses predefined thresholds.

| Resource Usage   | Status   |
| ---------------- | -------- |
| Below 70%        | NORMAL   |
| 70% to below 90% | WARNING  |
| 90% or above     | CRITICAL |

The same classification logic is applied to:

* CPU
* RAM
* Disk

### Overall Health Rule

The overall system health follows the highest severity detected.

For example:

```text
CPU  = NORMAL
RAM  = WARNING
Disk = NORMAL

Overall Health = WARNING
```

Another example:

```text
CPU  = NORMAL
RAM  = CRITICAL
Disk = WARNING

Overall Health = CRITICAL
```

---

## 9. Project Modules

| Module             | Source File             | Responsibility        |
| ------------------ | ----------------------- | --------------------- |
| CPU Monitor        | `cpu_monitor.cpp`       | CPU utilization       |
| Memory Monitor     | `memory_monitor.cpp`    | RAM utilization       |
| Disk Monitor       | `disk_monitor.cpp`      | Disk utilization      |
| Diagnostic Engine  | `diagnostic_engine.cpp` | Health classification |
| Fault Simulator    | `fault_simulator.cpp`   | Fault testing         |
| Logger             | `logger.cpp`            | Health logging        |
| System Information | `system_info.cpp`       | System details        |
| Report Generator   | `report_generator.cpp`  | Health report         |
| Main Application   | `main.cpp`              | Module integration    |

---

## 10. Module Responsibilities

### 10.1 CPU Monitor

The CPU monitoring module reads CPU statistics from:

```text
/proc/stat
```

It calculates CPU utilization and returns the result as a percentage.

---

### 10.2 Memory Monitor

The memory monitoring module reads:

```text
/proc/meminfo
```

It uses memory information such as total and available memory to calculate RAM utilization.

---

### 10.3 Disk Monitor

The disk monitoring module uses the Linux `statvfs()` system call to obtain filesystem statistics and calculate disk utilization.

---

### 10.4 Diagnostic Engine

The diagnostic engine:

* Evaluates resource utilization
* Applies predefined thresholds
* Produces NORMAL/WARNING/CRITICAL states
* Determines overall system health

---

### 10.5 Fault Simulator

The fault simulator provides controlled test scenarios.

Supported scenarios:

1. CPU Warning
2. CPU Critical
3. RAM Warning
4. RAM Critical
5. Disk Warning
6. Disk Critical
7. Multiple Faults

The simulator does not intentionally overload or damage the real system.

---

### 10.6 Logger

The logging module records monitoring results with timestamps.

Output file:

```text
logs/health_log.txt
```

---

### 10.7 System Information

The system information module collects:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count

---

### 10.8 Report Generator

The report generator creates a structured health report containing:

* System information
* CPU usage
* RAM usage
* Disk usage
* Individual health states
* Overall health

Output file:

```text
logs/health_report.txt
```

---

## 11. Project Deliverables

The final project deliverables include:

1. C++ source code
2. Header files
3. Compiled HARD-MON executable
4. Health log functionality
5. Health report functionality
6. Fault simulation functionality
7. Testing documentation
8. System design documentation
9. Requirements and development plan
10. README documentation
11. Git version history
12. Final project demonstration

---

# 12. Five-Day Development Roadmap

The project was planned using a five-day development schedule.

---

## Day 1 — Project Setup & Requirements

### Activities

* Define project objective
* Identify the problem
* Define project scope
* Identify functional requirements
* Identify non-functional requirements
* Finalize project modules
* Set up Ubuntu/WSL2 environment
* Configure G++ compiler
* Configure VS Code
* Create project directory structure
* Initialize Git repository
* Configure Git
* Create initial C++ application

### Expected Deliverable

A configured development environment and initial HARD-MON project structure.

---

## Day 2 — Hardware Monitoring Modules

### Activities

* Implement CPU monitoring
* Read CPU statistics from `/proc/stat`
* Implement RAM monitoring
* Read memory information from `/proc/meminfo`
* Implement disk monitoring
* Use `statvfs()` for filesystem statistics
* Calculate resource utilization percentages
* Test CPU monitoring
* Test RAM monitoring
* Test disk monitoring

### Expected Deliverable

Working CPU, RAM and disk monitoring modules providing real Linux system data.

---

## Day 3 — Diagnostic Engine & Fault Simulation

### Activities

* Define diagnostic thresholds
* Implement health classification
* Implement overall health calculation
* Develop fault simulation module
* Add CPU warning simulation
* Add CPU critical simulation
* Add RAM warning simulation
* Add RAM critical simulation
* Add disk warning simulation
* Add disk critical simulation
* Add multiple-fault simulation
* Test diagnostic conditions

### Expected Deliverable

Working diagnostic engine and fault simulation system.

---

## Day 4 — Integration, Logging & Reporting

### Activities

* Implement system information module
* Collect hostname
* Collect kernel version
* Detect CPU cores
* Collect system uptime
* Count processes
* Implement health logging
* Implement health report generation
* Integrate all modules through `main.cpp`
* Perform end-to-end execution
* Verify generated logs
* Verify generated reports

### Expected Deliverable

Complete integrated HARD-MON application.

---

## Day 5 — Testing, Documentation & Demonstration

### Activities

* Perform functional testing
* Test CPU monitoring
* Test RAM monitoring
* Test disk monitoring
* Test diagnostic thresholds
* Test fault simulation
* Test multiple faults
* Test health logging
* Test report generation
* Perform integration testing
* Perform reliability testing
* Verify Git repository
* Complete README
* Complete system design documentation
* Complete testing documentation
* Complete project plan
* Prepare final demonstration

### Expected Deliverable

Tested, documented and demonstration-ready HARD-MON system.

---

## 13. Five-Day Roadmap Summary

| Day   | Development Stage       | Main Output                           |
| ----- | ----------------------- | ------------------------------------- |
| Day 1 | Setup & Requirements    | Project foundation                    |
| Day 2 | Monitoring              | CPU/RAM/Disk monitoring               |
| Day 3 | Diagnosis & Simulation  | Diagnostic engine + fault simulation  |
| Day 4 | Integration             | Logging + reporting + complete system |
| Day 5 | Testing & Documentation | Final tested project                  |

### Development Flow

```text
Day 1
Project Setup & Requirements
        |
        v
Day 2
Monitoring Modules
        |
        v
Day 3
Diagnostic Engine
& Fault Simulation
        |
        v
Day 4
Integration
Logging & Reporting
        |
        v
Day 5
Testing
Documentation
Demonstration
```

---

## 14. Development Methodology

HARD-MON followed an incremental development approach.

Each major module was developed and tested independently before integration.

### Development Sequence

```text
Project Setup
      |
      v
CPU Monitoring
      |
      v
RAM Monitoring
      |
      v
Disk Monitoring
      |
      v
Diagnostic Engine
      |
      v
Fault Simulation
      |
      v
Health Logging
      |
      v
System Information
      |
      v
Health Report
      |
      v
Module Integration
      |
      v
Testing
      |
      v
Documentation
```

This approach reduced integration problems and allowed individual modules to be verified before complete system integration.

---

## 15. Version Control Strategy

Git was used throughout development to maintain source-code history and track project progress.

### Primary Branch

```text
master
```

Major development components were committed separately.

Examples include:

* CPU monitoring
* RAM monitoring
* Disk monitoring
* Diagnostic engine
* Fault simulation
* Health logging
* System information
* Health report
* Testing documentation
* System design documentation
* Project planning documentation

Generated files are excluded using `.gitignore`.

Ignored files include:

```text
hardmon
*.o
logs/*.txt
```

This prevents compiled binaries and generated runtime files from being added to the source repository.

---

## 16. Development Environment

| Component            | Technology           |
| -------------------- | -------------------- |
| Operating System     | Ubuntu 24.04.4 LTS   |
| Environment          | WSL2                 |
| Programming Language | C++17                |
| Compiler             | G++ 13.3.0           |
| IDE                  | Visual Studio Code   |
| Version Control      | Git                  |
| Linux Interfaces     | `/proc`, `statvfs()` |

---

## 17. Linux Interfaces Used

| Linux Interface              | Purpose               |
| ---------------------------- | --------------------- |
| `/proc/stat`                 | CPU statistics        |
| `/proc/meminfo`              | Memory information    |
| `/proc/cpuinfo`              | CPU information       |
| `/proc/uptime`               | System uptime         |
| `/proc/sys/kernel/osrelease` | Kernel version        |
| `/proc/` process directories | Process counting      |
| `statvfs()`                  | Filesystem statistics |

---

## 18. Expected System Workflow

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
Collect CPU/RAM/Disk Data
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
  +----------+----------+
  |                     |
  v                     v
Write Health Log    Generate Report
  |                     |
  +----------+----------+
             |
             v
      Fault Simulation?
             |
       +-----+-----+
       |           |
      Yes          No
       |           |
       v           v
   Simulate      Exit
     Fault
       |
       v
     Exit
```

---

## 19. Expected Outcome

After completion, HARD-MON provides a command-line system capable of:

1. Collecting real Linux system information.
2. Monitoring CPU utilization.
3. Monitoring RAM utilization.
4. Monitoring disk utilization.
5. Detecting abnormal resource conditions.
6. Classifying health as NORMAL, WARNING or CRITICAL.
7. Calculating overall system health.
8. Simulating controlled fault conditions.
9. Recording health information.
10. Generating a system health report.
11. Performing repeatable testing.
12. Maintaining project history through Git.

---

## 20. Project Success Criteria

The project is considered successfully implemented when:

* All monitoring modules execute successfully.
* CPU, RAM and disk values are collected correctly.
* Diagnostic thresholds produce the expected status.
* Fault simulations produce the expected diagnostic results.
* Health logs are generated successfully.
* Health reports are generated successfully.
* All modules work together through the main application.
* The application can execute repeatedly without failure.
* Project documentation is complete.
* Source code is maintained under Git version control.

---

## 21. Future Development

Future versions of HARD-MON may include:

### Hardware Monitoring

* CPU temperature
* GPU temperature
* Fan speed
* Battery health
* Additional hardware sensors

### System Monitoring

* Network health
* Network bandwidth
* Process-level resource monitoring
* Service monitoring

### User Interface

* Graphical dashboard
* Real-time charts
* Historical health visualization

### Alerts

* Desktop notifications
* Email notifications
* Configurable alert thresholds

### Advanced Diagnostics

* Historical trend analysis
* Automatic anomaly detection
* Predictive maintenance
* Machine learning-based diagnosis

### Advanced Linux Integration

* Kernel-level monitoring
* Device-driver integration
* Hardware sensor interfaces
* Remote Linux system monitoring

---

## 22. Conclusion

HARD-MON provides a modular Linux-based approach to hardware-related system monitoring and diagnostic analysis.

The project combines Linux system interfaces with C++ programming to collect system information, evaluate resource utilization, simulate abnormal conditions, maintain health logs and generate system health reports.

The five-day development plan provides a structured progression from project setup and monitoring implementation to diagnosis, integration, testing and final documentation.
