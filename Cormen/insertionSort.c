/*
    Algorithm for insertion Sort
    insertionSort(A):
    ---- for j in range 1 to A.length
    ---- key <- A[j]
    ---- // Insert A[j]  into the sorted sequence A[1...j]
    ---- i <- j-1
    ---- while i>0 and A[i] > key
        ---- A[i + 1] <- A[i]
        ---- i <- i + 1
    ---- A[i + 1] <- key
*/

#include <stdio.h>
#include <stdlib.h>

void input(void);
void display(void);
void insertionSort(void);

int *arr, size;

void input(void)
{
    int i;
    printf("\nEnter the Array : ");
    for (i = 0; i < size;i++)
        scanf("%d", arr + i);
}

void display(void)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ",*( arr + i));
}

void insertionSort(void)
{
    int i, key, j;
    for (i = 1; i < size;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = key;

        printf("\n===============\nArray after %d Iteration : ",i);
        display();
        printf("\n===============\n");
    }
}

int main()
{
    printf("\nEnter the size of the Array : ");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    input();
    printf("\nArray is : ");
    display();
    insertionSort();
    printf("\nSorted Array is : ");
    display();
    return 0;
}