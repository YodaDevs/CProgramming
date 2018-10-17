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
void print_tree_brackets(binary_tree* root);
void nodesprintHier(binary_tree* p ,int flag);
int main()
{
    binary_tree* bt = create_empty_binary_tree();
    bt = add(bt,11);
    bt = add(bt,2);
    bt = add(bt,4);
    bt = add(bt,13);
    bt = add(bt,15);

    print_tree_brackets(bt);
    printf("\n");
    nodesprintHier(bt,0);
    printf("\n");
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

// Function to construct brackets with binary tree 
void print_tree_brackets(binary_tree* root) 
{ 
    // bases case 
    if (root == NULL) 
        return; 
  
    // push the root data
    printf("%d", root->item);
  
    // if leaf node, then return 
    if (is_empty(root->left) && is_empty(root->right)) 
        return; 
  
    // for left subtree 
    printf("("); 
    print_tree_brackets(root->left);
    printf(")"); 
  
    // only if right child is present to  
    // avoid extra parenthesis 
    if (root->right) { 
        printf("("); 
        print_tree_brackets(root->right); 
        printf(")"); 
    } 
} 
/* flag is zero when we came form a left child and 1 when from a 
right one.When called,function gets as 2nd parameter 0 
void nodesprintHier(binary_tree* p ,int flag){ 

    if( p != NULL ) {
       
        if(!flag)  printf("(%d ", p->item);

        else   printf(" %d)", p->item);

        nodesprintHier(p->left,0);
        nodesprintHier(p->right,1);
  }
}*/

void nodesprintHier(binary_tree* p ,int flag)
{ 
    if (p == 0) {
        printf("[]");
        return;
    }
 
         printf("%d", p->item);
     
    printf("(");
    nodesprintHier(p->left,0);
    printf(")");
 
    printf("(");
    nodesprintHier(p->right,1);
    printf(")");
 
    return;
}
/*
TEST OF ELIMINATE BRACKETS

//functin to return the index of close parenthesis 
int findIndex(string str, int si, int ei) 
{ 
    if (si > ei) 
        return -1; 
  
    // Inbuilt stack 
    stack<char> s; 
  
    for (int i = si; i <= ei; i++) { 
  
        // if open parenthesis, push it 
        if (str[i] == '(') 
            s.push(str[i]); 
  
        // if close parenthesis 
        else if (str[i] == ')') { 
            if (s.top() == '(') { 
                s.pop(); 
  
                // if stack is empty, this is  
                // the required index 
                if (s.empty()) 
                    return i; 
            } 
        } 
    } 
    // if not found return -1 
    return -1; 
} 
  
// function to construct tree from string 
Node* treeFromString(string str, int si, int ei) 
{ 
    // Base case 
    if (si > ei) 
        return NULL; 
  
    // new root 
    Node* root = newNode(str[si] - '0'); 
    int index = -1; 
  
    // if next char is '(' find the index of 
    // its complement ')' 
    if (si + 1 <= ei && str[si + 1] == '(') 
        index = findIndex(str, si + 1, ei); 
  
    // if index found 
    if (index != -1) { 
  
        // call for left subtree 
        root->left = treeFromString(str, si + 2, index - 1); 
  
        // call for right subtree 
        root->right = treeFromString(str, index + 2, ei - 1); 
    } 
    return root; 
} 
  
// Driver Code 
int main() 
{ 
    string str = "4(2(3)(1))(6(5))"; 
    Node* root = treeFromString(str, 0, str.length() - 1); 
    preOrder(root); 
} */
