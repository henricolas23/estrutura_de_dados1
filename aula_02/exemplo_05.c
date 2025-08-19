#include<stdio.h>
#include<stdlib.h>


int main(){
    FILE * fp; // fp é um ponteiro para arquivo 
    fp = fopen("bd.txt","r"); // r  abre bd.txt
    
    if (fp == NULL){
        printf("erro: arquivo nao foi aberto\n");
        exit(1);
    }

   int conta;
   float saldo;
   char nome[50];

   for(int i = 0; i < 4; i++){


   fscanf(fp, "%d %f %[^\n]\n", &conta, &saldo, nome);
   printf("%d\t%f\t%s\n", conta, saldo, nome);
   }

    printf("arquivo aberto/criado\n");

    fclose(fp);
    return 0;
}