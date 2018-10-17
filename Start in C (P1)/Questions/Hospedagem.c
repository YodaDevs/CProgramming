#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

float CalculaHospedagem(char apartamento[],int d)
{
	float dia;

	if (d<3)
	{
		if (strcmp(apartamento,"individual")==0)
		{
			dia = (125*d);
		}
		else if (strcmp(apartamento,"su�te dupla")==0)
		{
			dia = (140*d);
		}
		else if (strcmp(apartamento,"su�te tripla")==0)
		{
			dia = (180*d);
		}
	}
	else
	{
		if (strcmp(apartamento,"individual")==0)
		{
			dia = (125*d);
			dia = (dia*0.85);
		}
		else if (strcmp(apartamento,"su�te dupla")==0)
		{
			dia = (140*d);
			dia = (dia*0.85);
		}
		else if (strcmp(apartamento,"su�te tripla")==0)
		{
			dia = (180*d);
			dia = (dia*0.85);
		}
	}
	return dia;
}

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

int main()
{
	char apartamento[MAX];
	int d,i,tam;
	gets(apartamento);
	strncase(apartamento);
	scanf("%d", &d);
	printf("%.2f\n",CalculaHospedagem(apartamento, d) );
	return 0;
}