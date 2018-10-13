#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
 int num;
 int tamanho;
 struct Node *prox;
};
typedef struct Node node;

int menu(void);
void inicia(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);

int main(void)
{
 node *back = (node *) malloc(sizeof(node));
 node *forward = (node *) malloc(sizeof(node));
 node *enter = (node *) malloc(sizeof(node));
 char str[8];
 //int i=9;
 inicia(back);
 inicia(forward);
 inicia(enter);


 while(scanf("%s", str) != EOF)
 {
  //fgets(str,8,stdin);
  //getchar();
  //printf("[%c]\n", str[0]);
  /*printf("%d\n", strcmp(str,"ENTER"));
  printf("%d\n", strcmp(str,"BACK"));
  printf("%d\n", strcmp(str,"FORWARD"));*/
  if(str[0]=='E')
  {
    push(enter);
    while(forward->tamanho > 0)
    {
        pop(forward);
    }
    //printf("%d\n", enter->tamanho);
  }
  else if (str[0]=='B') {
    if(enter->tamanho > 1){
        pop(enter);
        push(forward);
    }
    if(back->tamanho > 0){
        push(forward);
    }
  }
  else if(str[0]=='F'){
    if(enter->tamanho > 0){
        push(enter);
        pop(forward);
    }
    if(back->tamanho > 0){
        push(enter);
        pop(forward);
    }
  }
  //getchar();
 }
 pop(enter);
 printf("BACK: %d\n", enter->tamanho);
 printf("FORWARD: %d\n", forward->tamanho);
 free(back);
 free(forward);
 free(enter);
 return 0;
}

void inicia(node *PILHA)
{
 PILHA->prox = NULL;
 PILHA->tamanho=0;
}

int vazia(node *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  novo->num = 1;
  return novo;
 }
}

void push(node *PILHA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 PILHA->tamanho++;
}


node *pop(node *PILHA)
{
 if(PILHA->prox == NULL){
  return NULL;
 }else{
  node *ultimo = PILHA->prox,
              *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  PILHA->tamanho--;
  return ultimo;
 }
}
