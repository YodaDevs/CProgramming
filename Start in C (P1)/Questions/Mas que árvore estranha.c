#include <stdio.h>
#include <stdlib.h>

#define li long int


li **arvore;

li maximo(li a, li b)
{
	return a > b ? a : b;
}

li altura(li n)
{
	if (n == -1)
	{
		return 0;
	}
	return 1 + maximo( altura(arvore[n][0]), altura(arvore[n][1]) );
}

int main()
{
	li i, n, e, raiz, pai, filho_esq, filho_dir;
	
	scanf("%ld%ld%ld", &n, &e, &raiz);
	
	arvore = (li **) malloc( n * sizeof(li *) );

	for (i = 0; i < n; ++i)
	{
		// cada linha
		arvore[i] = (li *) malloc(sizeof(li) * 2);	
		arvore[i][0] = -1;
		arvore[i][1] = -1;
	}

	for (i = 0; i < e; ++i)
	{
		scanf("%ld%ld%ld", &pai, &filho_esq, &filho_dir);
		arvore[pai][0] = filho_esq;
		arvore[pai][1] = filho_dir;
	}
	
	printf("%ld\n", altura(raiz));

	return 0;
}