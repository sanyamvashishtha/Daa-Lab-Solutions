#include <stdio.h>
#include <conio.h>

int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[50], lrucal[50], count = 0;

int lruvictim();

void main()
{
    printf("LRU PAGE REPLACEMENT ALGORITHM");
    printf("\nEnter no.of Frames: ");
    scanf("%d", &nof);
    printf("Enter no.of reference string: ");
    scanf("%d", &nor);
    printf("Enter reference string: ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("LRU PAGE REPLACEMENT ALGORITHM ");
    printf("\nThe given reference string: ");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);
    printf("\n");

    for (i = 0; i < nof; i++)
    {
        frm[i] = -1;
    }
    for (i = 0; i < 50; i++)
    {
        recent[i] = -1;
    }

    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("Reference NO %d->\t", ref[i]);
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
            count++;
            if (count <= nof)
                victim++;
            else
                victim = lruvictim();
            pf++;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
            printf("\n");
        }
        recent[ref[i]] = i;
    }
    printf("No.of page faults...%d", pf);
}

int lruvictim()
{
    int i, j, temp1, temp2, min_index = 0;
    for (i = 0; i < nof; i++)
    {
        temp1 = frm[i];
        lrucal[i] = recent[temp1];
    }
    temp2 = lrucal[0];
    for (j = 1; j < nof; j++)
    {
        if (temp2 > lrucal[j])
        {
            temp2 = lrucal[j];
            min_index = j;
        }
    }
    return min_index;
}
