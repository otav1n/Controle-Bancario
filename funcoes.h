/*  Autor......: Matheus Bezerra
    Data.......: 23/10/2024
    Equipe.....: 159752-2023 - Otávio Augusto
                 166479-2024 - Matheus Bezerra
    Objetivo...: Função onde fica todas as outras funções e estruturas do codigo
*/

// Para criar a nossa estrutura de dados

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#ifndef FUNCOES_H

#define FUNCOES_H

// Criando nossa estrutura de dados da conta
typedef struct
{

    int codigo;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];

} reg_conta; // estrutura que armazena os dados de uma conta

typedef struct prox *ContaBancaria; // prox estrutura que representa um nó da lista, Conta Bancaria um tipo de ponteiro que aponta para prox

typedef struct prox
{
    reg_conta conteudo;    // Dados da conta
    ContaBancaria proximo; // Ponteiro para o próximo item da lista
} prox;

typedef struct
{
    ContaBancaria Primeiro; // Ponteiro para o primeiro item da lista
    ContaBancaria Ultimo;   // Ponteiro para o último item da lista
} TipoLista;

void gotoxy(int x, int y);

void tela();

void tela_contas();

void consultar_conta(TipoLista *L);

void salvar_Arquivo(TipoLista *L);

void cadastrar_Inicio(TipoLista *L);

void menu_contas();

TipoLista L;

int main();

#endif