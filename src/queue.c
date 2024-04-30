#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "info.h"

struct QUEUE{
    struct elemento *inicio;
    struct elemento *fim;
};
 
struct elemento{
    STU_STRUCT dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

QUEUE *makeQueue(void){
    QUEUE *fi = (QUEUE*) malloc(sizeof(QUEUE));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void deleteQueue(QUEUE *fi){
    if(fi != NULL){
        ELEM *node;
        while(fi->inicio != NULL){
            node = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(node);
        }
        free(fi);
    }
}

int queueSize(QUEUE *fi){
    if(fi == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *node = fi->inicio;
    while(node != NULL){
        acum++;
        node = node->prox;
    }
    return acum;
}

int emptyQueue(QUEUE *fi){
    if(fi == NULL){
        return 1;
    }
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;

}

int pushQueue(QUEUE *fi, STU_STRUCT al){
    if(fi == NULL){
        return 0;
    }
    ELEM *node = (ELEM*) malloc(sizeof(ELEM));
    if(node == NULL){
        return 0;
    }
    node->dados = al;
    node->prox = NULL;

    if(fi->fim == NULL){
        //Se a QUEUE estiver vazia o inicio recebe o nó
        fi->inicio = node;
    }else{
        // O nó deve ser passado para a o elemento seguinte ao fim da QUEUE
        fi->fim->prox = node;
    }
    //O fim sempre recebe o novo nó
    fi->fim = node;
    return 1;
}

int pullQueue(QUEUE *fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    ELEM *node = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->fim = NULL;
    }
    free(node);
    return 1;
}

int queryQueue(QUEUE *fi, STU_STRUCT *al){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }

    *al = fi->inicio->dados;
    return 1;
}
