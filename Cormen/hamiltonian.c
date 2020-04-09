#include <stdio.h>
int hamCycleUtil(int);
int isSafe(int,int);

int graph[20][20], path[20], size,i,j;

int hamCycleUtil(int ver)
{
    if (ver == size)
    {
        if (graph[path[ver - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (int v = 1; v < size; v++)
    {
        if (isSafe(ver,v)==1)
        {
            path[ver] = v;
            if (hamCycleUtil(ver+ 1))
                return 1;
            path[ver] = -1;
        }
    }
    return 0;
}

int isSafe(int ver,int pos)
{
    if (graph[path[ver - 1]][pos] == 0)
    {
        return 0;
    }
    for (int i = 0; i < ver; i++)
    {
        if (path[i] == pos)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    printf("\nEnter no of verstices : ");
    scanf("%d", &size);

    printf("\nEnter the adj vertices : \n");
    for (i = 0; i < size; i++)
        for (j = 0; j < size;scanf("%d",&graph[i][j]),j++);

    for (i = 0; i < size;i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(1))
    {
        printf("\nPath is : ");
        for (i = 0; i < size;i++)
            printf("%d->", path[i]);
        printf("0");
    }
    else
        printf("\nNot");
    return 0;
}
/*
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
*/