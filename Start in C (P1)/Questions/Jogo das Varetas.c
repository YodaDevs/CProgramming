#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n, tam, Q, soma;
    
    
    while (1)
    {
    scanf("%d", &n);
    if (n==0) break;
    soma =0;
    while (n--)
    {
        
        
    scanf("%d%d", &tam, &Q);
    
    if (Q%2!=0) Q--; 
    
    soma += Q;
    }
    printf ("%d\n", soma/4);
    
    }
    

	return 0;
}