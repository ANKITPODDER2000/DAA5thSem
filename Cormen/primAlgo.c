#include <stdio.h>
#include <limits.h>

void prim(void);
int minWeight(void);
void print_details(void);

int size,adj[20][20], visit[20], weight[20], parent[20];

void prim(void)
{
    int i, j;
    weight[0] = 0;
    parent[0] = -1;
    for (i = 0; i < size; i++)
    {
        int min_val = minWeight();
        visit[min_val] = 1;

        for (j = 0; j < size; j++)
        {
            if (adj[min_val][j] != 0 && visit[j] == 0 && adj[min_val][j] < weight[j])
            {
                parent[j] = min_val;
                weight[j] = adj[min_val][j];
            }
        }
    }

    print_details();
}
int minWeight(void)
{
    int min = INT_MAX, min_index, i;
    for (i = 0; i < size; i++)
    {
        if (visit[i] == 0 && weight[i] < min)
        {
            min = weight[i];
            min_index = i;
        }
    }
    return min_index;
}

void print_details(void)
{
    int i;
    printf("\n  Edge  |  Weight\n-----------------\n");
    for (i = 1; i < size; i++)
        printf("  %d - %d |   %d\n", parent[i], i, weight[i]);
}

int main()
{
    int i, j,min_weight=0;
    printf("\nEnter the total no of node : ");
    scanf("%d", &size);

    printf("\nEnter the Adj. Matrix :\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            scanf("%d", &adj[i][j]);
        visit[i] = 0;
        weight[i] = INT_MAX;
    }

    prim();
    for (i = 1; i < size; i++)
        min_weight += weight[i];
    printf("\nMin weight of MST is : %d", min_weight);
    return 0;
}



/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/