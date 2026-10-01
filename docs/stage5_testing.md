## 5.3 Test Execution Procedure

All tests were executed from the **Ubuntu/WSL terminal inside VS Code**.

### Step 1 — Navigate to Project

```bash
cd ~/WiproProject
```

### Step 2 — Compile the Complete Application

```bash
g++ -std=c++17 src/main.cpp src/cpu_monitor.cpp src/memory_monitor.cpp src/disk_monitor.cpp src/diagnostic_engine.cpp src/fault_simulator.cpp src/logger.cpp src/system_info.cpp src/report_generator.cpp -o hardmon
```

### Step 3 — Run the Application

```bash
./hardmon
```

The application displays system information, CPU/RAM/disk usage, individual health statuses, and overall health.

### Step 4 — Test Fault Simulation

When prompted:

```text
Run fault simulation? (y/n):
```

Enter:

```text
y
```

Then select individual test cases such as:

```text
1 → CPU Warning
2 → CPU Critical
3 → RAM Warning
4 → RAM Critical
5 → Disk Warning
6 → Disk Critical
7 → Multiple Faults
```

The expected status is verified against the predefined thresholds.

### Step 5 — Verify Logging

After execution:

```bash
cat logs/health_log.txt
```

The log should contain the timestamp, CPU usage, RAM usage, disk usage, and overall health status.

### Step 6 — Verify Health Report

```bash
cat logs/health_report.txt
```

The report should contain system information and the health status of CPU, RAM, disk, and the overall system.

### Step 7 — Reliability Test

The application was executed five consecutive times:

```bash
for i in {1..5}; do
    echo "===== TEST RUN $i ====="
    ./hardmon <<< n
done
```

All five executions completed successfully.

## 5.4 Test Results

| Test                 | Expected Result          | Status |
| -------------------- | ------------------------ | ------ |
| CPU Monitoring       | CPU usage calculated     | PASS   |
| RAM Monitoring       | RAM usage calculated     | PASS   |
| Disk Monitoring      | Disk usage calculated    | PASS   |
| System Information   | System details displayed | PASS   |
| NORMAL Condition     | NORMAL                   | PASS   |
| WARNING Condition    | WARNING                  | PASS   |
| CRITICAL Condition   | CRITICAL                 | PASS   |
| Multiple Faults      | Correct overall status   | PASS   |
| Health Logging       | Log generated            | PASS   |
| Health Report        | Report generated         | PASS   |
| Five-Run Reliability | All runs successful      | PASS   |

## 5.5 Testing Outcome

Testing confirmed that the HARD-MON prototype successfully performs monitoring, diagnosis, fault simulation, logging, and health-report generation.
