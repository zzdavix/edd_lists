#include <stdio.h>
#include <stdlib.h>

typedef struct listano ListaNo;
struct listano{
    int info;
    ListaNo* prox;
};

typedef struct lista Lista;
struct lista{
    ListaNo* prim;
};

Lista* lst_cria (void){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

void lst_insere (Lista* l, int v){
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
    novo->info = v;
    novo->prox = l->prim;
    l->prim = novo;
}

void lst_imprime (Lista* l){
    ListaNo* p = l->prim;
    for(p; p!= NULL; p=p->prox){
        printf("info = %d\n", p->info);
    }
}

int pertence (Lista* l, int v){
    ListaNo* p = l->prim;
    for (p; p!=NULL; p=p->prox){
        if (p->info == v){
            return 1;
        }
    }
    return 0;
}

void lst_insere_ordenado (Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;
    while(p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
    novo->info = v;
    if (ant == NULL){
        novo->prox = l->prim;
        l->prim = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

void lst_retira (Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l->prim;
    while (p!=NULL && p->info!=v){
        ant = p;
        p = p->prox;
    }
    if(p!=NULL){
        if(ant == NULL){
            l->prim = p->prox;
        }
        else{
            ant->prox = p->prox;
        }
        free(p);
    }
}

int lst_vazia(Lista* l){
    if(l->prim == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void lst_libera(Lista* l){
    ListaNo* p = l->prim;
    while (p!=NULL){
        ListaNo* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}



int main(){
Lista* l = lst_cria(); 

lst_insere(l, 23);
lst_insere(l, 45);
lst_insere(l, 56);
lst_insere(l, 78);
lst_imprime(l);

lst_retira(l, 78);
lst_imprime(l);

lst_retira(l, 45);
lst_imprime(l);

lst_libera(l);

return 0;

}