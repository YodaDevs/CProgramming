#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct binary_tree {
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right);
binary_tree* add(binary_tree *bt, int item);
int is_empty(binary_tree *bt);
void print_tree_brackets(binary_tree* root);

int main()
{
    binary_tree* bt = create_empty_binary_tree();
    int number;
    while(scanf("%d", &number)!= EOF){
        printf("----\nAdicionando %d\n", number);
        printf("   ");
        bt = add(bt,number);
        print_tree_brackets(bt);
        printf(" \n");
        
    }
    printf("----\n");
    
    return 0;
}

binary_tree* create_empty_binary_tree(){
    return NULL;
}

int is_empty(binary_tree *bt){
    return (bt == NULL);
}

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right){
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->item = item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}

binary_tree* add(binary_tree *bt, int item){
    if (bt == NULL) {
        bt = create_binary_tree(item, NULL, NULL);
    } 
    else if (bt->item > item) {
        bt->left = add(bt->left, item);
    } 
    else {
        bt->right = add(bt->right, item);
    }
    return bt;
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
        printf("( %d", root->item);
    }
    // for left subtree 
    printf("  ");
    print_tree_brackets(root->left);
    // for right subtree
    printf("  ");
    print_tree_brackets(root->right); 

    printf(" )");
} 
