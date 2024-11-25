/* Autor......: Matheus Bezerra
   Data.......: 22/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer a Tela de Menu da Movimentações
   Subfunção..: Função que mostra a tela de Menu de Movimentações
*/

#include "funcoes.h"

void menu_movi()
{
    int opc, pos;
    system("color 0A");

    system("cls"); // limpa tela

    do
    {

        tela();
        gotoxy(30, 06);
        printf("MENU MOVIMENTACOES");
        gotoxy(20, 9);
        printf("1 - Movimentacao de Debito e Credito");
        gotoxy(20, 11);
        printf("2 - Transferencia entre Contas");
        gotoxy(20, 13);
        printf("3 - Consulta Movimentacoes");
        gotoxy(20, 15);
        printf("4 - Retornar ao Menu Anterior");

        gotoxy(6, 23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastro_mov(&L);
            break;
        case 2:
            
            break;
        case 3:
    
            break;
        case 4:
            break;
        default:
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }
        //salvar_Movimentacoes(&L); // Salvar movimentações no arquivo ao sair
    } while (opc != 4);
}