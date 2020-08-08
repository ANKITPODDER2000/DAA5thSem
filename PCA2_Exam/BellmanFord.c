#include <stdio.h>
#include <limits.h>

int weight[20][20],distance[20],v,i,j,k;

void BellmanFord(void)
{
	for(i=0;i<v-1;i++)
	{
		for(j=0;j<v;j++)
		{
			for(k=0;k<v;k++)
				if((weight[j][k]!=0) && (distance[k] > weight[j][k]+distance[j]))
					distance[k] = weight[j][k]+distance[j];
		}	
	}

	for(j=0;j<v;j++)
	{
		for(k=0;k<v;k++)
			if((weight[j][k]!=0) && (distance[k]!=INT_MAX) && (distance[k] > weight[j][k]+distance[j]))
				printf("Graph contains negative weight cycle");
	}

}
int main()
{
	printf("\nEnter no of Vertices : ");
	scanf("%d",&v);

	printf("\nEnter the Weight Adjacency :\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			scanf("%d",&weight[i][j]);
		distance[i] = INT_MAX;
	}

	distance[0] = 0;
	BellmanFord();

	printf("\nDistance from 1st Vertices : ");
	for(i=0;i<v;i++)
		printf("%d ",distance[i]);
}
/*
0 -1 4 0 0
0 0 3 2 2
0 0 0 0 0
0 1 5 0 0
0 0 0 -3 0
*/