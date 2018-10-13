#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int euclides(int A,int D)
{
	int aux;
	if(A%D==0)
	{
		return D;
	}
	else
	{
		aux = D;
		D = A%D;
		A = aux;
	}
	euclides(A,D);
}

int main()
{
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d\n", euclides(a,b));
	return 0;
}