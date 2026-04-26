#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void sortByPriority(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n) {
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void printProcesses(struct Process p[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nPriority Scheduling (Non-Preemptive — Lower Number = Higher Priority):\n");
    printf("------------------------------------------------------------\n");
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].priority,
               p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("\nEnter burst time for Process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter priority for Process P%d (lower number = higher priority): ", i + 1);
        scanf("%d", &p[i].priority);
    }
    sortByPriority(p, n);
    calculateTimes(p, n);
    printProcesses(p, n);
    return 0;
}