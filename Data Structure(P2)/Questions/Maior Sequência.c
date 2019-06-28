
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct node {
  int item;
  int index;
  int sequence;
  struct node *next;
};

struct node* create_linked_list(){
  return NULL;
}

int is_empty(struct node *head){
  return (head == NULL);
}

struct node* add (struct node *head, int item,int index){
  struct node *new_node = (struct node*) malloc (sizeof(struct node));
  new_node->item = item;
  new_node->index = index;
  new_node->next = head;
  new_node->sequence = 0;
  return new_node;
}

void print_linked_list (struct node *head){
  if (!is_empty(head)) {
    printf("item: [%d] ", head -> item );
    printf("index: [%d] ", head -> index );
    printf("sequence: [%d]\n", head -> sequence);
    print_linked_list(head -> next);
  }
}

int FuncaoSequencia(struct node *head){
    if(is_empty(head) || head->item == 49) return 0;
    return 1 + FuncaoSequencia(head->next);
}

void navegacao(struct node *head){
  if (!is_empty(head)) {
    head->sequence = FuncaoSequencia(head);
    navegacao(head->next);
  }
}

void AchandoMaiorSequencia(int A[], struct node *head){
    if(is_empty(head)) return ;
    else if(A[1] < head->sequence){
        A[0] = head->index;
        A[1] = head->sequence;
    }
    AchandoMaiorSequencia(A,head->next);
}

int main() {
    int k=0,item,i=0, A[2];
    
    char c, *str = NULL;
    int l = 0, j = 1;
    str = (char *) malloc(10 * sizeof(char) + 1);
    while ((c = getchar()) != EOF)
    {
      if (j == 10)
      {
        str = (char *) realloc(str, strlen(str) + 10 * sizeof(char) + 1);
        j = 1;
      }
      *(str + l * sizeof(char)) = c;
      l++;
      j++;
    }
    *(str + l * sizeof(char)) = '\0';
    
    i=0;
    j=0;
    while(1){
        if(j >= strlen(str)-1) break;
        //criando a lista encadeado para a poss�vel opera��o
        struct node* list = create_linked_list();
        
        for( ; str[j]!='\n'; j++){
            //adicionando itens a lista encadeada
              list = add(list,str[j],i);
              i++;
        }
        
        if(str[j] == '\n') j++;
        
        navegacao(list);
        
        A[0] = -1;
        A[1] = -1;
        
        AchandoMaiorSequencia(A,list);
        printf("%d %d\n", (A[0]-A[1]+1), A[0]); // A[0] encontra-se o indice de maior sequencia, A[1] encontrase a sequencia dele
        //resetando i para 0 e free para lista encadeada
        i=0;
        free(list);
    }
    free(str);
	return 0;
}
