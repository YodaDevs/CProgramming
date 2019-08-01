#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node *next;
  struct node *previous;
}LinkedList;

LinkedList* create_linked_list(){
  return NULL;
}

int is_empty(LinkedList *head){
  return (head->next == NULL);
}

LinkedList* add (LinkedList *head, int item){
  LinkedList *new_node = (LinkedList*) malloc (sizeof(LinkedList));
  new_node->item = item;
  new_node->next = head;
  new_node->previous = NULL;
  if(head!=NULL) head->previous = new_node;
  return new_node;
}

void print_doubly_linked_list (LinkedList *head){
  if (!is_empty(head)) {
    print_doubly_linked_list(head -> next);
    printf("%c ", head -> item);
  }
}

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
    int A[20], B[20], i=0, j, Escrevendolista = 20 ,EscrevendoArray = 20, print = 0, printback = 1;
    LinkedList* lista1 = create_linked_list();
    LinkedList* lista2 = create_linked_list();
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
    Escrevendolista = 20;
    i = 0;
    while(Escrevendolista--){
        lista1 = add(lista1,A[i]);
        lista2 = add(lista2,B[i]);
        i++;
    }
    while(!is_empty(lista1)){
        while(lista1->item == lista2->item){
            if(print == 0){
                printf("%d\n", lista1->item);
                print++;
                printback = 0;
            }
            lista2 = lista2->next;
        }
        print = 0;   
        lista1 = lista1->next;
    }
    if (printback){
        printf("VAZIO");
    }
    return 0;
}
