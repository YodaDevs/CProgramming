#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct Linked_List {
    int id;
    struct Linked_List *next;
}linked_list;
 
typedef struct Doubly_Linked_List { 
    int id;
    struct Doubly_Linked_List *next, *prev;
}doubly_linked_list;
 
typedef struct queue{
    doubly_linked_list *head, *tail;
}queue;
 
typedef struct graph {
    linked_list **vertices;
    short *visited;
    int *dist;
    int *ant;
}graph;
 
graph* create_new_graph(int size){
    graph *new_graph = (graph*) malloc(sizeof(graph));
    int i;
    
    new_graph->vertices = (linked_list**) malloc(size * sizeof(linked_list*));
    new_graph->visited = (short*) malloc(size * sizeof(short));
    new_graph->dist = (int*) malloc(size * sizeof(int));
    new_graph->ant = (int*) malloc(size * sizeof(int));
    
    for (i = 0; i < size; i++) {
        new_graph->vertices[i] = NULL;
        new_graph->visited[i] = 0;
        new_graph->dist[i] = -1;
        new_graph->ant[i] = -1;         
    }
    return new_graph;
}
 
void clear_graph(graph *graph1, int size){
    int i; 
    for (i = 0; i < size; i++) {    
        graph1->visited[i] = 0;
        graph1->dist[i] = -1;
        graph1->ant[i] = -1;
    }
}
 
linked_list* create_new_node(int id){
    linked_list *new_node = (linked_list*) malloc(sizeof(linked_list));
    new_node->id = id; 
    new_node->next = NULL;
    return new_node;
} 

queue* create_new_queue(){
    queue *new_queue = (queue*) malloc(sizeof(queue));
    new_queue->head = new_queue->tail = NULL;
    return new_queue;
}

void add_edge_for_graph(graph *graph1, int x, int y){
   
    linked_list *vertice = create_new_node(y);
 
    if(graph1->vertices[x] == NULL || graph1->vertices[x]->id > y){
        vertice->next = graph1->vertices[x];
        graph1->vertices[x] = vertice;
    }else{
        linked_list *aux = graph1->vertices[x];
        
        while(aux->next != NULL && aux->next->id < y){  aux = aux->next;  }

        vertice->next = aux->next;
        aux->next = vertice;
    }
}
 
void enqueue(queue *q, int id){
    doubly_linked_list *new_doubly_list = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));
   
    new_doubly_list->id = id;
   
    if(q->head == NULL){
        new_doubly_list->next = new_doubly_list->prev = NULL;
        q->head = q->tail = new_doubly_list;
    }else{
        new_doubly_list->next = q->tail;
        new_doubly_list->prev = NULL;
        q->tail->prev = new_doubly_list;
        q->tail = new_doubly_list;
    }
}
int empty_queue(queue *q){
    return (q->head)? 0:1;
}
int dequeue(queue *q){
    if(empty_queue(q)) return -1;
 
    int dequeued = q->head->id;
    doubly_linked_list *aux = q->head;
 
    if(q->head == q->tail){
        q->head = q->tail = NULL;
    }else{
        q->head = q->head->prev;
        q->head->next = NULL;
    }
    free(aux);
 
    return dequeued;
}
 
void print_path(graph *graph1, int id){
    if(id != -1){
        if(graph1->ant[id] != -1){
            print_path(graph1, graph1->ant[id]);
            printf(" => %d", id);
        }else{
            printf("%d", id);
        }
    } return;
}
 
void print_previous(graph *graph1, int size, int source, int path){
    int i;
 
    for(i=0; i<size; i++){
        printf("%d |", i);
        if(graph1->dist[i] != -1){
            printf(" %d |", graph1->dist[i]);
        }else{
            printf(" - |");
        }
        if(graph1->ant[i] != -1){
            printf(" %d\n", graph1->ant[i]);
        }else{
            printf(" -\n");
        }
    }
 
    if(graph1->ant[path] != -1){
        printf("\nCaminho entre %d e %d: ", source, path);
        print_path(graph1, path);
    }else{
        printf("\nSem caminho entre %d e %d", source, path);
    }
}
 
void bfs(graph *graph1, int source, int path, int size){
   
    queue *queue_t = create_new_queue();
    int dequeued;
   
    linked_list *adj_list = graph1->vertices[source];
    int i;
   
    graph1->visited[source] = 1;
    graph1->dist[source] = 0;
 
    enqueue(queue_t, source);
   
    while (!empty_queue(queue_t)) {
       
        dequeued = dequeue(queue_t);
        printf("Iniciando busca em largura a partir de %d\n", dequeued);
                       
        adj_list = graph1->vertices[dequeued];
        while (adj_list != NULL) {
           
            if (!graph1->visited[adj_list->id]) {
                graph1->dist[adj_list->id] = graph1->dist[dequeued] + 1;
                graph1->ant[adj_list->id] = dequeued;
                graph1->visited[adj_list->id] = 1;
                enqueue(queue_t, adj_list->id);
            }
   
            adj_list = adj_list->next;
        }
 
    }
    puts("");
    print_previous(graph1,size, source, path);
    printf("\n\n--------");
}
 
int main(){
 
    int v[5], i;
 
    scanf("%d %d %d", &v[0], &v[1], &v[2]);getchar();
 
    graph *graph1 = create_new_graph(v[0]);
    i = 0;
    while( i < v[1]){
        scanf("%d %d", &v[3], &v[4]);getchar();
        add_edge_for_graph(graph1, v[3], v[4]);
        i++;
    }
   
    puts("--------");
    i = 0;
    while(i < v[2]){
        scanf("%d %d", &v[3], &v[4]);getchar();
 
        printf("\nCaso de Teste #%d - BFS(%d)\n\n", i+1, v[3]);
        bfs(graph1, v[3], v[4], v[0]);     
        clear_graph(graph1, v[0]);
        i++;
    }
    return 0;
}