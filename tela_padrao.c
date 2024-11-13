/* Autor......: Matheus Bezerra
   Data.......: 23/10/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Tela Padrão do Sistema
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

// Função para posionar o cursor
void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Nossa tela personalizada
void tela()
{

    int lin;
    int col;

    system("cls"); // limpa a tela

    for (lin = 1; lin < 25; lin++)
    {
        gotoxy(01, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }

    for (col = 1; col < 80; col++)
    {

        gotoxy(col, 01);
        printf("-");

        gotoxy(col, 04);
        printf("-");

        gotoxy(col, 22);
        printf("-");

        gotoxy(col, 24);
        printf("-");
    }

    gotoxy(01, 01);
    printf("+");
    gotoxy(79, 01);
    printf("+");

    gotoxy(01, 04);
    printf("+");
    gotoxy(79, 04);
    printf("+");

    gotoxy(01, 22);
    printf("+");
    gotoxy(79, 22);
    printf("+");

    gotoxy(01, 24);
    printf("+");
    gotoxy(79, 24);
    printf("+");

    gotoxy(02, 02);
    printf("UNICV");

    gotoxy(61, 02);
    printf("ESTRUTURA DE DADOS");

    gotoxy(02, 23);
    printf("MSG: ");

    gotoxy(02, 03);
    printf("SISTEMA DE CONTROLE BANCARIO");
}