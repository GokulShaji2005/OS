#include <stdio.h>

int main() {
    int n, at[20], bt[20], ct[20], tat[20], wt[20], pid[20];
    int completed[20] = {0};
    int time = 0, done = 0;
    float totalTat = 0, totalWt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    while (done < n) {
        int minBT = 9999;
        int index = -1;

        // Find process with minimum BT among arrived processes
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    index = i;
                }
            }
        }

        // If no process is ready
        if (index == -1) {
            time++;
        } else {
            ct[index] = time + bt[index];
            time = ct[index];

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            totalTat += tat[index];
            totalWt += wt[index];

            completed[index] = 1;
            done++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTat / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWt / n);

    // Gantt Chart
    printf("\nGantt Chart:\n");

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        int minIndex = -1, minCT = 9999;

        for (int j = 0; j < n; j++) {
            if (ct[j] < minCT && ct[j] > currentTime) {
                minCT = ct[j];
                minIndex = j;
            }
        }

        if (minIndex != -1) {
            printf("| P%d ", pid[minIndex]);
            currentTime = ct[minIndex];
        }
    }
    printf("|\n");

    return 0;
}
