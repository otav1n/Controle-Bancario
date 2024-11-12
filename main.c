/*
    Autor: Matheus Bezerra Domingos.
    Data: 23/10/2024
    Objetivo: Menu Principal do controle bancario
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

// Programa Principal
int main()
{

        TipoLista L = {NULL, NULL};

        int opc;
        system("color 5F");

        system("cls"); // limpa tela

        do
        {

                tela();
                gotoxy(33, 06);
                printf("MENU PRINCIPAL");
                gotoxy(29, 10);
                printf("1 - Contas Bancarias");
                gotoxy(29, 12);
                printf("2 - Movimentacao Bancaria");
                gotoxy(29, 14);
                printf("3 - Sair do Programa");
                gotoxy(6, 23);
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:
                        submenu_cadastros();
                        break;
                case 2:
                        break;
                case 3:
                        break;
                default:
                        gotoxy(6, 23);
                        printf("Opcao invalida. Tente novamente.");
                        getch();
                        break;
                }
        } while (opc != 3);

        // Salvar dados antes de encerrar
        salvarArquivo(&L);

        // Liberar memória da lista
        while (L.Primeiro != NULL)
        {
                ContaBancaria temp = L.Primeiro;
                L.Primeiro = L.Primeiro->proximo;
                free(temp);
        }

        return 0;
}