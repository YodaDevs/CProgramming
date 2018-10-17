#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct binary_tree {
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right);
binary_tree* add(binary_tree *bt, int item);
binary_tree* search(binary_tree *bt, int item);
int is_empty(binary_tree *bt);
void print_in_order(binary_tree *bt);
void print_pre_order(binary_tree *bt);
void print_post_order(binary_tree *bt);
int find(binary_tree *bt);

int main(){
    int i,N,root;

    binary_tree* bt = create_empty_binary_tree();
    scanf("%d", &N);
    int numbers[N*2];
    for(i = 0; i < N*2; i++){
        scanf("%d", &numbers[i]);
    }
    scanf("%d", &root);
    bt = add(bt,root);
    /*for(i = 0; i < N *2 ; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");*/

    for(i = 0; i < N - 1; i++){
        if(numbers[i] != -1)
        bt = add(bt,numbers[i]);
    }
    
    printf("Pre Order:\n");
    print_pre_order(bt);
    printf("\n");
    printf("In Order\n");
    print_in_order(bt);
    printf("\n");
    printf("Post Order\n");
    print_post_order(bt);
    printf("\n");

    return 0;
}

binary_tree* add(binary_tree *bt, int item, int flag){
    int esq,dir;
    if (bt == NULL) {
        bt = create_binary_tree(item, NULL, NULL);
    }
    else if (flag%2 || bt->left != NULL || bt->right!=NULL) {
        scanf("%d %d", &esq,&dir);
        bt->left = esq;
        bt->right = dir;
        bt->left = add(bt->left, item);
    }
    else {
        scanf("%d %d", &esq,&dir);
        bt->left = esq;
        bt->right = dir;
        bt->right = add(bt->right, item);
    }
    return bt;
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

int find(binary_tree *bt){
    if(bt != NULL){
    return (bt->item);
    }
    else{
    return (-1);
    }
}

void print_in_order(binary_tree *bt){
    if (!is_empty(bt)) {
        print_in_order(bt->left);
        printf("%d ", bt->item);
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        printf("Node %d: previous = %d next = %d\n", bt->item, find(bt->left), find(bt->right));
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(binary_tree *bt){
    if (!is_empty(bt)) {
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d ", bt->item);
    }
}

binary_tree* search(binary_tree *bt, int item){
    if ((bt == NULL) || (bt->item == item)) {
        return bt;
    }
    else if (bt->item > item) {
        return search(bt->left, item);
    }
    else {
        return search(bt->right, item);
    }
}

