#include <stdio.h>
#include <stdlib.h>

// STACK STRUCT WITH LINKED LIST
typedef struct node {
    int data;
    struct node *next;
}node;
// END OF STACK STRUCT

// TOP OF STACK
typedef struct Stack{
  node *top; 
}stack;

stack* Create_Stack() {
  stack *new_stack = (stack*) malloc(sizeof(stack));
  new_stack->top = NULL;
  return new_stack;
}

void Push(stack *stack, int value) {
    node *new_top = (node*) malloc(sizeof(node));
    new_top->data = value;
    new_top->next = stack->top;
    stack->top = new_top;
}

int Pop(stack* stack) {
    node *tmp;
    int n;
    tmp = stack->top;
    n = tmp->data;
    stack->top = stack->top->next;
    free(tmp);
    
    return n;
}

int Top(stack* stack) {
    return stack->top->data;
}

int is_empty(stack* stack) {
    return (stack->top==NULL);
}

int Stack_Size(node* top){
  if(top != NULL){
    return 1 + Stack_Size(top->next);
  }
  else {
    return 0;
  }
  
}

int main() {
  
  stack *back = Create_Stack();
  stack *forward = Create_Stack();
  
  char str[8];
  int flag = 0;
  while(scanf("%s", str) != EOF){
    
    if(str[0]=='E'){
      flag++;
      if(flag > 1) Push(back,1);
      forward = Create_Stack();
    }
    if(str[0]== 'B' && (!is_empty(back))){
      Push(forward,Pop(back));
      if(flag > 1) flag--;
    }
    if(str[0] == 'F' && (!is_empty(forward))){
      Push(back,Pop(forward));
    }
  }
  printf("BACK: %d\n", Stack_Size(back->top));
  printf("FORWARD: %d\n", Stack_Size(forward->top));
  free(back);
  free(forward);
  return 0;
}
