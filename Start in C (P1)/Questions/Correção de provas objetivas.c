#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int j,i,retorno=0,q,alunos;
	char gab[MAX],resp[MAX];
	scanf("%d", &q);
	scanf("%s", gab);
	scanf("%d",&alunos);
	for (i = 0; i < alunos; ++i)
	{
		scanf("%s", resp);
		for(j = 0; j < q ; j++) 
    	{                 
        	if(resp[j] != gab[j]) 
            	retorno++; 
    	} 
    	//printf("%d\n",retorno);
		printf("%d\n",q-retorno);
		retorno=0;
	}
	return 0;
}