#include <stdio.h>
#include <stdlib.h>

float jsp(void );
int *profit,*time,n,day,*slot;

float jsp(void)
{
	float sell = 0.0;
	for(int i = 0 ; i < n ; i++)
	{
		if(*(time+i) > day)
			*(time+i) = day;
		for(int j=*(time+i)-1 ; j>=0 ;j--)
		{
			if(*(slot + j) == -1)
			{
				*(slot + j) = i;
				sell += *(profit+i);
				break;
			}
		}
	}
	return sell;
}

int main()
{
	int temp;
	printf("\nEnter total no of jobs : ");
	scanf("%d",&n);

	profit = (int *)malloc(sizeof(int) * n);
	time   = (int *)malloc(sizeof(int) * n);

	for(int i = 0;i < n ;i++)
	{
		printf("\nEnter profit & time for the job : ");
		scanf("%d %d",(profit + i) , (time + i));
	}

	printf("Enter max day : ");
	scanf("%d",&day);
	slot   = (int *)malloc(sizeof(int) * day);
	for(int i=0;i<day;i++)
		*(slot + i) = -1;

	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(*(profit + j) < *(profit + j+1))
			{
				temp = *(profit + j);
				*(profit + j) = *(profit + j + 1);
				*(profit + j + 1) = temp;

				temp = *(time + j);
				*(time + j) = *(time + j + 1);
				*(time + j + 1) = temp;
			}
		}
	}

	printf("\nMax profit is : %.2f",jsp());
	return 0;
}