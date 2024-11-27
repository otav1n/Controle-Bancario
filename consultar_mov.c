/* Autor......: Otávio Augusto
   Data.......: 24/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para consultar movimentações bancárias por código de conta
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void consultar_movimentacoes(MoviLista *R)
{
    int codigo;
    MovimentacaoConta p = R->Primeiro;
    int resp;

    do
    {
        system("cls");
        tela(); // Chama a tela de interface
        tela_movi(); // Chama a tela de movimentações

        gotoxy(45, 03);
        printf("CONSULTAR MOVIMENTACOES POR CODIGO");

        gotoxy(7, 23);
        printf("DIGITE 0 PARA SAIR");

        gotoxy(9, 5);
        scanf("%d", &codigo);

        // Verificação de código "0" para sair
        if (codigo == 0)
        {
            return;
        }

        int found = 0;

        // Percorre a lista de movimentações para o código informado
        while (p != NULL)
        {
            // Verifica se o código da conta é o que estamos procurando
            if (p->conteudo.codigo_conta == codigo)
            {
                // Exibe a movimentação
                gotoxy(2, 9 + found);
                printf("%-10s %-30s %-15s %-11.2f %-11.2f",
                       p->conteudo.dt_movimentacao,
                       p->conteudo.ds_favorecido,
                       p->conteudo.tp_movimentacao,
                       p->conteudo.vl_movimentacao,
                       p->conteudo.vl_saldo);

                found++;
            }
            p = p->proximo;
        }

        // Se não encontrar movimentações para o código informado
        if (!found)
        {
            gotoxy(6, 10);
            printf("Nao ha movimentacoes para esse codigo de conta.");
        }

        // Pergunta se o usuário deseja procurar por outro código
        gotoxy(6, 23);
        printf("                                                          ");
        gotoxy(6, 23);
        printf("Deseja Procurar movimentacoes de outro codigo(1.Sim / 2.Nao): ");
        scanf("%d", &resp);

    } while (resp == 1);
}
