#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define MAX_QUEUE_SIZE 10

// STRUCT OF QUEUE
typedef struct queue {
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
}queue;
// END OF STRUCT OF QUEUE

//STRUCT OF GRAPH
typedef struct adj_list {
    int item;
    struct adj_list *next;
}adj_list;

typedef struct graph {
    adj_list *vertices[MAX_SIZE];
    short visited[MAX_SIZE];
}graph;
//END OF STRUCT OF GRAPH

// CONTRACT GRAPH FUNCTIONS

graph* create_graph();
void add_edge(graph *graph, int vertex1, int vertex2);
void dfs(graph *graph, int source);
void bfs(graph *graph, int source);
void print_graph(graph *graph);

// END OF CONTRACT GRAPH FUNCTIONS

// CONTRACT OF QUEUE FUNCTIONS

queue* create_queue();
void enqueue(queue *queue, int item);
int dequeue(queue *queue);
int is_empty(queue *queue);

// END OF CONTRACT QUEUE FUNCTIONS

//BEGIN OF MAIN
int main(){

    graph *undirected_graph = create_graph();
    add_edge(undirected_graph, 1, 2);
    add_edge(undirected_graph, 1, 5);
    add_edge(undirected_graph, 2, 5);
    add_edge(undirected_graph, 2, 3);
    add_edge(undirected_graph, 2, 4);
    add_edge(undirected_graph, 3, 4);
    add_edge(undirected_graph, 4, 5);
    return 0;
}
//END OF MAIN

// BEGIN OF GRAPH FUNCTIONS
graph* create_graph() {
    graph *gp = (graph*) malloc(sizeof(graph));
    int i;
    for (i = 1; i <= MAX_SIZE - 1; i++) {
        gp->vertices[i] = NULL;
        gp->visited[i] = 0;
    }
    return gp;
}

void add_edge(graph *graph, int vertex1, int vertex2) {
        
    adj_list *vertex = create_adj_list(vertex2);
    vertex->next = graph->vertices[vertex1];
    graph->vertices[vertex1] = vertex;
    //Undirected graph. Edge to the other direction as well.
    vertex = create_adj_list(vertex1);
    vertex->next = graph->vertices[vertex2];
    graph->vertices[vertex2] = vertex;
}

adj_list* create_adj_list(int item) {
        
    adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
    new_adj_list->item = item;
    new_adj_list->next = NULL;
    return new_adj_list;
}

void dfs(graph *graph, int source) {

    graph->visited[source] = 1;
    printf("%d\n", source);
    adj_list *adj_list = graph->vertices[source];

    while (adj_list != NULL) {
        if (!graph->visited[adj_list->item]) {
            dfs(graph, adj_list->item);
        }
        adj_list = adj_list->next;
    }
}

void bfs(graph *graph, int source) {   

        queue *queue = create_queue();
        int dequeued;

        adj_list * adj_list = graph->vertices[source];
        graph->visited[source] = 1;

        enqueue(queue, source);

        while (!is_empty(queue)) {
            dequeued = dequeue(queue);
            adj_list = graph->vertices[dequeued];
            
            while (adj_list != NULL) {
                
                if (!graph->visited[adj_list->item]) {
                    printf("%d\n", adj_list->item);
                    graph->visited[adj_list->item] = 1;
                    enqueue(queue, adj_list->item);
                }

                adj_list = adj_list->next;
            }
    }
}
//END OF GRAPH FUNCTIONS


// BEGIN OF QUEUE FUNCTIONS
queue* create_queue(){

    queue *new_queue = (queue*) malloc(sizeof(queue));
    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_QUEUE_SIZE - 1;
    return new_queue;
}

void enqueue(queue *queue, int item){

    if (queue->current_size >= MAX_QUEUE_SIZE) {
        printf("Queue overflow");
    } else {
        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int dequeue(queue *queue){

    if (is_empty(queue)) {
        printf("Queue underflow");
        return -1;
    } else {
        int dequeued = queue->items[queue->head];
        queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
        queue->current_size--;
        return dequeued;
    }
}
//END OF QUEUE FUNCTIONS 