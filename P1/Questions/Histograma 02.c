#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int tam, i, f[10]={0}, aux, maior=0;
    scanf ("%d", &tam);
    float v[tam];
    for (i=0; i<tam; i++)
    {
        scanf ("%f", &v[i]);
        
       aux = (int)(v[i]*10);
      
            if (aux%10 ==0 && (aux/10) !=0 && aux !=10 && aux !=100)
            {
                f[((aux/10))-1]++;
            }
           if ((aux/10) !=0 && aux%10 !=0 && aux !=100)
            {
                f[(aux/10)] ++;
            }
        if (aux==100) f[9]++;
        if (aux <=10) f[0]++;
            } 
    
    for (i=0; i<10; i++)
    {
        if (f[i]>maior) maior = f[i];
    }
    
    printf ("^\n");
    
     for (i=9; i>=0; i--)
    {
        printf ("|");
        while (f[i]--)
        {
            printf ("*");
        }
        printf ("\n");
    }
    printf ("+");
    while (maior--)
    {
        printf ("-");
    }
    printf (">\n");
    
	return 0;
}