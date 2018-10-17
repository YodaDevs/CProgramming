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
 int i,j,k, lim,abort = 0, balanced1 = 0,balanced2 = 0;
 scanf("%d", &i);
 getchar();
 while(i--){
 	node *parenteses = (node *) malloc(sizeof(node));
 	inicia(parenteses);
 	char l[256];
 	for(k=0; k < 256; k++){
 	    l[k] = 0;
 	}
 	k=0;
 	while(scanf("%c",l[k]) != '\n'){
 	    k++;
 	}
 	for(k=0; k < 256; k++){
 		//printf("%c\n", l[k]);
 	    if(l[k]==0){
 	        lim = k;
 	        break;
 	    }
 	}
 	for (j = 0; j < lim ; j++)
 	{
 		if(l[j] == '('){
 			push(parenteses);
 		}
 		if (l[j] == ')')
 		{
 			if (vazia(parenteses))
 			{
 				abort = 1;
 				break;
 			}
 			else{
 				pop(parenteses);
 			}
 		}
 	}
 	if (!abort && vazia(parenteses))
 	{
 		balanced1 = 1;
 	}
 	for (j = 0; j < lim ; j++)
 	{
 		if(l[j] == '['){
 			push(parenteses);
 		}
 		if (l[j] == ']')
 		{
 			if (vazia(parenteses))
 			{
 				abort = 1;
 				break;
 			}
 			else{
 				pop(parenteses);
 			}
 		}
 	}
 	if (!abort && vazia(parenteses))
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