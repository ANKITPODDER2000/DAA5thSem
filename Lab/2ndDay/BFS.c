#include <stdio.h>
#include <stdlib.h>

void BFS(void);
void insert(int);
int delete(void);
int len(void);

int queue[20], adj_mat[20][20], visit[20], front = -1, rear = -1, node;

//Insert Function
void insert(int index)
{
    if(front==-1)
        front++;
    queue[++rear] = index;
    visit[index] = 1;
}

int delete(void)
{
    if(front==-1)
        return -1;
    int val = queue[front];
    if (front==rear)
        front = rear = -1;
    else
        front++;
    return val;
}

int len(void)
{
    int val = front == -1 ?  0 : (front == rear ? 1 : rear - front + 1);
    return val;
}

void BFS(void)
{
    if(len()==0)
        return;
    else{
        int i;
        int index = delete ();
        printf("%d ", index);
        for (i = 0; i < node;i++)
        {
            if(adj_mat[index][i]==1 && visit[i]==0)
                insert(i);
        }
        BFS();
    }
}

int main()
{
    int i, j,start;
    //Initialization
    for (i = 0; i < 20;i++)
        visit[i] = 0;
    printf("\nEnter no of vertices & starting node : ");
    scanf("%d%d", &node, &start);
    printf("Enter the adjacency matrix : ");
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
            scanf("%d", &adj_mat[i][j]);
    }

    /*printf("\nAdjacency Matrix is : \n");
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
            printf("%d ", adj_mat[i][j]);
        printf("\n");
    }*/


    if(start>=node){
        printf("\nBFS not Possible.");
        exit(1);
    }
    insert(start);
    printf("\nBFS of the graph is : ");
    BFS();
    return 0;
}