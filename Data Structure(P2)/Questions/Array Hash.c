#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE_HASH_TABLE 50

typedef struct element {
    int key;
    int value;
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

void put(hash_table *ht, int key, int value){
    int h = key % MAX_SIZE_HASH_TABLE;
    while (ht->table[h] != NULL) {
        if (ht->table[h]->key == key) {
        ht->table[h]->value = value;
        break;
    }
    h = (h + 1) % MAX_SIZE_HASH_TABLE;
    }
    if (ht->table[h] == NULL) {
        element *new_element = (element*) malloc(sizeof(element));
        new_element->key = key;
        new_element->value = value;
        ht->table[h] = new_element;
    }
}


int Sum_Hash(hash_table* ht){
    int h = 0, sum = 0;
    while(ht->table[h] != NULL){
        sum = sum + ht->table[h]->value;
        h++;
    }
    return sum;
}


int main(){
   int i,j=0, round,conta = 0, elemento = 0, posicao,input;
   char str[51];
   

   scanf("%d\n", &input);
   
   while(input--){
     scanf("%d\n", &round);
     hash_table* array_hash = (hash_table*) malloc(sizeof(hash_table));
       while(round--){
         fgets(str,51,stdin);
         for(posicao = 0; posicao < strlen(str); posicao++){
           if(str[posicao] == '\n') break;
           
           conta = conta + (str[posicao] - 65) + elemento + posicao;
           //printf("other: %d, ele: %d, pos: %d / ",(str[posicao] - 65) , elemento, posicao);
         }
         
         elemento++;
         //printf("conta: %d\n", conta);
        }
      put(array_hash,j,conta);
      j++;
      printf("%d\n", Sum_Hash(array_hash));
      elemento = 0;
      conta = 0;
      j=0;
      free(array_hash);
    }
}