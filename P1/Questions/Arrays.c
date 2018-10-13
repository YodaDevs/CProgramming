#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

void insertionSort(int V[], int tam)
{    
  int i, j, aux;
 
  for(i = 1; i < tam; i++){
    j = i;
 
    while((j != 0) && (V[j] < V[j - 1])) {
      aux = V[j];
      V[j] = V[j - 1];
      V[j - 1] = aux;
      j--;     
    }
  }
}
void insertionSort1(int V[], int tam)
{    
  int i, j, aux;
 
  for(i = 1; i < tam; i++){
    j = i;
 
    while((j != 0) && (V[j] > V[j - 1])) {
      aux = V[j];
      V[j] = V[j - 1];
      V[j - 1] = aux;
      j--;     
    }
  }
}

int main()
{
	int A[MAX], B[MAX];
	int tamA,tamB, k, m,i,j=0,a=1,achou=0,achei=0;
	scanf("%d%d", &tamA,&tamB);
	scanf("%d%d", &k,&m);
	for (i = 0; i < tamA; ++i)
	{
		scanf("%d", &A[i]);
	}
	for (i = 0; i < tamB; ++i)
	{
		scanf("%d", &B[i]);
	}
	insertionSort(A,tamA);
	insertionSort1(B,tamB);
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<k;j++)
        {
            if(B[i]>A[j])
                achou++;
        }
        //printf("%d\n",achou);
        if(achou==k)
        achei++;
        
        achou=0;
    }
	//printf("%d\n",achei);
	//printf("%d\n",k);
	if (achei==m)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}