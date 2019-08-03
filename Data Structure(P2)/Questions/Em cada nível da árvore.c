#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct binary_tree {
    struct binary_tree **binarytree_node;
    int id, height, left, right;
}binary_tree;

binary_tree* create_fake_empty_binary_tree(int size_of_tree);
int height_of_tree(binary_tree* bt, int i, int height);
int low_id(binary_tree* bt, int level, int i);
int high_id(binary_tree* bt, int level, int i);

int main() {
    int i=0,id=0, left = 0, right = 0,input;
    scanf("%d\n", &input);
    binary_tree * root = create_fake_empty_binary_tree(input);
    while(input--){
        scanf("%d %d %d", &id, &left, &right);
        root->binarytree_node[i]->id = id;
        root->binarytree_node[i]->left = left;
        root->binarytree_node[i]->right = right;
        i++;   
    }
    for( i = 1; i <= height_of_tree(root,0,1); i++){
        printf("Nivel %d: Maior = %d, Menor = %d\n", i, high_id(root, i, 0), low_id(root, i, 0));
    }
	return 0;
}


binary_tree* create_fake_empty_binary_tree(int size_of_tree){
    int i;
    binary_tree* new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
   
    new_binary_tree->binarytree_node = (binary_tree**) malloc(sizeof(binary_tree*)*size_of_tree);
   
    for(i=0; i<size_of_tree; i++){
        new_binary_tree->binarytree_node[i] = (binary_tree*) malloc(sizeof(binary_tree));
        new_binary_tree->binarytree_node[i]->id  = new_binary_tree->binarytree_node[i]->height = new_binary_tree->binarytree_node[i]->left = new_binary_tree->binarytree_node[i]->right = -1;
    }
    return new_binary_tree;
}


int height_of_tree(binary_tree* bt, int i, int height){
    int h1,h2;
    if(i==-1) return height-1;
    
    bt->binarytree_node[i]->height = height;
   
    h1 = height_of_tree(bt, bt->binarytree_node[i]->left, height+1);
    h2 = height_of_tree(bt, bt->binarytree_node[i]->right, height+1);
    
    if(h1 > h2) return h1;
    else return h2;
}


int low_id(binary_tree* bt, int level, int i){
    int low1, low2;
    if(i==-1) return 6666;
    
    if(bt->binarytree_node[i]->height==level) return bt->binarytree_node[i]->id;
 
    low1 = low_id(bt, level, bt->binarytree_node[i]->left);
    low2 = low_id(bt, level, bt->binarytree_node[i]->right);
 
    if(low1 > low2) return low2;
    else return low1;
}
 
int high_id(binary_tree* bt, int level, int i){
    int high1,high2;
    if(i==-1) return -1;
    
    if(bt->binarytree_node[i]->height==level) return bt->binarytree_node[i]->id;
    
    high1 = high_id(bt, level, bt->binarytree_node[i]->left);
    high2 = high_id(bt, level, bt->binarytree_node[i]->right);
    
    if(high1 > high2) return high1;
    else return high2;

}