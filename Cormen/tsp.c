#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findmincost(int );
int left(void);

int size,flag[20],adj[20][20];

int left(void)
{
	int count = 0;
	for(int i=0;i<size;i++){
		if(flag[i]==1)
			count++;
	}
	return count;		
}

int findmincost(int start)
{
	int min_cost = INT_MAX;
	int a = 0;
	if(left()==0)
	{
		if(adj[start][0]==0)
			return INT_MAX;
		else
			return adj[start][0];
	}

	for(int i=1;i<size;i++)
	{
		if(flag[i]==0)
			continue;
		else
		{
			flag[i] = 0;
			a = adj[start][i] + findmincost(i);
			flag[i]=1;
			if(a<min_cost)
				min_cost = a;
		}
	}

	return min_cost;
}

int main()
{
	printf("\nEnter no of Vertices : ");
	scanf("%d",&size);
	printf("\nEnter the Adjacency Matrix \n");

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			scanf("%d",&adj[i][j]);
		flag[i] = 1;
	}

	flag[0] = 0;
	int cost = findmincost(0);
	printf("\nOptimal cost is : %d",cost);
	return 0;
}
/*
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
===============================
0 2 9 10
1 0 6 4
15 7 0 8
6 3 12 0
*/