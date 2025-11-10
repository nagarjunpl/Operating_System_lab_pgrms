#include <stdio.h>

struct file 
{
    int all[10];
    int max[10];
    int need[10];
    int flag;
};

int main() 
    {
    struct file f[10];
    int avail[10], seq[10];
    int n, r, i, j, k, p, b, g, cnt = 0, fl = 0;
    int id, newr;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) 
    {
        printf("\nEnter details for P%d\n", i);
        printf("Enter Allocation: ");
        for (j = 0; j < r; j++)
            scanf("%d", &f[i].all[j]);
        printf("Enter Max: ");
        for (j = 0; j < r; j++)
            scanf("%d", &f[i].max[j]);
        f[i].flag = 0;
    }

    printf("\nEnter Available Resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    printf("\nEnter New Request Details:\n");
    printf("Enter process id: ");
    scanf("%d", &id);
    printf("Enter requested resources: ");
    for (i = 0; i < r; i++) 
    {
        scanf("%d", &newr);
        f[id].all[i] += newr;
        avail[i] -= newr;
    }

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < r; j++) 
        {
            f[i].need[j] = f[i].max[j] - f[i].all[j];
            if (f[i].need[j] < 0)
                f[i].need[j] = 0;
        }
    }

    cnt = 0;
    fl = 0;

    while (cnt != n) 
    {
        g = 0;
        for (j = 0; j < n; j++) 
        {
            if (f[j].flag == 0) 
            {
                b = 0;
                for (p = 0; p < r; p++) 
                {
                    if (avail[p] >= f[j].need[p])
                        b++;
                    else
                        break;
                }
                if (b == r) 
                {
                    printf("\nP%d is visited", j);
                    seq[fl++] = j;
                    f[j].flag = 1;
                    for (k = 0; k < r; k++)
                        avail[k] += f[j].all[k];
                    cnt++;
                    printf(" (Available now: ");
                    for (k = 0; k < r; k++)
                        printf("%3d", avail[k]);
                    printf(" )");
                    g = 1;
                }
            }
        }
        if (g == 0) 
        {
            printf("\n\nREQUEST NOT GRANTED — DEADLOCK OCCURRED");
            printf("\nSYSTEM IS IN UNSAFE STATE\n");
            goto display;
        }
    }

    printf("\n\nSYSTEM IS IN SAFE STATE\n");
    printf("The Safe Sequence is: ");
    for (i = 0; i < fl; i++)
        printf("P%d ", seq[i]);
    printf("\n");

display:
    printf("\n---------------------------------------------------------------\n");
    printf("Process\t   Allocation\t     Max\t     Need\n");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) 
    {
        printf("P%d\t   ", i);
        for (j = 0; j < r; j++)
            printf("%3d ", f[i].all[j]);
        printf("\t");
        for (j = 0; j < r; j++)
            printf("%3d ", f[i].max[j]);
        printf("\t");
        for (j = 0; j < r; j++)
            printf("%3d ", f[i].need[j]);
        printf("\n");
    }

    printf("---------------------------------------------------------------\n");

    return 0;
}
