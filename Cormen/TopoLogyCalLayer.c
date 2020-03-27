#include <stdio.h>
#include <stdlib.h>

void topologicalSort(void);
int allVisit(void);

int *adj, *inorder,*layer, size;
int allVisit(void)
{
    for (int i = 0; i < size; i++)
    {
        if (*(inorder + i) != -1)
            return 0;
    }
    return 1;
}
void topologicalSort(void)
{
    int node;
    printf("\nTopological Sort is : ");
    while (!allVisit())
    {
        for (int i = 0; i < size; i++)
        {
            if (*(inorder + i) == 0)
            {
                *(inorder + i) -= 1;
                node = i;
                break;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (*(adj + node * size + i) == 1)
            {
                *(inorder + i) -= 1;
                if(*(layer+i) < *(layer+node)+1)
                    *(layer + i) = *(layer + node) + 1;
            }
        }
        printf("%d ", node);
    }
}

int main()
{
    printf("\nEnter no of Vertices : ");
    scanf("%d", &size);
    adj = (int *)malloc(sizeof(int) * size * size);
    inorder = (int *)malloc(sizeof(int) * size);
    layer = (int *)malloc(sizeof(int) * size);
    printf("\nEnter Adjacency Matrices : \n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", adj + i * size + j);
        }
    }
    for (int i = 0; i < size; i++)
    {
        inorder[i] = 0;
        layer[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (*(adj + j * size + i) == 1)
                inorder[i]++;
        }
    }
    printf("\nInorder Deg is : ");
    /*
    for (int i = 0; i < size; i++)
        printf("%d ", *(inorder + i));
    */
    topologicalSort();
    printf("\nLayer is : ");
    for (int i = 0; i < size;i++)
        printf("%d ", *(layer + i));
    return 0;
}

/*
Adj Matrix is :
=======================
=======================
0 1 1 1 0 0 0
0 0 0 1 0 1 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 1 0 1 0 0 0
0 0 0 0 0 0 0
0 0 1 0 0 1 0
=======================
=======================
*/