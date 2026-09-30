# HARD-MON Testing Documentation

## 1. Testing Objective

The objective of testing is to verify that HARD-MON correctly collects Linux system information, calculates hardware resource utilization, identifies abnormal conditions, generates health reports, records monitoring data, and operates reliably across repeated executions.

---

## 2. Test Environment

| Component            | Configuration                    |
| -------------------- | -------------------------------- |
| Operating System     | Ubuntu 24.04.4 LTS               |
| Environment          | WSL2                             |
| Kernel               | 6.6.87.2-microsoft-standard-WSL2 |
| Programming Language | C++                              |
| Compiler             | G++ 13.3.0                       |
| IDE                  | Visual Studio Code               |
| Version Control      | Git                              |

---

## 3. Functional Testing

| Test ID | Test Case                 | Expected Result                                                 | Result |
| ------- | ------------------------- | --------------------------------------------------------------- | ------ |
| TC-01   | Compile complete project  | Project compiles without errors                                 | PASS   |
| TC-02   | Start HARD-MON            | Application starts successfully                                 | PASS   |
| TC-03   | CPU monitoring            | CPU usage is collected from Linux                               | PASS   |
| TC-04   | RAM monitoring            | RAM usage is calculated correctly                               | PASS   |
| TC-05   | Disk monitoring           | Disk usage is calculated correctly                              | PASS   |
| TC-06   | System information        | Hostname, kernel, CPU cores, uptime and processes are displayed | PASS   |
| TC-07   | CPU Warning simulation    | 75% CPU is classified as WARNING                                | PASS   |
| TC-08   | CPU Critical simulation   | 95% CPU is classified as CRITICAL                               | PASS   |
| TC-09   | RAM Warning simulation    | 75% RAM is classified as WARNING                                | PASS   |
| TC-10   | RAM Critical simulation   | 95% RAM is classified as CRITICAL                               | PASS   |
| TC-11   | Disk Warning simulation   | 75% disk usage is classified as WARNING                         | PASS   |
| TC-12   | Disk Critical simulation  | 95% disk usage is classified as CRITICAL                        | PASS   |
| TC-13   | Multiple fault simulation | Overall health becomes CRITICAL when critical faults exist      | PASS   |
| TC-14   | Health logging            | Monitoring results are stored in health_log.txt                 | PASS   |
| TC-15   | Health report generation  | Health report is generated successfully                         | PASS   |

---

## 4. Diagnostic Threshold Testing

HARD-MON uses predefined utilization thresholds.

| Resource Usage   | Diagnostic Status |
| ---------------- | ----------------- |
| Below 70%        | NORMAL            |
| 70% to below 90% | WARNING           |
| 90% and above    | CRITICAL          |

The diagnostic engine was tested using simulated CPU, RAM and disk values.

---

## 5. Fault Simulation Testing

### CPU Warning

Input:

```text
CPU = 75%
RAM = 10%
Disk = 10%
```

Expected:

```text
CPU = WARNING
Overall Health = WARNING
```

Result: PASS

### RAM Critical

Input:

```text
CPU = 10%
RAM = 95%
Disk = 10%
```

Expected:

```text
RAM = CRITICAL
Overall Health = CRITICAL
```

Result: PASS

### Multiple Faults

Input:

```text
CPU = 95%
RAM = 75%
Disk = 95%
```

Expected:

```text
CPU = CRITICAL
RAM = WARNING
Disk = CRITICAL
Overall Health = CRITICAL
```

Result: PASS

---

## 6. Logging Testing

The logging module was tested by executing the monitoring application multiple times.

The system successfully recorded:

* Timestamp
* CPU utilization
* RAM utilization
* Disk utilization
* Overall health

Log file:

```text
logs/health_log.txt
```

Result: PASS

---

## 7. Health Report Testing

The report generator was tested after successful system monitoring.

The generated report contains:

* Hostname
* Kernel version
* CPU core count
* System uptime
* Process count
* CPU utilization
* RAM utilization
* Disk utilization
* Individual diagnostic status
* Overall health

Report file:

```text
logs/health_report.txt
```

Result: PASS

---

## 8. Reliability Testing

The complete HARD-MON application was executed five consecutive times.

Each execution completed successfully without application crashes.

Result: PASS

---

## 9. Integration Testing

The following modules were tested together:

```text
CPU Monitor
     +
RAM Monitor
     +
Disk Monitor
     +
System Information
     ↓
Diagnostic Engine
     ↓
Overall Health
     ↓
Logger + Report Generator
```

The integrated application successfully collected monitoring data, determined health status, logged the result and generated a health report.

Result: PASS

---

## 10. Testing Conclusion

All implemented functional, integration, fault simulation, logging, reporting and reliability tests completed successfully.

The testing phase verified that HARD-MON performs its intended monitoring and diagnostic functions correctly in the Linux/WSL2 environment.
