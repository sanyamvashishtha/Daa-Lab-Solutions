#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
struct semaphore
{
    int mutex;
    int rcount;
    int rwait;
    bool wrt;
};
void addR(struct semaphore *s)
{
    if (s->mutex == 0 && s->rcount == 0)
    {
        printf("Sorry, File open in Write mode.\nNew Reader added to queue.\n");
        s->rwait++;
    }
    else
    {
        printf("Reader Process added\n");
        s->rcount++;
        s->mutex--;
    }
    return;
}
void addW(struct semaphore *s)
{
    if (s->mutex == 1)
    {
        s->mutex--;
        s->wrt = 1;
        printf("Writer Process added\n");
    }
    else if (s->wrt)
        printf("Sorry, Writer already operational\n");
    else
        printf("Sorry, File open in Read mode\n");
    return;
}
void remR(struct semaphore *s)
{
    if (s->rcount == 0)
        printf("No readers to remove\n");
    else
    {
        printf("Reader Removed\n");
        s->rcount--;
        s->mutex++;
    }
    return;
}
void remW(struct semaphore *s)
{
    if (s->wrt == 0)
        printf("No Writer to Remove\n");
    else
        printf("Writer Removed\n");
    s->mutex++;
    s->wrt = 0;
    if (s->rwait != 0)
    {
        s->mutex = s->rwait;
        s->rcount = s->rwait;
        s->rwait = 0;
        printf("%d waiting Readers Added.", s->rcount);
    }
}
int main()
{
    struct semaphore S1 = {1, 0, 0};
    while (1)
    {
        printf("Options :-\n1.Add Reader\n2.Add Writer\n3.Remove Reader\n4.Remove Writer\n5.Exit\nChoice: ");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addR(&S1);
            break;
        case 2:
            addW(&S1);
            break;
        case 3:
            remR(&S1);
            break;
        case 4:
            remW(&S1);
            break;
        case 5:
            printf("\tGoodBye!");
            return 0;
        default:
            printf("Invalid Entry!\n");
            continue;
        }
        printf("<<<<<< Current Status >>>>>>\n\tMutex: %d\n\tActive Readers: %d\n\tWaiting Readers: %d\n\tWriter Active: %s\n", S1.mutex, S1.rcount, S1.rwait, (S1.mutex == 0 && S1.rcount == 0) ? "YES" : "NO");
    }
}