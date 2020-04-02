#include <stdio.h>
#include <stdlib.h>

int absdif(int, int);
int isPossible(int *, int, int,int);
int nQueen(int *, int,int );


int nQueen(int *board, int size,int pos)
{
    int i;
    for (i = 0; i < size;i++)
    {
        if (pos == size)
            return 1;
        board[pos] = i;
        if(isPossible(board,size,pos,i))
        {
            if(nQueen(board, size,i+1))
                return 1;
        }
    }
    return 0;
}

int isPossible(int *board, int size, int row,int col)
{
    int i;
    printf("%d---%d---%d\n", size, row, col);
    printf("\nBoard : ");
    for (i = 0; i < size;i++)
        printf("%d ", board[i]);
    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", board[i], col);
        if ((board[i] == col) || (absdif(board[i], i) == absdif(row, col)))
        {
            //printf("%d\t%d\n", board[i], col);
            return 0;
        }
    }
    return 1;
}

int absdif(int a,int b)
{
    if(a>b)
        return a - b;
    return b - a;
}

int main()
{
    int i;
    int size, *board;
    printf("\nEnter Total no of rows : ");
    scanf("%d", &size);
    board = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size;i++)
        board[i] = -1;
    if(!nQueen(board, size,0))
    {
        printf("\nX  ->> ");
        for (i = 0; i < size;i++)
            printf("%d ", board[i]);
    }
    else
    {
        printf("\nX: ");
        for (i = 0; i < size;i++)
            printf("%d ", board[i]);
    }
    return 0;
}