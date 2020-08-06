#include <stdio.h>
#include <stdlib.h>

int color_graph(int );
int perfectcolor(int );

int *adj,*color,v,col;

int color_graph(int ver)
{
	if(ver==v)
		return 1;
	for(int i=0;i<col;i++)
	{
		*(color + ver) = i;
		
		if(perfectcolor(ver)){
			if(color_graph(ver + 1))
				return 1;
		}
		
		*(color + ver) = -1;
	}

	return 0;
}
int perfectcolor(int ver)
{
	for(int i=0;i<v;i++)
	{
		if(i!=ver && *(adj + ver*v + i) != 0 && *(color+i) == *(color + ver) )
			return 0;
	}
	return 1;
}

int main()
{
	printf("\nEnter no of vertices : ");
	scanf("%d",&v);

	adj = (int *)malloc(sizeof(int ) * v * v);
	color = (int *)malloc(sizeof(int ) * v);

	printf("\nEnter adjacency matrix :\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			scanf("%d",(adj + i * v + j));
		*(color+i) = -1;
	}
	printf("\nEnter total no of colors : ");
	scanf("%d",&col);

	if(color_graph(0) == 0)
		printf("Not Possible");
	else{
		printf("\nColor := ");
		for(int i=0;i<v;i++)
			printf("%d ",*(color+i) + 1);
	}

	return 0;
}