#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void input(int * , int );
void print(int * , int );
void max_min(int * , int , int );

int max  , min ;

void max_min(int *arr , int l , int h)
{
	if(l==h)
		max = min = *(arr + l);
	
	else if(l+1 == h){
		if(*(arr + l ) > *(arr + h )){
			max = *(arr + l);
			min = *(arr + h);
		}
		else{
			min = *(arr + l);
			max = *(arr + h);
		}
	}
	
	else{
		int max1 , max2 , min1 , min2 , mid;
		mid = (l + h) / 2;
		
		max_min(arr , l , mid);
		max1 = max ; 
		min1 = min ;
		
		max_min(arr , mid + 1 , h);
		max2 = max;
		min2 = min;

		max = max1 > max2 ? max1 : max2 ;
		min = min1 < min2 ? min1 : min2 ;
	}
}

void input(int *arr , int n)
{
	printf("\nEnter all array element : ");
	for(int i=0;i<n;i++)
		scanf("%d",(arr+i));
}

void print(int *arr , int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",*(arr + i));
}

int main()
{
	int *arr , n;
	printf("\nEnter value of n : ");
	scanf("%d",&n);
	arr = (int *) malloc(sizeof(int ) * n);
	input(arr , n);
	printf("\nArray is : ");
	print(arr , n);
	
	max_min(arr , 0 , n-1);
	printf("\nMax := %d\nMin := %d",max,min);

	return 0;
}