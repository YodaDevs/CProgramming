#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void embaixo(int n)
{
	int i,j=n-1,aux=0,an=n,b=n-(n-1);
	for ( ; aux < an-1; ++aux)
	{
		for (i = 0; i < b; i++)
		{
			printf(".");
		}
		for (i = 0; i < j ; ++i)
		{
			printf("*.");
		}
		for (i = 0; i < b-1; i++)
		{
			printf(".");
		}
		printf("\n");	
		j--;
		b++;
	}
}

void meio(int n)
{
	int i;
	for (i = 0; i < n-1; ++i)
	{
		printf("*.");
	}
	printf("*");	
	printf("\n");
}

void pontos2(int n)
{
	int i,j=i+1,aux=0,an=n;
	for ( ; aux < an-2; ++aux)
	{
		for (i = 0; i < n-2; ++i)
		{
			printf(".");
		}
		for (i = 0; i <= j ; ++i)
		{
			printf("*.");
		}
		for (i = 0; i < n-3; ++i)
		{
			printf(".");
		}
		printf("\n");	
		j++;
		n--;
	}
}

/* primeira camada do diamante */

void pontos(int n)
{
	int i;
	for (i = 0; i < n-1; ++i)
	{
		printf(".");
	}
	printf("*");
	for (i = 0; i < n-1; ++i)
	{
		printf(".");
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n==0)
	{
		printf("\n");
		return 0;
	}
	else if(n==1)
	{
		printf("*\n");
		return 0;
	}
	pontos(n);
	pontos2(n);
	meio(n);
	embaixo(n);
	return 0;
}