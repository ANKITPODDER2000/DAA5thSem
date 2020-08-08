#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

void dijkstra(int );
int printSolution(int *); 
int minDistance(int *, int *);

int v,*adj,source;

void dijkstra(int src) 
{ 
	int *dist,*visit;
	dist = (int *)malloc(sizeof(int) * v);
	visit = (int *)malloc(sizeof(int) * v);

	for (int i = 0; i < v; i++) 
	{
		dist[i] = INT_MAX;
		visit[i] = 0; //0 -> Not Visited , 1 -> Visited
	}

	dist[src] = 0; 

	for (int count = 0; count < v - 1; count++) { 
		int u = minDistance(dist, visit); 
		visit[u] = 1;
		
		//printf("\n====%d",u);
		for (int i = 0; i < v; i++)
		{
			if (!visit[i] && *(adj+u*v+i)!=0 && dist[u] + *(adj+u*v+i) < dist[i]) 
			{
				dist[i] = dist[u] + *(adj+u*v+i);
			}
		}
	} 

	printSolution(dist); 
} 

int minDistance(int *dist, int *visit) 
{
	int min = INT_MAX,min_index; 

	for (int i = 0; i < v; i++)
	{ 
		if (visit[i] == 0 && dist[i] <= min) 
		{
			min = dist[i],
			min_index = i; 
		}
	}
	
	return min_index; 
} 

int printSolution(int *dist) 
{ 
	printf("\nVertex | Weight\n");
	printf("----------------\n");
	for (int i = 0; i < v; i++) 
	{
		if(*(dist+i) ==INT_MAX)
			printf("%d      |   INF\n", i);
		else
			printf("%d      |   %d\n", i, dist[i]);
	} 
} 
 
int main() 
{ 
	system("cls");
	printf("\nEnter no of Vertices : ");
	scanf("%d",&v);

	adj = (int *)malloc(sizeof(int ) * v * v);
	printf("\nEnter the Adjacency matrix :\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			scanf("%d",(adj + i * v + j));
	}

	printf("\nEnter the Source : ");
	scanf("%d",&source);

	/*printf("\nGraph is :\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			printf("%d ",*(adj + i * v + j));
		printf("\n");
	}
	*/


	dijkstra(source); 

	return 0; 
} 

/*
0 0 2 0 0 0 0
4 0 0 0 0 0 0
0 0 0 0 0 0 0
0 15 0 0 0 5 23	
0 17 0 0 0 0 11
0 0 9 0 0 0 13
0 0 0 0 0 0 0

source -> 3
*/