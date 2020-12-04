#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DEFINICAO DA ESTRUTURA DOS NOS QUE ARMAZENARAO ATLETAS NA LISTA
typedef struct _SLNode_ {
    struct _SLNode_ *next;
    void * data;
} SLNode;

//DEFINICAO DA ESTRUTURA DA LISTA SIMPLESMENTE ENCADEADA
typedef struct _SLLIst_ {
    SLNode *first;
    SLNode *cur;
} SLList;

//CRIA A LISTA E ALOCA O ESPACO NA MEMORIA NECESSARIO
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

//CRIA UM NOVO NO COM UM DADO FORNECIDO E O INSERE NA LISTA, CASO EXISTA
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

//REMOVE UM DETERMINADO NO DA LISTA A PARTIR DE DADOS FORNECIDOS
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

//ENCONTRA NA LISTA OS DADOS DE UM DETERMINADO NO, A PARTIR DE DADOS FORNECIDOS
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

//DESALOCA-SE A LISTA, SE A MESMA ESTIVER VAZIA
int SllDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

//METODO QUE RETORNA O PRIMEIRO ELEMENTO DA LISTA, UTILIZADO NA FUNCAO DE LISTAGEM
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

//METODO QUE RETORNA O PROXIMO ELEMENTO DA LISTA, GERALMENTE UTILIZADO EM CONJUNTO COM A FUNCAO ANTERIOR
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

