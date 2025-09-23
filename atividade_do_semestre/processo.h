#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    char id_processo[50];
    char numero_sigilo[50];
    char sigla_grau[5];
    char procedimento[100];
    char ramo_justica[5];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    char id_ultimo_oj[50];
    char dt_recebimento[20];
    char id_ultima_classe[50];
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char decisao[50];
    char dt_resolvido[20];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;

// Funções principais
int carregar_csv(Processo lista[], char *nome_arquivo);
int contar_processos(Processo lista[], int n);
char* buscar_id_ultimo_oj(Processo lista[], int n, char *id_processo);
char* processo_mais_antigo(Processo lista[], int n);
int contar_violencia_domestica(Processo lista[], int n);
int contar_feminicidio(Processo lista[], int n);
int contar_ambiental(Processo lista[], int n);
int contar_quilombolas(Processo lista[], int n);
int contar_indigenas(Processo lista[], int n);
int contar_infancia(Processo lista[], int n);
int dias_entre_datas(char *data1, char *data2);
double calcular_meta1(Processo lista[], int n);
void salvar_julgados_csv(Processo lista[], int n, char *nome_arquivo);

#endif
