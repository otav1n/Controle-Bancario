/* Autor......: Matheus Bezerra
   Data.......: 26/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma função para consultar em ordem alfabetica
   Subfunção..: Função para consultar em ordem alfabetica
*/

#include "funcoes.h"

// Função para ordenar as contas bancárias por ordem alfabética do banco
void ordenar_contas_banco(TipoLista *L) {
    if (L->Primeiro == NULL) return; // Se a lista estiver vazia, não há o que ordenar

    ContaBancaria i, j;
    reg_conta temp;

    // Algoritmo Bubble Sort para ordenar as contas por nome do banco
    for (i = L->Primeiro; i != NULL; i = i->proximo) {
        for (j = i->proximo; j != NULL; j = j->proximo) {
            // Compara os nomes dos bancos usando strcmp
            if (strcmp(i->conteudo.banco, j->conteudo.banco) > 0) {
                // Se o banco de 'i' for lexicograficamente maior que 'j', troca os dados
                temp = i->conteudo;
                i->conteudo = j->conteudo;
                j->conteudo = temp;
            }
        }
    }

    // Exibe as informações de cada conta, agora ordenadas por banco
    ContaBancaria p = L->Primeiro;

    while (p != NULL) {
        system("cls"); // limpa tela
        // Após ordenar as contas, chama novamente a tela de contas para exibir a lista ordenada
        tela();
        tela_contas();  // Chama novamente a tela de contas para exibir as contas ordenadas
        // Exibe as informações da conta para o usuário
        gotoxy(31, 6);  // Ajusta a posição na tela
        printf("%d", p->conteudo.codigo);  // Exibe o código da conta

        gotoxy(30, 8);
        printf(" %s", p->conteudo.banco);  // Exibe o nome do banco

        gotoxy(30, 10);
        printf(" %s", p->conteudo.agencia);  // Exibe o número da agência

        gotoxy(30, 12);
        printf(" %s", p->conteudo.numero_conta);  // Exibe o número da conta

        gotoxy(30, 14);
        printf(" %s", p->conteudo.tipo_conta);  // Exibe o tipo da conta

        gotoxy(31, 16);
        printf("%.2lf", p->conteudo.vl_saldo);  // Exibe o saldo da conta

        gotoxy(31, 18);
        printf("%.2lf", p->conteudo.vl_limite);  // Exibe o limite da conta

        gotoxy(30, 20);
        printf(" %s", p->conteudo.status);  // Exibe o status da conta

        getch();
        p = p->proximo;  // Vai para o próximo nó
    }
}
