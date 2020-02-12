#include <stdio.h>

void mergeSort(int *, int, int);
void merge(int *, int,int, int);

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
    mergeSort(arr, 0, size-1);
    printf("\nSorted Array is : ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void mergeSort(int *a, int l, int h)
{
    if(l<h)
    {
        int mid = (l + h)/2;
        mergeSort(a, 0, mid);
        mergeSort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

void merge(int *a,int l,int mid,int h)
{
    int i, j, k;
    int temp[h - l + 1];
    for (i = l, j = mid+1, k = l; i <= mid && j <= h;k++)
    {
        if(a[i]<a[j])
            temp[k] = a[i++];
        else
            temp[k] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= h)
        temp[k++] = a[j++];
    for (i = l; i <= h; i++)
        a[i] = temp[i];
}