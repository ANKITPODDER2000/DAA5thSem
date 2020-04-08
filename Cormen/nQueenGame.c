#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int placeQueen(int);
int issafe(int);

int size, *board;

int placeQueen(int pos)
{
    if(pos>=size)
        return 1;
    int i;
    for (i = 0; i < size;i++)
    {
        *(board + pos) = i;
        /*
        printf("\n%d . Board is : ", pos);
        for (int i = 0; i < size; i++)
            printf("%d ", *(board + i));
        */
        if(issafe(pos))
        {
            if(placeQueen(pos+1))
                return 1;
        }
        *(board + pos) = -1;
    }
    return 0;
}

int issafe(int pos)
{
    int i;
    for (i = 0; i < pos;i++)
    {
        if(*(board+i)==*(board+pos))
            return 0;
        else if ((abs((i - pos))) == (abs((*(board + i) - *(board + pos)))))
            return 0;
    }
    return 1;
}

int main()
{
    printf("\nEnter board size : ");
    scanf("%d", &size);
    board = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size;i++)
        *(board + i) = -1;
    
    if(placeQueen(0)!=1)
        printf("\nNot Possible.");
    else
    {
        printf("\nSolution is : ");
        for (int i = 0; i < size; i++)
            printf("%d ", *(board + i) + 1);
    }
    return 0;
}