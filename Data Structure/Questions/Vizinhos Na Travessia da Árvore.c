#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct binary_tree {
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

binary_tree* treez = NULL;
int counter = 0;
int current[100];
int cj = 0;

binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(int item);
binary_tree* add(binary_tree *bt, int item);
binary_tree* search(binary_tree *bt, int item);
int is_empty(binary_tree *bt);
void print_in_order(binary_tree *bt);
void print_pre_order(binary_tree *bt);
void print_post_order(binary_tree *bt);
void level_order_insert(binary_tree* root, int* arr, int start, int size);
int find(binary_tree *bt);

int main()
{

    int i,N,root,size, p,q,r, salve,aux, aux2, rg,lf,tam;
    p = 0;
    q = 1;
    r = 1;
    tam = 0;
    salve = 0;
    scanf("%d", &N);
    size = (N*2)+1;
    int numbers[size];
    for(i = 1; i < size; i++){
        scanf("%d", &numbers[i]);
    }
    scanf("%d", &root);
    numbers[0] = root;

    /*for(i = 0; i < size ; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");*/

    level_order_insert(treez, numbers, 0, size);
    
    printf("Pre Order:\n");
    print_pre_order(treez);
    current[cj] = -1;
    tam = cj;
    cj=0;
    i = 0;
    p++;
    salve++;
    aux2 = 1;
    printf("Node %d: previous = %d next = %d\n", i, -1,current[p]);
    while(current[i] != -1) {
        if(current[i] == -1) break;
        if(current[i++] == salve)
        {
            q = i - 2;
            r = i;
            printf("Node %d: previous = %d next = %d\n", aux2, current[q],current[r]);
            i = 0;
            aux2++;
            salve++;
        } 
    }
    printf("In Order\n");
    print_in_order(treez);
    current[cj] = -1;
    tam = cj;
    cj=0;
    i = 0;
    salve = 0;
    aux2 = 0;
    while(current[i] != -1) {
        if(current[i] == -1) break;
        if(current[i++] == salve)
        {
            q = i - 2;
            r = i;
            rg = current[r];
            lf = current[q];
            if(r > tam) rg = -1;
            if(q < 0) lf = -1;
            printf("Node %d: previous = %d next = %d\n", aux2, lf,rg);
            i = 0;
            salve++;
            aux2++;
        }
    }
    printf("Post Order\n");
    print_post_order(treez);
    current[cj] = -1;
    tam = cj;
    cj=0;
    i = 0;
    salve = 0;
    aux2 = 0;
    while(current[i] != -1) {
        if(current[i] == -1) break;
        if(current[i++] == salve)
        {
            q = i - 2;
            r = i;
            rg = current[r];
            lf = current[q];
            if(r > tam) rg = -1;
            if(q < 0) lf = -1;
            printf("Node %d: previous = %d next = %d\n", aux2, lf, rg);
            i = 0;
            aux2++;
            salve++;
        }
        
    }
    return 0;
}

void level_order_insert(binary_tree* root, int* arr, int start, int size)
{
    int left = 2*start+1;
    int right = 2*start+2;
 
    if(left > size || right > size)
        return;
 
    if(root == NULL) {
        treez = create_binary_tree(arr[start]);
        root = treez;
    }
 
    if(root->left == NULL && root->right == NULL) {
        if(left < size)
            root->left = create_binary_tree(arr[left]);
        if(right < size)
            root->right = create_binary_tree(arr[right]);
    }
    level_order_insert(root->left, arr, left, size);
    level_order_insert(root->right, arr, right, size);
 
}

binary_tree* create_empty_binary_tree(){
    return NULL;
}

int is_empty(binary_tree *bt){
    return (bt == NULL);
}

binary_tree* create_binary_tree(int item){
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->item = item;
    new_binary_tree->left = NULL;
    new_binary_tree->right = NULL;
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
        if(bt->item != -1)
        current[cj++] = bt->item;
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        if(bt->item != -1)
        current[cj++] = bt->item;
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(binary_tree *bt){
    if (!is_empty(bt)) {
        print_post_order(bt->left);
        print_post_order(bt->right);
        if(bt->item != -1)
        current[cj++] = bt->item;
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
