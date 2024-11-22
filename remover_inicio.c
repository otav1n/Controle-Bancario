/* Autor......: Matheus Bezerra
   Data.......: 21/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma função para remover conta no inicio
   Subfunção..: Função para remover conta no inicio
*/

#include "funcoes.h"

void remover_inicio(TipoLista *L){

    ContaBancaria atual = L->Primeiro, anterior = NULL;  // Ponteiros para o nó atual e o anterior
    int resp;

     // Verifica se a lista está vazia
    if (L->Primeiro == NULL) {
        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(7, 23);
        printf("Lista vazia.");
        getch();
        return;
    }

    // Exibe as informações da conta para o usuário
    system("cls");
    tela();
    tela_contas();

    gotoxy(32, 6);
    printf("%d", atual->conteudo.codigo);

    gotoxy(31, 8);
    printf(" %s", atual->conteudo.banco);

    gotoxy(31, 10);
    printf(" %s", atual->conteudo.agencia);

    gotoxy(31, 12);
    printf(" %s", atual->conteudo.numero_conta);

    gotoxy(31, 14);
    printf(" %s", atual->conteudo.tipo_conta);

    gotoxy(32, 16);
    printf("%.2lf", atual->conteudo.vl_saldo);

    gotoxy(32, 18);
    printf("%.2lf", atual->conteudo.vl_limite);

    gotoxy(31, 20);
    printf(" %s", atual->conteudo.status);

    gotoxy(7, 23);
    printf("                                             ");
    gotoxy(7, 23);
    printf("Deseja remover esta conta (1.Sim / 2.Nao): ");
    scanf("%d", &resp);

     // Se o usuário deseja remover a conta
    if (resp == 1)
    {
        // Caso a lista tenha mais de um elemento
        atual = L->Primeiro;
        L->Primeiro = atual->proximo;

        // Libera a memória do nó removido
        free(atual);

        system("cls");
        tela();
        gotoxy(7, 23);
        printf("Conta removida com sucesso.");
        getch();
    }
}