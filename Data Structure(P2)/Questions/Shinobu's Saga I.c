#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}


STACK* Create_stack(){
    STACK *p = (STACK*)malloc(sizeof(STACK));
    p->head = NULL;
    return p;
}

void PUSH(STACK* stack, int elem){
    NODE *n = (NODE*)malloc(sizeof(NODE));
    n->element = elem;
    n->next = stack->head;
    stack->head = n;
}
int POP(STACK* stack){
    if(IS_EMPTY(stack)) { exit(1); }
    NODE *n = stack->head;
    int elem = n->element;
    stack->head = n->next;
    free(n);
    return elem;
}
int IS_EMPTY(STACK* stack){
    return (stack->head == NULL);
}


//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation){
    int conta=0, number;

    if (operation == '+'){
        number = POP(stack);
        PUSH(stack,(POP(stack) + number));
    }
    else if (operation == '-'){
        number = POP(stack);
        PUSH(stack,(POP(stack) - number));
    }
    else if (operation == '*'){
        number = POP(stack);
        PUSH(stack,(POP(stack) * number));
    }
    else if (operation == '/'){
        number = POP(stack);
        PUSH(stack,(POP(stack) / number));
    }
    else{
        return ;
    }
}

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size){
    int i,aux=0, aux1 = 0, tam;
    char num[5];
    while(size--){
            scanf("%s", num);

            tam = strlen(num);
            for (i = 0; i < tam; i++){
                aux1 = num[i]*pow(10,tam-i);
                aux = aux + aux1;
            }
            
            if(tam > 1) {aux/=10;}
                
            if(aux!=0){
                PUSH(calculadora, aux);
            }
            else{
                result(calculadora,num[0]);
            }
            aux=0;
    }
}
