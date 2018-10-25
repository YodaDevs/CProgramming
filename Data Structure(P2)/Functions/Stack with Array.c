#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 10

// BEGIN STACK STRUCT WITH ARRAY
typedef struct stack {
    int current_size; 
    int items[MAX_STACK_SIZE];
}stack;
// END OF STACK STRUCT

// CONTRACT FUNCTIONS
stack* create_stack();
void push(stack *stack, int item);
int pop(stack *stack);
int peek(stack *stack);
int is_empty(stack *stack);
// END OF CONTRACT FUNCTIONS

int main(){
    
    return 0;
}

// STACK FUNCTIONS
stack* create_stack() {

    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack->current_size = 0;
    return new_stack;
}

int is_empty(stack *stack){
    return (stack->current_size == 0);
}

void push(stack *stack, int item) {

    if (stack->current_size == MAX_STACK_SIZE) {
        printf("Stack overflow");
    } else {
        stack->items[stack->current_size++] = item;
    }

}

int pop(stack *stack) {
    
    if (is_empty(stack)) {
        printf("Stack underflow");
        return -1;

    } else {
        return stack->items[--stack->current_size];
    }
}
int peek(stack *stack) {
    
    if (is_empty(stack)) {
        printf("Stack underflow");
        return -1;

    } else {
        return stack->items[stack->current_size - 1];
    }
}

//END OF STACK FUNCTIONS