/*  
    Autor: Otávio Augusto Zangelmi Costa
    Data: 23/10/2024
    Objetivo:
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void menu_contas() // Função para switch case do menu de Contas
{

    int msg;

    do
    {
        tela();
        gotoxy(19, 8);
        printf("1 - Cadastrar Contas Bancarias no Final");
        gotoxy(19, 9);
        printf("2 - Cadastrar Contas Bancarias no Inicio");
        gotoxy(19, 10);
        printf("3 - Cadastrar Contas Bancarias na Posicao");
        gotoxy(19, 11);
        printf("4 - Remover Contas Bancarias no Final");
        gotoxy(19, 12);
        printf("5 - Remover Contas Bancarias no Inicio");
        gotoxy(19, 13);
        printf("6 - Remover Contas Bancarias na Posicao");
        gotoxy(19, 14);
        printf("7 - Alteracao de uma Conta Bancaria");
        gotoxy(19, 15);
        printf("8 - Consultar Contas Bancarias");
        gotoxy(19, 16);
        printf("9 - Retornar ao Menu Anterior");
        gotoxy(6, 23);
        scanf("%d", &msg);

        // Switch para Opções
        switch (msg)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        default:
            gotoxy(7, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }

    } while (msg != 9);
}