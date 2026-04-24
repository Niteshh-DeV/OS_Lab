#include <stdio.h>
struct Process
{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculateTimes(struct Process p[], int n)
{
    p[0].waiting_time = 0; // First process has no waiting time
    for (int i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void printProcesses(struct Process p[], int n)
{
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nFirst Come First Serve (FCFS) Scheduling:\n");
    printf("--------------------------------------------\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time,
            p[i].waiting_time, p[i].turnaround_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("\nEnter burst time for Process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }
    calculateTimes(p, n);
    printProcesses(p, n);
    return 0;
}