#include<stdio.h>
void sjf(int n, int bt[]) {
    int wt[n], tat[n], total_wt=0, total_tat=0, temp;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(bt[i]>bt[j]) {
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }
    wt[0]=0;
    for(int i=1;i<n;i++) {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    for(int i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("Average Waiting Time: %.2f\n", (float)total_wt/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Enter burst times:\n");
    for(int i=0;i<n;i++)
        scanf("%d", &bt[i]);
    sjf(n, bt);
    return 0;
}