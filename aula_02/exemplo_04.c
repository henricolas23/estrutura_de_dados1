#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE * fp; // fp é um ponteiro para arquivo 
    fp = fopen("teste.txt","w"); // abre teste.txt
    
    if (fp == NULL){
        printf("erro: arquivo nao foi aberto\n");
        exit(1);
    }

    int i;

        fprintf(fp,"tabuada do 8\n\n");

    for (i = 1; i <= 10; i++){
        fprintf(fp, "8 x %d = %d\n", i , 8 * i);
    }

    printf("arquivo aberto/criado\n");

    fclose(fp);

}