#include <stdio.h>

int main() {
    int num, frames, pageFaults = 0, pageHits = 0;
    printf("Enter Limit: ");
    scanf("%d", &num);
    int incomingStream[num];
    printf("Enter page string: ");
    for (int i = 0; i < num; i++) scanf("%d", &incomingStream[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int temp[frames];
    for (int i = 0; i < frames; i++) temp[i] = -1;

    printf("Pages\tFrame1\t\tFrame2\t\tFrame3\t\tPage Hits\n");
    for (int i = 0; i < num; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (incomingStream[i] == temp[j]) {
                found = 1;
                pageHits++;
                break;
            }
        }
        if (!found) {
            temp[pageFaults % frames] = incomingStream[i];
            pageFaults++;
        }
        printf("%d\t\t", incomingStream[i]);
        for (int j = 0; j < frames; j++) 
            printf(temp[j] != -1 ? "%d\t\t" : "-\t\t", temp[j]);
        printf("%d\n", found);
    }

    printf("\nTotal Page Faults:\t%d\nTotal Page Hits:\t%d\n", pageFaults, pageHits);
    return 0;
}
