#include <stdio.h>
#include <stdlib.h>

// 1)
typedef struct listano ListaNo;
struct listano{
    int info;
    ListaNo* prox;
};

typedef struct lista Lista;
struct lista{
    ListaNo* prim;
};

void retira_n (Lista* l, int v){
    if (l == NULL){
        printf("Lista vazia");
        return;
    }
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;

    while(p!=NULL && p->info!=v){
        ant = p;
        p = p->prox;
    } 
    if (p!=NULL){
        if (ant == NULL){
            l->prim = p->prox;
        }
        else{
            ant->prox = p->prox;
        }
        free(p);
    }
}

// 2)
void para_circular (Lista* l){
    if (l->prim == NULL){
        printf("Lista vazia");
        return;
    }
    else{
        ListaNo* p = l->prim;
        while (p!=NULL){
            p=p->prox;
        }
        p->prox = l->prim;
    }
}

// 3)
typedef struct listano2 ListaNo2;
struct listano2{
    int info;
    ListaNo2* prox;
    ListaNo2* ant;
};

typedef struct lista2 Lista2;
struct lista2{
    ListaNo2* prim;
    ListaNo2* ult;
};

void retira_ini (Lista2* l){
    if (l->prim == NULL){
        printf("Lista vazia");
        return;
    }
    else{
        ListaNo2* temp = l->prim;
        l->prim = l->prim->prox;
        if (l->prim != NULL){
            l->prim->ant = NULL;
        }
        else{
            l->ult = NULL;
        }
        free(temp);
    }
}

void retira_fim (Lista2* l){
    if (l->ult == NULL){
        printf("Lista vazia");
        return;
    }
    else{
        ListaNo2* temp = l->ult;
        l->ult = l->ult->ant;
        if(l->ult != NULL){
            l->ult->prox = NULL;
        }
        else{
            l->prim = NULL;
        }
        free(temp);
    }
}

// 4) 
// As funções de fila são responsáveis por operações básicas de manipulação de uma fila, que é uma estrutura de dados do tipo FIFO (First In, First Out), ou seja, o primeiro elemento inserido na fila é o primeiro a ser removido.
// As principais funções de fila incluem:
// enqueue(): Esta função é usada para adicionar um elemento ao final da fila.
// dequeue(): Esta função é usada para remover e retornar o elemento no início da fila.
// isEmpty(): Verifica se a fila está vazia.
// isFull(): Verifica se a fila está cheia. (Geralmente não é necessária em implementações com listas encadeadas, mas é útil em implementações com arrays estáticos).
// peek(): Retorna o elemento no início da fila sem removê-lo.
// Para implementar uma fila com uma lista encadeada em C, você precisa criar uma estrutura para representar um nó da lista, que conterá o dado a ser armazenado e um ponteiro para o próximo nó na fila. A fila em si também precisará armazenar ponteiros para o primeiro e último nós da lista.
// Ao adicionar um elemento à fila, você cria um novo nó com o dado fornecido e o insere no final da lista encadeada, atualizando os ponteiros conforme necessário.
// Para remover um elemento da fila, você remove o nó no início da lista encadeada e atualiza o ponteiro para o primeiro nó.

// 5)
// a) 
// As funções de pilha são responsáveis por operações básicas de manipulação de uma pilha, que é uma estrutura de dados do tipo LIFO (Last In, First Out), ou seja, o último elemento inserido na pilha é o primeiro a ser removido.
// As principais funções de pilha incluem:
// push(): Adiciona um novo elemento no topo da pilha.
// pop(): Remove e retorna o elemento no topo da pilha.
// isEmpty(): Verifica se a pilha está vazia.
// isFull(): Verifica se a pilha está cheia. (Geralmente não é necessária em implementações com listas encadeadas, mas é útil em implementações com arrays estáticos).
// peek(): Retorna o elemento no topo da pilha sem removê-lo.

// b)
#ifndef STACK_H
#define STACK_H

typedef struct stack_element{

    int data;
   Node* next;
   
} StackElement;


typedef struct {
    StackElement* elements; 
    int capacity;           
    int size;               
    int top;                
} Stack;

Stack* createStack(int capacity);
void destroyStack(Stack* stack);
int push(Stack* stack, StackElement element);
StackElement pop(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
StackElement peek(Stack* stack);

#endif /* STACK_H */

b) Bool esta_balanceada(char[]* c, int tam){
    char analise;
    pilha* p = cria_pilha();
    for(int i = 0; i<tam; i++){
        analise = strcpy(c[i]);
        if(analise == "[" || analise == "{" || analise == "["){
            push_pilha(p, analise);
        }else{
            if(analise "]" && topo(p) == "["){
                pop_pilha(p);
            }else if(analise "}" && topo(p)== "{"){
                pop_pilha(p);
            }else if (analise ")" && topo(p)== "("){
                pop_pilha(p);
            }
        }

    }
    return pilha_vazia(p);
}