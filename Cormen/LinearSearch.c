#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int index);

int size,arr[50],key;

int LinearSearch(int index)
{
	if(index>=size)
		return -1;
	if(arr[index]==key)
		return index;
	LinearSearch(index+1);
}

int main()
{
	system("cls");
	int i;
	printf("\nEnter the no of Element : ");
	scanf("%d",&size);

	printf("\nEnter the array : ");
	for(i=0;i<size;scanf("%d",&arr[i++]));

	printf("\nEnter Key to Search ");
	scanf("%d",&key);

	LinearSearch(0) != -1? printf("\nPosition of %d is: %d",key,1+LinearSearch(0)) : printf("\nKey not found.");
	return 0;
}