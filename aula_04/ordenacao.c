#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int conjunto[] = {1, 9, 7, 8, 5, 2};
    int tamanho = sizeof (conjunto) / sizeof(int);
    insertion_sort(conjunto, tamanho);
    exibir_vetor(conjunto, tamanho);
}


//implementação das funçoes 

void insertion_sort(int *v , int N){
    int chave; 
    int i;
    int j;
    for (i = 1; i < N; i++){
        chave = V[i];
        j = i - 1;

        while (j >= 0 && V[j]) > chave {
            V[j + 1] = V[j];
            j--;
        }
        v[j+ 1] = chave; 
    }
}