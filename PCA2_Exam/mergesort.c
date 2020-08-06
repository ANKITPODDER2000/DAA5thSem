#include <stdio.h>
#include <stdlib.h>

void input(int * , int );
void print(int * , int );
void mergesort(int * , int , int );
void merge(int * , int , int , int );

void mergesort(int *arr , int l , int h)
{
	if(h>l)
	{
		int mid = (l + h) / 2;
		mergesort(arr , l , mid);
		mergesort(arr , mid+1 , h);

		merge(arr , l , mid , h);
	}
}

void merge(int * arr, int l, int mid, int h)
{
	int i,j,k;
	int * temp = (int * )malloc(sizeof(int ) * (h - l + 1));
	for(i = l , j = mid + 1 , k = 0 ; i<=mid || j <= h ; k++)
	{
		if(i>mid){
			*(temp + k ) = *(arr + j);
			j++;
		}
		else if(j>h){
			*(temp + k) = *(arr + i);
			i++;
		}
		else if(*(arr + i) < *(arr + j)){
			*(temp + k) = *(arr + i);
			i++;
		}
		else{
			*(temp + k ) = *(arr + j);
			j++;
		}
	}

	for(i = 0 , j = l ; j<= h ; i++ , j++)
		*(arr + j) = *(temp + i);
}

void input(int *arr , int n)
{
	printf("\nEnter all array element : ");
	for(int i=0;i<n;i++)
		scanf("%d",(arr+i));
}

void print(int *arr , int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",*(arr + i));
}

int main()
{
	int *arr,n;
	arr =  (int *)malloc(sizeof(int ) * n);
	printf("\nEnter total no of element : ");
	scanf("%d",&n);
	input(arr,n);
	printf("\nArray is : ");
	print(arr,n);
	mergesort(arr,0,n-1);
	printf("\nSorted array is : ");
	print(arr,n);

	return 0;
}