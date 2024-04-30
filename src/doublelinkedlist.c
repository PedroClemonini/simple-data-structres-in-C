#include <stdlib.h>
#include <stdio.h>
#include "doublelinkedlist.h"
#include "info.h"

struct elem {
    struct elem* ant;
    struct elem* prox;
    STU_STRUCT dados;
};

typedef struct elem ELEM;


D_LIST *makeDoubleLL(void){
    D_LIST *li = (D_LIST*) malloc(sizeof(D_LIST));

    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void deleteDoubleLL(D_LIST *li){
    if(li != NULL){
        ELEM *node;
        while((*li) != NULL){
            node = *li;
            *li = (*li)->prox;
            free(node);
        }
    }
}

int doubleLLSize(D_LIST *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *node = *li;

    while(node != NULL){
        acum++;
        node = node->prox; 
    }
    return acum;
}

int emptyDoubleLL(D_LIST *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}


int pushFirstDoubleLL(D_LIST *li, STU_STRUCT al){
    if(li == NULL) return 0;
    ELEM *node = (ELEM*) malloc(sizeof(ELEM));

    if(node == NULL) return 0;
    // Passa os dados do STU_STRUCT para o nó
    node->dados = al;
    // Declara o próximo elemento do nó como sendo o antigo primeiro;
    node->prox = *li;
    // Nó anterior recebe nulo
    node->ant = NULL;

    // Caso o primeiro elemento da D_LIST seja diferente de nulo (D_LIST não vazia)
    // O ponteiro anterior do primeiro elemento aponta para o nó
    if(*li != NULL) (*li)->ant = node;

    // O primeiro elemento se torna o nó;
    *li = node;
    return 1;
}

int pushLastDoubleLL(D_LIST *li, STU_STRUCT al){
    if(li == NULL) return 0;
    ELEM *node = (ELEM*) malloc(sizeof(ELEM));
    if(node == NULL) return 0;

    node->dados = al;
    node->prox = NULL;

    if((*li) == NULL) {
        node->ant = NULL;
        *li = node;
    }else{
        ELEM *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = node;
        node->ant = aux;
        
    }
    return 1;

}

int pushOrderedDoubleLL(D_LIST *li, STU_STRUCT al){
    if(li == NULL) return 0;
    ELEM *node = (ELEM*) malloc(sizeof(ELEM));
    if(node == NULL) return 0;

    node->dados = al;
    if(emptyDoubleLL(li)){
        node->prox = NULL;
        node->ant = NULL;
        *li = node;
        return 1;
    }else{
        // criaçao de ponteiros auxiliares para percorrermos a D_LIST
        ELEM *aux_ant, *aux_atual = *li;
        // Enquanto o atual não chegar ao fim e seu dado da matricula for menor do que a matricula desejada
        while(aux_atual != NULL && aux_atual->dados.matricula < al.matricula){
            // Auxiliar anterior recebe o atual
            aux_ant = aux_atual;
            // Auxiliar atual avança na D_LIST
            aux_atual = aux_atual->prox;
        }
        if(aux_atual == *li){ // Caso o atual seja a cabeça da D_LIST

            // O elemento anterior dentro do nó recebe nulo
            node->ant = NULL;
            // O elemento anterior da D_LIST recebe o nó, inserindo atrás do seu maior (lá ele)
            (*li)->ant = node;
            // O próximo elemento no nó recebe o primeiro elemento da D_LIST;
            node->prox = (*li);
            // O primeiro elemento da D_LIST recebe o nó
            *li = node;
        }else { // Caso o elemento atual seja qualquer elemento da D_LIST
            
            node->prox = aux_ant->prox; // o próximo elemento de nó recebe o próximo elemento do auxiliar anterior
            node->ant = aux_ant; // O elemento anterior de nó recebe o valor do auxiliar anterior
            aux_ant->prox = node; // O  próximo elemento doauxiliar anterior recebe o nó
            if(aux_atual != NULL) { // Caso o auxiliar atual seja nulo (fim da D_LIST)
                aux_atual->ant = node; // O elemento anterior do auxiliar atual recebe o nó 
            }
        }
    }
    return 1;


}

int removeDoubleLL(D_LIST *li, int mat){
    if(li == NULL) return 0;

    ELEM  *node = *li;
    while(node != NULL && node->dados.matricula != mat){
        node = node->prox;
    }
    if(node == NULL) return 0;

    if(node == *li){
        *li = node->prox;
    } else {
        node->ant->prox = node->prox;
        if(node->prox == NULL){
            node->prox->ant = node->ant;
        }
    }
    free(node);
    return 1;


}


int queryPositionDoubleLL(D_LIST *li, int pos, STU_STRUCT *al){
    if(li == NULL ) return 0;

    ELEM  *node = *li;
    int i=0;

    while(node!=NULL && pos > i){
        node = node->prox;
        i++;
    }

    if(node == NULL) return 0;

    else {
        *al = node->dados;
        return 1;
    }

    
    
}

int queryDataDoubleLL(D_LIST *li, int mat, STU_STRUCT *al){
    if(li == NULL ) return 0;

    ELEM  *node = *li;

    while(node != NULL && node->dados.matricula != mat){
        node = node->prox;
    }

    if(node == NULL) return 0;

    
    else {
        *al = node->dados;
        return 1;
    }

}
