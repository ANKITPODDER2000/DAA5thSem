#include <stdio.h>

int quickSort(int *, int, int);
void partition(int *, int, int);

int main()
{
    int arr[20], size, i;
    printf("\nEnter total no of element : ");
    scanf("%d", &size);
    printf("\nEnter the array : ");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray is : ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    partition(arr, 0, size - 1);
    printf("\nSorted Array is : ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void partition(int *a,int l,int h)
{
    if(h>l)
    {
        int pi = quickSort(a, l, h);
        partition(a, l, pi - 1);
        partition(a, pi + 1, h);
    }
}

int quickSort(int *a,int l,int h)
{
    int pivot = a[h],i=l-1,j,temp;
    for (j = l; j <= h - 1;j++)
    {
        if(a[j]<pivot)
        {
            temp = a[j];
            a[j] = a[++i];
            a[i] = a[j];
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[h];
    a[h] = temp;
    return i + 1;
}