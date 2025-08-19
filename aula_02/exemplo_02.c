#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE * fp; // fp é um ponteiro para arquivo 
    fp = fopen("teste.txt","w"); // abre teste.txt
    
    if (fp == NULL){
        printf("erro: arquivo nao foi aberto\n");
        exit(1);
    }

    printf("arquivo aberto/criado\n");

    fclose(fp);

}