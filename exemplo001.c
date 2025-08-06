#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição do TAD fração 

typedef struct {
    int numerrador;
    int denominador;
}fracao;

int main (){

    int t = sizeof(fracao);
    printf("tamanho : %d\n", t);
    
}