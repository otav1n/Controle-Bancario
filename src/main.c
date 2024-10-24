/*
    Autor: Matheus Bezerra Domingos.
    Data: 23/10/2024
    Objetivo: Menu Principal do controle bancario
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

// Programa Principal
int main()
{

        int opc;
        system("color 3F");

        do
        {

                tela();
                gotoxy(35, 06);
                printf("MENU PRINCIPAL");
                gotoxy(31, 10);
                printf("1 - Contas Bancarias");
                gotoxy(31, 12);
                printf("2 - Movimentacao Bancaria");
                gotoxy(31, 14);
                printf("3 - Sair do Programa");
                gotoxy(6, 23);
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:

                        submenu_cadastros();
                        break;
                default:

                        break;
                }
        } while (opc != 3);

        return 0;
}