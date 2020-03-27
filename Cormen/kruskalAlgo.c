#include <stdio.h>

void swap(int *, int *);
void krushkal(void);
int allVisit(void);
void print_details(void);

int adj[20][20], source[400], destination[400], weight[400], visit[20], parent[20],final_weight[20],count = 0,size;

int main()
{
    int i, j;
    printf("\nEnter the total no of node : ");
    scanf("%d", &size);

    printf("\nEnter the Adj. Matrix :\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &adj[i][j]);
            if(adj[i][j]!=0)
            {
                source[count] = i;
                destination[count] = j;
                weight[count] = adj[i][j];
                count++;
            }
        }
        visit[i] = 0;
        parent[i] = -1;
    }

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if(weight[j] > weight[j+1])
            {
                swap(&weight[j], &weight[j + 1]);
                swap(&source[j], &source[j + 1]);
                swap(&destination[j], &destination[j + 1]);
            }
        }
    }
    for (i = 0; i < count; i++)
        printf("\n%d\t%d\t%d", source[i],destination[i], weight[i]);

    krushkal();
    return 0;
}
void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void krushkal(void)
{
    int i = 0;
    while (!allVisit() && i < count)
    {
        if(visit[destination[i]]==0)
        {
            parent[destination[i]] = source[i];
            visit[source[i]] = 1;
            visit[destination[i]] = 1;
            final_weight[destination[i]] = weight[i];
        }
        i++;
    }
    print_details();
}
int allVisit(void)
{
    int i;
    for (i = 0; i < size;i++)
    {
        if(visit[i]==0)
            return 0;
    }
    return 1;
}
void print_details(void)
{
    int i;
    printf("\n  Edge  |  Weight\n-----------------\n");
    for (i = 0; i < size; i++)
    {
        if(source[0]!=i)
            printf("  %d - %d |   %d\n", parent[i], i, final_weight[i]);
    }
}

/*
0 7 3 0 0
7 0 4 9 11
3 4 0 10 0
0 9 10 0 0
0 11 0 0 0
*/