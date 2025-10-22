#include <stdio.h>
#include <conio.h>

void main()
{
    int bt[10], wt[10], tat[10], i, n;
    float wavg, tavg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wavg = 0;
    tat[0] = tavg = bt[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wavg = wavg + wt[i];
        tavg = tavg + tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++)
        printf("\nP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time = %f", wavg/n);
    printf("\nAverage Turnaround Time = %f", tavg/n);

}
