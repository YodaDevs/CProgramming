#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N,D;

int moeda(int diff,int i){

	if (diff==D && i==N) return 1;
	
	else if (diff!=D && i==N) return 0;
	
	if (i!=N) return moeda(abs(diff+1), i+1) + moeda(abs(diff-1), i+1);
}

int main() {
	scanf("%d %d", &N,&D);
	printf("%d\n", moeda(0,0));
	return 0;
