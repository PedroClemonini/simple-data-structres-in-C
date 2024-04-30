#ifndef STACK_H
#define STACK_H
#include "info.h"

typedef struct elem *STACK;

STACK *makeStack(void);

void deleteStack(STACK *pi);

int stackSize(STACK *pi);

int emptyStack(STACK *pi);

int pushStack(STACK *pi, STU_STRUCT al);

int pullStack(STACK *pi);

int queryStack(STACK *pi, STU_STRUCT *al);


#endif
