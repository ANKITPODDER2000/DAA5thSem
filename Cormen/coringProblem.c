#include <stdio.h>
#include <stdlib.h>

int colorGraph(int);
int perfectColor(int);

int size, col, *adj, *x;

int colorGraph(int ver)
{
    if(ver==size)
        return 1;
    for (int i = 0; i < col;i++)
    {
        *(x + ver) = i;
        if(perfectColor(ver))
        {
            if (colorGraph(ver + 1))
                return 1;
        }
        *(x + ver) = -1;
    }
    return 0;
}

int perfectColor(int ver)
{
    for (int i = 0; i < size;i++)
    {
        if(*(adj+size*ver+i)==1 && (*(x+i) == *(x+ver)) && i!=ver)
            return 0;
    }
    return 1;
}

int main()
{
    printf("\nEnter total no of Vertices : ");
    scanf("%d", &size);
    adj = (int *)malloc(sizeof(int) * size * size);

    printf("\nEnter Adj Matrix :\n");
    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < size;j++)
            scanf("%d",(adj + i * size + j));
    }

    printf("\nEnter total no of Color : ");
    scanf("%d", &col);
    x = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size;i++)
        *(x + i) = -1;

    if (colorGraph(0) != 1)
        printf("\nNot Possible.");
    else
    {
        printf("\nColor is");
        for (int i = 0; i < size;i++)
            printf(" -> %d ", *(x + i) + 1);
    }

    return 0;
}