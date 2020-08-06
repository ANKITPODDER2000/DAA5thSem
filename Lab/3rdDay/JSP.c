#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
int jsp(void);
//void display(int *);

int p[20], d[20], slot[20],counter[20],size;


void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int jsp(void)
{
    int profit = 0,i,j;
    for (i = 0; i < size;i++)
    {
        for (j = d[i] - 1; j >= 0;j--)
        {
            if(slot[j]==-1)
            {
                profit += p[i];
                slot[j] = i;
                break;
            }
        }
    }
    return profit;
}
/*void display(int *a)
{
    for (int i = 0; i < size;i++)
    {
        printf("%d ", a[i]);
    }
}*/

int main()
{
    system("cls");
    int i,j;
    printf("\nEnter total no of Job : ");
    scanf("%d", &size);
    printf("\nEnter value of each job : ");
    for (i = 0; i < size;i++)
        scanf("%d", &p[i]);
    printf("\nEnter deadline of eachjob : ");
    for (i = 0; i < size;i++)
    {
        scanf("%d", &d[i]);
        slot[i] = -1;
        counter[i] = i;
    }
    for (i = 0; i < size;i++)
    {
        for (j = 0; j < size;j++)
        {
            if(p[j]<p[j+1])
            {
                swap(&counter[j], &counter[j + 1]);
                swap(&p[j], &p[j + 1]);
                swap(&d[j], &d[j + 1]);
            }
        }
    }
    /*
        printf("\nCounter : ");
        display(counter);
        printf("\nProfit : ");
        display(p);
        printf("\nDeadLine : ");
        display(d);
        printf("\nSlot : ");
        display(slot);
    */
    printf("\nMax profit of seller : %d", jsp());
    printf("\nSequence of Job");
    for (i = 0; i < size;i++)
    {
        if(slot[i]!=-1)
        {
            printf(" -> %d", counter[slot[i]]+1);
        }
    }
    return 0;
}