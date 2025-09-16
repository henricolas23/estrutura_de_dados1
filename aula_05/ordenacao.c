#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void TrocarElemento(int * A, int * B);
int particao(int * V, int inf, int Sup);

int main() {


   int vetor [] = {3, 6, 4,  5, 1 ,  7, 2};
   int tamanho = sizeof(vetor)/ sizeof(int);
   particao(vetor, 1, 4);
 

}

void TrocarElemento(int * A, int * B){

    //obs A e B sao ponteiros 

    int temp = *A;
    *A = *B;
    *B = temp;
}

int particao(int * V, int inf, int Sup){
int povi

}
