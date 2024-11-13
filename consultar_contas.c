/* Autor......: Matheus Bezerra
   Data.......: 11/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para Consultar Contas Cadastradas
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void consultar_conta(TipoLista *L)
{

    ContaBancaria p = L->Primeiro;

    while (p != NULL)
    {

        tela();
        tela_contas();

        gotoxy(32, 6);
        printf("%d", p->conteudo.codigo);

        gotoxy(31, 8);
        printf(" %s", p->conteudo.banco);

        gotoxy(31, 10);
        printf(" %s", p->conteudo.agencia);

        gotoxy(31, 12);
        printf(" %s", p->conteudo.numero_conta);

        gotoxy(31, 14);
        printf(" %s", p->conteudo.tipo_conta);

        gotoxy(32, 16);
        printf("%.2lf", p->conteudo.vl_saldo);

        gotoxy(32, 18);
        printf("%.2lf", p->conteudo.vl_limite);

        gotoxy(31, 20);
        printf(" %s", p->conteudo.status);

        gotoxy(7, 23);
        printf("Pressione qualquer tecla para continuar.... ");
        getch();
        p = p->proximo;
    }
}