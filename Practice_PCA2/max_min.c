#include <stdio.h>
#include <stdlib.h>

void input(int *,int );
void print(char * , int * ,int );
void max_min(int ,int );

int arr[20],n,max,min;

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
void max_min(int s,int e)
{
	if(s==e)
	{
		max = min = arr[s];
	}
	else if(e==s+1)
	{
		if(arr[s]>arr[e])
		{
			max = arr[s];
			min = arr[e];
		}
		else
		{
			max = arr[e];
			min = arr[s];
		}
	}
	else
	{
		int max1,min1,max2,min2;
		int mid = (s+e)/2;
		max_min(s,mid);
		max1 = max;
		min1 = min;
		max_min(mid+1,e);
		min2 = min;
		max2 = max;
		max = max1>max2 ? max1 : max2;
		min = min1>min2 ? min2 : min1;
	}
}

int main()
{
	printf("\nEnter total no of elements : ");
	scanf("%d",&n);
	input(arr,n);
	print("\nArray is",arr,n);
	max_min(0,n-1);
	printf("\nMax is :%d\nMin is : %d",max,min);

	return 0;
}
/*
F:\Design&AnalysisOfAlgorithms\Practice_PCA2>a

Enter total no of elements : 10

Enter the array elements : -20 -40 -50 20050 200 5000 10 0 -10 -30

Array is : -20 -40 -50 20050 200 5000 10 0 -10 -30
Max is :20050
Min is : -50
*/