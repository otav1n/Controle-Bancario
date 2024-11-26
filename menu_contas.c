/* Autor......: Otávio Augusto
   Data.......: 13/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer a Tela de Menu da Contas
   Subfunção..: Função que mostra a tela de Menu de Contas
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void menu_contas()
{
    int opc, pos;
    system("color 0A");

    system("cls"); // limpa tela

    do
    {

        tela();
        gotoxy(35, 06);
        printf("MENU CONTAS");
        gotoxy(20, 9);
        printf("1 - Cadastrar Contas Bancarias no Inicio");
        gotoxy(20, 10);
        printf("2 - Cadastrar Contas Bancarias no Final");
        gotoxy(20, 11);
        printf("3 - Cadastrar Contas Bancarias em Posicao");
        gotoxy(20, 12);
        printf("4 - Remover Contas Bancarias no Inicio");
        gotoxy(20, 13);
        printf("5 - Remover Contas Bancarias no Final");
        gotoxy(20, 14);
        printf("6 - Remover Contas Bancarias em Posicao");
        gotoxy(20, 15);
        printf("7 - Alteracao de Contas Bancarias");
        gotoxy(20, 16);
        printf("8 - Consultar Contas Bancarias");
        gotoxy(20, 17);
        printf("9 - Retornar ao Menu Anterior");

        gotoxy(6, 23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastrar_Inicio(&L);
            break;
        case 2:
            cadastrar_Final(&L);
            break;
        case 3:
            cadastrar_Posicao(&L);
            break;
        case 4:
            remover_inicio(&L);
            break;
        case 5:
            remover_final(&L);
            break;
        case 6:
            gotoxy(6, 23);
            printf(" ");
            gotoxy(6, 23);
            printf("Digite a posicao: ");
            scanf("%d", &pos);
            remover_posicao(&L, pos);
            break;
        case 7:
            alterar_cadastro(&L);
            break;
        case 8:
            menu_consulta(&L);
            break;
        case 9:
            break;
        default:
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
        }
        salvar_Contas(&L); // Salvar contas no arquivo ao sair
    } while (opc != 9);
}