# Stage 2 — Requirements & Development Plan

## 1. Functional Requirements

HARD-MON should be able to:

* Monitor CPU, RAM, and disk usage.
* Collect basic system information.
* Classify resource usage as NORMAL, WARNING, or CRITICAL.
* Simulate different fault conditions.
* Store health information in log files.
* Generate a system health report.

## 2. Non-Functional Requirements

* **Performance:** The application should execute with low system overhead.
* **Reliability:** Monitoring should produce consistent results.
* **Usability:** The application should be simple to run and understand.
* **Maintainability:** The code should be divided into separate modules.
* **Portability:** The application should work on Linux-based systems.

## 3. Product Requirements

The system consists of the following main functions:

| Module              | Purpose                                               |
| ------------------- | ----------------------------------------------------- |
| Hardware Monitoring | Collect CPU, RAM and disk information                 |
| System Information  | Collect hostname, kernel, cores, uptime and processes |
| Diagnostic Engine   | Determine resource health status                      |
| Fault Simulator     | Test abnormal conditions                              |
| Logger              | Store health information                              |
| Report Generator    | Generate a health report                              |

## 4. Project Scope

### In Scope

* Linux system monitoring
* C++ diagnostic processing
* Fault simulation
* Health logging
* Health report generation

### Out of Scope

* Graphical user interface
* Cloud monitoring
* Database integration
* AI-based prediction
* Physical hardware control

## 5. Deliverables

The project will deliver:

* C++ source code
* Header files
* Fault simulation module
* Health logs
* Health report
* Testing documentation
* Project documentation
* Git version history

## 6. Development Roadmap

| Day   | Work                                            |
| ----- | ----------------------------------------------- |
| Day 1 | Requirements, project setup and basic structure |
| Day 2 | CPU, RAM and disk monitoring                    |
| Day 3 | Diagnostic engine and fault simulation          |
| Day 4 | Integration, logging and reporting              |
| Day 5 | Testing and debugging                           |
| Day 6 | Documentation and final demonstration           |

## 7. Development Environment

* **OS:** Ubuntu 24.04 LTS on WSL2
* **Language:** C++17
* **Compiler:** G++ 13.3
* **Editor:** Visual Studio Code
* **Version Control:** Git
* **Linux Interfaces:** `/proc`, `/sys`, `statvfs`

## 8. Version Control Plan

Git is used to track project development. Changes are committed after completing major modules or stages so that project progress can be maintained and reviewed.
