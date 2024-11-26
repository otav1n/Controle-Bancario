#include "funcoes.h"

void cadastmovi(TipoLista *L, MoviLista *R){

    reg_conta reg_c;
    reg_movimentos reg_m;
    ContaBancaria p;
    ContaBancaria aux;
    MovimentacaoConta q;

    char dt_data_inv[11];
    char dt_maior[11];
    char dt_maior_inv[11];

    int resp, qtde, x;

    int codigo_conta;

    do{
        tela();
        tela_padrao_mov();
        if(R->Primeiro == NULL){
            reg_m.sequencial = 1;
        }
        else{
            reg_m.sequencial = R->Ultimo->conteudo.sequencial + 1;
        }

        gotoxy(35, 6);
        printf("%d", reg_m.sequencial);

        do{
            // Solicita o código da conta
            gotoxy(33, 7);
            scanf("%d", &codigo_conta);

            // Verifica se o código da conta existe na lista
            aux = L->Primeiro;
            while (aux != NULL) {
                if (aux->conteudo.codigo == codigo_conta) {
                    break;
                }
                aux = aux->proximo;
            }

            // Se a conta não for encontrada, informa o usuário e pede para tentar novamente
            if (aux == NULL) {
                gotoxy(7, 23);
                printf("Conta nao encontrada! Tente novamente.");
                getch();  // Espera o usuário pressionar qualquer tecla para continuar
                gotoxy(7, 23);
                printf("                                          ");
                gotoxy(33, 7);
                printf("  ");
            }

        } while (aux == NULL); // Continua pedindo o código até que uma conta válida seja encontrada


        // Exibe as informações da conta
        gotoxy(33, 8);
        printf("%s", aux->conteudo.banco);

        gotoxy(33, 9);
        printf("%s", aux->conteudo.agencia);

        gotoxy(33, 10);
        printf("%s", aux->conteudo.numero_conta);

        gotoxy(33, 11);
        printf("%s", aux->conteudo.tipo_conta);

        gotoxy(33, 12);
        printf("%.2f", aux->conteudo.vl_saldo);

        gotoxy(33, 13);
        printf("%.2f", aux->conteudo.vl_limite);

        gotoxy(33, 14);
        printf("%.2f", aux->conteudo.vl_saldo + aux->conteudo.vl_limite);

        //cadastra movimentações bancarias
        reg_m.codigo_conta = reg_c.numero_conta;

        gotoxy(7, 23);
        printf("Data da Movimentacao (DD/MM/AAAA): ");
        gotoxy(33, 16);
        fflush(stdin);
        fgets(reg_m.dt_movimentacao, 11, stdin);

        

    }while(resp != 3);

}