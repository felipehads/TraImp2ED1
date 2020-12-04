#ifndef SLL_H
#define SLL_H

#define TRUE 1
#define FALSE 0

typedef struct _SLNode_ SLNode;
typedef struct _SLLIst_ SLList;

SLList *SllCreate();

int SllInsert(SLList *l, void * data);

void * SllRemoveSpec(SLList *l, void * key, int (*cmp)(void*, void*));

void * SllQuery(SLList *l, void *key, int (*cmp)(void*, void*));

void * SllShow(SLList *l);

int SllDestroy(SLList *l);

void * SllGetFirst(SLList * l);

void * SllGetNext(SLList *l);

#endif
