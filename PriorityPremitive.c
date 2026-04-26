#include <stdio.h>

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Arrival Time, Burst Time and Priority for Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        p[i].is_completed = 0;
    }

    int completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    while (completed != n) {
        int idx = -1;
        int best_priority = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !p[i].is_completed &&
                p[i].priority < best_priority && p[i].remaining_time > 0) {
                best_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining_time--;
            current_time++;
            if (p[idx].remaining_time == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                total_tat += p[idx].turnaround_time;
                total_wt += p[idx].waiting_time;
                p[idx].is_completed = 1;
                completed++;
            }
        } else {
            // No process available; CPU idle
            current_time++;
        }
    }

    printf("\nPreemptive Priority Scheduling (Lower number = Higher priority):\n");
    printf("----------------------------------------------------------\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority,
            p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}