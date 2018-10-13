#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int x,aux;
    int votoali=0,votoalc=0,votonul=0,votobr=0;
    float porcali,porcalc,soma;
    aux=0;
    for(;aux!=-1;)
    {
    scanf("%d",&x);
    if(x==83)
    {
        votoali++;
    }
    else if(x==93)
    {
        votoalc++;
    }
    else if(x!=83 && x!=93 && x!=0 && x!=-1)
    {
        votonul++;
    }
    else if(x==0)
    {
        votobr++;
    }
    aux=x;
    }
    
    printf("%d\n", votoali);
    printf("%d\n", votoalc);
    printf("%d\n", votobr);
    printf("%d\n", votonul);
    if(votoali>votoalc)
    {
        printf("83\n");
    }
    else
    {
        printf("93\n");
    }
    soma=(votoali+votoalc+votobr+votonul);
    porcali=(100*votoali)/(soma-votonul);
    porcalc=(100*votoalc)/(soma-votonul);
    printf("%.2f\n", porcali);
    printf("%.2f\n", porcalc);
    
	return 0;
}