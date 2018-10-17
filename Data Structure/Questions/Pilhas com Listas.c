#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
	char num[10000];
	//char *num = (char*)malloc(sizeof(char*100));
	struct node* next;
} No;

typedef struct pilha {
	No *topo;
} Pilha;

Pilha* create_stack (void);
void push(Pilha *p, char elem[]);
void pop(Pilha *p);
int empty (Pilha *p);
void print (Pilha *p);
void free_stack (Pilha *p);

int main()
{
  char str[5], num[10000];
  int i=0;
  Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
  pi = create_stack();
  while(fgets(str,5,stdin))
  {
    //fgets(str,5,stdin);
    
    if (str[1]=='U') {

      getchar();
      fgets(num,10000,stdin);

      push(pi,num);

    }
    else if(str[1]=='O'){
      if (!(empty(pi))) {
        pop(pi);
      }
      else{
        printf("EMPTY STACK\n");
      }
    }
  }
	return 0;
}

Pilha* create_stack (void) {
  	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  	p->topo = NULL;
  	return p;
}

void push(Pilha *p, char elem[]) {
  	No *n = (No*)malloc(sizeof(No));
  	strcpy(n->num, elem);
  	n->next = p->topo;
  	p->topo = n;
}

void pop(Pilha *p){
	if(empty(p)) { exit(1); }
	No *n = p->topo;
	char elem[10000];
	strcpy(elem,n->num);
	p->topo = n->next;
	free(n);
	printf("%s", elem);
}

int empty (Pilha *p) {
	return (p->topo == NULL);
}

void print (Pilha *p) {
	No *n;
	for (n=p->topo; n!=NULL; n=n->next) {
		printf("%s\n", n->num);
	}
}

void free_stack (Pilha *p) {
	No *n = p->topo;
	while (n != NULL) {
		No *temp = n->next;
		free(n); /*desalocando os nos*/
		n = temp;
	}
	free (p); /*desalocando a pilha*/
}