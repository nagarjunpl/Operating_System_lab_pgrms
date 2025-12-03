#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek = 0;
    printf("*** SSTF Disk Scheduling Algorithm ***\n");

    printf("Enter the size of Queue: ");
    scanf("%d", &n);

    int queue[n], dist[n], i, j;

    printf("Enter the Queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // compute distance from head
    for (i = 0; i < n; i++)
        dist[i] = abs(head - queue[i]);

    // sort by distance (SSTF)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (dist[i] > dist[j]) {
                int temp = dist[i]; 
                dist[i] = dist[j]; 
                dist[j] = temp;
                
                temp = queue[i];   
                queue[i] = queue[j]; 
                queue[j] = temp;
            }
        }
    }

    // calculate total seek time
    for (i = 0; i < n; i++) {
        seek += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\nTotal Seek Time is %d", seek);
    printf("\nAverage Seek Time is %.2f\n", seek / (float)n);

    return 0;
}
