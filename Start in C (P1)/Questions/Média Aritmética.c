#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int i,x;
	double codig=1,media=0,nota;
	while(codig!=0)
	{
	    printf("Informe o codigo do aluno: (0 para encerrar o programa)\n");
			scanf("%lf", &codig);
			if (codig==0)
			{
				break;
			}
			printf("Informe a primeira nota do aluno:\n");
			scanf("%lf", &nota);
			media+=nota;
			
			printf("Informe a segunda nota do aluno:\n");
			scanf("%lf", &nota);
			media+=nota;
			
			printf("Informe a terceira nota do aluno:\n");
			scanf("%lf", &nota);
			media+=nota;
		
		x = media;
	    if (x*10==media*10)
		{
			printf("Media do aluno: %.1lf\n",media/3);
		}
		else
		{
			printf("Media do aluno: %.2lf\n",media/3);
		}
		media=0;
	}
	return 0;
}