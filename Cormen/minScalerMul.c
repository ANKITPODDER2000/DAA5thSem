#include <stdio.h>
#include <limits.h>

int minOper(int *,int,int);
int minOper(int *arr, int i, int j)
{
    if(i==j)
        return 0;
    
    //printf("Noo");
    int k, sub_min;
    int min = INT_MAX;

    for (k = i; k < j;k++)
    {
        sub_min = minOper(arr, i, k) + minOper(arr, k + 1, j) + arr[i-1] * arr[k] * arr[j];
        //printf("\n=====%d", sub_min);
        if (min > sub_min)
            min = sub_min;
    }
    
    return min;
}

int main()
{
    int size, i,arr[20];
    printf("\nEnter total no of marices : ");
    scanf("%d", &size);
    size++;
    printf("\nEnter the matrix : ");
    
    for (i = 0; i < size;i++)
        scanf("%d", &arr[i]);
    
    //printf("\n%d\n", INT_MAX);
    // ->  A1[i][j] * A2[j][k]  -> i * j * k operations needed
    
    printf("\nMinimum no of mul need : %d", minOper(arr,1,size-1));
    return 0;
}