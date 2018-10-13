#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

int tocas(int V[],int inicial,int x,int y)
{
	x = V[y];
	y = V[x];
	if (x==inicial)
	{
		return 1;
	}
	else
	{
		return tocas(V,inicial,y,x) + 1; 		
	}
}

int main() 
{
	int k,num,i,aux,x,y,maior,p;
	scanf("%d", &num);
	int V[num];
	for (i = 0; i < num; ++i)
	{
		scanf("%d", &V[i]);
	}
	aux=num;
	maior = tocas(V,V[0],0,V[0]);
	i=0;
	while(aux--)
	{
		k = tocas(V,V[i],0,V[i]);
		if (maior < k)
		{
			maior = k; 
		}
		i++;
	}
	printf("%d\n", maior);

	return 0;
}