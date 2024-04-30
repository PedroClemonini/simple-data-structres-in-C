#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "info.h"


typedef struct elemento* LIST;

LIST *makeLinkedList(void); // Definição da função de criação da cabeça da LIST, devolve um ponteiro;

void deleteLinkedList(LIST *li); // Usada para percorrer o nós da LIST apagando um a um;

int linkedListSize(LIST *li); // Retorna a quantidade de elementos da LIST;

int emptyLinkedList(LIST *li); // Retorna a condição da LIST caso esteja vazia;

int pushsFirstLL(LIST *li, STU_STRUCT al); // Função utilizada para inserir um elemento no inicio da LIST;

int pushLastLL(LIST *li, STU_STRUCT al); // Função utilizada para inserir um elemento no final da LIST;

int pushOrderedLL(LIST *li, STU_STRUCT al); // Função utilizada para inserir um elemento em qualquer lugar da LIST;

int removeOrderedLL(LIST *li, int mat); // Função utilizada para remover um elemento em qualquer lugar da LIST;

int queryPositionLL(LIST *li, int pos, STU_STRUCT *al); // Função utilizada para procurar um elemento da LIST por sua posição;

int queryDataLL(LIST *li, int mat, STU_STRUCT *al); // Função utilizada para procurar um elemento da LIST por seu conteudo(matricula);

#endif
