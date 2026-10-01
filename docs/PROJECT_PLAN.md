# HARD-MON — Linux-Based Hardware Health & Diagnostic System

## 1. Project Overview

**Project Name:** HARD-MON
**Full Name:** Linux-Based Hardware Health & Diagnostic System
**Technology:** C++
**Platform:** Linux / Ubuntu
**Development Environment:** Ubuntu 24.04 LTS on WSL2, VS Code
**Version Control:** Git

HARD-MON is a Linux-based system monitoring and diagnostic application developed in C++. The system collects hardware-related information from the Linux operating system, evaluates system health using predefined thresholds, simulates hardware faults, records health information and generates a health report.

---

## 2. Project Objective

The main objective of HARD-MON is to develop a lightweight Linux-based diagnostic system capable of:

* Monitoring CPU usage
* Monitoring RAM usage
* Monitoring disk usage
* Collecting system information
* Detecting abnormal resource utilization
* Classifying system health as NORMAL, WARNING or CRITICAL
* Simulating hardware-related faults
* Recording health information in log files
* Generating a system health report

---

## 3. Problem Statement

System administrators and users need a simple method to identify abnormal resource utilization and understand the health condition of a Linux system.

Traditional monitoring tools may provide large amounts of information without directly classifying the system condition.

HARD-MON addresses this problem by collecting system information and applying predefined diagnostic rules to produce an easy-to-understand health status.

---

## 4. Project Scope

### Included

* CPU monitoring
* RAM monitoring
* Disk monitoring
* System information collection
* Threshold-based diagnostics
* Fault simulation
* Health logging
* Health report generation
* Testing and reliability verification
* Git-based version control
* Project documentation

### Not Included

* Artificial intelligence or machine learning
* Cloud monitoring
* Database integration
* Web application
* Mobile application
* External hardware sensors
* Kernel module development
* Complex graphical user interface

---

# 5. Functional Requirements

The system shall:

1. Collect CPU utilization from Linux.
2. Collect RAM utilization from Linux.
3. Collect disk utilization.
4. Display hostname and kernel information.
5. Display CPU core count.
6. Display system uptime.
7. Count running processes.
8. Classify individual resource health.
9. Calculate overall system health.
10. Simulate CPU, RAM and disk faults.
11. Support multiple-fault simulation.
12. Store health events in a log file.
13. Generate a health report.
14. Allow repeated execution without failure.

---

# 6. Non-Functional Requirements

The system should:

* Be lightweight.
* Be easy to execute from a Linux terminal.
* Provide readable output.
* Use modular C++ code.
* Provide reliable results.
* Maintain clean source-code organization.
* Use version control.
* Generate documentation for development and testing.
* Avoid unnecessary external dependencies.

---

# 7. Product Requirements

The final application should provide:

### Monitoring

* CPU utilization
* RAM utilization
* Disk utilization
* CPU core count
* System uptime
* Process count
* Hostname
* Kernel version

### Diagnostics

* NORMAL status
* WARNING status
* CRITICAL status
* Overall health status

### Fault Simulation

* CPU warning
* CPU critical
* RAM warning
* RAM critical
* Disk warning
* Disk critical
* Multiple simultaneous faults

### Reporting

* Health log
* Health report
* System information
* Individual resource status
* Overall health status

---

# 8. Diagnostic Requirements

The system uses predefined resource-utilization thresholds.

| Resource Usage   | Status   |
| ---------------- | -------- |
| Below 70%        | NORMAL   |
| 70% to below 90% | WARNING  |
| 90% or above     | CRITICAL |

The overall health status follows the highest detected severity:

```text
CRITICAL > WARNING > NORMAL
```

If any monitored resource reaches CRITICAL status, the overall system status becomes CRITICAL.

If no resource is CRITICAL but at least one is WARNING, the overall status becomes WARNING.

If all resources are NORMAL, the overall status is NORMAL.

---

# 9. Project Modules

## Module 1 — Hardware Data Collector

Collects hardware and system-related information from Linux.

Responsibilities:

* CPU usage
* RAM usage
* Disk usage
* CPU core count
* System uptime
* Process count

---

## Module 2 — System Monitoring Engine

Reads Linux system information using interfaces such as:

* `/proc/stat`
* `/proc/meminfo`
* `/proc/cpuinfo`
* `/proc/uptime`
* `/proc/sys/kernel/osrelease`
* `/proc` process directories
* `statvfs()`

---

## Module 3 — Diagnostic Engine

Evaluates collected resource utilization.

Responsibilities:

* Apply thresholds
* Generate resource status
* Calculate overall health
* Identify abnormal conditions

---

## Module 4 — Fault Simulation Module

Provides controlled fault scenarios for testing.

Supported scenarios:

* CPU WARNING
* CPU CRITICAL
* RAM WARNING
* RAM CRITICAL
* Disk WARNING
* Disk CRITICAL
* Multiple faults

---

## Module 5 — Alert & Logging Module

Records system health information.

The module stores:

* Timestamp
* CPU usage
* RAM usage
* Disk usage
* Overall health status

---

## Module 6 — System Information Module

Collects:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count

---

## Module 7 — Health Report Generator

Generates a structured health report containing:

* System information
* Resource utilization
* Individual health status
* Overall system health

---

# 10. Project Deliverables

The project deliverables include:

* C++ source code
* Header files
* Working HARD-MON executable
* Fault simulation module
* Health log
* Health report
* README documentation
* System design documentation
* Testing documentation
* Project report
* Project plan
* Git repository
* Architecture diagram
* Final presentation

---

# 11. Six-Day Development Roadmap

## Day 1 — Project Introduction, Requirements & Setup

### Activities

* Finalize project idea.
* Define project objective.
* Identify the problem statement.
* Define project scope.
* Identify functional requirements.
* Identify non-functional requirements.
* Prepare initial project plan.
* Set up Ubuntu/WSL2 environment.
* Configure C++ compiler.
* Configure VS Code.
* Initialize Git repository.
* Create project directory structure.

### Expected Deliverable

**Project requirements + development environment + initial Git repository**

---

## Day 2 — Hardware Monitoring Modules

### Activities

* Implement CPU monitoring.
* Implement RAM monitoring.
* Implement disk monitoring.
* Read Linux `/proc` interfaces.
* Implement system information collection.
* Collect:

  * Hostname
  * Kernel version
  * CPU cores
  * Uptime
  * Process count
* Compile and test individual modules.

### Expected Deliverable

**Working Hardware Monitoring Module**

---

## Day 3 — Diagnostic Engine & Fault Simulation

### Activities

* Implement diagnostic thresholds.
* Implement NORMAL status.
* Implement WARNING status.
* Implement CRITICAL status.
* Implement overall health calculation.
* Implement CPU fault simulation.
* Implement RAM fault simulation.
* Implement disk fault simulation.
* Implement multiple-fault simulation.
* Test all diagnostic conditions.

### Expected Deliverable

**Diagnostic Engine + Fault Simulation Module**

---

## Day 4 — Integration, Logging & Reporting

### Activities

* Integrate all monitoring modules.
* Integrate the diagnostic engine.
* Integrate fault simulation.
* Implement health logging.
* Implement health report generation.
* Integrate system information.
* Build the complete application.
* Perform end-to-end execution testing.
* Resolve integration or compilation issues.

### Expected Deliverable

**Complete working HARD-MON prototype**

---

## Day 5 — Testing, Debugging & Improvement

### Activities

* Perform CPU monitoring tests.
* Perform RAM monitoring tests.
* Perform disk monitoring tests.
* Test NORMAL conditions.
* Test WARNING conditions.
* Test CRITICAL conditions.
* Test multiple faults.
* Verify health logs.
* Verify health reports.
* Perform integration testing.
* Perform repeated-execution reliability testing.
* Fix identified issues.
* Clean generated build artifacts.
* Verify Git status.

### Expected Deliverable

**Tested and stable HARD-MON system**

---

## Day 6 — Finalization, Documentation & Demonstration

### Activities

* Finalize README.
* Finalize project plan.
* Finalize system design documentation.
* Finalize testing documentation.
* Finalize project report.
* Perform final source-code audit.
* Verify complete project structure.
* Perform clean compilation.
* Perform final application execution.
* Prepare professional architecture diagram.
* Prepare project presentation.
* Prepare live demonstration flow.
* Prepare viva/interview questions and answers.
* Prepare GitHub repository.
* Push final project to GitHub.

### Expected Deliverable

**Final HARD-MON project + complete documentation + GitHub repository + presentation**

---

# 12. Six-Day Summary

| Day   | Major Activity                       | Deliverable                  |
| ----- | ------------------------------------ | ---------------------------- |
| Day 1 | Introduction, Requirements & Setup   | Requirements + Project Setup |
| Day 2 | Hardware Monitoring                  | Monitoring Modules           |
| Day 3 | Diagnostics & Fault Simulation       | Diagnostic Engine            |
| Day 4 | Integration, Logging & Reporting     | Working Prototype            |
| Day 5 | Testing & Improvement                | Stable Tested System         |
| Day 6 | Documentation, GitHub & Presentation | Final Project                |

---

# 13. Development Methodology

The project follows an incremental development approach.

Each major module is developed and tested individually before integration.

The development sequence is:

```text
Requirements
     ↓
Environment Setup
     ↓
Hardware Monitoring
     ↓
Diagnostic Engine
     ↓
Fault Simulation
     ↓
Logging & Reporting
     ↓
Integration
     ↓
Testing
     ↓
Documentation
     ↓
Final Demonstration
```

---

# 14. Version Control Strategy

Git is used for source-code version control.

Development follows a commit-based workflow.

Major development milestones are committed separately, including:

* Project initialization
* CPU monitoring
* RAM monitoring
* Disk monitoring
* Diagnostic engine
* Fault simulation
* Logging
* System information
* Report generation
* Documentation
* Final project updates

Generated files such as executables, object files and generated logs are excluded using `.gitignore`.

---

# 15. Development Environment

### Operating System

Ubuntu 24.04 LTS

### Linux Environment

WSL2

### Programming Language

C++17

### Compiler

G++ 13.3

### IDE

Visual Studio Code

### Version Control

Git

### Linux Interfaces

* `/proc/stat`
* `/proc/meminfo`
* `/proc/cpuinfo`
* `/proc/uptime`
* `/proc/sys/kernel/osrelease`
* `/proc`
* `statvfs()`

---

# 16. Expected System Workflow

The expected application workflow is:

```text
Start HARD-MON
      ↓
Collect System Information
      ↓
Collect CPU Data
      ↓
Collect RAM Data
      ↓
Collect Disk Data
      ↓
Evaluate Resource Thresholds
      ↓
Calculate Overall Health
      ↓
Display Health Status
      ↓
Write Health Log
      ↓
Generate Health Report
      ↓
Optional Fault Simulation
      ↓
End
```

---

# 17. Expected Outcome

At the completion of the project, HARD-MON should provide a working Linux-based diagnostic application capable of monitoring system resources and identifying abnormal utilization.

The system should:

* Successfully collect Linux system information.
* Monitor CPU, RAM and disk utilization.
* Classify system health.
* Simulate abnormal conditions.
* Record health events.
* Generate health reports.
* Execute reliably.
* Maintain modular and maintainable source code.
* Provide complete project documentation.

---

# 18. Success Criteria

The project will be considered successful when:

* All major modules compile successfully.
* The complete application executes successfully.
* CPU, RAM and disk monitoring work correctly.
* Diagnostic thresholds produce the expected results.
* Fault simulations produce the expected statuses.
* Logs are generated correctly.
* Health reports are generated correctly.
* Repeated execution is stable.
* Documentation is complete.
* Source code is maintained through Git.
* The final project can be demonstrated successfully.

---

# 19. Future Development

Possible future enhancements include:

* Real-time monitoring mode
* Graphical user interface
* Network monitoring
* Temperature monitoring
* Hardware sensor integration
* Email or desktop alerts
* Historical health analysis
* Database storage
* Advanced diagnostic algorithms
* Linux kernel driver integration
* Remote system monitoring

---

# 20. Final Project Outcome

HARD-MON provides a modular Linux-based approach for monitoring and diagnosing basic system-health conditions.

The completed project demonstrates practical knowledge of:

* Linux system interfaces
* C++ programming
* System programming
* File-system and process information
* Resource monitoring
* Diagnostic logic
* Fault simulation
* Logging
* Report generation
* Software testing
* Git version control
* Technical documentation
