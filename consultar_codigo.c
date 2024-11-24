/* Autor......: Otávio Augusto
   Data.......: 24/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para consultar conta por codigo
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void consultar_codigo(TipoLista *L)
{
    int codigo;
    ContaBancaria p;
    int resp;
    reg_conta reg_c;

    do
    {
        tela();
        tela_contas();
        gotoxy(54, 03);
        printf("CONSULTAR CONTAS CODIGO");

        gotoxy(7, 23);
        printf("DIGITE 0 PARA SAIR");

        gotoxy(31, 6);
        scanf("%d", &codigo);

        // Verificação de código "0" para sair
        if (reg_c.codigo == 0)
        {
            return;
        }

        p = L->Primeiro;

        // percorre a lista até o código digitado
        while (p != NULL && p->conteudo.codigo != codigo)
        {
            p = p->proximo;
        }

        if (p == NULL)
        {
            gotoxy(6, 23);
            printf("Esse codigo de conta nao existe.");
            getch();
        }
        else
        {
            // Exibe as informações da conta para o usuário
            gotoxy(31, 6);
            printf("%d", p->conteudo.codigo);

            gotoxy(30, 8);
            printf(" %s", p->conteudo.banco);

            gotoxy(30, 10);
            printf(" %s", p->conteudo.agencia);

            gotoxy(30, 12);
            printf(" %s", p->conteudo.numero_conta);

            gotoxy(30, 14);
            printf(" %s", p->conteudo.tipo_conta);

            gotoxy(31, 16);
            printf("%.2lf", p->conteudo.vl_saldo);

            gotoxy(31, 18);
            printf("%.2lf", p->conteudo.vl_limite);

            gotoxy(30, 20);
            printf(" %s", p->conteudo.status);
        }

        gotoxy(6, 23);
        printf("                                                          ");
        gotoxy(6, 23);
        printf("Deseja Procurar outra Conta (1.Sim / 2.Nao): ");
        scanf("%d", &resp);

    } while (resp == 1);
}
