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
  return new_node;
}

void print_linked_list (struct node *head){
  if (!is_empty(head)) {
    printf("[%d]", head -> item );
    print_linked_list(head -> next);
  }
}

int FuncaoSequencia(struct node *head,int item){
    if(item == 1) return 0;
    head->sequence = 1 + FuncaoSequencia(head->next,head->next->item);
}

void navegacao(int (*f)(struct node *head, int item), struct node *head){
  if (!is_empty(head)) {
    head->sequence = (*f)(head,head->item);
    navegacao((*f)(head,head->next->item), head -> next);
  }
}

void AchandoMaiorSequencia(int A[], struct node *head){
    if(!is_empty(head)) return ;
    else if(A[1] < head->sequence){
        A[0] = head->index;
        A[1] = head->sequence;
    }
    AchandoMaiorSequencia(A,head->next);
}

int main() {
    struct node* list = create_linked_list();
    int a,i=0, A[2];
    A[0] = -1;
    A[1] = -1;
    while(scanf("%d", &a)!=EOF){
    getchar();
    list = add(list,a,i);
    i++;
    }
    navegacao(FuncaoSequencia,list);
    AchandoMaiorSequencia(A,list);
    printf("%d %d\n", (A[0]-A[1]+1), A[0]);
	return 0;
}
