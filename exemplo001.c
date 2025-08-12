#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição do TAD fração 

typedef struct {
    int Num;
    int Den;
}fracao;

// Protòtipos das frações

int calcularMDC(int A, int B);
simplificarFacao(fracao F);

    fracao criarFracao(int N,int D);
    void exibirFracao(fracao F);

    int main (){
        system("cls");
    
        fracao F1 = criarFracao(24, 30);
        F1 = simplificarFacao(F1);
        exibirFracao(F1); // sera exibido 4/5

        fracao F2 = criarFracao(-30, 40);
        F2 = simplificarFacao(F2);
        exibirFracao(F2); // sera mostrado -3 / 4

         fracao F3 = criarFracao(-30, 40);
        F3 = simplificarFacao(F3);
        exibirFracao(F3); // sera mostrado 37 / 42

        fracao F4 = criarFracao(5, 6);
        fracao F5 = criarFracao(4, 9);
        fracao F6 = somarFracoes(F4, F5);
        exibirFracao(F6);
    
    
    return 0;
    } 

    fracao criarFracao(int N, int D){
        fracao F;
        F.Den = D;
        F.Num = N;
        return F;
    }

    void exibirFracao(fracao F){
        printf("%d /%d",F.Den, F.Num );
    }
    



    fracao simplificarFacao(fracao F){
        int mdc = calcularMDC(F.Num, F.Den);
        F.Num = F.Num / mdc;
        F.Den = F.Den / mdc;
        return F;
    }

    fracao somarFracoes(fracao F, fracao G){
        fracao resposta;
        resposta.Den = F.Den * G.Den;
        resposta.Num = F.Num * G.Den + G.Num * F.Den;
        resposta = simplificarFacao(resposta);
        return resposta;
    }








    
    