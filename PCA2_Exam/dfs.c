#include <stdio.h>
#include <stdlib.h>

int *stack,*adj,*visit,size,top=-1;

void push(int);
int pop(void);
void DFS(void);
int isStackEmpty();

void push(int index)
{
    visit[index] = 1;
    stack[++top] = index;
}

int pop(void)
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}

int isStackEmpty()
{
    return top == -1 ? 1 : 0;
}

void DFS()
{
    if(isStackEmpty())
        return;
    int index = pop();
    int i;
    printf(" -> %d", index);
    for (i = 0; i < size;i++)
    {
        if(*(adj+index*size+i)==1 && visit[i]==0)
            push(i);
    }
    DFS();
}

int main()
{
    int start, i, j;
    printf("\nEnter the total no of node : ");
    scanf("%d", &size);

    adj = (int *)malloc(sizeof(int) * size * size);
    stack = (int *)malloc(sizeof(int) * size);
    visit = (int *)malloc(sizeof(int) * size);

    printf("\nEnter the Adj. Matrix :\n");
    for (i = 0; i < size;i++)
    {
        for (j = 0; j < size;j++)
            scanf("%d", adj + i * size + j);
        visit[i] = 0;
    }

    printf("\nEnter the Starting node : ");
    scanf("%d", &start);

    /*
        printf("\nAdj Matrix is :\n");
        for (i = 0; i < size;i++)
        {
            for (j = 0; j < size;j++)
                printf("%d", *(adj + i * size + j));
            printf("\n");
        }
    */

    push(start);
    printf("\nDFS of the graph is : ");
    DFS();
    return 0;
}

/*
0 1 1 0 1
1 0 0 1 0
1 0 0 1 0
0 1 1 0 1
1 0 0 1 0
*/