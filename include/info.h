#ifndef INFO_H
#define INFO_H

typedef struct aluno {
    int matricula;
    float n[3];
}STU_STRUCT;


STU_STRUCT pegaDados(void); // Função utilizada internamente para capturar os dados de uma struct aluno;

#endif