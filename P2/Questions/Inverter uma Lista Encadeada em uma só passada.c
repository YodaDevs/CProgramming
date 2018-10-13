#include <stdio.h>
#include <string.h>
#include <math.h>
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
    printf("%d ", head -> item );
    print_linked_list(head -> next);
  }
}

int main() {
  struct node* list = create_linked_list();
  int a;
  while(scanf("%d",&a) != EOF){
    list = add(list,a);
  }
  print_linked_list(list);
  return 0;
}