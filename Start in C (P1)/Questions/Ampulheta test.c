#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void emcima(int n, int x)
{
	int i,j=n-1,aux=0,an=n,b=n-(n-1);
	for ( ; aux < an-1; ++aux)
	{
		printf("*");
		for (i = 0; i < b-1; i++)
		{
			printf(" ");
		}
		for (i = 0; i < j ; ++i)
		{
			printf("*");
			
			if (aux==an-2)
			{
				printf(".");
			}
			else if (x>j)
			{
				for (i = 0; i < x; ++i)
				{
					printf(".");
					if (i>=3)
					{
						printf(".");
					}
				}

				x--;
			}
			else
			{
				for (i = 0; i < j; ++i)
				{
					printf(" ");
				}
			
				for (i = 1; i < j; ++i)
				{
					printf(" ");
				}
			}
			printf("*");
		}
		for (i = 0; i < b-1; i++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");	
		j--;
		b++;
	}
}

void base(int n)
{
	int i;
	printf("*");
	for (i = 0; i < n-2; ++i)
	{
		printf("*");
		printf(" ");
	}
	printf("*");
	printf("*");
	printf("\n");
}

void meio(int n)
{
	int i;
	printf("*");
	/*if (n%2!=0)
	{
			printf(" ");
	}*/
	for (i = 0; i < n-1; ++i)
	{
		printf(" ");
	}
	printf("*");
	for (i = 0; i < n-1; ++i)
	{
		printf(" ");
	}
	/*if (n%2!=0)
	{
			printf(" ");
	}*/
	printf("*");
	printf("\n");
}

void pontos2(int n,int ar)
{
	int i=0,l,j=i+1,k=ar,areia=n-3,aux=0,an=n;
	for ( ; aux < an-2; ++aux)
	{
		printf("*");
		for (i = 0; i < n-3; ++i)
		{
			printf(" ");
		}
		for (i = 0; i <= j ; ++i)
		{
			printf("*");
			if(k>=areia)	
			{
				for (i = 1; i < j ; i++)
				{
					printf(".");
				}
				for (i = 0; i < j ; i++)
				{
					printf(".");
				}
			}
			else
			{
				for (i = 0; i < j; ++i)
				{
					printf(" ");
				}
			
				for (i = 1; i < j; ++i)
				{
					printf(" ");
				}
			}
			printf("*");
		}
		for (i = 0; i < n-3; ++i)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");	
		j++;
		n--;
		k++;
		if (aux==an-4)
		{
			break;
		}
	}
}


/* primeira camada do diamante */

void pontos(int n)
{
	int i;
	printf("*");
	for (i = 0; i < n-2; ++i)
	{
		printf(" ");
	}
	printf("*");
	for (i = 0; i < n-2; ++i)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");
}

int main()
{
	int n,areia,x,casos,i=1;
	scanf("%d",&casos);
	while(casos--)
	{	
		scanf("%d", &n);
		scanf("%d", &areia);
		x=(n-3)-areia;
		x+=2;
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
		printf("Caso %d:\n", i);
		base(n+1);
		emcima(n,x);
		meio(n);
		pontos(n+1);
		pontos2(n+1,areia);
		base(n+1);
		printf("\n");
		i++;
	}
	return 0;
}