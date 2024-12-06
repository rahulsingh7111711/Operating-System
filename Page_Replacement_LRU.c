#include <stdio.h>
#include <limits.h>

int checkHit(int page, int queue[], int size) {
    for (int i = 0; i < size; i++)
        if (queue[i] == page)
            return 1;
    return 0;
}

void printFrame(int queue[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d\t\t", queue[i]);
}

int main() {
    int n, frames = 3, occupied = 0, pageFaults = 0, pageHits = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int incomingStream[n], queue[frames], distance[frames];
    printf("Enter the page stream: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &incomingStream[i]);
    
    printf("Page\t Frame1 \t Frame2 \t Frame3\n");
    for (int i = 0; i < n; i++) {
        printf("%d:\t\t", incomingStream[i]);
        if (checkHit(incomingStream[i], queue, occupied)) {
            printFrame(queue, occupied);
            printf("Hit");
            pageHits++;
        } else {
            if (occupied < frames) {
                queue[occupied++] = incomingStream[i];
            } else {
                int maxDist = -1, replaceIndex = -1;
                for (int j = 0; j < frames; j++) {
                    distance[j] = 0;
                    for (int k = i - 1; k >= 0 && queue[j] != incomingStream[k]; k--)
                        distance[j]++;
                    if (distance[j] > maxDist) {
                        maxDist = distance[j];
                        replaceIndex = j;
                    }
                }
                queue[replaceIndex] = incomingStream[i];
            }
            printFrame(queue, occupied);
            printf("Page Fault");
            pageFaults++;
        }
        printf("\n");
    }
    printf("Page Hits: %d\nPage Faults: %d\n", pageHits, pageFaults);
    return 0;
}
