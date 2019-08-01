#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue queue;

struct queue {
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
};

queue* create_queue(){
    queue *new_queue = (queue*) malloc(sizeof(queue));
    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_QUEUE_SIZE - 1;
    return new_queue;
}

void enqueue(queue *queue, int item){

    if (queue->current_size >= MAX_QUEUE_SIZE){
        printf("Queue overflow");
    } 
    else{
        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int is_empty(queue *queue){
    return (queue->head == NULL);
}

void insertionSort(int V[], int tam)
{    
  int i, j, aux;
 
  for(i = 1; i < tam; i++)
  {
    j = i;
 
    while((j != 0) && (V[j] < V[j - 1])) 
    {
      aux = V[j];
      V[j] = V[j - 1];
      V[j - 1] = aux;
      j--;     
    }
  }
}

void ratio(queue * Fila, int p[], int y){
    
    int r = 0, counter = 0;
	for(int s = y-1; s >= 0; s--){
		if(p[s] == Fila->items[r]) counter++;
		
		r++;
	}
	printf("%d\n", counter);
}

void main () {

    int count, N_notas, numbers, a[MAX_QUEUE_SIZE],j;
	scanf("%d", &count);
	while(count--){
        j = 0;
		scanf("%d",&N_notas);
        queue *FilaRecreio = create_queue();
		while (N_notas--){
			scanf("%d", &numbers);
			a[j] = numbers;
			enqueue(FilaRecreio,numbers);
			j++;	
		}
		insertionSort(a, j);
		ratio(FilaRecreio, a, j);
	}
}