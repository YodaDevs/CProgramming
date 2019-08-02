#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// BEGIN STRUCT BINARY TREE
typedef struct binary_tree {
    int item;
    int count;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;
// END OF STRUCT BINARY TREE

#define MAX_STACK_SIZE 100

// BEGIN STACK STRUCT WITH ARRAY
typedef struct stack {
    int current_size; 
    char items[MAX_STACK_SIZE];
}stack;
// END OF STACK STRUCT

// STACK FUNCTIONS
stack* create_stack() {

    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack->current_size = 0;
    return new_stack;
}

int is_stack_empty(stack *stack){
    return (stack->current_size == 0);
}

void push(stack *stack, int item) {

    if (stack->current_size == MAX_STACK_SIZE) {
        //printf("Stack overflow");
    } else {
        stack->items[stack->current_size++] = item;
    }

}

int pop(stack *stack) {
    
    if (is_stack_empty(stack)) {
        //printf("Stack underflow");
        return -1;

    } else {
        return stack->items[--stack->current_size];
    }
}
int peek(stack *stack) {
    
    if (is_stack_empty(stack)) {
        //printf("Stack underflow");
        return -1;

    } else {
        return stack->items[stack->current_size - 1];
    }
}
//END OF STACK FUNCTIONS


binary_tree* create_empty_binary_tree(){
    return NULL;
}

int is_empty(binary_tree *bt){
    return (bt == NULL);
}

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right){
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->item = item;
    new_binary_tree->count = 0;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        printf("[%d]", bt->item);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

int Find_Index(char str[], int begin, int end){
    stack* aux_stack = create_stack();

    /*while(str[begin] >= 48 && str[begin]<=57 ){
        begin++;
    }*/

    if(str[begin] == '('){
        push(aux_stack,str[begin]);
    }

    while(!is_stack_empty(aux_stack)){
        begin++;
        if(str[begin] == '('){
            push(aux_stack,str[begin]);
        }
        if(str[begin] == ')'){
            pop(aux_stack);
        }
    }

    return begin;

}

binary_tree* build_BinaryTree_from_string(char str[],int begin,int end){
    int number = -1, index_left_end = 0, index_right_begin = 0;

    if(begin >= end) return NULL;

    if(str[begin] >= 48 && str[begin]<=57){
        number = (str[begin] - 48);
        begin++;
        while(str[begin] >= 48 && str[begin]<=57 ){
            number = number*10;
            number = number + (str[begin] - 48);
            begin++;
        }
    }
    if(number == -1) return NULL;
    binary_tree* root = create_binary_tree(number,NULL,NULL);

    index_left_end = Find_Index(str,begin,end);

    root->left = build_BinaryTree_from_string(str,begin + 1,index_left_end - 1);
    index_right_begin = Find_Index(str,begin,end) + 1;
    if(str[index_right_begin] == ' ') index_right_begin++;
    root->right = build_BinaryTree_from_string(str,index_right_begin + 1,end - 1);
    
    return root;
}


void is_binary_tree(binary_tree* root){
    if(!is_empty(root->left)){
        if(root->item > root->left->item) ;
        else root->count++; 
    }
    if(!is_empty(root->right)){
        if(root->item < root->right->item) ;
        else root->count++;
    }
    return;
}

void navegation(binary_tree *bt){
    if (!is_empty(bt)) {
        is_binary_tree(bt);
        navegation(bt->left);
        navegation(bt->right);
    }
}

int find_count(binary_tree *bt){
    if (!is_empty(bt)) {
        if(bt->count > 0) return 1;
        return 0 + find_count(bt->left) + find_count(bt->right);
    }
}

// Function to construct brackets with binary tree 
void print_tree_brackets(binary_tree* root) 
{ 
    // bases case 
    if (root == NULL){ 
        printf("("); 
        printf(")");
        return; 
    }
    if(root != NULL){
        printf("(%d", root->item);
    }
    // for left subtree 
    //printf("");
    print_tree_brackets(root->left);
    // for right subtree
    //printf("  ");
    print_tree_brackets(root->right); 

    printf(")");
} 

int main()
{
    int i,l=0, j=1,number, bol;
    binary_tree* bt = create_empty_binary_tree();
    
    char c, *str = NULL;
    str = (char *) malloc(10 * sizeof(char) + 1);
    //Lendo todas as letras possiveis de entrada com realloc para string dinamicamente
    while ((c = getchar()) != '\n' && c != EOF && c != '\0'){
      if (j == 10){
        str = (char *) realloc(str, strlen(str) + 10 * sizeof(char) + 1);
        j = 1;
      }
      *(str + l * sizeof(char)) = c;
      l++;
      j++;
    }
    *(str + l * sizeof(char)) = '\0';
    /*for (i = 0; i < strlen(str); i++){
        printf("%c", str[i]);
    }
    printf("\n");*/
    
    bt = build_BinaryTree_from_string(str,1,strlen(str)-1);
    
    //print_tree_brackets(bt);
    //printf("\n");
    navegation(bt);
    bol = find_count(bt);
    //printf("%d\n", bol);
    if(bol && !is_empty(bt)){
        printf("FALSO\n");
    }
    else{
        printf("VERDADEIRO\n");
    }
    
    return 0;
}
