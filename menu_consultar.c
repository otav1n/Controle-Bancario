/* Autor......: Otávio Augusto
   Data.......: 24/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Menu de consulta de contas
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void menu_consulta(TipoLista *L)
{
    system("cls");

    int opc;

    do
    {
        tela();
        gotoxy(32, 06);
        printf("MENU CONSULTA DE CONTAS");
        gotoxy(29, 10);
        printf("1 - Consultar por Codigo");
        gotoxy(29, 12);
        printf("2 - Consultar Geral");
        gotoxy(29, 14);
        printf("3 - Retornar Menu anterior");

        gotoxy(6, 23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            consultar_codigo(L);
            break;
        case 2:
            consultar_conta(L);
            break;
        case 3:
            menu_contas();
        default:
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }
    } while (opc != 3);
}
