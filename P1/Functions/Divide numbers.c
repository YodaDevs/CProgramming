#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int separanumber(int N, int a[])
{
	int i,y,quanti;
	for (i = 0, quanti = 0; N!=0 ; ++i)
	{
		y=N%10;
		a[i]=y;
		N=N/10;
		quanti++;
	}
	return quanti;
}