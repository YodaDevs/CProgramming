#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void swap(int *pa, int *pb);
int is_empty(heap *pq);
void print_heap(heap *pq);

int main(){
    heap *pq = create_heap();

    for(int i = 1; i < 20; i++){
        enqueue(pq,i);
    }
    print_heap(pq);
    return 0;
}

heap* create_heap(){
    heap *pq = (heap*) malloc(sizeof(heap));
	pq->size = 0;
    pq->data[0]= '\0';
	return pq;
}

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

void enqueue(heap *heap, int item){
    
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap overflow");
    } 
    else {
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

int dequeue(heap *heap){
    if (is_empty(heap)) {
        printf("Heap underflow");
        return -1;
    } 
    else {
        int item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        heap->size--;

        max_heapify(heap, 1);

        return item;
    }
}

void max_heapify(heap *heap, int i){

    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index] > heap->data[i]) {
        largest = left_index;
    } 
    else {
        largest = i;
    }
    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest]) {
        largest = right_index;
    }
    if (heap->data[i] != heap->data[largest]) {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }
}

void heapsort(heap *heap){

    int i;

    for (i = heap->size; i >= 2; i--) {
        swap(&heap->data[1], &heap->data[i]);
        heap->size--;
        max_heapify(heap, 1);
    }
}

void swap(int *pa, int *pb){

    int temp = *pa;
    *pa = *pb;
    *pb = temp;

}

int is_empty(heap *pq){
  return (pq == NULL);
}

void print_heap(heap *pq)
{
  int size = pq->size;
  for(int i = 1; i < size; i++){
      printf("[%d] ", pq->data[i]);
  }
  printf("\n");
}
