#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>


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

	//main Algo
	maxprofit = INT_MIN;
	for(i=0;i<n-1;i++)
	{
		sum = 0;
		for(j=i;j<n-1;j++)
		{
			sum = sum + *(change+j);
			maxprofit = sum > maxprofit ? sum : maxprofit;
		}
	}

	printf("\nMax profit is : %d",maxprofit);
	return 0;
}