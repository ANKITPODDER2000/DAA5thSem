#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input_graph(int *,int);
void print_graph(int *, int);
int PRIM(int *, int);
int allvisit(int *, int);
int SelectVertex(int *, int *, int);
void print_details(int *, int *, int);

void input_graph(int *a,int size)
{
    int i, j;
    for (i = 0; i < size;i++)
        for (j = 0; j < size;scanf("%d",(a+i*size+j)),j++);
}

void print_graph(int *a, int size)
{
    int i, j;
    for (i = 0; i < size;printf("\n"), i++)
        for (j = 0; j < size; printf("%d ", *(a + i * size + j)), j++);
}

int PRIM(int *a,int size)
{
    int *visit = (int *)malloc(sizeof(int) * size);
    int *weight = (int *)malloc(sizeof(int) * size);
    int *parent = (int *)malloc(sizeof(int) * size);
    int i, j, k;
    for (i = 0; i < size;visit[i]=0,weight[i]=INT_MAX,parent[i]=-1,i++);

    weight[0] = 0;
    while(allvisit(visit,size)!=1)
    {
        j = SelectVertex(visit,weight,size);

        visit[j] = 1;

        for (k = 0; k < size;k++)
        {
            if((*(a+j*size+k)!=0) && (*(a+j*size+k) < *(weight+k)))
            {
                *(weight + k) = *(a + j * size + k);
                *(parent + k) = j;
            }
        }
    }
    print_details(parent,weight, size);
    int sum = 0;
    for (i = 0; i < size;i++)
        sum += weight[i];
    return sum;
}

int allvisit(int *visit, int size)
{
    for (int i = 0; i < size;i++)
    {
        if(*(visit+i)==0)
            return 0;
    }
    return 1;
}

int SelectVertex(int *visit,int *weight,int size)
{
    int min_weight = INT_MAX, min_index = 0,i;
    for (i = 0; i < size;i++)
    {
        if((*(visit+i)==0) && (*(weight+i) < min_weight))
        {
            min_index = i;
            min_weight = weight[i];
        }
    }
    return min_index;
}

void print_details(int *parent, int *weight, int size)
{
    int i;
    printf("\n  Edge  |  Weight\n-----------------\n");
    for (i = 1; i < size; i++)
        printf("  %d - %d |   %d\n", parent[i], i, weight[i]);
}

int main()
{
    system("cls");
    int *graph, size;

    printf("\nEnter total no of Vertices : ");
    scanf("%d", &size);
    graph = (int *)malloc(sizeof(int) * size *size);

    printf("\nEnter the Adjacency Matrix :\n");
    input_graph(graph,size);

    printf("\nGraph is:\n");
    print_graph(graph,size);

    int minWeight = PRIM(graph, size);
    printf("\n========================\nMin Weight is : %d\n", minWeight);
    return 0;
}

/*
0 7 3 0 0
7 0 4 9 11
3 4 0 10 0
0 9 10 0 0
0 11 0 0 0
*/