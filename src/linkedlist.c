#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

struct elemento
{
    STU_STRUCT dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;


LIST *makeLinkedList(void)
{
    LIST *li; // Como essa função devolve um ponteiro do tipo LIST, devemos iniciar criando esse ponteiro;

    li = (LIST*)malloc(sizeof(LIST)); // Alocação de memória da cabeça da LIST
    if (li != NULL)
    { // Se a alocação for bem sucedida, inicie a LIST com NULL
        *li = NULL;
    }
    return li; // Retorna a cabeça da LIST
}

void deleteLinkedList(LIST *li)
{

    if (li != NULL)
    {               // Verifica se a LIST é valida (existe) para prosseguir
        ELEM *node; // Cria um nó auxiliar(node) para percorrer a LIST apagando registros sem que o endereço original li se perca
        while ((*li) != NULL)
        {                      // Enquanto o conteudo do primeiro elemento for diferente de Nulo percorra
            node = *li;        // O primeiro elemento é copiado para node
            *li = (*li)->prox; // O primeiro elemento se torna o próximo
            free(node);        // Agora podemos liberar a memória armazenada para o nó
        }
        free(li); // Ao final da liberação de nós, libera a memória da "cabeça da LIST"
    }
}

int linkedListSize(LIST *li)
{
    if (li == NULL)
    {
        return 0;
    }
    int acum = 0;
    ELEM *node = *li; // O nó recebe o primeiro elemento da LIST

    while(node != NULL){ 
        acum++; 
        node = node->prox; // O endereço de nó se torna o endereço do próximo nó
    }
    return acum;
}

int emptyLinkedList(LIST *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}



int pushsFirstLL(LIST *li, STU_STRUCT al){
    if(li == NULL){
        return 0;
    }
    ELEM *node = (ELEM*) malloc(sizeof(ELEM)); // Aloca memória para um nó
    if(node == NULL){
        return 0;
    }
    
    node->dados = al; // Os dados armazenados em nó recebem novos dados inseridos pelo usuário;
    node->prox = (*li); // O próximo elemento do nó aponta para o início da LIST atual
    *li = node; // O Nó é atribuido ao primeiro elemento da LIST 
    return 1;
}


int pushLastLL(LIST *li, STU_STRUCT al){
     if(li == NULL){
        return 0;
    }
    ELEM *node = (ELEM*) malloc(sizeof(ELEM)); // Aloca memória para um nó
    if(node == NULL){
        return 0;
    }

    
    node->dados = al;
    node->prox = NULL;
    if(emptyLinkedList(li)){ // Se a LIST for vazia insere o elemento no início;
        *li = node;
    } else {
    ELEM *aux = *li;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = node;
    }
    return 1;
}

int pushOrderedLL(LIST *li, STU_STRUCT al) { 

    if(li == NULL){
        return 0;
    }
    ELEM *node = (ELEM*) malloc(sizeof(ELEM)); // Aloca memória para um nó
    if(node == NULL){
        return 0;
    }
    
    node->dados = al;
    if(emptyLinkedList(li)){ // Se a LIST for vazia insere o elemento no início;
        node->prox = NULL;
        *li = node;
    } else {
    ELEM *ant, *atual = *li;

    while(atual != NULL && atual->dados.matricula < node->dados.matricula){
        /* Este loop roda caso elemnto atual for diferente de nulo
        e o número da matrícula de atual for menor que a matrícula da inserção.
        Ou seja, caso a LIST chegue ao fim ou caso uma matricula menor for encontrada. */
        ant = atual;
        atual = atual->prox;
    }

    if(atual == (*li)){ // Caso o elemento atual seja o primeiro da LIST
        node->prox = (*li);
        *li = node;
    } else {
        node->prox = ant->prox;
        ant->prox = node;
    }

    
}
return 1;
}

int removeOrderedLL(LIST *li, int mat){
    if(li == NULL){
        return 0;
    }

    ELEM *ant, *node = *li;

    while(node != NULL && node->dados.matricula != mat){
        ant = node;
        node = node->prox;
    }
    if(node == NULL){
        return 0;
    }
    if(node == *li){
        *li = node->prox;
    }else{
        ant->prox = node->prox;
    }
    free(node);
    return 1;

}

int queryPositionLL(LIST *li, int pos, STU_STRUCT *al){
    if(li == NULL || pos <= 0){
        return 0;
    }
    ELEM *node = *li;
    int i = 1;

    while(node != NULL && i < pos){
        //Percorre a LIST procurando o elemento cuja posição foi solicitada
        node = node->prox;
        i++;
    }
    if(node == NULL){
        //Retorna nulo se a LIST chegou ao fim
        return 0;
    }else{
        //copia os dados do elemnto encontrado no elemento *al;
        *al = node->dados;
        return 1;
    }
}

int queryDataLL(LIST *li, int mat, STU_STRUCT *al){
    if(li == NULL){
        return 0;
    }
    ELEM *node = *li;
    
    while(node !=NULL && node->dados.matricula != mat ){
        node = node->prox;
    }
    if(node == NULL){
        return 0;
    }else{
        *al = node->dados;
        return 1;
    }

}

