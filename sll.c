#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SLNode_ {
    struct _SLNode_ *next;
    void * data;
} SLNode;

typedef struct _SLLIst_ {
    SLNode *first;
    SLNode *cur;
} SLList;

//CRIA UMA LISTA
SLList *SllCreate(){
    SLList *l;
    //� ALOCADO UM SLLIST NA VARI�VEL l
    l = (SLList *)malloc(sizeof(SLList));
    //� CHECADA A ALOCA��O DE l
    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}


int SllInsert(SLList *l, void * data){
    SLNode * newnode;
    if (l != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL){
            newnode->data = data;
            if(l->first == NULL){
                newnode->next = NULL;
            } else {
                newnode->next = l->first;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}


void * SllRemoveSpec(SLList * l, void * key, int(*cmp)(void *, void *)){
    void * data;
    SLNode *spec, *prev;
    if (l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            while (spec->next != NULL && cmp(key,spec->data) != TRUE){
                prev = spec;
                spec = spec->next;
            }
            if (cmp(key,spec->data) == TRUE){
                data = spec->data;
                if(spec == l->first){
                    l->first = spec->next;
                } else {
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void * SllQuery(SLList *l, void * key, int(*cmp)(void *, void *)){
    SLNode * spec;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(spec->next != NULL && cmp(key, spec->data) != TRUE){
                spec = spec->next;
            }
            if(cmp(key, spec->data) == TRUE){
                return spec->data;
            }
        }
    }
    return NULL;
}


int SllDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

void * SllGetFirst(SLList * l){
    SLNode * first = NULL;
    void * data = NULL;

    if (l != NULL){
        if(l->first != NULL){
            first = l->first;
            l->cur = first;
            data = first->data;
            return data;
        }
    }
    return NULL;
}

void * SllGetNext(SLList *l){
    SLNode *next = NULL;
    void * data = NULL;
    if(l != NULL){
        if(l->first != NULL){
            next = l->cur->next;
            if(l->cur->next != NULL){
                data = next->data;
                l->cur = next;
                return data;
            }
        }
    }
    return NULL;
}

