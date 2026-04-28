# 🖥️ OS Lab — BE Computer Engineering (5th Semester)

A collection of C programs written for the **Operating System Laboratory** as part of the BE Computer Engineering curriculum (5th Semester). The programs cover core OS concepts including CPU scheduling algorithms, process management, and deadlock handling.

> **Note:** More programs will be added as the course progresses.

---

## 📁 Programs

### 🔄 CPU Scheduling Algorithms

| File | Algorithm | Type |
|------|-----------|------|
| [`fcfs.c`](fcfs.c) | First Come First Serve (FCFS) | Non-Preemptive |
| [`sjf.c`](sjf.c) | Shortest Job First (SJF) | Non-Preemptive |
| [`Priority.c`](Priority.c) | Priority Scheduling | Non-Preemptive |
| [`PriorityPremitive.c`](PriorityPremitive.c) | Priority Scheduling | Preemptive |

### 🔀 Process Management

| File | Description |
|------|-------------|
| [`pid.c`](pid.c) | Display current process ID (`getpid`) and parent process ID (`getppid`) |
| [`fork.c`](fork.c) | Demonstrate multiple `fork()` calls and process creation |
| [`ForkProcess.c`](ForkProcess.c) | Distinguish parent and child processes after `fork()` |

### 🔒 Deadlock

| File | Description |
|------|-------------|
| [`Bankers.c`](Bankers.c) | Banker's Algorithm — checks if the system is in a safe state and prints the safe sequence |
| [`DeadlockDetection.c`](DeadlockDetection.c) | Deadlock Detection Algorithm — identifies deadlocked processes |

---

## 🚀 How to Compile & Run

All programs are written in **C** and can be compiled with `gcc`.

```bash
# General syntax
gcc <filename>.c -o <output_name>
./<output_name>

# Examples
gcc fcfs.c -o fcfs && ./fcfs
gcc Bankers.c -o bankers && ./bankers
gcc ForkProcess.c -o forkprocess && ./forkprocess
```

> **Tip:** Programs that use `fork()` require a Linux/Unix environment (or WSL on Windows).

---

## 📚 Topics Covered

- **CPU Scheduling:** FCFS, SJF, Priority (Non-Preemptive & Preemptive)
- **Process Management:** `fork()`, `getpid()`, `getppid()`
- **Deadlock Avoidance:** Banker's Algorithm
- **Deadlock Detection:** Resource-Allocation Graph based detection

---

## 🛠️ Requirements

- GCC compiler (`gcc`)
- Linux / Unix / macOS (or WSL on Windows)

---

## 📌 Course Info

- **Course:** Operating System Lab
- **Degree:** BE Computer Engineering
- **Semester:** 5th Semester
