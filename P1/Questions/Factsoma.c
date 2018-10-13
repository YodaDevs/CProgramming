#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n,k,num=0,resul,i;
	scanf("%d%d", &n,&k);
	if (n==0)
	{
		printf("0\n");
	}
	else if (n>=0 && n<=100000)
	{
			i=n;
			num=n;
			for( ;i>0 ; --i)
			{
				num=(num-k);
				if (num<0)
				{
					num=0;
				}
				resul= n + num;
				n=resul;
			}
			printf("%d\n", resul);
	}
    return 0;
}