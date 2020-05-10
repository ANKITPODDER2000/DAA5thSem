//Not Done
#include <stdio.h>
#include <stdlib.h>

void strassen(int,int,int,int);

int a[20][20],b[20][20],c[20][20],n;

void strassen(int rs,int re,int cs,int ce)
{
	if(re-rs==2 && ce-cs==2)
	{
		c[rs][cs]     = (a[rs][cs] * b[rs][cs]) + (a[rs][cs+1] * b[rs+1][cs]);
		c[rs][cs+1]   = (a[rs][cs] * b[rs][cs+1]) + (a[rs][cs+1] * b[rs+1][cs+1]);
		c[rs+1][cs]   = (a[rs+1][cs] * b[rs][cs]) + (a[rs+1][cs+1] * b[rs+1][cs]);
		c[rs+1][cs+1] = (a[rs+1][cs] * b[rs][cs+1]) + (a[rs+1][cs+1] * b[rs+1][cs+1]);
		return;
	}
	else
	{
		strassen(rs,re/2,cs,ce/2);
		strassen(rs,re/2,ce/2,ce);
		strassen(re/2,re,cs,ce/2);
		strassen(re/2,re,ce/2,ce);
	}
}

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

	strassen(0,n,0,n);//Row->0-n  column->0-n
	printf("\nMatrix C is :\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}