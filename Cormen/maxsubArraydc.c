#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

int max_min_subarray(int* ,int ,int);
int find_max(int *,int ,int ,int);

int max_min_subarray(int *ptr,int low,int high)
{
	if(low==high)
		return *(ptr+low);
	int mid = (low+high) / 2;
	int maxLeft  = max_min_subarray(ptr,low,mid);
	int maxRight = max_min_subarray(ptr,mid+1,high);
	int maxCross = find_max(ptr,low,mid,high);

	if((maxLeft>maxRight) && (maxLeft>maxCross))
		return maxLeft;
	else if(maxRight > maxCross)
		return maxRight;
	return maxCross;
}

int find_max(int *ptr,int low,int mid,int high)
{
	int i;
	int leftMax = INT_MIN;
	int rightMax = INT_MIN;
	int sum = 0;
	for(i=mid;i>=0;i--)
	{
		sum = sum + *(ptr+i);
		if(sum>leftMax)
			leftMax = sum;
	}

	sum = 0;
	for(i=mid+1;i<=high;i++)
	{
		sum = sum + *(ptr+i);
		if(sum>rightMax)
			rightMax = sum;
	}

	return leftMax+rightMax;
}

int main()
{
	system("cls");
	int n,*price,*change,i,j,maxprofit,sum;
	printf("\nEnter no of days : ");
	scanf("%d",&n);

	price = (int *)malloc(sizeof(int) * n);
	change = (int *)malloc(sizeof(int) * (n-1));

	printf("\nEnter the Price : ");
	for(i=0;i<n;scanf("%d",(price+i++)));

	for(i=1;i<n;*(change+(i-1)) = *(price+i) - *(price+(i-1)),i++);

	//D&C Algo
	maxprofit = max_min_subarray(change,0,n-2);

	printf("\nMax profit is : %d",maxprofit);
	return 0;
}

/*
	check for:
	len = 16
	array : 100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97
	ans : 43
*/