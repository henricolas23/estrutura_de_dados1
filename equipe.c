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
        
    }
    





    FILE * fp = fopen(arquivo, "r");

    fclose(fp);
    return X;

}
