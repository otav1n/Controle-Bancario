/*
    Autor: Matheus Bezerra Domingos.
    Data: 25/10/2024
    Objetivo: Menu para cadastrar conta
*/

// Importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void cadastro_conta(TipoLista *L)
{

    reg_conta reg_c;
    ContaBancaria p;
    int resp;

    do
    {
        tela();
        tela_contas();

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

        gotoxy(06, 23);
        printf("                                                           ");
        gotoxy(06, 23);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
        getchar();

        if (resp == 1)
        {
            p = (ContaBancaria)malloc(sizeof(prox));
            if (p == NULL)
            {
                gotoxy(06, 23);
                printf("                                                  ");
                gotoxy(06, 23);
                printf("Erro ao alocar memória. Tente novamente.");
                getch();
                return;
            }

            p->proximo = NULL;
            p->conteudo = reg_c;

            if (L->Primeiro == NULL)
            {
                L->Primeiro = p;
                L->Ultimo = p;
            }
            else
            {
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }

            gotoxy(06, 23);
            printf("                                                      ");
            gotoxy(06, 23);
            printf("Cadastrada com sucesso! Pressione qualquer tecla...");
            getch();

            // Salvar contas no arquivo
            salvarArquivo(L);
        }

        gotoxy(06, 23);
        printf("                                                           ");
        gotoxy(06, 23);
        printf("Cadastrar nova Conta (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
        getchar();

    } while (resp == 1);
}
