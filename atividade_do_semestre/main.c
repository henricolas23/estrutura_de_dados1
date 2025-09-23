#include <stdio.h>
#include "processo.h"

int main() {
    Processo lista[10000];
    int n = carregar_csv(lista, "TJDFT_amostra.csv"); // troque para TJDFT_filtrado.csv
    printf("Total de processos: %d\n", contar_processos(lista, n));

    // Exemplos de chamadas:
    printf("Processo mais antigo: %s\n", processo_mais_antigo(lista, n));
    printf("Violência Doméstica: %d\n", contar_violencia_domestica(lista, n));
    printf("Feminicídio: %d\n", contar_feminicidio(lista, n));
    printf("Ambiental: %d\n", contar_ambiental(lista, n));
    printf("Quilombolas: %d\n", contar_quilombolas(lista, n));
    printf("Indígenas: %d\n", contar_indigenas(lista, n));
    printf("Infância: %d\n", contar_infancia(lista, n));

    double meta = calcular_meta1(lista, n);
    printf("Cumprimento da Meta 1: %.2f%%\n", meta);

    salvar_julgados_csv(lista, n, "julgados_meta1.csv");

    return 0;
}
