#include <stdio.h>

void swapfloat(float *, float *);
void swapint(int *, int *);
float jsp(void);

float profit[20];
int size, deadline[20], time[20];


float jsp(void)
{
    for (int i = 0; i < size;i++){
        for (int j = deadline[i] - 1; j >= 0;j--){
            if(time[j]==-1){
                time[j] = i;
                //printf("\n%d  %d", j, i);
                break;
            }
        }
    }

    float earn = 0;
    for (int i = 0; i < size;i++){
        if(time[i]!=-1){
            earn = earn + profit[time[i]];
        }
    }

    return earn;
}

void swapint(int *p, int *q)
{
    float temp = *p;
    *p = *q;
    *q = temp;
}
void swapfloat(float *p, float *q)
{
    float temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    printf("\nEnter the no of items : ");
    scanf("%d", &size);
    for (int i = 0; i < size;i++)
    {
        printf("\nEnter Profit and deadline of job no %d : ", i + 1);
        scanf("%f%d", &profit[i], &deadline[i]);
        time[i] = -1;
    }
    for (int i = 0; i < size-1;i++)
    {
        for (int j = 0; j < size - i - 1;j++){
            if(profit[j]<profit[j+1]){
                swapfloat(&profit[j], &profit[j + 1]);
                swapint(&deadline[j], &deadline[j + 1]);
            }
        }
    }
    /*for (int i = 0; i < size;i++){
        printf("\n%f %d %d", profit[i], deadline[i], time[i]);
    }*/
    printf("\nProfit is : %f", jsp());
}