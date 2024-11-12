/*
    Autor: Matheus Bezerra Domingos.
    Data: 23/10/2024
    Objetivo: Arquivo onde ficam todas as nossas funções
*/

// Para criar a nossa estrutura de dados

// typedef....... pensamos nisto dps

#ifndef FUNCOES_H

#define FUNCOES_H

//Criando nossa estrutura de dados da conta
typedef struct{

    int codigo;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];

}reg_conta; //estrutura que armazena os dados de uma conta

typedef struct prox *ContaBancaria; // prox estrutura que representa um nó da lista, Conta Bancaria um tipo de ponteiro que aponta para prox

typedef struct prox{ 
    reg_conta conteudo; // Dados da conta
    ContaBancaria proximo; // Ponteiro para o próximo item da lista
}prox;

typedef struct{ 
    ContaBancaria Primeiro; // Ponteiro para o primeiro item da lista
    ContaBancaria Ultimo; // Ponteiro para o último item da lista
}TipoLista;

void gotoxy(int x, int y);

void tela();

void submenu_cadastros();

void incluir_contas();

void remover_contas();

void tela_contas();

void cadastro_conta(TipoLista *L);

void consultar_conta(TipoLista *L);

void salvarArquivo(TipoLista *L);

void cadastrarInicio(TipoLista *L);

TipoLista L;

int main();

#endif