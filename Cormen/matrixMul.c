//O(n^3)

#include <stdio.h>
#include <stdlib.h>

int a[20][20],b[20][20],c[20][20],n;

int main()
{
	system("cls");
	printf("\nEnter Matrix Size : ");
	scanf("%d",&n);

	printf("\nEnter the Matrix A : \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}

	printf("\nEnter the Matrix B : \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j] = 0;
			for(int k=0;k<n;k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}


	printf("\nMatrix C is :\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
//check for : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
/*ans:
90 100 110 120
202 228 254 280
314 356 398 440
426 484 542 600
*/