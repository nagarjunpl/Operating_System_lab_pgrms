#include <stdio.h>

#define MAX 25

int main() 
{
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
    static int bf[MAX], ff[MAX];
    int highest;

    printf("\n\tMemory Management Scheme - Worst Fit");

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) 
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) 
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++) 
    {
        highest = -1;
        for (j = 0; j < nb; j++) 
        {
            if (bf[j] != 1) 
            { 
                temp = b[j] - f[i];
                if (temp >= 0 && (highest == -1 || temp > (b[ff[i]] - f[i]))) 
                {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }

        if (highest != -1) 
        {
            frag[i] = b[ff[i]] - f[i];
            bf[ff[i]] = 1;
        } else 
        {
            ff[i] = -1; 
            frag[i] = -1;
        }
    }

    printf("\nFile_No\tFile_Size\tBlock_No\tBlock_Size\tFragment");
    for (i = 0; i < nf; i++) 
    {
        if (ff[i] != -1)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated\t-", i + 1, f[i]);
    }

    return 0;
}
