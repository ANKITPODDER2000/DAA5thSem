#include <stdio.h>

void swapIng(float *, float *);
float knapSack();

float ratio[20], weight[20], profit[20], cap;
int size;

void swapIng(float *p,float *q){
    float temp = *p;
    *p = *q;
    *q = temp;
}
float knapSack(void)
{
    float earn = 0;
    float capCopy = cap;
    int i = 0;
    while(capCopy>0 && i<=size)
    {
        if(capCopy>weight[i]){
            earn += profit[i];
            capCopy -= weight[i];
            //printf("\n===Earn : %f",earn);

        }
        else{
            earn += capCopy * ratio[i];
            capCopy -= capCopy;
            //printf("\n===Earn : %f",earn);
        }
        i++;
    }
    //printf("\n===Earn : %f",earn);
    return earn;
}

int main()
{
    printf("\nEnter the no of object : ");
    scanf("%d", &size);
    printf("\nEnter the seller capacity : ");
    scanf("%f", &cap);

    for (int i = 0; i < size;i++){
        printf("\nEnter weight and profit of object %d : ", i + 1);
        scanf("%f%f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size - i - 1;j++)
        {
            if(ratio[j]<ratio[j+1]){
                swapIng(&ratio[j], &ratio[j + 1]);
                swapIng(&profit[j], &profit[j + 1]);
                swapIng(&weight[j], &weight[j + 1]);
            }
        }
    }
    /*for (int i = 0; i < size;i++){
        printf("\n%f  %f  %f", profit[i], weight[i], ratio[i]);
    }*/
    printf("\nSeller profit :  %.4fRs", knapSack());
    return 0;
}