#include <stdio.h>
#include <conio.h>
int i, j, nor, nof, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
void main()
{
    printf("FIFO PAGE REPLACEMENT ALGORITHM");
    printf("\nEnter no.of frames: ");
    scanf("%d", &nof);
    printf("Enter number of Pages: ");
    scanf("%d", &nor);
    printf("Enter the Page No: ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);
    printf("The given Pages are: ");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);
    for (i = 1; i <= nof; i++)
        frm[i] = -1;
    printf("\n");
    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("page no %d->\t", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            pf++;
            victim++;
            victim = victim % nof;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
            printf("\n");
        }
    }
    printf("No.of pages faults:%d", pf);
}