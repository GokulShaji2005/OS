#include <stdio.h>

int main() {

    int n, at[20], bt[20], ct[20], tat[20], wt[20], pid[20];
    int temp;
    float totalWat = 0, totalTat = 0;

    printf("Enter the no of process:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter the arrival time and burst time of P%d:", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && pid[i] > pid[j])) {

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = at[i] + bt[i];
        } else {
            if (ct[i - 1] < at[i])
                ct[i] = at[i] + bt[i];
            else
                ct[i] = ct[i - 1] + bt[i];
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalTat += tat[i];
        totalWat += wt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time: %f\n", totalTat / n);
    printf("Average Waiting Time: %f", totalWat / n);
    
    printf("\n Gantt Chart\n");
    printf("%d ",at[0]);
    for(int i=0;i<n;i++){
     printf("P%d %d ",pid[i],ct[i]);
    }
    return 0;
}
