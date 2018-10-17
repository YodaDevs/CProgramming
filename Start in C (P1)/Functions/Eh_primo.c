#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int primo(int n)
{
    int d,EhPrimo;
   
    d = 2;
    EhPrimo = 1;
    if (n <= 1)
	EhPrimo = 0;

    while (EhPrimo == 1 && d <= n / 2) 
    {
		if (n % d  == 0)
		EhPrimo = 0;

		d = d + 1;
    }

    if (EhPrimo == 1)
    printf("1\n");
    else
   	printf("0\n");

    return 0;
}
