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
	int V[MAX],tam=3, i;
	for (i = 0; i < tam; ++i)
	{
		scanf("%d", &V[i]);
	}
	insertionSort(V,tam);
	for (i = 0; i < tam; i++)
	{
		printf("%d\n", V[i]);
	}
	return 0;
}