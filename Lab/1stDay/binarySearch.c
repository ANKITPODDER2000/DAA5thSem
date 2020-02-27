#include <stdio.h>

int main()
{
    int arr[20], i,j , beg, mid, end, key,size,flag=0;
    printf("\nEnter total no of element : ");
    scanf("%d", &size);
    printf("\nEnter the array : ");

    for (i = 0; i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray is : ");
    
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    for (i = 0;i<size-1;i++)
    {
        for (j = 0; j < size-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j+1] = arr[j] + arr[j+1];
                arr[j] = arr[j + 1] - arr[j];
                arr[j + 1] = arr[j + 1] - arr[j];
            }
        }
    }
    printf("\nSorted Array is : ");
    for (i = 0; i < size;i++)
        printf("%d ", arr[i]);
    printf("\nEnter the key : ");
    scanf("%d",&key);

    beg = 0;
    end = size - 1;

    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(arr[mid]==key)
        {
            flag = 1;
            break;
        }
        else if(arr[mid]>key)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if(flag)
        printf("%d found at index : %d", key, mid);
    else
        printf("Key not found.");
    return 0;
}