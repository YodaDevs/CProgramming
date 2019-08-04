#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node *next;
}node;

void OrdenacaoSelecao (node *lst) {
    node *pmin;
    node *p = lst->next;
    node *q;
    int aux;

    while(p->next->next != NULL) {
        pmin = p;
        q = p->next;
        while(q->next != NULL){
            if(pmin->item > q->item)
                pmin = q;
            q = q->next;
        }
        aux = p->item;
        p->item = pmin->item;
        pmin->item = aux;
        p = p->next;
    }
}

int main(){
    return 0;
}