#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000000

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

	/*int x;
	for( ; scanf("%d", &x) != EOF ; ){
	}*/
	int V[MAX],tam, i;
	scanf("%d", &tam);
	for (i = 0; i < tam; ++i)
	{
		scanf("%d", &V[i]);
	}
	insertionSort(V,tam);

	for (i = 0; i < tam; i++)
	{
		if (V[i]%2==0)
		{
			printf("%d\n", V[i]);
		}
	}
	for (i = tam - 1; i >= 0 ; i--)
	{
		if (V[i]%2!=0)
		{
			printf("%d\n", V[i]);
		}
	}
	return 0;
}