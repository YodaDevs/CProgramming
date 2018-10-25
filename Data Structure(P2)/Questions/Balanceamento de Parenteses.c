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
void inicia(node *PILHA);
int vazia(node *PILHA);

int main(void)
{
    char str[256];
    int counter,j,i=0, balanced1=0,balanced2=0, abort=0;
    scanf("%d\n", &counter);
    while(counter--){
        fgets(str,256,stdin);
        /*for(i=0; i < strlen(str)-1; i++){
            printf("%c", str[i]);
        }
        printf("\n");*/
        node *parent = (node *) malloc(sizeof(node));
        inicia(parent);

        for (j = 0; j < strlen(str) ; j++)
        {
            if(str[j] == '('){
                push(parent);
            }
            if (str[j] == ')')
            {
                if((vazia(parent))!= 1)
                    pop(parent);
                else
                    i++;
            }
        }
        if (vazia(parent) && i==0)
        {
            balanced1 = 1;
        }
        i=0;
        for (j = 0; j < strlen(str) ; j++)
        {
            if(str[j] == '['){
                push(parent);
            }
            if (str[j] == ']')
            
                if((vazia(parent))!= 1)
                    pop(parent);
                else
                    i++;
        }
        if (vazia(parent) && i==0)
        {
            balanced2 = 1;
        }
        if (balanced1 && balanced2)
        {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        free(parent);
        i=0;
        balanced1=0;
        balanced2=0;

    }
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