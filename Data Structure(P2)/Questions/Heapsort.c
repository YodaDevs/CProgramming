#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
#define MAX_HEAP_SIZE 100
 
typedef struct heap {
    int size;
    int data[MAX_HEAP_SIZE];
}heap;
 
heap* create_heap();
void enqueue(heap *heap, int item);
int dequeue(heap *heap);
int get_parent_index(heap *heap, int i);
int get_left_index(heap *heap, int i);
int get_right_index(heap *heap, int i);
void max_heapify(heap *heap, int i);
int item_of(heap *heap, int i);
void heapsort(heap *heap);
 
int get_parent_index(heap *heap, int i){
    return i/2;
}
int get_left_index(heap *heap, int i){
    return 2*i;
}
int get_right_index(heap *heap, int i){
    return 2*i + 1;
}
int item_of(heap *heap, int i){
    return heap->data[i];
}
 
heap* create_heap(){
    heap *new_heap = (heap*) malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}
 
void swap(int *x, int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
 
void enqueue(heap *heap, int item){
       
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap overflow");
    }else{
        heap->data[++heap->size] = item;
        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);
        while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index]) {
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);
        }
    }
}
 
int is_empty(heap *heap){
    return !heap->size;
}
int dequeue(heap *heap){
    if(is_empty(heap)){
        printf("Heap underflow");
        return -1;
    }else{
        int item = heap->data[1];
       
        heap->data[1] = heap->data[heap->size];
       
        heap->size--;
       
        max_heapify(heap, 1);
       
        return item;
    }
}
 
void Construct_Max_Heap(heap* heap){
    
    int size = heap->size;
    
    for(size/= 2; size>= 1; size--){
        max_heapify(heap, size);
    }
}
 
void max_heapify(heap* h, int i){
    int l = get_left_index(h, i),
        r = get_right_index(h, i),
        largest;
   
    if(l <= h->size && h->data[l]>h->data[i])
        largest = l;
    else
        largest = i;
    if(r <= h->size && h->data[r]>h->data[largest])
        largest = r;
       
    if(h->data[largest] != h->data[i]){
        swap(&h->data[i], &h->data[largest]);
        max_heapify(h, largest);
    }
}
 
void heapsort(heap* h){
    int i, j;
    for (i=h->size; i >= 2; i--) {
        printf("Estado Atual da Heap: %d", h->data[1]);
        for(j=2; j<=h->size; j++){
            printf(" | %d", h->data[j]);
        }puts("");
        printf("Maior elemento neste passo: %d\n", h->data[1]);
        swap(&h->data[1], &h->data[i]);
        h->size--;
        max_heapify(h, 1);
    }
    printf("Estado Atual da Heap: %d", h->data[1]);
    for(j=2; j<=h->size; j++){
        printf(" | %d", h->data[j]);
    }puts("");
}
 
int main() {
    int size=1, i;
    
    heap *Heap = create_heap();
    
    for(size = 1;scanf("%d", &Heap->data[size])!=EOF; size++);
    
    Heap->size = --size;
    printf("Estado inicial: %d", Heap->data[1]);
    
    for(i=2; i<=size; i++){
        printf(" | %d", Heap->data[i]);
    }puts("");
    
    Construct_Max_Heap(Heap);
    heapsort(Heap);

    printf("Resultado Final: %d", Heap->data[1]);
    
    for(i=2; i<=size; i++){
        printf(" | %d", Heap->data[i]);
    }puts("");
   
    return 0;
}