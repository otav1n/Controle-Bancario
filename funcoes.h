/*  Autor......: Matheus Bezerra
    Data.......: 23/10/2024
    Equipe.....: 159752-2023 - Otávio Augusto
                 166479-2024 - Matheus Bezerra
    Objetivo...: Fazer a Função onde fica todas as outras funções e estruturas do codigo
    Subfunção..: Onde fica armazenado nossas funções
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

void tela(); // Função que constroi a tela padrão

void tela_contas(); // Função sobre as Perguntas das Contas

void consultar_conta(TipoLista *L); // Função para Consultar Contas Cadastradas

void salvar_Arquivo(TipoLista *L); // Função para salvar as movimentações e contas no disco

void carregarContas(TipoLista *L);

void cadastrar_Inicio(TipoLista *L); // Função para Cadastrar conta no Inicio da Lista

void cadastrar_Final(TipoLista *L); // Função para cadastrar no final da lista

void menu_contas(); // Tela de Menu da Contas

void cadastrar_Posicao(TipoLista *L); // Função para Cadastrar em posição na lista

int codigoExiste(TipoLista *L, int codigo); //Função verificador do código já existente

void remover_final(TipoLista *L); // Função para remover conta no final da lista

void remover_inicio(TipoLista *L);  // Função para remover conta no início da lista

void remover_posicao(TipoLista *L, int pos); // Função para remover em posição

void alterar_cadastro(TipoLista *L); // Função para alterar cadastro

void menu_consulta(TipoLista *L); // Função menu de consulta

TipoLista L;

int main(); // Programa Principal

//------------ MOVIMENTAÇÕES --------------


void menu_movi(); // Tela de Menu da Movimentações

void cadastro_mov(TipoLista *L); // Função para o Cadastro de Movimentações

void tela_padrao_mov(); // Função que constroi a tela padrão das movimentações

#endif