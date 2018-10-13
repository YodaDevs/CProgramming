#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    
    char monstro[MAX], tipo[MAX], ataque[MAX];
    int f, a, i, s;
    int tamanho=0;
    int j;
    
    
    while(scanf("%s %d,%d,%d,%d", &monstro, &f, &a, &i, &s) != EOF && scanf("%s %s", &tipo, &ataque) != EOF)
    {
        printf("Criatura: %s\n", monstro);
        
        printf("Status:\n");
        printf(" Forca: %d\n", f);
        printf(" Agilidade: %d\n", a);
        printf(" Intigencia: %d\n", i);
        printf(" Sabedoria: %d\n", s);
        
        
            tamanho = strlen(tipo);
            
            for(j=0; j<tamanho; j++)
            {
                //printf("OPA\n");
                if(tipo[j] == ',')
                {
                    tipo[j] = ' ';
                }
            }
            
            tamanho = strlen(ataque);
            
            for(j=0; j<tamanho; j++)
            {
                //printf("OPA\n");
                if(ataque[j] == ',')
                {
                    ataque[j] = ' ';
                }
            }
            
        
        printf("\nCaracteristicas:\n%s \n\n", tipo);
        printf("Habilidades:\n%s \n\n", ataque);
        
    }
    
	return 0;
}