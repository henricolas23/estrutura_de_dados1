#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

int main(){
    time * tabela = LerDados("tabela.csv");
    for (int i = 0 ; i < 20; i++)
        printf("%d\t%.2f\t%s\n",
        tabela[i].pos, tabela[i].aproveitamento, tabela[i].esquipe);
}