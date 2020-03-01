#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input(int *, int);
void print(int *, int);
void apsp(int *, int);//APSP->All Pairs Shortest Path

void input(int *graph,int n)
{
    printf("\nEnter the adjacency matrix of weighted Graph :\n");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            scanf("%d", graph + i * n + j);
            if (*(graph + i * n + j) == -1)
                *(graph + i * n + j) = INT_MAX;
        }
    }
}
void print(int *graph,int n)
{
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            if (*(graph + i * n + j)!=INT_MAX)
                printf("%4d", *(graph + i * n + j));
            else
                printf(" INF");
        }
        printf("\n");
    }
}

void apsp(int *graph, int n)
{
    int i, j, k;
    int *distance = (int *)malloc(sizeof(int) * n * n);
    for (i = 0; i < n;i++)
    {
        for(j = 0;j < n;j++)
            *(distance + i * n + j) = *(graph + i * n + j);
    }

    //k->Intermidiate vertex
    for (k = 0; k < n;k++)
    {
        for (i = 0; i < n;i++)
        {
            for (j = 0; j < n;j++)
            {
                //printf("\n%d    %d  %d", *(distance + i * n + j), *(distance + i * n + k), *(distance + k * n + j));
                if (*(distance + i * n + j) > *(distance + i * n + k) + *(distance + k * n + j))
                    *(distance + i * n + j) = *(distance + i * n + k) + *(distance + k * n + j);
            }
        }
    }
    printf("\nShorest path is : \n");
    print(distance, n);
}

int main()
{
    int n,*graph;
    printf("\nEnter no of vertices : ");
    scanf("%d", &n);
    graph = (int *)malloc(sizeof(int) * n * n);
    input(graph, n);
    printf("\nGraph is : \n");
    print(graph, n);
    apsp(graph, n);
    return 0;
}