#ifndef EQUIPE_H
#define EQUIPE_H

typedef struct {
    int pos;
    char estado[30];
    char esquipe[50];
    int pts;
    int v;
    int e;
    int d;
    int gp;
    int gc;
    int sg;
    int j;
    int gs;
    float aproveitamento;
}time;

time * LerDados(char * arquivo);

int getPontos(equipe * T, int posicao);
float getAproveitamentos() 










#endif