#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

void strncase (char* s)
{
   char notcase (char c)
   {
       if((c >= 'A') && (c <= 'Z'))
           return 'a' + (c - 'A');

       return c;
   }
   while(*s != '\0')
   {
       *s = notcase(*s);
       s++;
   }
}

int campeonato(char miguel[], char maria[])
{
	int contmi=0,contma=0;
	if (strcmp(miguel,"papel")==0 && strcmp(maria,"pedra")==0)
	{
		contmi++;
	}
	else if (strcmp(miguel,"pedra")==0 && strcmp(maria,"tesoura")==0)
	{
		contmi++;
	}
	else if (strcmp(miguel,"tesoura")==0 && strcmp(maria,"papel")==0)
	{
		contmi++;
	}
	else if (strcmp(miguel,"pedra")==0 && strcmp(maria,"papel")==0)
	{
		contma++;
	}
	else if (strcmp(miguel,"tesoura")==0 && strcmp(maria,"pedra")==0)
	{
		contma++;
	}
	else if (strcmp(miguel,"papel")==0 && strcmp(maria,"tesoura")==0)
	{
		contma++;
	}
	else if (strcmp(miguel,maria)==0)
	{
		return 0;
	}
	if (contmi>contma)
	{
		return 1;
	}
	else if (contma>contmi)
	{
		return 2;
	}
}

int main()
{
	char miguel[MAX],maria[MAX];
	int i=5,contmi=0,contma=0;
	while(i--)
	{	
		gets(miguel);
		gets(maria);
		strncase(miguel);
		strncase(maria);
		
		if (campeonato(miguel,maria)==1)
		contmi++;
		
		else if (campeonato(miguel,maria)==2)
		contma++;
		
	}
	
	if (contmi>contma)
	printf("MARIA\n");
	
	else if (contma>contmi)
	printf("MIGUEL\n");
	
	else
	printf("MARIA\n");
	return 0;
}