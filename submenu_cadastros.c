/*
    Autor: Otávio Augusto Zangelmi Costa
    Data: 23/10/2024
    Objetivo:
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void submenu_cadastros() // função para tela de submenu do cadastro de contas
{

    int msg;

    system("cls"); // limpa tela

    do
    {
        tela();
        gotoxy(35, 06);
        printf("MENU CONTAS");
        gotoxy(31, 10);
        printf("1 - Incluir Conta");
        gotoxy(31, 12);
        printf("2 - Alterar Conta");
        gotoxy(31, 14);
        printf("3 - Consultar Conta");
        gotoxy(31, 16);
        printf("4 - Remover Conta");
        gotoxy(31, 18);
        printf("5 - Voltar");
        gotoxy(6, 23);
        scanf("%d", &msg);

        // Switch para Opções
        switch (msg)
        {
        case 1:
            incluir_contas();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            remover_contas();
            break;
        case 5:
            main();
            break;
        default:
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }

    } while (msg != 5);
}