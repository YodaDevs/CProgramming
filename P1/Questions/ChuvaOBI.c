#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int contador=0,E,D,i,j,k;
	int n,a[100000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		E=0;
		D=0;
		for (j = i-1 ; j >= 0; j--)
		{
			if (a[j]>a[i])
			{
				E=1;
				break;
			}
		}
		for (k = i+1; k < n; k++)
		{
			if (a[k]>a[i])
			{
				D=1;
				break;
			}
		}
		if (E==1 && D==1)
		{
			contador++;
		}
	}
	printf("%d\n", contador);
	return 0;
}