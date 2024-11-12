/*
    Autor: Matheus Bezerra Domingos
    Data: 25/10/2024
    Objetivo: Menu para descrição das contas
*/

// Impotando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void tela_contas()
{
        
        /*gotoxy(22, 3);
        printf(" CADASTRO DE CONTAS ");*/

        gotoxy(8, 6);
        printf("1. NOME DO BANCO................: ");

        gotoxy(8, 8);
        printf("2. NUMERO DA AGENCIA............: ");

        gotoxy(8, 10);
        printf("3. NUMERO DA CONTA..............: ");

        gotoxy(8, 12);
        printf("4. TIPO DA CONTA................: ");

        gotoxy(8, 14);
        printf("5. SALDO DA CONTA...............: "); 

        gotoxy(8, 16);
        printf("6. SALDO LIMITE.................: ");

        gotoxy(8, 18);
        printf("7. STATUS DA CONTA..............: ");

        gotoxy(8, 20);
        printf("8. CODIGO DA CONTA..............: ");
}