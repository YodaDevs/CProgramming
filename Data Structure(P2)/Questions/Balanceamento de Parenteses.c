#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(!is_empty(stack)){
        node *tmp;
        int n;
        tmp = stack->top;
        n = tmp->data;
        stack->top = stack->top->next;
        free(tmp);
        return n;

    }
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
  
  char str[256];
  int counter, i =0, k = 0, j;
  scanf("%d\n", &counter);
  while(counter--){
      stack *parenteses = Create_Stack();
      fgets(str,256,stdin);
      for (j = 0; j < strlen(str) ; j++){
            if(str[j] == '('){
                Push(parenteses,str[j]);
                i++;
            }
            if (str[j] == ')')
            {
                Pop(parenteses);
                i--;
            }
            if(str[j] == '['){
                Push(parenteses,str[j]);
                k++;
            }
            if(str[j] == ']'){
                Pop(parenteses);
                k--;
            }
      }   
      if(i == 0 && k == 0 && is_empty(parenteses))
      printf("Yes");
      else printf("No");

      free(parenteses);
  }
  return 0;
}
