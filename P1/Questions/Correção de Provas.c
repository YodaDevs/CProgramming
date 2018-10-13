#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 12

int main() {
    int i,j=0,aluno;
    float percentual,nota=0,aprovados = 0,salva=0, notas[MAX],maior=0;
    float comp[MAX];
    char gab[MAX], resposta[MAX];
    
    for(i=0 ; i < 10; i++){
        scanf("%c", &gab[i]);
    }
    getchar();
    /*for(i=0; i < 10; i++){
        printf("%c ", gab[i]);
    }*/
    while(1){
        scanf("%d", &aluno);
        getchar();

        if(aluno==9999) break;

        for(i=0; i< 10; i++){
            scanf("%c", &resposta[i]);
        }
        getchar();
        for(i=0; i < 10; i++){
            if(resposta[i] == gab[i]) nota++;
        }
        printf("%d %.1f\n", aluno, nota);
        notas[j] = nota;
        j++;
        if(nota>=6) aprovados++;

        salva = aluno;
        nota=0;
    }
    percentual = (aprovados/salva);
    printf("%.1lf%%\n", percentual*100);
    for(i=0 ; i < salva; i++){
        
        comp[i] = 0;
    }
    for(i = 0; i < salva; i++){
        
        for(j = 0; j < salva; j++){
            
            if(notas[i]==notas[j]) comp[i]++;
        }
    }
    for(i=0; i < salva; i++){
        
        if(comp[i] > maior) maior = comp[i];
    }
    for(i=0; i < salva; i++){
        
        if(maior==comp[i]){
            printf("%.1f\n", notas[i]);
            break;
        }
        
    }
	return 0;
}