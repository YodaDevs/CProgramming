#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node{
 char num;
 int tamanho;
 struct Node *prox;
};

typedef struct Node node;

typedef struct binary_tree {
	int item;
	int h;
	struct binary_tree* left;
	struct binary_tree* right;
}binary_tree;

//FUNCTION RENEGADES
void print_la_arvore(binary_tree *bt, node *pilha);

//FUNCTION PILHA
void inicia(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);
int vazia(node *PILHA);

//VARIABLE
int help = 0;

//FUNCTION AVL
binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(
int item, binary_tree *left, binary_tree *right);
binary_tree* add(binary_tree *bt, int item, node *pilha);
int is_empty(binary_tree *bt);
int h(binary_tree *bt);
int balance_factor(binary_tree *bt);
binary_tree* rotate_left(binary_tree *bt);
binary_tree* rotate_right(binary_tree *bt);
int max(int a, int b);

int main() {
	int i;
	binary_tree *no = (binary_tree *) malloc(sizeof(binary_tree));
	no = create_empty_binary_tree();
	node *pi = (node *) malloc(sizeof(node));
	inicia(pi);
	for (i = 0; i < 40; i++)
	{
		push(pi);
	}
	while(scanf("%d", &i)!= EOF){
		printf("----\n");
		printf("Adicionando %d\n", i);
		no = add(no,i,pi);
		/*printf("pai: %d\n", no->item);
		if(no->left != NULL) printf("[%d]\n", no->left->item);
		if(no->right != NULL) printf("%d\n", no->right->item);*/
		if(help == 0){	
			printf("Continuou AVL...\n");
			print_la_arvore(no,pi->prox);
		}

		printf(")\n");
		for (i = 0; i < 40; i++)
		{
			push(pi);
		}
		help = 0;
	}

	
	return 0;
}

//FUNCOES AVL

int is_empty(binary_tree *bt){
	if(bt->h == -1) return 1;
	else return 0;
}

int balance_factor(binary_tree *bt)
{
	if (bt == NULL) {
		return 0;
	} else if ((bt->left != NULL) && (bt->right != NULL)) {
		return (bt->left->h - bt->right->h);
	} else if ((bt->left != NULL) && (bt->right == NULL)) {
		return (1 + bt->left->h);
	} else {
		return (-bt->right->h - 1);
	}
}

binary_tree* rotate_left(binary_tree *bt)
{
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->right != NULL) {
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}

binary_tree* rotate_right(binary_tree *bt)
{
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->left != NULL) {
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}

binary_tree* create_binary_tree(
int item, binary_tree *left, binary_tree *right){
	binary_tree *pai = (binary_tree *) malloc(sizeof(binary_tree));
	pai->item = item;
	pai->h = 0;
	pai->left = NULL;
	pai->right = NULL;
	return pai;

}
binary_tree* create_empty_binary_tree(){
	return NULL;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
int h(binary_tree *bt)
{
	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max(h(bt->left), h(bt->right));
	}
}

binary_tree* add(binary_tree *bt, int item, node *pilha)
{
	if (bt == NULL) {
		return create_binary_tree(item, NULL, NULL);
	} else if (bt->item > item) {
		bt->left = add(bt->left, item,pilha);
	} else {
		bt->right = add(bt->right, item,pilha);
	}
		bt->h = h(bt);
		binary_tree *child;
	if (balance_factor(bt) == 2 || balance_factor(bt) == -2) {
		if(help == 0)
		{	
			printf("Antes de ajustar balanceamento...\n");
			print_la_arvore(bt,pilha);
			help++;
		}
		if (balance_factor(bt) == 2) {
				child = bt->left;
			if (balance_factor(child) == -1) {
				bt->left = rotate_left(child);
			}
				bt = rotate_right(bt);
		} else if (balance_factor(bt) == -2) {
				child = bt->right;
			if (balance_factor(child) == 1) {
				bt->right = rotate_right(child);
				}
				bt = rotate_left(bt);
		}
		printf("\nDepois de ajustar balanceamento...\n");
		print_la_arvore(bt,pilha);
	}
	return bt;
}
//END OF FUCTION AVL


//FUNCOES PILHA
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
  novo->num = '(';
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

//END OF FUNCTION PILHA

//FUNCTION OF RENEGADES

void print_la_arvore(binary_tree *bt, node *pilha){
	
    if(pilha->prox == NULL) return;

    printf("%c", pilha->num);
    pop(pilha);

    if(bt!=NULL)
	{	
	   	printf(" %d ", bt->item);
	   
	    print_la_arvore(bt->left, pilha->prox);
		
		print_la_arvore(bt->right, pilha->prox);

	}
	else
	{
		printf(") ");
	}
	
	//print_la_arvore(bt, pilha->prox);
	
}