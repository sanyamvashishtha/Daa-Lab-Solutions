#include <stdio.h>
#include <conio.h>
#define max 25

void main()
{
    int frag[max], b[max], f[max], bf[max], ff[max];
    int i, j, nb, nf, temp;

    printf("\tMemory Management Scheme - First Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Initialize bf[] to mark all blocks as free initially
    for (i = 1; i <= nb; i++)
        bf[i] = 0;

    // Allocation logic
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] == 0 && b[j] >= f[i]) // Check if block is free and size is sufficient
            {
                ff[i] = j;             // Allocate file i to block j
                frag[i] = b[j] - f[i]; // Calculate fragmentation
                bf[j] = 1;             // Mark block as allocated
                break;
            }
        }
        if (j > nb) // If no suitable block is found
        {
            ff[i] = 0;   // File i is not allocated
            frag[i] = 0; // No fragmentation
        }
    }

    // Display results
    printf("File_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++)
    {
        if (ff[i] != 0)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        }
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\n", i, f[i]);
        }
    }
}
