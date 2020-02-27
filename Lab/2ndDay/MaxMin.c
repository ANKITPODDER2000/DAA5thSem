#include <stdio.h>

void max_min(int , int );

int a[20], max, min;

void max_min(int beg,int end)
{
    int min1, max1;
    if(beg==end)
        max = min = a[beg];
    else if(beg==end-1)
    {
        if(a[beg]>a[end])
        {
            max = a[beg];
            min = a[end];
        }
        else
        {
            max = a[end];
            min = a[beg];
        }
    }
    else
    {
        int mid = (beg + end) / 2;
        max_min(beg, mid);
        max1 = max;
        min1 = min;
        max_min(mid + 1, end);
        max = max1 > max ? max1 : max;
        min = min1 < min ? min1 : min;
    }
}

int main()
{
    int size,i;
    printf("\nEnter the size of the Array : ");
    scanf("%d", &size);
    printf("\nEnter the Array : ");
    for (i = 0; i < size;i++)
        scanf("%d", &a[i]);
    max = min = a[0];
    max_min(0, size - 1);
    printf("\nDone");
    printf("\nMax is : %d\nMin is : %d", max, min);
    return 0;
}