/* Autor......: Otávio Augusto
   Data.......: 25/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Tela transferencia entre contas
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void telaTransferencia()
{
   system ("cls");
   tela();
   gotoxy(55, 3);
   printf("TRANSFERENCIA DE VALORES");
   gotoxy(2, 7);
   printf("-------C O N T A  O R I G E M---------+-------C O N T A  D E S T I N O--------");
   gotoxy(3, 8);
   printf("Conta de Origem:                     | Conta de Destino: ");
   gotoxy(3, 9);
   printf("Banco..........:                     | Banco...........: ");
   gotoxy(3, 10);
   printf("Agencia........:                     | Agencia.........: ");
   gotoxy(3, 11);
   printf("Numero da Conta:                     | Numero da Conta.: ");
   gotoxy(3, 12);
   printf("Tipo da Conta..:                     | Tipo da Conta...: ");
   gotoxy(3, 13);
   printf("Saldo..........:                     | Saldo...........: ");
   gotoxy(3,14);
   printf("Limite.........:                     | Limite..........: ");
   gotoxy(3, 15);
   printf("Saldo + Limite.:                     | Saldo + Limite..: ");
   gotoxy(3, 16);
   printf("Novo Saldo.....:                     | Novo Saldo......: ");
   gotoxy(2, 17);
   printf("--------------------------------------+--------------------------------------");
   gotoxy(2, 19);
   printf("Valor a Ser transferido.: ");
   gotoxy(2, 20);
   printf("Data da Transferencia...: ");


   getch();
}