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
binary_tree* search(binary_tree *bt, int item);
binary_tree* delete(binary_tree* node, binary_tree* pnode, int target);
int is_empty(binary_tree *bt);
void print_in_order(binary_tree *bt);
void print_pre_order(binary_tree *bt);
void print_post_order(binary_tree *bt);

int main()
{
    
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

void print_in_order(binary_tree *bt){
    if (!is_empty(bt)) {
        print_in_order(bt->left);
        printf("%d", bt->item);
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        printf("%d", bt->item);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(binary_tree *bt){
    if (!is_empty(bt)) {
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d", bt->item);
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


binary_tree* delete(binary_tree* node, binary_tree* pnode, int target){

    binary_tree* rchild;
    binary_tree* rchildparent;

    if(node==NULL) {
        return pnode;
    }
    else {
        if(target == node->item){

            if(node->left == NULL && node->right == NULL){   //leaf node
                if(pnode == NULL){ //special case deleting the root node
                    free(node);
                    return NULL;
                }
                if(pnode->left == node) {
                    pnode->left = NULL;
                } else {
                    pnode->right = NULL;
                }
                free(node);
                return pnode;
            }
            if(node->left ==NULL ){ //one child
                if(pnode == NULL){ //deleting root having no left child
                    binary_tree* temp = node;
                    node = node->right;
                    free(temp);
                    return(node);
                }
                if(pnode->left == node) {
                    pnode->left = node->right;
                }
                else {
                    pnode->right = node->right;
                }   
                free(node);
                return(pnode);
            }
            if(node->right ==NULL ) { //one child
                if(pnode == NULL) { //deleting root having no right child
                    binary_tree* temp = node;
                    node = node->left;
                    free(temp);
                    return(node);
                }
                if(pnode->left == node) {
                    pnode->left = node->left;
                }
                else {
                    pnode->right = node->left;
                }   
                free(node);
                return(pnode);
            }

            //two children case
            rchild = node->right;
            rchildparent=node;
            while(rchild->left != NULL) {
                rchildparent=rchild;
                rchild = rchild->left;
            }
            node->item = rchild->item;
            if(rchildparent == node) {
                //rchildparent->right=rchild->right;
                node->right = rchild->right;
            }
            else {
                //rchildparent->left=NULL;
                rchildparent->left = rchild->right;
            }
            free(rchild);
            if(pnode ==NULL){ //root node
                return node;
            }           
            return pnode;
        }
        else {
            if(target < node->item) {
                delete(node->left,node,target);
                return node;
            } else {
                delete(node->right,node,target);
                return node;
            }
        }
    }
}
