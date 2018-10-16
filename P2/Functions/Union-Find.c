#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 100

int id[ARRAY_SIZE];
int size[ARRAY_SIZE];

void initialize();
int find(int p, int q);
void Union(int p, int q);
int root(int i);
int find_with_roots(int p, int q);
void union_with_roots(int p, int q);
void union_with_weigthed_roots(int p, int q);

int main()
{
    
    return 0;
}


void initialize(){
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        id[i] = i;
    }
}

int find(int p, int q){
    return (id[p] == id[q]);
}

void Union(int p, int q){

    int p_id = id[p];
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        
        if (id[i] == p_id) {
            id[i] = id[q];
        }

    }
}

int root(int i){

    while (i != id[i]) {
        i = id[i];
    }
        return i;
}

int find_with_roots(int p, int q){

    return (root(p) == root(q));
}

void union_with_roots(int p, int q){
    int p_root = root(p);
    int q_root = root(q);
    id[p_root] = q_root;
}

void union_with_weigthed_roots(int p, int q){
        
    int p_root = root(p);
    int q_root = root(q);
    if (size[p_root] < size[q_root]) {

        id[p_root] = q_root;
        size[q_root] = size[q_root] + size[p_root];
    } 
    else {

        id[q_root] = p_root;
        size[p_root] = size[p_root] + size[q_root];
    }
}