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

        do {
        gotoxy(7, 23); 
        printf("Escolha uma opcao (1-Credito, 2-Debito): ");
        scanf("%d", &resp); 

        if (resp == 1) {

            gotoxy(33, 17);
            printf("1-Credito         ");
            gotoxy(33, 18);
            strcpy(reg_m.tp_movimentacao, "Credito");

        } else if (resp == 2) {

            gotoxy(33, 17);
            printf("2-Debito          ");
            gotoxy(33, 18);
            strcpy(reg_m.tp_movimentacao, "Debito"); 
        } else {
            gotoxy(6, 23);
            printf("                                          ");
            gotoxy(6, 23);
            printf("Formato invalido. Tente novamente.");
        }
        getch();
    } while (resp != 1 && resp != 2); 

    gotoxy(33, 18);
    fflush(stdin);
    fgets(reg_m.ds_favorecido, 50, stdin);


    do{
        gotoxy(33, 19);
        scanf("%lf", &reg_m.vl_movimentacao);

        qtde =  reg_m.vl_movimentacao;

        if(qtde > aux->conteudo.vl_saldo + aux->conteudo.vl_limite) {
            gotoxy(7, 23);
            printf("Valor excede saldo + limite! Por favor, digite outro valor.");
            getch();  // Espera o usuário pressionar qualquer tecla para continuar
            gotoxy(7, 23);
            printf("                                                           ");
            gotoxy(33, 19);
            printf("             ");
        }

    }while (qtde > aux->conteudo.vl_saldo + aux->conteudo.vl_limite); // Repete enquanto o valor for inválido

    // Processa a movimentação dependendo do tipo de movimentação (Crédito ou Débito)
        if (resp == 1) {  // Crédito
            aux->conteudo.vl_saldo += qtde;  // Adiciona o valor (crédito)
            gotoxy(33, 20);
            printf("%.2f", aux->conteudo.vl_saldo);  // Exibe o novo saldo após o crédito
            getch(); // Espera o usuário pressionar qualquer tecla para continuar
        } 
        else if (resp == 2) {  // Débito
            // Verifica se o saldo é suficiente para o débito
            if (aux->conteudo.vl_saldo >= qtde) {
                aux->conteudo.vl_saldo -= qtde;  // Subtrai o valor (débito)
                gotoxy(33, 20);
                printf("%.2f", aux->conteudo.vl_saldo);  // Exibe o novo saldo após o débito
            } else {
                gotoxy(7, 23);
                printf("Saldo insuficiente para essa operacao!");
                getch(); // Espera o usuário pressionar qualquer tecla para continuar
            }
        }
   
    }while(resp != 3);

}