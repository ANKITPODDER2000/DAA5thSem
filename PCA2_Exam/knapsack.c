#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int p[20], w[20], counter[20], i, j, size, cap;
float r[20], ratio[20];

void swapFloat(float *, float *);
void swapInt(int *, int *);
float knapsack(void);

void swapInt(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void swapFloat(float *p, float *q)
{
    float temp = *p;
    *p = *q;
    *q = temp;
}

float knapsack(void)
{
    int c = cap;
    int i=0;
    float sell = 0.0;
    while(c>0 && i<size)
    {
        if(w[i]<=c){
            sell += p[i];
            c = c - w[i];
            ratio[i] = 1;
        }
        else{
            sell += r[i] * c;
            ratio[i] = c / ((float)w[i]);
            c = 0;
        }
        i++;
    }
    return sell;
}



int main()
{
    system("cls");
    printf("\nEnter total no of Items : ");
    scanf("%d", &size);
    printf("\nEnter element Weight : ");
    for(i=0;i<size;i++)
        scanf("%d", w + i);
    printf("\nEnter the profit : ");
    for (i = 0; i < size;i++)
    {
        scanf("%d", &p[i]);
        r[i] = p[i] / ((float)w[i]);
        counter[i] = i;
        ratio[i] = 0.0;
    }
    printf("\nEnter the cap of seller : ");
    scanf("%d", &cap);
    for (i = 0; i < size;i++)
    {
        for (j = 0; j < size - i - 1;j++)
        {
            if(r[j]<r[j+1])
            {
                swapFloat(&r[j] , & r[j + 1]);
                swapInt(&w[j] , & w[j + 1]);
                swapInt(&counter[j] , & counter[j + 1]);
                swapInt(&p[j] , & p[j + 1]);
            }
        }
    }
    printf("\nMax Profit is : %.2f", knapsack());
    printf("\nWeight Ratio : ");
    for (i = 0; i < size;i++)
    {
        for (j = 0; j < size;j++)
        {
            if(counter[j]==i)
                printf("%.3f ", ratio[j]);
        }
    }
    return 0;
}