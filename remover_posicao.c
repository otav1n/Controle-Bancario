/* Autor......: Matheus Bezerra
   Data.......: 22/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma função para remover conta na posicao
   Subfunção..: Função para remover conta na posicao
*/

#include "funcoes.h"
void remover_posicao(TipoLista *L, int pos){
    
    ContaBancaria aux, ant;
    int x, resp;

    // Verifica se a lista está vazia
    if (L->Primeiro == NULL)
    {
        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(7, 23);
        printf("Lista vazia.");
        getch();
        return;
    }
    
       // Verificar se a posição é válida (se existe na lista)
    aux = L->Primeiro;
    for (x = 1; x < pos && aux != NULL; x++) {
        ant = aux;
        aux = aux->proximo;
    }

    // Se não encontrou a posição ou a lista tem menos elementos que o valor de 'pos'
    if (aux == NULL) {
        gotoxy(6, 23);
        printf("                                                         ");
        gotoxy(7, 23);
        printf("Posicao invalida. A lista possui apenas %d elementos.\n", x-1);
        getch();
        return;
    }
    

    if (pos == 1) {
        remover_inicio(L); // Remover o primeiro
    } else {
        aux = L->Primeiro;
        for (x = 1; x < pos; x++) {
            ant = aux;
            aux = aux->proximo;
        }

        // Exibindo os dados da conta na posição 'pos'
        system("cls");
        tela();
        tela_contas();
        gotoxy(54, 03);
        printf("REMOVENDO CONTA DO INICIO");
        
        gotoxy(32, 6);
        printf("%d", aux->conteudo.codigo);

        gotoxy(31, 8);
        printf(" %s", aux->conteudo.banco);

        gotoxy(31, 10);
        printf(" %s", aux->conteudo.agencia);

        gotoxy(31, 12);
        printf(" %s", aux->conteudo.numero_conta);

        gotoxy(31, 14);
        printf(" %s", aux->conteudo.tipo_conta);

        gotoxy(32, 16);
        printf("%.2lf", aux->conteudo.vl_saldo);

        gotoxy(32, 18);
        printf("%.2lf", aux->conteudo.vl_limite);

        gotoxy(31, 20);
        printf(" %s", aux->conteudo.status);

        // Perguntando ao usuário se deseja realmente remover
        gotoxy(7, 23);
        printf("Deseja remover esta conta (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
        gotoxy(7, 23);
        printf("                                            ");

        if (resp == 1) {
            ant->proximo = aux->proximo;

            if (aux == L->Ultimo) {
                L->Ultimo = ant; // Se for o último, atualiza o último
            }

            free(aux);
            gotoxy(7, 23);
            printf("Conta removida com sucesso!\n");
        } else {
            gotoxy(7, 23);
            printf("Remocao cancelada.\n");
        }

        getch();
    }

}