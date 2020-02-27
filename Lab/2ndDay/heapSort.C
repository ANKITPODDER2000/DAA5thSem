#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
void display(int *, int);
void heapSort(int *, int);
void heapify(int *, int, int);
void swap(int *, int *);

void input(int *arr, int n)
{
    int i;
    printf("\nEnter the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
}
void heapSort(int *arr, int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
        heapify(arr, n, i);
    printf("\nArray after 1st for Loop : ");
    display(arr, n);
    for (i = n - 1; i >= 0; i--)
    {
        swap((arr + 0), (arr + i));
        heapify(arr, i, 0);
        printf("\nIntermidiate Array is : ");
        display(arr, n);
    }
}
void heapify(int *arr, int n, int pos)
{
    int large = pos;
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    if (left < n && (*(arr + left) > *(arr + pos)))
        large = left;
    if (right < n && (*(arr + right) > *(arr + pos)))
        large = right;
    if (large != pos)
    {
        swap((arr + pos), (arr + large));
        heapify(arr, n, large);
    }
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int n, *arr;
    printf("\nEnter total no of Element : ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    input(arr, n);
    printf("\nArray is : ");
    display(arr, n);
    heapSort(arr, n);
    printf("\nSorted array is : ");
    display(arr, n);
    return 0;
}