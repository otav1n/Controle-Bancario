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

void submenu_cadastros() // Função para switch case do menu de Contas
{

    int msg;

    do
    {
        tela();
        gotoxy(19, 8);
        printf("1 - Incluir Conta");
        gotoxy(19, 9);
        printf("2 - Alterar Conta");
        gotoxy(19, 10);
        printf("3 - Consultar Conta");
        gotoxy(19, 11);
        printf("4 - Remover Conta");
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
        default:
            gotoxy(7, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }

    } while (msg != 4);
}