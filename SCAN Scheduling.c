#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int t[20], d[20], atr[20];
    int h, n, i, j, temp, k, p, sum = 0;

    printf("Enter the no of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;      // lower end
    t[1] = h;      // head position

    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    // sort all tracks including head
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // find head index
    for (i = 0; i < n + 2; i++)
        if (t[i] == h)
            break;

    j = i;
    p = 0;

    // go left from head until 0
    while (t[j] != 0) {
        atr[p++] = t[j];
        j--;
    }
    atr[p++] = t[j];  // insert 0

    // then go right from head
    for (k = i + 1; k < n + 2; k++)
        atr[p++] = t[k];

    // calculate movements
    for (j = 0; j < p - 1; j++)
        sum += abs(atr[j + 1] - atr[j]);

    printf("\nAverage header movements: %f\n", (float)sum / n);

    return 0;
}
