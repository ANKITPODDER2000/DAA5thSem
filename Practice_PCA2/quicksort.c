#include <stdio.h>
#include <stdlib.h>

void input(int *,int );
void print(char * , int * ,int );
void quicksort(int *,int ,int );
int partition(int *,int ,int );

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

void quicksort(int *arr,int s,int e)
{
	if(s<=e)
	{
		int q = partition(arr,s,e);
		quicksort(arr,s,q-1);
		quicksort(arr,q+1,e);
	}
}

int partition(int *arr,int s,int e)
{
	int key = *(arr+e);
	int j = s;
	int temp;
	for(int i=s;i<=e-1;i++)
	{
		if(*(arr+i)<key)
		{
			temp = *(arr+i);
			*(arr+j) = temp;
			*(arr+i) = *(arr+j);
			j++;
		}
	}
	temp = *(arr+j);
	*(arr+j) = *(arr+e);
	*(arr+e) = temp;
	return j;
}

int main()
{
	int *arr,n;
	printf("\nEnter total no of elements : ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int) * n);
	
	input(arr,n);
	print("\nArray is",arr,n);

	quicksort(arr,0,n-1);
	print("\nSorted array is",arr,n);
	free(arr);
	return 0;
}

/*
F:\Design&AnalysisOfAlgorithms\Practice_PCA2>a

Enter total no of elements : 10

Enter the array elements : -10 -20 -30 -40 -50 20050 200 5000 10 0

Array is : -10 -20 -30 -40 -50 20050 200 5000 10 0
Sorted array is : -50 -40 -30 -20 -10 0 10 200 5000 20050
*/