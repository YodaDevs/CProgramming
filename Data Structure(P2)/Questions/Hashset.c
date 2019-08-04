#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct node{
    int key;
    struct node *next;
}node;
 
typedef struct hash_table{
    node **table;
}hash_table;
 
 
hash_table* create_hash_table(int size){
    hash_table *new_hash = (hash_table*) malloc(sizeof(hash_table));
    int i;
    new_hash->table = (node**) calloc(sizeof(node)*size, sizeof(node));
   
    for(i=0; i<size; i++){
        new_hash->table[i] = NULL;
    }
    return new_hash;
}
 
int put(hash_table *ht, int key, int size, int *count){
    int h = key % size;
    node *aux = ht->table[h], *new_node = (node*) malloc(sizeof(node));
 
    new_node->key = key;
    new_node->next = NULL;
    while(aux != NULL){
        (*count)++;
        if(aux->key == key){
            return 0;
        }
        aux = aux->next;
    }
 
    if(ht->table[h] == NULL){
        ht->table[h] = new_node;
    }else{
        new_node->next = ht->table[h];
        ht->table[h] = new_node;
    }
    return 1;
}
void print_t(node *x){
    if(x == NULL) return;
    
    print_t(x->next);
    printf("%d ", x->key);
}
 
void print(hash_table *ht, int size){
    int i;
    for(i = 0; i<size; i++){
        printf("%d ", i);
        print_t(ht->table[i]);
        puts("");
    }
    puts("");
}

void delete_node(node *x){
    if(x == NULL) return;
    if(x->next == NULL) return;
    delete_node(x->next);
    free(x->next);
}
 
void delete_ht(hash_table *ht, int size){
    int i;
    for(i=0; i<size; i++){
        delete_node(ht->table[i]);
        ht->table[i] = NULL;
    }
}

 
int check_hash(hash_table *ht, int key, int size, int *count){
    int h = key % size;
   
    node *aux = ht->table[h];    
   
    if(aux == NULL) return 0;
    (*count)++;
    while(aux->next != NULL && aux->key != key){
        (*count)++;
        aux = aux->next;
    }
   
    if(aux->key == key) return 1;
   
    return 0;
}

int erase_h(hash_table *ht, int key, int size, int *count){
    int h = key % size;
    node *aux = ht->table[h];

    if(aux == NULL) return 0;
    (*count)++;
    if(aux->key == key){
        ht->table[h] = ht->table[h]->next;
        return 1;
    }
 
    while(aux->next!=NULL){
        (*count)++;
        if(aux->next->key == key){
            aux->next = aux->next->next;
            return 1;
        }
        aux = aux->next;
    }
    return 0;
 
}
 
int count_node(node *x){
    if(x == NULL) return 0;
    return 1 + count_node(x->next);
}
 
float count_h(hash_table *ht, int size, int *biggest){
    int i, j = 0;
    float count = 0;
    for(i=0; i<size; i++){
        j = count_node(ht->table[i]);
        count += j;
        if(j > *biggest) *biggest = j;
    }
    return count;
}
 
void rehashing_node(node *previous, hash_table *new_hash, int size){
    int count = 0;
    while(previous != NULL){
        put(new_hash, previous->key, size, &count);
        previous = previous->next;
    }
}
 
hash_table* rehashing(hash_table *ht, int *size){
    int aux = *size, i;
    *size = (2*(*size) - 1);
 
    hash_table *new_hash = create_hash_table(*size);
   
    for(i=0; i<aux; i++){        
        rehashing_node(ht->table[i], new_hash, *size);
    }
 
    return new_hash;
}
 
int main() {
   
    int size = 7, key, i, count, biggest;
    float card = 0;
    i = count = biggest = 0;
    hash_table *ht = create_hash_table(size);  
    char caracters[4];
   
    while(scanf("%s", caracters) != EOF){
        count = biggest = 0;        
        printf("%d ", i);i++;
        if(caracters[0] == 'A'){
            scanf("%d\n", &key);
            printf("%d ", put(ht, key, size, &count));
           printf("%d\n", count);
            card = count_h(ht, size, &biggest);
            if(card/(float)size >= 0.75){
                ht = rehashing(ht, &size);            
            }
        }else if(caracters[0] == 'H'){          
            scanf("%d\n", &key);
            printf("%d ", check_hash(ht, key, size, &count));
            printf("%d\n", count);
           
        }else if(caracters[0] == 'D'){
            scanf("%d\n", &key);
            printf("%d ", erase_h(ht, key, size, &count));
           printf("%d\n", count);
        }else if(caracters[0] == 'P'){
            card = count_h(ht, size, &biggest);
            printf("%d %.0f %d\n", size, card, biggest);
        }else if(caracters[0] == 'I'){puts("");
            print(ht, size);
        }
    }
   
    return 0;
}