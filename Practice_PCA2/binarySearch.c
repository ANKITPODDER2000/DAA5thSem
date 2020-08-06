#include <stdio.h>
#include <stdlib.h>

void input(int *,int );
void print(char * , int * ,int );
int binarySearch(int *,int ,int,int );
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

int binarySearch(int *arr,int s,int e,int key)
{
	if(s>e)
		return -1;
	int mid = (s+e)/2;
	if(*(arr+mid)==key)
		return mid;
	else if(*(arr+mid)>key)
		return binarySearch(arr,s,mid-1,key);
	else
		return binarySearch(arr,mid+1,e,key);
}
int main()
{
	int n,*arr,key,index;
	
	printf("\nEnter total no of elements in the Array : ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int ) * n);
	
	input(arr,n);
	print("Array is",arr,n);

	printf("\nEnter the Element to search in the Array : ");
	scanf("%d",&key);
	insertionSort(arr,n);

	index = binarySearch(arr,0,n-1,key);
	if(index!=-1)
		printf("Element found!");
	else
		printf("\nElement not found.");

	free(arr);

	return 0;
}