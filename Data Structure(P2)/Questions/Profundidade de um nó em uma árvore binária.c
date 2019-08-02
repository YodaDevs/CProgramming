#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// BEGIN STRUCT BINARY TREE
typedef struct binary_tree {
    int item;
    int level;
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
    new_binary_tree->level = 0;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        printf("[%d] level: [%d] ", bt->item, bt->level);
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

// Function to construct brackets with binary tree 
void print_tree_brackets(binary_tree* root) { 
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

int getLevelCount(binary_tree *root){
    if (root == NULL){
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(root->left);
    int rightMaxLevel = 1 + getLevelCount(root->right);
    
    if (leftMaxLevel > rightMaxLevel)  return leftMaxLevel;
    else return rightMaxLevel;
    
}

int printLevel(binary_tree* root, int level){
    if (root != NULL && level == 0){
        printf("%d\n", root->item);
    }   
    else if (root != NULL){
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int complete_deep(binary_tree* root, int level, int i){
    if(root == NULL){
        return 0;
    }
    else{
        root->level = (level - i);
    }
    complete_deep(root->left, level, --i);
    i++;
    complete_deep(root->right, level, --i);
}

void Find_all_Levels(binary_tree* root){
    int levelCount = getLevelCount(root);
    complete_deep(root,levelCount,levelCount);
}

binary_tree* find_number(binary_tree* root, int number, binary_tree* search){
    if(root == NULL){
        return search;
    }
    if(root->item == number){
        return root;
    }
    search = find_number(root->left,number,search);
    search = find_number(root->right,number,search);

    return search;
}


int main(){

    int i,l=0, j=1, number, tam,aux;
    binary_tree* bt = create_empty_binary_tree();
    
    char c, *str = NULL;
    str = (char *) malloc(10 * sizeof(char) + 1);
    //Lendo todas as letras possiveis de entrada com realloc para string dinamicamente
    while ((c = getchar()) != EOF && c != '\0'){
      if (j == 10){
        str = (char *) realloc(str, strlen(str) + 10 * sizeof(char) + 1);
        j = 1;
      }
      *(str + l * sizeof(char)) = c;
      l++;
      j++;
    }
    *(str + l * sizeof(char)) = '\0';
    tam = strlen(str);
    /*for (i = 0; i < tam; i++){
        printf("%c", str[i]);
    }
    printf("\n");*/
    
    bt = build_BinaryTree_from_string(str,1,tam-1);
    
    //print_tree_brackets(bt);
    //printf("\n");
    tam--;
    if(str[tam] >= 48 && str[tam]<=57){
        number = (str[tam] - 48);
        tam--;
        while(str[tam] >= 48 && str[tam]<=57 ){
            aux = (str[tam] - 48)*10;
            number = number + aux;
            tam--;
        }
    }
    //printf("%d\n", number);
    Find_all_Levels(bt);
    /*printf("level of root: %d", bt->level);
    printf("\n");
    print_pre_order(bt);
    printf("\n");*/
    binary_tree* search = NULL;
    search = find_number(bt,number,search);
    if(!is_empty(search)){
        printf("ESTA NA ARVORE\n%d\n", search->level);
    }
    else{
        printf("NAO ESTA NA ARVORE\n-1\n");
    }
    return 0;
}
