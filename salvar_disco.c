/*
    Autor: Otávio Augusto Zangelmi Costa
    Data: 24/10/2024
    Objetivo: Funcao para salvar no disco
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

// Carregar contas do arquivo
void carregarArquivo(TipoLista *L) {
    FILE *arq = fopen("folha.dat", "rb");
    if (arq == NULL) {
        printf("Nenhum arquivo encontrado. Iniciando sem dados.\n");
        return;
    }

    reg_conta reg_func;
    while (fread(&reg_func, sizeof(reg_conta), 1, arq)) {
        ContaBancaria p = (ContaBancaria)malloc(sizeof(prox));
        if (p == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arq);
            return;
        }
        p->conteudo = reg_func;
        p->proximo = NULL;

        if (L->Primeiro == NULL) {
            L->Primeiro = p;
            L->Ultimo = p;
        } else {
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }
    }

    fclose(arq);
}