#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, totwt = 0, totta = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], st[n], ft[n], wt[n], ta[n];
    char pn[n][10], temp[10];
    for (i = 0; i < n; i++) {
        printf("Enter process ID, arrival time & burst time: ");
        scanf("%s %d %d", pn[i], &at[i], &bt[i]);
    }

    // Sort based on burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = at[i]; at[i] = at[j]; at[j] = t;
                strcpy(temp, pn[i]); strcpy(pn[i], pn[j]); strcpy(pn[j], temp);
            }
        }
    }

    // Calculate waiting time, turnaround time, and completion time
    for (i = 0; i < n; i++) {
        st[i] = (i == 0) ? at[i] : (ft[i - 1] > at[i] ? ft[i - 1] : at[i]);
        ft[i] = st[i] + bt[i];
        wt[i] = st[i] - at[i];
        ta[i] = ft[i] - at[i];
        totwt += wt[i];
        totta += ta[i];
    }

    // Display results
    printf("\nProcessID\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", pn[i], at[i], bt[i], wt[i], ta[i]);

    printf("\nAverage Waiting Time: %.2f\n", (double)totwt / n);
    printf("Average Turnaround Time: %.2f\n", (double)totta / n);

    return 0;
}
