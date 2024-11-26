/* Autor......: Otávio Augusto
   Data.......: 26/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para fazer transferencia entre as contas
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void transferencia_conta(TipoLista *L,  MoviLista *R)
{
    int codigo_origem, codigo_destino;
    ContaBancaria conta_origem;
    ContaBancaria conta_destino;
    float valor_transferido;

    do
    {
        tela();
        telaTransferencia();

        gotoxy(7, 23);
        printf("DIGITE 0 PARA SAIR");

        gotoxy(20, 8);
        scanf("%d", &codigo_origem);

        // Verificação de código "0" para sair
        if (codigo_origem == 0)
        {
            return;
        }

        // Busca a conta de origem
        conta_origem = L->Primeiro;
        while (conta_origem->conteudo.codigo != codigo_origem)
        {
            conta_origem = conta_origem->proximo;
        }

        if (conta_origem == NULL) // verificando se tem uma conta com o codigo
        {
            gotoxy(6, 23);
            printf("Esse codigo de conta nao existe.");
            getch();
            continue;
        }
        else
        {
            // Exibe as informações da conta de origem
            gotoxy(19, 9);
            printf(" %s", conta_origem->conteudo.banco);
            gotoxy(19, 10);
            printf(" %s", conta_origem->conteudo.agencia);
            gotoxy(19, 11);
            printf(" %s", conta_origem->conteudo.numero_conta);
            gotoxy(19, 12);
            printf(" %s", conta_origem->conteudo.tipo_conta);
            gotoxy(20, 13);
            printf("%.2lf", conta_origem->conteudo.vl_saldo);
            gotoxy(20, 14);
            printf("%.2lf", conta_origem->conteudo.vl_limite);
            gotoxy(20, 15);
            printf("%.2f", conta_origem->conteudo.vl_saldo + conta_origem->conteudo.vl_limite);
        }

        // Solicita o código da conta de destino
        gotoxy(60, 8);
        scanf("%d", &codigo_destino);

        // limpa a linha MSG: se o usuario não deseja sair 
        gotoxy (7, 23);
        printf ("                                 ");

        // Busca a conta de destino
        conta_destino = L->Primeiro;
        while (conta_destino->conteudo.codigo != codigo_destino)
        {
            conta_destino = conta_destino->proximo;
        }

        if (conta_destino == NULL) // verificando se tem uma conta com o codigo
        {
            gotoxy(6, 23);
            printf("Esse codigo de conta nao existe.");
            getch();
            continue;
        }
        else
        {
            // Exibe as informações da conta de destino
            gotoxy(59, 9);
            printf(" %s", conta_destino->conteudo.banco);
            gotoxy(59, 10);
            printf(" %s", conta_destino->conteudo.agencia);
            gotoxy(59, 11);
            printf(" %s", conta_destino->conteudo.numero_conta);
            gotoxy(59, 12);
            printf(" %s", conta_destino->conteudo.tipo_conta);
            gotoxy(60, 13);
            printf("%.2lf", conta_destino->conteudo.vl_saldo);
            gotoxy(60, 14);
            printf("%.2lf", conta_destino->conteudo.vl_limite);
            gotoxy(60, 15);
            printf("%.2f", conta_destino->conteudo.vl_saldo + conta_destino->conteudo.vl_limite);
        }

        // Solicita o valor da transferência
        gotoxy(28, 19);
        scanf("%f", &valor_transferido);

        // Verifica se o valor de transferência e valido
        if (valor_transferido <= 0)
        {
            gotoxy(6, 23);
            printf("Valor de transferencia invalido.");
            getch();
            continue;
        }

        // Verifica se a conta de origem tem saldo suficiente
        if (conta_origem->conteudo.vl_saldo + conta_origem->conteudo.vl_limite < valor_transferido)
        {
            gotoxy(6, 23);
            printf("Saldo insuficiente para a transferencia.");
            getch();
            continue;
        }

        // Fazer a tranferencia, da conta origem para a conta destino
        conta_origem->conteudo.vl_saldo -= valor_transferido;
        conta_destino->conteudo.vl_saldo += valor_transferido;

        // exibe a atualização do saldo nas duas contas
        gotoxy(19, 16);
        printf(" %.2f", conta_origem->conteudo.vl_saldo);

        gotoxy(59, 16);
        printf(" %.2f", conta_destino->conteudo.vl_saldo);

        
        // data de tranferencia

        gotoxy (7, 23);
        printf ("Data da Movimentacao (DD/MM/YYYY)");

        getch();

    } while (codigo_origem != 0);
}
