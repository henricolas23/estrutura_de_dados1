#define TAREFA_H
#ifdef TAREFA_H

#define TAM_TITULO 96
#define TAM_NOME 48

#define A_FAZER 0 
#define EM_ANDAMENTO


typedef struct {
    char Titulo[TAM_TITULO];
    char Responsavel[TAM_NOME];
    int Status; 
    float Progresso;
    int Avaliacao;
   
}Tarefa;




#endif