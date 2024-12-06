#include <stdio.h>
#include <string.h>

int main() {
    char pn[10][10], temp[10];
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10];
    int n, totwt = 0, tottat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time & Burst Time: ");
        scanf("%s %d %d", pn[i], &arr[i], &bur[i]);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arrival time, burst time, and process ID
                int tempInt = arr[i]; arr[i] = arr[j]; arr[j] = tempInt;
                tempInt = bur[i]; bur[i] = bur[j]; bur[j] = tempInt;
                strcpy(temp, pn[i]); strcpy(pn[i], pn[j]); strcpy(pn[j], temp);
            }
        }
    }

    // Calculate times
    for (int i = 0; i < n; i++) {
        star[i] = (i == 0) ? arr[i] : (finish[i - 1] > arr[i] ? finish[i - 1] : arr[i]);
        finish[i] = star[i] + bur[i];
        wt[i] = star[i] - arr[i];
        tat[i] = finish[i] - arr[i];
        totwt += wt[i];
        tottat += tat[i];
    }

    // Display results
    printf("\nPID\tArrival\tBurst\tWait\tStart\tTAT\tFinish\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", pn[i], arr[i], bur[i], wt[i], star[i], tat[i], finish[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)tottat / n);

    return 0;
}
