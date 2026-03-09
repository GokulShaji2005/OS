#include <stdio.h>

int main() {

    int n, at[20], bt[20], ct[20], tat[20], wt[20], pid[20], priority[20];
    int completed[20] = {0};
    int currentTime = 0, completedCount = 0;
    float totalWat = 0, totalTat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time, burst time and priority of P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &priority[i]);
    }

    while (completedCount < n) {

        int index = -1;
        int highestPriority = 9999;

   
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= currentTime) {
                if (priority[i] < highestPriority) {
                    highestPriority = priority[i];
                    index = i;
                }
            }
        }

        if (index == -1) {
            currentTime++;
        } else {
            ct[index] = currentTime + bt[index];
            currentTime = ct[index];

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            totalTat += tat[index];
            totalWat += wt[index];

            completed[index] = 1;
            completedCount++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], priority[i],
               ct[i], tat[i], wt[i]);
    }
    
    printf("\n Gantt Chart\n");
    printf("%d ",at[0]);
    for(int i=0;i<n;i++){
     printf("P%d %d ",pid[i],ct[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTat / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWat / n);

    return 0;
}
