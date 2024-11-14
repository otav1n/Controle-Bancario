/* Autor......: Otávio Augusto
   Data.......: 13/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função sobre as Perguntas das Contas
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void tela_contas()
{

    gotoxy(14, 6);
    printf("Codigo da Conta: ");

    gotoxy(9, 8);
    printf("1 - Nome do Banco...: ");

    gotoxy(9, 10);
    printf("2 - Agencia.........: ");

    gotoxy(9, 12);
    printf("3 - Numero da Conta.: ");

    gotoxy(9, 14);
    printf("4 - Tipo da Conta...: ");

    gotoxy(9, 16);
    printf("5 - Saldo da Conta..: ");

    gotoxy(9, 18);
    printf("6 - Limite..........: ");

    gotoxy(9, 20);
    printf("8 - Status Conta....: ");
}