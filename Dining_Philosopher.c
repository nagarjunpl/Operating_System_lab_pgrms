#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int tfph, howhung, hu[20], cho;

void one();
void two();

int main() {
    int i;

    printf("\nDINING PHILOSOPHER PROBLEM\n");

    printf("Enter the total no. of Philosophers: ");
    scanf("%d", &tfph);

    printf("\nHow many are hungry: ");
    scanf("%d", &howhung);

    if (howhung == tfph)
        printf("In All are hungry, Dead lock stage will occur!\n");

    for (i = 0; i < howhung; i++) {
        printf("Enter philosopher %d position: ", i + 1);
        scanf("%d", &hu[i]);
        hu[i]--;   // convert 1-based to 0-based
    }

    do {
        printf("\n------------------------------------\n");
        printf("1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);

        if (cho == 1) one();
        else if (cho == 2) two();
        else if (cho == 3) exit(0);
        else printf("Invalid option!\n");

    } while (1);

    return 0;
}

void one() {
    int eater = hu[0];   // first hungry philosopher
    printf("\nAllow one Philosopher to eat\n");

    printf("P%d is granted to eat\n", eater + 1);

    for (int i = 1; i < howhung; i++)
        printf("P%d is waiting\n", hu[i] + 1);
}

void two() {
    printf("\nAllow two philosophers to eat at the same time\n");

    if (howhung < 2) {
        printf("Need at least two hungry philosophers.\n");
        return;
    }

    int comb = 1;

    for (int i = 0; i < howhung; i++) {
        for (int j = i + 1; j < howhung; j++) {

            int p1 = hu[i];
            int p2 = hu[j];

            printf("\nCombination %d: P%d and P%d\n", comb++, p1 + 1, p2 + 1);
            printf("P%d and P%d are granted to eat\n", p1 + 1, p2 + 1);

            // Print waiting philosophers
            for (int k = 0; k < howhung; k++) {
                int p = hu[k];
                if (p != p1 && p != p2)
                    printf("P%d is waiting\n", p + 1);
            }
        }
    }

    printf("\nEnd of all combinations.\n");
}
