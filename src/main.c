#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "info.h"
#include "linkedlist.h"
#include "doublelinkedlist.h"


int main(void){
    int x;
    // Declaração de variáveis principais no programa
    STACK *pi;
    QUEUE *fi;
    LIST *li;
    D_LIST *dli;

    STU_STRUCT al,al1,al2,al3;

    al1.matricula = 100;
    al1.n[0] = 8.3;
    al1.n[1] = 9.5;
    al1.n[2] = 7.8;

    al2.matricula = 110;
    al2.n[0] = 8.3;
    al2.n[1] = 9.5;
    al2.n[2] = 7.8;

    al3.matricula = 120;
    al3.n[0] = 8.3;
    al3.n[1] = 9.5;
    al3.n[2] = 7.8;

    pi = makeStack();
    fi = makeQueue();
    li = makeLinkedList();
    dli = makeDoubleLL();

    x = pushStack(pi, al1);
    if(x){
        printf("\nAluno inserido na pilha com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno\n");
    }
     x = pushStack(pi, al2);
    if(x){
        printf("\nAluno 2 inserido na pilha com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 2 \n");
    }
     x = pushStack(pi, al3);
    if(x){
        printf("\nAluno 3 inserido na pilha com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 3\n");
    }

    // FILA
     x = pushQueue(fi, al1);
    if(x){
        printf("\nAluno inserido na fila com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno\n");
    }
     x = pushQueue(fi, al2);
    if(x){
        printf("\nAluno 2 inserido na fila com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 2 \n");
    }
     x = pushQueue(fi, al3);
    if(x){
        printf("\nAluno 3 inserido na fila com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 3\n");
    }

    //Lista Ligada

     x = pushOrderedLL(li, al1);
    if(x){
        printf("\nAluno inserido na lista com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno\n");
    }
     x = pushOrderedLL(li, al2);
    if(x){
        printf("\nAluno 2 inserido na lista com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 2 \n");
    }
     x = pushOrderedLL(li, al3);
    if(x){
        printf("\nAluno 3 inserido na lista com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 3\n");
    }
    

    //Lista duplamente ligada

    x = pushOrderedDoubleLL(dli, al1);
    if(x){
        printf("\nAluno inserido na lista dupla com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno\n");
    }
     x = pushOrderedDoubleLL(dli, al2);
    if(x){
        printf("\nAluno 2 inserido na lista dupla com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 2 \n");
    }
     x = pushOrderedDoubleLL(dli, al3);
    if(x){
        printf("\nAluno 3 inserido na lista dupla com sucesso\n");
    }else{
        printf("\nErro ao inserir aluno 3\n");
    }


    
    // if(x){
    //     printf("\nMatricula %d", al.matricula);
    //     printf("\nNota 1: %.2f", al.n[0]);
    //     printf("\nNota 2: %.2f", al.n[1]);
    //     printf("\nNota 3: %.2f", al.n[2]);
    // }else{
    //     printf("\nConsulta nao encontrada!");
    // }

}
