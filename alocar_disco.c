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

// Salvar contas no arquivo
void salvarArquivo(TipoLista *L) {
    FILE *arq = fopen("folha.dat", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    ContaBancaria aux = L->Primeiro;
    while (aux != NULL) {
        fwrite(&aux->conteudo, sizeof(reg_conta), 1, arq);
        aux = aux->proximo;
    }

    fclose(arq);
}