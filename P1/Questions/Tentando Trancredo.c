#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXP 41
#define MAXI 10000

int main() {
	int fornalhas, i,j=0;
	int numpizzas;
	int counterpizza[MAXP];
	
	for(i=0; i < MAXP; i++)
	{
		counterpizza[i] = 0;
	}
	scanf("%d", &fornalhas);

	while(fornalhas--){
		scanf("%d", &numpizzas);

		char pizza[(numpizzas+1)*1000];
		
		for(i=0; i < numpizzas; i++){

		scanf("%c", &pizza[i]);
		counterpizza[j]++;

		if (pizza[i]== '\n')
		{
			j++;
			break;
		}
		}




	}
	return 0;
}