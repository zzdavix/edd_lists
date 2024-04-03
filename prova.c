#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _simple_node{
    int val;
    struct _simple_node *next;
} SNode;

typedef struct _linked_list{
    SNode *begin;
    SNode *end;
    size_t size;
} LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void LinkedList_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val);
    p->next = L->begin;

    if (L->begin == NULL && L->end == NULL){
        
        L->end = p;
    }
        L->begin = p;
        L->size++;
}

void LinkedList_add_last(LinkedList *L, int val){
    SNode *p = SNode_create(val);

    if (L->begin == NULL && L->end == NULL){
        L->begin = p;
        L->end = p;
    }
    else {
        L->end->next = p;
        L->end = L->end->next;

    }
    L->size++;
}

void LinkedList_print (const LinkedList *L){
    SNode *p = L->begin;
    printf("L -> ");

    while (p != NULL){
        printf ("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL");
}

void LinkedList_remove_v1 (LinkedList *L, int val){
    if (L->begin != NULL){
        if (L->begin->val == val){
            SNode *pos = L->begin;

            if (L->begin == L->end){
                L->begin = NULL;
                L->end = NULL;
                free(pos);
                L->size--;
            }
            else{
                L->begin = L->begin->next;
                free(pos);
                L->size--;
            }
        
        SNode *prev = L->begin;
        SNode *pos = L->begin->next;

        while (pos != NULL && pos->val != val){
            prev = prev->next;
            pos = pos->next;
        }

        if (pos != NULL){
            prev->next = pos->next;

            if (pos->next == NULL){
                L->end = prev;
            }

            free(pos);
            L->size--;
        }
        }
    }

}

void LinkedList_remove(LinkedList *L, int val){
    if (L->begin != NULL){
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while(pos != NULL && pos->val != val){
            prev = pos;
            pos = pos->next;
        }

        if (pos != NULL){
            if(L->end == pos){
                L->end = prev;
            }
            if(L->begin == pos){
                L->begin = pos->next;
            }
            else{
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
            }
        }
    }
