#include <stdlib.h>
#include <stdio.h>
#include "info.h"

STU_STRUCT pegaDados(void){
    STU_STRUCT al;
    printf("Digite o numero da sua matricula: ");
    scanf("%d", &al.matricula);
    for(int i = 0; i < 3;i++){
        printf("Digite sua nota %d: ", i+1);
        scanf("%f", &al.n[i]);
    }
    return al;
}

