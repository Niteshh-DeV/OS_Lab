#include <stdio.h>
int max[100][100], alloc[100][100], need[100][100], avail[100];
int n, r;
void input();
void show();
void detectDeadlock();
int main() {
    printf("********** Deadlock Detection Algorithm ************\n");
    input();
    show();
    detectDeadlock();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of Resource instances: ");
    scanf("%d", &r);
    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    for (j = 0; j < r; j++)
        scanf("%d", &alloc[i][j]);
    printf("Enter the Available Resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);
    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

void show() {
    int i, j;
    printf("\nProcess\t Allocation\t Max\t Available\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t ", i + 1);
        for (j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);
        printf("\t");
        for (j = 0; j < r; j++)
            printf("%d ", max[i][j]);
        printf("\t");
        if (i == 0)
            for (j = 0; j < r; j++)
                printf("%d ", avail[j]);
        printf("\n");
    }
}

void detectDeadlock() {
    int finish[100] = {0}, safeSeq[100], deadlocked[100], flag = 1;
    int i, j, k, count = 0, deadCount = 0;
    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            int canBeExecuted = 1;
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canBeExecuted = 0;
                        break;
                    }
                }
                if (canBeExecuted) {
                    for (k = 0; k < r; k++)
                        avail[k] += alloc[i][k];
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    flag = 1;
                }
            }
        }
    }
    // Check for deadlock
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            deadlocked[deadCount++] = i;
        }
    }
    if (deadCount > 0) {
        printf("\nSystem is in Deadlock! Deadlocked Processes:\n");
        for (i = 0; i < deadCount; i++)
            printf("P%d\n", deadlocked[i] + 1);
        printf("\n");
    } else {
        printf("\nNo Deadlock Occurred! System is in a Safe State.\nSafe Sequence: ");
        for (i = 0; i < count; i++)
            printf("%d ", safeSeq[i] + 1);
        printf("\n");
    }
}