// implementar todas as funçaões do tda e equipe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

time * LerDados(char * arquivo){

    printf("arquivo a ser aberto :%S", arquivo);

time * X = malloc(20 * sizeof(time));    

    
    FILE * fp = fopen(arquivo, "r");
    if (X == NULL){
        printf("erro: memoria insuficiente\n");
        exit(1);
    }

    int i = 0;

    while (fscanf
        (fp, 
        "%d; %[^;]; %[^ ;];%d; %d; %d; %d; %d; %d; %d; %d",
        &X[i].pos, X[i].estado, X[i].esquipe, &X[i].pts, &X[i].j, &X[i].v, &X[i].e, &X[i].d, &X[i].gp, &X[i].gc, &X[i].gs
        )== 11){
        printf("%s\n", X[i].esquipe);
        X[i].aproveitamento = (float) 100 * X[i].pts / (3 * X[i].pts / 3 * X[i].j);
        i++;
    }
    





    FILE * fp = fopen(arquivo, "r");

    fclose(fp);
    return X;



int getAproveitamentos(equipe * T, char * nome){

    int i;

    for(i = 0; i < 20; i++)
        if (strcmp(T[i].nome, nome) == 0)
            return T[i].aproveitamento;


    return ERRO;
}

}
