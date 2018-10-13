#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insertionSort(int V[], int tam)
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
	int i, N,j, V[5],aux,k,conta1=0,conta2=0,conta3=0,conta4=0,troco;
	scanf("%d",&N);
	/*for (i = 0; i < 4; ++i)
	{
		scanf("%d",&V[i]);
	}
	scanf("%d", &troco);
	aux=troco;
	insertionSort(V,4);*/
	/*for (i = 0; i < 4; ++i)
	{
		printf("%d\n",V[i]);
	}*/
	for (i = 0,k=1; i < N ; i++,k++)
	{
    	for (j = 0; j < 4; ++j)
    	{
    		scanf("%d",&V[j]);
    	}
    	scanf("%d", &troco);
    	aux=troco;
    	insertionSort(V,4);
		while(troco>0)
		{
			if ((troco-V[0])>=0)
			{
				conta1++;
				troco-=V[0];
			}
			else if ((troco-V[1])>=0)
			{
				conta2++;
				troco-=V[1];
			}
			else if ((troco-V[2])>=0)
			{
				conta3++;
				troco-=V[2];
			}
			else if ((troco-V[3])>=0)
			{
				conta4++;
				troco-=V[3];
			}
			else
			{
				break;
			}
		}
		printf("Costumer %d:\n",k);
		printf("Change: $%d\n",aux);
		printf("%d of $%d\n", conta1,V[0]);
		printf("%d of $%d\n", conta2,V[1]);
		printf("%d of $%d\n", conta3,V[2]);
		printf("%d of $%d\n", conta4,V[3]);
		printf("Tip: $%d\n", troco);
		conta1=0;
		conta2=0;
		conta3=0;
		conta4=0;
		printf("\n");
	}
	return 0;
}