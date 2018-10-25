#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// STACK STRUCT WITH LINKED LIST
typedef struct node {
    int data;
    struct node *next;
}node;
// END OF STACK STRUCT

// TOP OF STACK
node *top; 

void create_empty_stack();
void push(int value);
int pop();
int Top();
int is_empty();
void display(node *head);

int main() {
    create_empty_stack();
    push(10);
    push(20);
    push(30);
    printf("The top is %d\n",Top());
    pop();
    printf("The top after pop is %d\n",Top());
    display(top);
    return 0;
}


void create_empty_stack() {
    top = NULL;
}

void push(int value) {
    
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
}

int pop() {
    
    node *tmp;
    int n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    
    return n;
}

int Top() {
    return top->data;
}

int is_empty() {
    return top==NULL;
}

void display(node *head) {
    if(head == NULL) {
        printf("NULL\n");
    } else {
        printf("%d\n", head->data);
        display(head->next);

    }
}