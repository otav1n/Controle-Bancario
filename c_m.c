/* Autor......: Matheus Bezerra
   Data.......: 24/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma função para alterar dados de uma movimentação
   Subfunção..: Função para alterar dados de uma movimentação
*/

#include "funcoes.h"

void cadastmovi(TipoLista *L, MoviLista *R){

    reg_conta reg_c; 
    reg_movimentos reg_m;
    ContaBancaria p;
    ContaBancaria aux;
    MovimentacaoConta q;

    int resp, qtde, x, salvar_movimentacao;
    int dia, mes, ano;
    int dia_last, mes_last, ano_last;
    int dt_fleg = 1;

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
    
  // Declaração da variável de controle
int valid_date = 1;

do {
    

    while(dt_fleg == 1){
    gotoxy(33, 16);
    fflush(stdin);
    fgets(reg_m.dt_movimentacao, 50, stdin);

    // Verifica se a data está no formato DD/MM/AAAA
    if (sscanf(reg_m.dt_movimentacao, "%2d/%2d/%4d", &dia, &mes, &ano) == 3 &&
        dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1000 && ano <= 9999) {
        dt_fleg = 1;
        break;
    }

    // Limpa o espaço onde a mensagem de erro aparecerá
    gotoxy(6, 23);
    printf("                                          "); // Limpa a linha
    gotoxy(6, 23);
    printf("Formato ou data invalida. Use DD/MM/AAAA.    ");
    getch();
    gotoxy(33, 16);
    printf("             ");
    gotoxy(6, 23);
    printf("                                              ");

    
    }


    // Verifica o formato e a validade da data inserida
    if (sscanf(reg_m.dt_movimentacao, "%2d/%2d/%4d", &dia, &mes, &ano) == 3 &&
        dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1000 && ano <= 9999) {
        
        // Agora verifica se a data inserida é posterior à última movimentação
        q = R->Primeiro;
        valid_date = 1;  // Assume que a data é válida até que se prove o contrário
        
        while (q != NULL) {
            if (q->conteudo.codigo_conta == reg_m.codigo_conta) {
                // Converte a última data de movimentação
                sscanf(q->conteudo.dt_movimentacao, "%2d/%2d/%4d", &dia_last, &mes_last, &ano_last);

                // Compara a nova data com a última
                if (ano < ano_last || (ano == ano_last && mes < mes_last) || 
                    (ano == ano_last && mes == mes_last && dia < dia_last)) {
                    // Se a data inserida for anterior à última, torna a data inválida
                    valid_date = 0;
                    break;  // Não precisa verificar mais
                }
            }
            q = q->proximo;  // Avança para o próximo nó
        }
    } else {
        valid_date = 0;  // Data inválida por formato incorreto
    }

    // Se a data for inválida, exibe a mensagem de erro
    if (!valid_date) {
        gotoxy(6, 23);  // Posiciona o cursor na linha 23, coluna 6
        printf("A data da movimentacao nao pode ser anterior a ultima movimentacao.");
        gotoxy(33, 16);  // Retorna para o campo de data
        printf("                      ");  // Limpa o campo de data
        getch();  // Aguarda a tecla do usuário para permitir correção
    }
} while (!valid_date);  // Repete enquanto a data for inválida


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

          // Pergunta se deseja salvar a movimentação
        do {
            gotoxy(6, 23);
            printf("Deseja salvar a movimentacao? (1 - Sim / 2 - Nao): ");
            gotoxy(59, 23);
            scanf("%d", &salvar_movimentacao);
            gotoxy(6, 23);
            printf("                                                        ");

            if (salvar_movimentacao == 1) {
                aux->conteudo.tem_movi = 1;
                // Aloca memória para a nova movimentação
                q = (MovimentacaoConta)malloc(sizeof(MoviProx));  // Correção na alocação
                if (q == NULL) {
                    gotoxy(6, 23);
                    printf("Erro ao alocar memoria.");
                    getch();
                    return;
                }

                q->conteudo = reg_m;
                q->anterior = R->Ultimo;
                if (R->Ultimo != NULL) {
                    R->Ultimo->proximo = q;
                }
                R->Ultimo = q;

                if (R->Primeiro == NULL) {
                    R->Primeiro = q;
                }

                gotoxy(7, 23);
                printf("Movimentacao salva com sucesso!");
                getch();
            } else if (salvar_movimentacao == 2) {
                gotoxy(7, 23);
                printf("Movimentacao nao salva.");
                getch();
            } else {
                gotoxy(6, 23);
                printf("Opcao invalida. Tente novamente.");
                getch();
            }
        } while (salvar_movimentacao != 1 && salvar_movimentacao != 2);  // Repete até uma opção válida (1 ou 2)


         gotoxy(6, 23);
        printf("Deseja cadastrar outra movimentacao? (1 - Sim / 2 - Nao): ");
        gotoxy(64, 23);
        scanf("%d", &resp);
        gotoxy(6, 23);

    }while (resp == 1);  // Repete até uma opção válida (1 ou 2)

}