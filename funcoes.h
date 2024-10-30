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

}reg_conta; //registro de contas

typedef struct prox *ContaBancaria; //definição do prox -> ponteiro, para proxima conta

typedef struct prox{ //tipo d. conta
    reg_conta conteudo; //ai só coloco conteudo.oque eu quero
    ContaBancaria proximo; //para o proximo
}prox;

typedef struct{ //tipo lista
    ContaBancaria Primeiro; //primeiro da lista 
    ContaBancaria Ultimo; //ultimo da lista
}TipoLista;

void gotoxy(int x, int y);

void tela();

void submenu_cadastros();

void incluir_contas();

void remover_contas();

void tela_contas();

void cadastro_conta(TipoLista *L);

void consultar_conta(TipoLista *L);

void carregarArquivo(TipoLista *L);

void salvarArquivo(TipoLista *L);

TipoLista L;

int main();

#endif