#include <stdio.h>
#include <stdlib.h>

void input(int *,int );
void print(char * , int * ,int );
void mergesort(int *,int,int);
void merge(int *,int ,int ,int );

int n;

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

void mergesort(int *arr,int s,int e)
{
	if(s<e)
	{
		int mid = (s+e)/2;
		mergesort(arr,s,mid);
		mergesort(arr,mid+1,e);
		merge(arr,s,mid,e);
	}
}

void merge(int *arr,int s,int mid,int e)
{
	int i,j,k;
	int *temp = (int *)malloc(sizeof(int)*(n));
	for(i=s,j=mid+1,k=s;i<=mid || j<=e;k++)
	{
		if(i>mid){
			*(temp+k) = *(arr+j);
			j++;
		}
		else if(j>e){
			*(temp+k) = *(arr+i);
			i++;
		}
		else if(*(arr+i)<*(arr+j)){
			*(temp+k) = *(arr+i);
			i++;
		}
		else{
			*(temp+k) = *(arr+j);
			j++;
		}
	}

	for(i=s;i<=e;i++)
		*(arr+i) = *(temp+i);
}

int main()
{
	int *arr;
	printf("\nEnter total no of elements : ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int) * n);
	
	input(arr,n);
	print("\nArray is",arr,n);

	mergesort(arr,0,n-1);
	print("\nSorted array is",arr,n);
	free(arr);
	return 0;
}

/*
Enter total no of elements : 10

Enter the array elements :  -10 -20 -30 -40 -50 20050 200 5000 10 0

Array is : -20 -40 -50 20050 200 5000 10 0 -10 -30
Sorted array is : -50 -40 -30 -20 -10 0 10 200 5000 20050
*/