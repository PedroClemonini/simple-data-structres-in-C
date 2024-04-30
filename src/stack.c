#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "info.h"

struct elem {
    STU_STRUCT dados;
    struct elem *prox;
};

typedef struct elem ELEM;

STACK *makeStack(void){
    STACK *pi = (STACK*) malloc(sizeof(STACK));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void deleteStack(STACK *pi){
    if(pi != NULL){
        ELEM* node;
        while((*pi) != NULL){
            node = *pi;
            *pi = (*pi)->prox;
            free(node);
        }
        free(pi);
    }
}


int stackSize(STACK *pi){
    if(pi == NULL){
        return 0;
    }
    int acum =0;

    ELEM* node = *pi;
    while(node != NULL){
        acum++;
        node = node->prox;
    }
    return acum;
}

int emptyStack(STACK *pi){
    if(pi == NULL){
        return 1;
    }
    if(*pi == NULL){
        return 1;
    }
    return 0;
}


int pushStack(STACK *pi, STU_STRUCT al){
    if(pi == NULL){
        return 0;
    }
    ELEM *node = (ELEM*) malloc(sizeof(ELEM));
    if(node == NULL){
        return 0;
    }
    node->dados = al;
    node->prox = (*pi);
    *pi = node;
    return 1;
}

int pullStack(STACK *pi){
    if(pi== NULL) return 0;
    if(*pi == NULL) return 0; 

    ELEM *node = *pi;
    *pi = node->prox;
    free(node);
    return 1;
}

int queryStack(STACK *pi, STU_STRUCT *al){
    if(pi== NULL) return 0;
    if(*pi == NULL) return 0;

    *al = (*pi)->dados;
    return 1;

}
