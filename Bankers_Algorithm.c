#include<stdio.h>

int max[100][100], alloc[100][100], need[100][100], avail[100];
int n, r;

void input() {
    printf("Enter the no of Processes\t");
    scanf("%d", &n);

    printf("Enter the no of resources instances\t");
    scanf("%d", &r);

    printf("Enter the Max Matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Allocation Matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the available Resources\n");
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);
}

void show() {
    printf("Process\t Allocation\t Max\t Available\t");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t ", i+1);

        for (int j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);

        printf("\t\t");

        for (int j = 0; j < r; j++)
            printf("%d ", max[i][j]);

        printf("\t\t");

        if (i == 0)
            for (int j = 0; j < r; j++)
                printf("%d ", avail[j]);
    }
    printf("\n");
}

void cal() {
    int finish[100] = {0}, safe[100], c1 = 0;
    int flag = 1, index = 0;

    // Need Matrix
    printf("\n----Need Matrix-------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    while (flag) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int count = 0;

                for (int j = 0; j < r; j++)
                    if (need[i][j] <= avail[j]) count++;

                if (count == r) {
                    for (int k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    safe[index++] = i;
                    printf("P%d->", i);
                    flag = 1;
                }
            }
        }
    }

    printf("\n\n");
    for (int i = 0; i < n; i++) {
        if (finish[i]) c1++;
        else printf("P%d->", i);
    }

    if (c1 == n)
        printf("\n The system is in safe state");
    else {
        printf("\n Process are in dead lock");
        printf("\n System is in unsafe state");
    }
}

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    return 0;
}
