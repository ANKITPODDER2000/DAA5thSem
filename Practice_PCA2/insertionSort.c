#include <stdio.h>
#include <stdlib.h>

void input(int *,int );
void print(char * , int * ,int );
void insertionSort(int *,int);

void input(int *arr,int n)
{
	printf("\nEnter the array elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",(arr+i));
}

void print(char *str,int *arr,int n)
{
	printf("%s : ",str);
	for(int i=0;i<n;i++)
		printf("%d ",*(arr+i));
}

void insertionSort(int *arr,int n)
{
	int key,j;
	for(int i=1;i<n;i++)
	{
		key = *(arr+i);
		j = i-1;
		while(j>=0 && *(arr+j)>key)
		{
			*(arr+(j+1)) = *(arr+j);
			j--;
		}
		*(arr+j+1) = key;
	}
}

int main()
{
	int *arr,n;
	printf("\nEnter total no of elements : ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int) * n);
	
	input(arr,n);
	print("\nArray is",arr,n);

	insertionSort(arr,n);
	print("\nSorted array is",arr,n);
	free(arr);
	return 0;
}

/*
Enter total no of elements : 10

Enter the array elements :  -10 -20 -30 -40 -50 20050 200 5000 10 0

Array is : -10 -20 -30 -40 -50 20050 200 5000 10 0
Sorted array is : -50 -40 -30 -20 -10 0 10 200 5000 20050
*/