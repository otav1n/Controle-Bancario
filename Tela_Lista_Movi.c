/* Autor......: Otávio Augusto
   Data.......: 25/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Tela de Consulta Movimentacoes Bancarias
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void ListaMovimentacoes()
{

    system("cls");
    tela();

    gotoxy(2, 5);
    printf("Codigo: ");
    gotoxy(1, 6);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(2, 7);
    printf("Dt.Movim   Favorecido                    TpMovim       Vl.Movim    Saldo");
    gotoxy(2, 8);
    printf("---------- ----------------------------- ------------- ----------- -----------");

    getch();
}