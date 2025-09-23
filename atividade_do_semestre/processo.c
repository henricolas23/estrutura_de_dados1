#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "processo.h"

// ---------- Função para carregar CSV ----------
int carregar_csv(Processo lista[], char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if(!fp) {
        printf("Erro ao abrir arquivo.\n");
        return 0;
    }

    char linha[2048];
    int i = 0;

    fgets(linha, 2048, fp); // ignora cabeçalho

    while(fgets(linha, 2048, fp)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%[^;];%[^;];%[^;];%d;%d;%d;%d;%d;%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d",
            lista[i].id_processo,
            lista[i].numero_sigilo,
            lista[i].sigla_grau,
            lista[i].procedimento,
            lista[i].ramo_justica,
            lista[i].sigla_tribunal,
            &lista[i].id_tribunal,
            &lista[i].recurso,
            lista[i].id_ultimo_oj,
            lista[i].dt_recebimento,
            lista[i].id_ultima_classe,
            &lista[i].flag_violencia_domestica,
            &lista[i].flag_feminicidio,
            &lista[i].flag_ambiental,
            &lista[i].flag_quilombolas,
            &lista[i].flag_indigenas,
            &lista[i].flag_infancia,
            lista[i].decisao,
            lista[i].dt_resolvido,
            &lista[i].cnm1,
            &lista[i].primeirasentm1,
            &lista[i].baixm1,
            &lista[i].decm1,
            &lista[i].mpum1,
            &lista[i].julgadom1,
            &lista[i].desm1,
            &lista[i].susm1
        );
        i++;
    }
    fclose(fp);
    return i; // retorna quantidade de processos carregados
}

// ---------- Funções pedidas ----------
int contar_processos(Processo lista[], int n) {
    return n;
}

char* buscar_id_ultimo_oj(Processo lista[], int n, char *id_processo) {
    for(int i=0; i<n; i++) {
        if(strcmp(lista[i].id_processo, id_processo) == 0) {
            return lista[i].id_ultimo_oj;
        }
    }
    return NULL;
}

char* processo_mais_antigo(Processo lista[], int n) {
    int pos = 0;
    for(int i=1; i<n; i++) {
        if(strcmp(lista[i].dt_recebimento, lista[pos].dt_recebimento) < 0) {
            pos = i;
        }
    }
    return lista[pos].id_processo;
}

int contar_violencia_domestica(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_violencia_domestica) cont++;
    return cont;
}

int contar_feminicidio(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_feminicidio) cont++;
    return cont;
}

int contar_ambiental(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_ambiental) cont++;
    return cont;
}

int contar_quilombolas(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_quilombolas) cont++;
    return cont;
}

int contar_indigenas(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_indigenas) cont++;
    return cont;
}

int contar_infancia(Processo lista[], int n) {
    int cont = 0;
    for(int i=0; i<n; i++) if(lista[i].flag_infancia) cont++;
    return cont;
}

// Função auxiliar para converter string "YYYY-MM-DD" para struct tm
struct tm str_para_data(char *data) {
    struct tm tm_data = {0};
    if(strlen(data) < 10) return tm_data;
    sscanf(data, "%d-%d-%d", &tm_data.tm_year, &tm_data.tm_mon, &tm_data.tm_mday);
    tm_data.tm_year -= 1900;
    tm_data.tm_mon -= 1;
    return tm_data;
}

int dias_entre_datas(char *data1, char *data2) {
    if(strlen(data1) < 10 || strlen(data2) < 10) return -1;
    struct tm tm1 = str_para_data(data1);
    struct tm tm2 = str_para_data(data2);
    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);
    double diff = difftime(t2, t1) / (60*60*24);
    return (int) diff;
}

double calcular_meta1(Processo lista[], int n) {
    int cnm1 = 0, julgadom1 = 0, desm1 = 0, susm1 = 0;
    for(int i=0; i<n; i++) {
        cnm1 += lista[i].cnm1;
        julgadom1 += lista[i].julgadom1;
        desm1 += lista[i].desm1;
        susm1 += lista[i].susm1;
    }
    if(cnm1 + desm1 - susm1 == 0) return 0.0;
    return ((double) julgadom1 / (cnm1 + desm1 - susm1)) * 100.0;
}

void salvar_julgados_csv(Processo lista[], int n, char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if(!fp) {
        printf("Erro ao criar arquivo.\n");
        return;
    }
    fprintf(fp, "id_processo;julgadom1\n");
    for(int i=0; i<n; i++) {
        if(lista[i].julgadom1 > 0) {
            fprintf(fp, "%s;%d\n", lista[i].id_processo, lista[i].julgadom1);
        }
    }
    fclose(fp);
}
