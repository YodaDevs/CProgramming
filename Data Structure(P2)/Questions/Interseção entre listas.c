#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main() {
    int A[20], B[20], i=0, j, EscrevendoArray = 20, print = 0, printback = 1;
    while(EscrevendoArray--){
        scanf("%d", &A[i]);
        i++;
    }
    EscrevendoArray = 20;
    i=0;
    while(EscrevendoArray--){
        scanf("%d", &B[i]);
        i++;
    }
    mergeSort(A,0,19);
    mergeSort(B,0,19);
    
    j = 0;
    for (i = 0; i < 20; i++){
        while(A[i]==B[j]){
            if(print == 0){
                printf("%d\n", A[i]);
                print++;
                printback = 0;
            }
            j++;
        }
        print = 0;   
    }
    if (printback){
        printf("VAZIO");
    }
    return 0;
}
