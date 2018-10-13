#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primo(int a)
{
	int d,primo;
	d=2;
	primo= 1;

	if (a<=1)
	primo= 0;
	
	while(primo == 1 && d<= a/2)
	{
		if (a%d==0)
		primo = 0;
		
		d+=1; 

	}

	if (primo == 1)
	return a;

	else
	return 0;	
}

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d", &a,&b,&c,&d);

	if (primo(a)==0 || primo(b)==0 || primo(c)==0 || primo(d)==0)
	{
		printf("SEM PRODUTO\n");
	}
	else
	printf("%d\n",(primo(a)*primo(b)*primo(c)*primo(d)));

    return 0;
}