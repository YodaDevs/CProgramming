#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
  int letter;
  int frenquency;
  int index;
  struct node *next;
  struct node *previous;
}LinkedList;

LinkedList* create_linked_list(){
  return NULL;
}

int is_empty(LinkedList *head){
  return (head->next == NULL);
}

LinkedList* add (LinkedList *head, int letter, int index,int frenquency){
  LinkedList *new_node = (LinkedList*) malloc (sizeof(LinkedList));
  new_node->letter = letter;
  new_node->next = head;
  new_node->previous = NULL;
  new_node->frenquency = frenquency;
  new_node->index = index;
  if(head!=NULL) head->previous = new_node;
  return new_node;
}

void print_doubly_linked_list (LinkedList *head){
  if (!is_empty(head)) {
    print_doubly_linked_list(head -> next);
    printf("%c ", head -> letter);
    printf("%d\n",head->frenquency);
  }
}

//Ordenação com algoritmo Insertion Sort de uma lista duplamente encadeada
void InsertionSort_Linked_List (LinkedList *lst) {
    
    LinkedList *p = lst->next;
    LinkedList *q;
    char x;

    while (p->next != NULL) {
        q = p->previous;
        x = p->letter;

        while ((q != lst) && (q->letter > x)) {
            q->next->letter =  q->letter;
            q = q->previous;
        }

        q->next->letter = x;
        p = p->next;
    }
}

//Funçao que atribuira os valores de Sequencia a um node, ou seja, quantas vezes ele repetiu na lista
int FuncaoSequencia_with_flag(LinkedList *head){
    int i=0;
    char flag = head->letter;
    while(!is_empty(head)){
      i++;
      if(head->next->letter != flag){
        return i;
      }
      head = head->next;
    }
}

//Navegação na lista com implementação de atribuir cada no sua frequencia na lista
void navegacao(LinkedList *head){
  if (!is_empty(head)) {
    head->frenquency = FuncaoSequencia_with_flag(head);
    navegacao(head->next);
  }
}

//Função que removerá um no da lista
LinkedList* Remove_Node(LinkedList *head, int index){

  LinkedList *current = head;

  while (current != NULL && current->index != index){
    current = current->next;
  }
  if (current == NULL) return head;
  
  if (head == current) {
    head = current->next;
  } else {
  current->previous->next = current->next;
  }
  
  if (current->next != NULL) {
  current->next->previous = current->previous;
  current->previous->next = current->next;
  }
  
  free(current);
  return head;
}

//Reformaremos a lista duplamente encadeada para que possua somente os valores corretos de frequencia de cada letter
LinkedList* Create_list_with_max_frequency(LinkedList *head){

    LinkedList* flag_plus = head;
    LinkedList* flag = head;
    head = head->next;
    
    while(!is_empty(head)){ 
      if(flag->letter == head->letter){
        head = Remove_Node(head, head->index);
      }
      else{
        flag = head;
        head = head->next;
      }
    }

    return flag_plus;

}

int main() {
    int i, l=0, j=1;
    
    char c, *str = NULL;
    LinkedList* lista = create_linked_list();
    str = (char *) malloc(10 * sizeof(char) + 1);
    //Lendo todas as letras possíveis de entrada
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

    lista = add(lista,0,-1,1);
    for(i=0; i < strlen(str); i++){
        lista = add(lista,str[i],i,1);
    }
    lista = add(lista,0,-1,1);
    free(str);

    InsertionSort_Linked_List(lista);

    navegacao(lista->next);

    lista->next = Create_list_with_max_frequency(lista->next);
    print_doubly_linked_list(lista->next);
    free(lista);
	return 0;
}
