#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "info.h"

typedef struct elem *D_LIST;

D_LIST *makeDoubleLL(void);

void delesteDoubleLL(D_LIST *li);

int doubleLLSize(D_LIST *li);

int emptyDoubleLL(D_LIST *li);

int pushFirstDoubleLL(D_LIST *li, STU_STRUCT al);

int pushLastDoubleLL(D_LIST *li, STU_STRUCT al);

int pushOrderedDoubleLL(D_LIST *li, STU_STRUCT al);

int removeDoubleLL(D_LIST *li, int mat);

int queryPositionDoubleLL(D_LIST *li, int pos, STU_STRUCT *al); 

int queryDataDoubleLL(D_LIST *li, int mat, STU_STRUCT *al);



#endif

