/* Autor......: Matheus Bezerra
   Data.......: 22/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma função para a tela padrao movimentacao com os detalhes 
   Subfunção..: Função para a ttela padrao movimentacao com os detalhes 
*/

#include "funcoes.h"

void tela_padrao_mov(){

    gotoxy(8, 6);
    printf("Sequencia Movimentacao.: ");

    gotoxy(8, 7);
    printf("Codigo da Conta........: ");

    gotoxy(8, 8);
    printf("Banco..................: ");

    gotoxy(8, 9);
    printf("Agencia................: ");

    gotoxy(8, 10);
    printf("Numero da Conta........: ");

    gotoxy(8, 11);
    printf("Tipo da Conta..........: ");

    gotoxy(8, 12);
    printf("Saldo..................: ");

    gotoxy(8, 13);
    printf("Limite.................: ");

    gotoxy(8, 14);
    printf("Total Saldo + Limite...: ");

    gotoxy(2, 15);
    printf("-----------------------------------------------------------------------------");

    gotoxy(8, 16);
    printf("1 - Data Movimentacao..: ");

    gotoxy(8, 17);
    printf("2 - Tipo Movimentacao..: ");

    gotoxy(8, 18);
    printf("3 - Favorecido.........: ");

    gotoxy(8, 19);
    printf("4 - Valor Movimentacao..: ");

    gotoxy(8, 20);
    printf("5 - Novo saldo..........: ");
}