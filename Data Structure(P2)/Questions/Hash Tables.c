#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE_HASH_TABLE 100

typedef struct element {
    int key;
    int value[100];
}element;

typedef struct hash_table {
    element *table[MAX_SIZE_HASH_TABLE];
}hash_table;

hash_table* create_hash_table(){
    hash_table *new_hash_table = (hash_table*) malloc(sizeof(hash_table));
    int i;
    for (i = 0; i < MAX_SIZE_HASH_TABLE; i++) {
        new_hash_table->table[i] = NULL;
    }
    return new_hash_table;
}

void put(hash_table *ht, int key, int value,int tam){
    int h = value % key, i = 0;
    while (ht->table[h] != NULL) {
        if (ht->table[h]->key == key) {
            while(ht->table[h]->value[i] != -1)
            i++;
            ht->table[h]->value[i] = value;
            break;
        }
        h = (h + 1) % key;
    }
    if (ht->table[h] == NULL) {
        element *new_element = (element*) malloc(sizeof(element));
        new_element->key = key;
        new_element->value[0] = value;
        for(i = 1; i < 100; i++){
            new_element->value[i] = -1;
        }
        ht->table[h] = new_element;
    }
}

void print_hash_table(hash_table *ht, int key){
    int i,j = 0;
    for(i = 0; i < key; i++){
        printf("%d ->", i);
        if(ht->table[i] != NULL){
            while(ht->table[i]->value[j] != -1) {
                printf(" %d ->",ht->table[i]->value[j]);
                j++;
            }
            j=0;
        }
        printf(" \\\n");
    }
}

int main(){
   int i,case_of_test, M, C,numbers;
   
   scanf("%d\n", &case_of_test);
   //printf("%d\n", case_of_test);
   while(case_of_test--){
       hash_table* ht = create_hash_table();
       scanf("%d %d\n",&M, &C);
       while(C--){
           scanf("%d",&numbers);
           put(ht,M,numbers,5);
       }
       print_hash_table(ht,M);
       free(ht);
       printf("\n");
   }

}