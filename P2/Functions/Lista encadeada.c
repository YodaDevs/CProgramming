#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node *next;
};

struct node* create_linked_list(){
  return NULL;
}

int is_empty(struct node *head){
  return (head == NULL);
}

struct node* add (struct node *head, int item){
  struct node *new_node = (struct node*) malloc (sizeof(struct node));
  new_node->item = item;
  new_node->next = head;
  return new_node;
}

void print_linked_list (struct node *head){
  if (!is_empty(head)) {
    printf("[%d]", head -> item );
    print_linked_list(head -> next);
  }
}

int main() {
  struct node* list = create_linked_list();
  int a;
  char c;
  while(1){
    printf("Cadastre seu número\n");
    scanf("%d",&a);
    getchar();
    list = add(list,a);
    printf("tentar novamente?\nS ou N: ");
    scanf("%c", &c);
    if (c=='N') break;
  }
  print_linked_list(list);
  printf("\n");
  return 0;
}