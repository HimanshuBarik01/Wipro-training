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

1. Abstract

HARD-MON is a Linux-based Hardware Health and Diagnostic System developed using C++17. It monitors CPU, RAM, and disk utilization, collects system information, evaluates resource health using predefined thresholds, simulates abnormal conditions, records health information, and generates a system health report.

The application uses standard Linux interfaces including /proc/stat, /proc/meminfo, /proc/cpuinfo, /proc/uptime, /proc/sys/kernel/osrelease, /proc, and statvfs().

The project demonstrates practical concepts in C++, Linux system programming, resource monitoring, diagnostic logic, fault simulation, logging, testing, documentation, and Git version control.

2. Introduction

Modern Linux systems continuously consume CPU, memory, and storage resources. Abnormally high resource utilization can affect system performance and reliability.

HARD-MON provides a lightweight command-line solution for monitoring selected system resources and classifying their health as NORMAL, WARNING, or CRITICAL.

The system collects real Linux system data, processes it through modular C++ components, applies diagnostic rules, and produces readable health information.

3. Problem Statement

Linux provides system information through interfaces such as /proc, but raw system statistics do not directly indicate whether a system is operating normally.

HARD-MON addresses this by:

Collecting system resource information.
Processing the collected data.
Applying predefined diagnostic thresholds.
Identifying abnormal conditions.
Calculating an overall health status.
Supporting controlled fault simulation.
Recording health information.
Generating a structured health report.
4. Objectives and Scope
Objectives

The project aims to:

Monitor CPU, RAM, and disk utilization.
Collect important Linux system information.
Detect abnormal resource utilization.
Classify resource health.
Calculate overall system health.
Simulate CPU, RAM, disk, and multiple faults.
Maintain health logs.
Generate health reports.
Demonstrate Linux and C++ system-programming concepts.
Provide a tested and maintainable implementation.
Scope
Included
CPU monitoring
RAM monitoring
Disk monitoring
System information collection
Threshold-based diagnostics
Fault simulation
Health logging
Health reporting
Functional, integration, and reliability testing
Git version control
Technical documentation
Not Included
Artificial intelligence or machine learning
Cloud monitoring
Database integration
Web or mobile application
External hardware sensors
Complex GUI
Actual Linux kernel-driver development
5. System Architecture

HARD-MON follows a modular monitoring and diagnostic architecture:

+------------------------------------------------+
|              HARD-MON APPLICATION              |
+------------------------------------------------+
                      |
                      v
+------------------------------------------------+
|             System Information                 |
| Hostname | Kernel | CPU Cores | Uptime | PID  |
+------------------------------------------------+
                      |
                      v
+------------------------------------------------+
|          Hardware Monitoring Layer             |
| CPU Monitor | RAM Monitor | Disk Monitor       |
+------------------------------------------------+
                      |
                      v
+------------------------------------------------+
|              Diagnostic Engine                |
|       NORMAL | WARNING | CRITICAL              |
+------------------------------------------------+
                      |
             +--------+--------+
             |                 |
             v                 v
+----------------------+  +----------------------+
|  Fault Simulation   |  | Logging & Reporting   |
+----------------------+  +----------------------+
Data Flow
Linux System
     ↓
System Information & Resource Data
     ↓
Monitoring Modules
     ↓
Diagnostic Engine
     ↓
Resource Status
     ↓
Overall Health
     ↓
Terminal Output
     ├── Health Log
     └── Health Report

A graphical architecture diagram will be prepared separately for the final presentation.

6. System Components
6.1 CPU Monitoring

Reads CPU statistics from /proc/stat and calculates CPU utilization over a measurement interval.

Source: src/cpu_monitor.cpp

6.2 RAM Monitoring

Reads /proc/meminfo and uses MemTotal and MemAvailable to calculate RAM utilization.

Source: src/memory_monitor.cpp

6.3 Disk Monitoring

Uses the Linux statvfs() interface to calculate filesystem capacity and disk utilization.

Source: src/disk_monitor.cpp

6.4 Diagnostic Engine

Classifies resource utilization using the following thresholds:

Usage	Status
Below 70%	NORMAL
70% to below 90%	WARNING
90% or above	CRITICAL

Overall health follows the highest severity:

CRITICAL > WARNING > NORMAL

Source: src/diagnostic_engine.cpp

6.5 Fault Simulation

Provides controlled test scenarios:

CPU Warning
CPU Critical
RAM Warning
RAM Critical
Disk Warning
Disk Critical
Multiple Faults

Source: src/fault_simulator.cpp

6.6 Logging and Reporting

The logging module records:

Timestamp
CPU usage
RAM usage
Disk usage
Overall health status

The report generator produces a structured report containing system information and health results.

Sources:

src/logger.cpp
src/report_generator.cpp

Generated files:

logs/health_log.txt
logs/health_report.txt
6.7 System Information

Collects:

Hostname
Kernel version
CPU core count
System uptime
Process count

Source: src/system_info.cpp

7. Linux Interfaces Used
Interface	Purpose
/proc/stat	CPU statistics
/proc/meminfo	Memory information
/proc/cpuinfo	CPU/core information
/proc/uptime	System uptime
/proc/sys/kernel/osrelease	Kernel version
/proc	Process information
statvfs()	Filesystem/disk information

These standard Linux interfaces allow HARD-MON to obtain system information without external monitoring software.

8. Project Structure
WiproProject/
│
├── .gitignore
├── README.md
│
├── docs/
│   ├── PROJECT_PLAN.md
│   ├── PROJECT_REPORT.md
│   ├── SYSTEM_DESIGN.md
│   └── TESTING.md
│
├── include/
│   ├── diagnostic.h
│   ├── fault_simulator.h
│   ├── logger.h
│   ├── monitor.h
│   ├── report_generator.h
│   └── system_info.h
│
├── logs/
│   ├── health_log.txt
│   └── health_report.txt
│
└── src/
    ├── cpu_monitor.cpp
    ├── diagnostic_engine.cpp
    ├── disk_monitor.cpp
    ├── fault_simulator.cpp
    ├── logger.cpp
    ├── main.cpp
    ├── memory_monitor.cpp
    ├── report_generator.cpp
    └── system_info.cpp
9. Development Environment
Component	Environment
Operating System	Ubuntu 24.04.4 LTS
Linux Environment	WSL2
Kernel	6.6.87.2-microsoft-standard-WSL2
Language	C++17
Compiler	G++ 13.3
IDE	Visual Studio Code
Version Control	Git
10. Build and Execution

From the project root:

g++ -std=c++17 src/main.cpp src/cpu_monitor.cpp src/memory_monitor.cpp src/disk_monitor.cpp src/diagnostic_engine.cpp src/fault_simulator.cpp src/logger.cpp src/system_info.cpp src/report_generator.cpp -o hardmon

Run:

./hardmon

Generated executables and object files are excluded from Git using .gitignore.

11. Application Execution

The program follows this sequence:

Start HARD-MON
      ↓
Collect System Information
      ↓
Collect CPU / RAM / Disk Data
      ↓
Evaluate Resource Thresholds
      ↓
Calculate Overall Health
      ↓
Display Health Report
      ↓
Write Health Log
      ↓
Generate Health Report
      ↓
Optional Fault Simulation
      ↓
Exit
12. Example Output

A final clean execution produced:

====================================
          HARD-MON SYSTEM
 Hardware Health & Diagnostic System
====================================

Collecting hardware information...

------------- SYSTEM INFORMATION -------------

Hostname       : Victus
Kernel Version : 6.6.87.2-microsoft-standard-WSL2
CPU Cores      : 16
System Uptime  : 19430 seconds
Processes      : 46

------------- HEALTH REPORT -------------

CPU Usage  : 0.06 % [NORMAL]
RAM Usage  : 8.56 % [NORMAL]
Disk Usage : 5.42 % [NORMAL]

------------------------------------------
Overall Health : NORMAL
------------------------------------------

Health report generated successfully.

Run fault simulation? (y/n): n

Dynamic values such as CPU usage, uptime, and process count may vary between executions.

13. Testing

Testing was performed at functional, diagnostic, integration, and reliability levels.

Functional Tests
CPU monitoring
RAM monitoring
Disk monitoring
System information
Logging
Health report generation
Diagnostic Tests
NORMAL condition
WARNING condition
CRITICAL condition
Fault Simulation Tests
CPU WARNING
CPU CRITICAL
RAM WARNING
RAM CRITICAL
Disk WARNING
Disk CRITICAL
Multiple faults
Integration Testing

All modules were integrated into the main application and executed together.

Reliability Testing

The complete application was executed five consecutive times to verify stable operation.

14. Test Results
Test Area	Result
Compilation	PASS
Program Execution	PASS
CPU Monitoring	PASS
RAM Monitoring	PASS
Disk Monitoring	PASS
System Information	PASS
NORMAL Status	PASS
WARNING Status	PASS
CRITICAL Status	PASS
CPU Fault Simulation	PASS
RAM Fault Simulation	PASS
Disk Fault Simulation	PASS
Multiple Fault Simulation	PASS
Health Logging	PASS
Health Report	PASS
Integration Testing	PASS
Reliability Testing	PASS

The final clean build and execution also completed successfully using the complete source-code set.

15. Results

The completed HARD-MON application successfully:

Collects Linux system information.
Monitors CPU, RAM, and disk utilization.
Classifies individual resource health.
Calculates overall system health.
Simulates abnormal resource conditions.
Records health information.
Generates health reports.
Executes reliably across repeated test runs.
16. Advantages and Limitations
Advantages
Lightweight implementation.
Modular C++ architecture.
Uses standard Linux interfaces.
No external hardware required.
No database or third-party monitoring software required.
Simple command-line execution.
Clear health classification.
Controlled fault testing.
Persistent logging and reporting.
Limitations
Monitors only selected resources.
Uses threshold-based diagnosis.
Fault simulation does not create actual hardware failures.
No graphical interface.
No historical data analysis.
No remote monitoring.
No hardware temperature/sensor monitoring.
Does not implement an actual Linux kernel driver.
17. Future Enhancements

Potential future improvements include:

Real-time monitoring mode
CPU/GPU temperature monitoring
Hardware sensor integration
Network monitoring
Historical data storage
Database integration
Remote monitoring
Desktop or email alerts
Graphical user interface
Web-based monitoring dashboard
Advanced diagnostic algorithms
Linux kernel driver integration
18. Version Control and Documentation

Git was used for source-code version control throughout development.

Major milestones were committed separately, including:

Project initialization
CPU monitoring
RAM monitoring
Disk monitoring
Diagnostic engine
Fault simulation
Logging
System information
Report generation
Documentation

Generated executables, object files, and logs are excluded using .gitignore.

Project documentation consists of:

README.md
docs/PROJECT_PLAN.md
docs/SYSTEM_DESIGN.md
docs/TESTING.md
docs/PROJECT_REPORT.md
19. Six-Day Development Roadmap
Day 1 — Project Introduction, Requirements & Setup
Finalize project idea and objectives.
Define problem statement and scope.
Identify functional and non-functional requirements.
Set up Ubuntu/WSL2, C++, VS Code, and Git.
Create project structure.

Deliverable: Requirements and development environment.

Day 2 — Hardware Monitoring
Implement CPU monitoring.
Implement RAM monitoring.
Implement disk monitoring.
Implement system information collection.
Test individual modules.

Deliverable: Hardware monitoring modules.

Day 3 — Diagnostics & Fault Simulation
Implement health thresholds.
Implement NORMAL, WARNING, and CRITICAL states.
Implement overall health calculation.
Implement CPU, RAM, disk, and multiple-fault simulations.

Deliverable: Diagnostic engine and fault simulator.

Day 4 — Integration, Logging & Reporting
Integrate all modules.
Implement health logging.
Implement health report generation.
Perform end-to-end testing.

Deliverable: Complete working prototype.

Day 5 — Testing & Improvement
Perform functional testing.
Perform fault simulation testing.
Perform integration testing.
Perform reliability testing.
Verify logs and reports.
Resolve identified issues.

Deliverable: Stable tested system.

Day 6 — Finalization & Presentation Preparation
Finalize documentation.
Perform final source-code audit.
Perform clean compilation and execution.
Prepare architecture diagram.
Prepare final demonstration and presentation.
Prepare GitHub repository.

Deliverable: Final project and presentation-ready documentation.

20. Learning Outcomes

The project provided practical experience in:

C++
Modular programming
Header/source organization
File handling
System-level programming
C++17 compilation
Linux
/proc filesystem
Process information
CPU and memory statistics
Filesystem statistics
Linux command-line development
Software Engineering
Requirements analysis
Modular architecture
Incremental implementation
Testing and debugging
Technical documentation
Version Control
Git initialization
Commit-based development
.gitignore
Repository organization
21. Conclusion

HARD-MON successfully demonstrates a modular Linux-based approach to hardware and system health monitoring using C++.

The application collects real Linux system data, evaluates resource utilization using predefined diagnostic rules, simulates abnormal conditions for testing, records health information, and generates structured reports.

The completed project demonstrates practical knowledge of Linux system programming, C++, resource monitoring, diagnostic logic, fault simulation, software testing, documentation, and Git version control.

The architecture can be extended in the future with real-time monitoring, hardware sensors, graphical interfaces, remote monitoring, and more advanced diagnostic capabilities.