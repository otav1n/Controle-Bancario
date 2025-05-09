/* Autor......: Matheus Bezerra e Otávio Augusto
   Data.......: 23/10/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer o Programa Principal
   Subfunção..: Programa principal
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

// Programa Principal
int main()
{
        carregarContas(&L);
        carregarMovimentacoes(&R);
        TipoLista L = {NULL, NULL};
        MoviLista R = {NULL, NULL};
        int opc;
        system("color 0A");
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
                        menu_contas();
                        break;
                case 2:
                        menu_movi();
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

        // Liberar memória da lista
        while (L.Primeiro != NULL)
        {
                ContaBancaria temp = L.Primeiro;
                L.Primeiro = L.Primeiro->proximo;
                free(temp);
        }

        return 0;
}