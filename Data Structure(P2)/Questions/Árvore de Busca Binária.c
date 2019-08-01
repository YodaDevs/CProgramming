#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct binary_tree {
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

int array_number[100];
int count = 0;
int id = 0;

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
        bt = create_binary_tree(item,NULL, NULL);
    } 
    else if (bt->item > item) {
        bt->left = add(bt->left, item);
    } 
    else {
        bt->right = add(bt->right, item);
    }
    return bt;
}

int boolean(binary_tree* bt){
    if(array_number[id] != bt->item){
        id++;
        return 1;
    }
    else {
        id++;
        return 0;
    }
}

void relationship_array_with_tree(binary_tree *bt){
    if (!is_empty(bt)) {
        count = count + boolean(bt);
        relationship_array_with_tree(bt->left);
        relationship_array_with_tree(bt->right);
    }
}

void print_pre_order(binary_tree *bt){
    if (!is_empty(bt)) {
        printf("[%d] ", bt->item);
       // printf(" left-> ");
        print_pre_order(bt->left);
       // printf(" Right-> ");
        print_pre_order(bt->right);
    }
}

int main()
{
    int i,l=0, j=1,number;
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
    
    for(i = 0, j = 0; i < strlen(str) ; i++){
        number=0;
        if(str[i] >= 48 && str[i]<=57){
            number = str[i] - 48;
            i++;
            while(str[i] >= 48 && str[i]<=57 ){
                number = number*10;
                number = number + (str[i] - 48);
                i++;
            }
            bt = add(bt,number);
            array_number[j] = number;
            j++;
        }
    }
    free(str);
    for(i = 0; i < j; i++){
        printf("[%d] ", array_number[i]);
    }
    printf("\n");
    print_pre_order(bt);
    printf("\n");
    relationship_array_with_tree(bt);
    if(count){
        printf("FALSO\n");
    }
    else{
        printf("VERDADEIRO\n");
    }
    return 0;
}
