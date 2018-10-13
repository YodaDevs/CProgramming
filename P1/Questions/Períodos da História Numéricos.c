#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, number = 0, maior = 0, champ = 0;
	char ano, cristo;

	 while (champ < 3)
	 {
	 	scanf("%d", &x);
	 	getchar();
	 	scanf("%c%c", &ano, &cristo);
	 	number = 0;


	 	if (x >= 4000 && ano == 'a')
	 	{
	 		number = 1;
	 	}
	 	if (x <= 3999 || x == 1  && ano == 'a')
	 	{
	 		number = 2;
	 	}
	 	if (x > 1 && x <= 476 && ano == 'd')
	 	{
	 		number = 2;
	 	}
	 	if (x >= 477 && x <= 1789 && ano == 'd')
	 	{
	 		number = 3;
	 	}
	 	if (x >= 1790 && ano == 'd')
	 	{
	 		number = 4;
	 	}


	 	if (number > maior)
	 	{
	 		maior = number;
	 	}
	 	champ++;
	 }
	

	printf("%d\n", maior);

}