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
            break;
        case 2:
            break;
        case 3:
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