#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

void insertionSort(int V[], int tam)
{    
  int i, j, aux;
 
  for(i = 1; i < tam; i++)
  {
    j = i;
 
    while((j != 0) && (V[j] < V[j - 1])) 
    {
      aux = V[j];
      V[j] = V[j - 1];
      V[j - 1] = aux;
      j--;     
    }
  }
}

int main() 
{
	int div,V[MAX],tam=0,i=0;
	float mediana;
	while(scanf("%d", &V[i]) != EOF)
	{
		tam++;
		i++;
	}
	insertionSort(V,tam);
	/*for (i = 0; i < tam; ++i)
	{
		printf("%d\n", V[i]);
	}*/
	if (tam%2==0)
	{
		div = tam/2;
		mediana = (V[div] + V[div-1]);
		printf("Mediana = %.1f\n",mediana/2);
		return 0;
	}
	else
	{
		div = (tam+1)/2;
		printf("Mediana = %d\n", V[div-1]);
		return 0;
	}
	return 0;
}