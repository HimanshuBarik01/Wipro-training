# Stage 1 — Project Introduction

## 1. Project Title

**HARD-MON — Linux-Based Hardware Health & Diagnostic System**

## 2. Project Idea and Objective

HARD-MON is a Linux-based hardware health monitoring and diagnostic system developed using **C++ and Linux system interfaces**.

The main objective of the project is to monitor important system resources such as **CPU usage, RAM usage, disk usage, system uptime, CPU core count, and running processes**, and determine the overall health condition of the system.

The system collects information from Linux system interfaces such as `/proc` and `/sys`, processes the collected information through a C++ diagnostic engine, and classifies system conditions as **NORMAL, WARNING, or CRITICAL** based on predefined thresholds.

The project also includes a fault simulation module that allows abnormal conditions to be safely simulated and tested without intentionally damaging the actual system.

## 3. Problem Statement

Modern computer systems continuously generate hardware and system performance information, but this information is distributed across different operating-system interfaces and monitoring utilities.

Manually checking CPU, memory, disk, and other system parameters can make it difficult to quickly determine whether a system is operating normally or approaching a critical condition.

HARD-MON addresses this problem by providing a lightweight application that can:

* Collect system and hardware-related information automatically.
* Monitor important resource utilization parameters.
* Identify abnormal resource conditions.
* Classify system health using predefined thresholds.
* Record health information for later analysis.
* Generate a structured health report.
* Provide a safe method for simulating abnormal conditions.

## 4. Project Scope

The scope of HARD-MON includes the development of a Linux-based monitoring and diagnostic application with the following capabilities.

### System Monitoring

The application monitors:

* CPU utilization
* RAM utilization
* Disk utilization
* CPU core count
* System uptime
* Running process count
* Hostname
* Linux kernel version

### Health Diagnosis

The system evaluates CPU, RAM, and disk utilization using predefined thresholds:

| Resource Usage   | Health Status |
| ---------------- | ------------- |
| Below 70%        | NORMAL        |
| 70% to below 90% | WARNING       |
| 90% or above     | CRITICAL      |

The individual resource statuses are combined to determine the overall system health.

### Fault Simulation

The application provides controlled simulation of:

* CPU warning condition
* CPU critical condition
* RAM warning condition
* RAM critical condition
* Disk warning condition
* Disk critical condition
* Multiple simultaneous fault conditions

This allows the diagnostic engine to be tested under different abnormal scenarios.

### Logging and Reporting

The system records health information in log files and generates a health report containing:

* System information
* Resource utilization
* Individual health statuses
* Overall health status

## 5. Expected Outcome

At the completion of the project, HARD-MON is expected to provide a working Linux-based diagnostic application capable of:

1. Collecting system and hardware-related information from Linux.
2. Monitoring CPU, RAM, and disk utilization.
3. Detecting abnormal resource conditions.
4. Classifying system health as NORMAL, WARNING, or CRITICAL.
5. Simulating different fault conditions for testing.
6. Maintaining health logs.
7. Generating a structured health report.
8. Demonstrating practical use of Linux system programming and C++.

## 6. Potential Applications

The concepts implemented in HARD-MON can be applied to:

* Basic Linux system monitoring.
* Server health monitoring.
* System diagnostic utilities.
* Performance monitoring tools.
* Educational Linux and system-programming projects.
* Automated infrastructure health checks.

The current project is designed as a **prototype diagnostic system** and focuses on CPU, memory, disk, and basic system information rather than complete enterprise-level hardware monitoring.

## 7. Stage 1 Deliverable

Stage 1 establishes the foundation of the HARD-MON project by defining:

**Project Idea → Problem → Objective → Scope → Expected Outcome → Applications**

The following stages will define the detailed requirements, system design, implementation, testing, and final delivery of the project.
