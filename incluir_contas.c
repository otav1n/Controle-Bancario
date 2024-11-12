/*
    Autor: Otávio Augusto Zangelmi Costa
    Data: 24/10/2024
    Objetivo: Menu de Incluir contas
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void incluir_contas()
{

    int msg;

    system("cls"); // limpa tela

    do
    {
        tela();
        gotoxy(35, 06);
        printf("MENU INCLUIR");
        gotoxy(28, 10);
        printf("1 - Inserir conta no Inicio");
        gotoxy(28, 12);
        printf("2 - Inserir conta no Final");
        gotoxy(28, 14);
        printf("3 - Inserir conta em Posicao");
        gotoxy(28, 16);
        printf("4 - Voltar");
        gotoxy(6, 23);
        scanf("%d", &msg);

        switch (msg) // switch para incluir contas
        {
        case 1:
            cadastrarInicio(&L);
            break;
        case 2:
            cadastro_conta(&L);
            break;
        case 3:
            cadastro_conta(&L);
            break;
        case 4:
            submenu_cadastros();
            break;
        default:
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }
    } while (msg != 4);
}

void cadastrarInicio(TipoLista *L)
{

    // declarando variaveis

    reg_conta reg_c; // conteudo das contas
    ContaBancaria p;
    int resp;

    do
    {
        tela();
        tela_contas();

        // SCANFS PARA LEITURA DOS DADOS

        gotoxy(43, 6);
        fflush(stdin);
        fgets(reg_c.banco, 50, stdin);

        gotoxy(43, 8);
        fflush(stdin);
        fgets(reg_c.agencia, 10, stdin);

        gotoxy(43, 10);
        fflush(stdin);
        fgets(reg_c.numero_conta, 20, stdin);

        gotoxy(43, 12);
        fflush(stdin);
        fgets(reg_c.tipo_conta, 20, stdin);

        gotoxy(43, 14);
        scanf("%lf", &reg_c.vl_saldo);

        gotoxy(43, 16);
        scanf("%lf", &reg_c.vl_limite);

        gotoxy(43, 18);
        fflush(stdin);
        fgets(reg_c.status, 10, stdin);

        gotoxy(43, 20);
        scanf("%d", &reg_c.codigo);
        getchar(); // Limpa o buffer após a leitura da resposta

        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(6, 23);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao) ");
        scanf("%d", &resp);

        if (resp == 1) // if se quiser gravar os dados
        {

            p = (ContaBancaria)malloc(sizeof(prox)); // utilizando o comando m-alloc para reserver memoria para o conteudo
            if (p == NULL)
            {
                gotoxy(6, 23);
                printf("                                             ");
                gotoxy(6, 23);
                printf("Erro ao alocar memoria.");
                getch();
                return;
            }

            p->conteudo = reg_c;
            p->proximo = L->Primeiro;
            L->Primeiro = p;

            if (L->Ultimo == NULL)
            {
                L->Ultimo = p;
            }
            gotoxy(7, 23);
            printf("                                             ");
            gotoxy(7, 23);
            printf("Cadastrado com sucesso");

            salvarArquivo(L);
        }
        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(6, 23);
        printf("Cadastrar novo funcionario (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
    } while (resp == 1);
}
