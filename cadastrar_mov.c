/* Autor......: Matheus Bezerra
   Data.......: 25/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer a Tela de cadastro de movimentações
   Subfunção..: Função de cadastro de movimentações
*/


#include "funcoes.h"

void cadastro_mov(TipoLista *L) {
    int codigo_conta;
    reg_movimentos reg_mov;
    ContaBancaria conta;
    double valor_movimentacao;
    int tipo_movimentacao_opcao = 0;  // Variável para armazenar a escolha de Crédito/Débito
    char tempBuffer[20];  // Buffer para ler a entrada do usuário
    int resp, salvar_movimentacao;

    do {
        system("cls"); // Limpa a tela
        tela(); // Exibe a tela padrão
        tela_padrao_mov(); // Exibe a tela para movimentações

        // Loop principal para cadastrar movimentações
        do {
            // Solicita o código da conta
            gotoxy(33, 7);
            scanf("%d", &codigo_conta);

            // Verifica se o código da conta existe na lista
            conta = L->Primeiro;
            while (conta != NULL) {
                if (conta->conteudo.codigo == codigo_conta) {
                    break;
                }
                conta = conta->proximo;
            }

            // Se a conta não for encontrada, informa o usuário e pede para tentar novamente
            if (conta == NULL) {
                gotoxy(7, 23);
                printf("Conta nao encontrada! Tente novamente.");
                getch();  // Espera o usuário pressionar qualquer tecla para continuar
                gotoxy(7, 23);
                printf("                                          ");
                gotoxy(33, 7);
                printf("  ");
            }

        } while (conta == NULL); // Continua pedindo o código até que uma conta válida seja encontrada

        // Exibe as informações da conta
        gotoxy(33, 8);
        printf("%s", conta->conteudo.banco);

        gotoxy(33, 9);
        printf("%s", conta->conteudo.agencia);

        gotoxy(33, 10);
        printf("%s", conta->conteudo.numero_conta);

        gotoxy(33, 11);
        printf("%s", conta->conteudo.tipo_conta);

        gotoxy(33, 12);
        printf("%.2f", conta->conteudo.vl_saldo);

        gotoxy(33, 13);
        printf("%.2f", conta->conteudo.vl_limite);

        gotoxy(33, 14);
        printf("%.2f", conta->conteudo.vl_saldo + conta->conteudo.vl_limite);

        gotoxy(7, 23);
        printf("Data da Movimentacao (DD/MM/AAAA): ");
        gotoxy(33, 16);
        fflush(stdin);
        fgets(reg_mov.dt_movimentacao, 10, stdin);

        // Pergunta se a movimentação será de crédito ou débito
        do {
            gotoxy(6, 23);
            printf("                                                          ");
            gotoxy(6, 23);
            printf("Utilizar: 1=Credito / 2=Debito: ");
            
            fflush(stdin);  // Limpa o buffer antes de usar fgets()
            fgets(tempBuffer, 20, stdin);  // Leitura do tipo de movimentação

            if (tempBuffer[0] == '1') {
                tipo_movimentacao_opcao = 1;  // Crédito
            } else if (tempBuffer[0] == '2') {
                tipo_movimentacao_opcao = 2;  // Débito
            } else {
                tipo_movimentacao_opcao = 0; // Opção inválida
            }

            // Switch case para definir a movimentação
            switch (tipo_movimentacao_opcao) {
                case 1:  // Crédito
                    gotoxy(33, 17);
                    printf("Credito");
                    gotoxy(6, 23);
                    printf("                                                          ");
                    break;
                case 2:  // Débito
                    gotoxy(33, 17);
                    printf("Debito");
                    gotoxy(6, 23);
                    printf("                                                          ");
                    break;
                default:  // Opção inválida
                    gotoxy(6, 23);
                    printf("                                                          ");
                    gotoxy(6, 23);
                    printf("Opcao invalida. Tente novamente.");
                    getch();
                    break;
            }
        } while (tipo_movimentacao_opcao < 1 || tipo_movimentacao_opcao > 2);  // Repete até uma opção válida (somente 1 ou 2)

        gotoxy(33, 18);
        fflush(stdin);
        fgets(reg_mov.ds_favorecido, 50, stdin);
        // Leitura do valor da movimentação
        do {
            gotoxy(33, 19);
            fflush(stdin);  // Limpa o buffer
            fgets(tempBuffer, 20, stdin);  // Leitura do valor da movimentação
            valor_movimentacao = atof(tempBuffer);  // Converte a string para double

            // Verifica se o valor da movimentação não ultrapassa o saldo + limite da conta
            if (valor_movimentacao > conta->conteudo.vl_saldo + conta->conteudo.vl_limite) {
                gotoxy(8, 20);
                printf("Valor excede saldo + limite! Por favor, digite outro valor.");
                getch();  // Espera o usuário pressionar qualquer tecla para continuar
                gotoxy(8, 20);
                printf("                                                    ");
            }

        } while (valor_movimentacao > conta->conteudo.vl_saldo + conta->conteudo.vl_limite); // Repete enquanto o valor for inválido

        // Processa a movimentação dependendo do tipo de movimentação (Crédito ou Débito)
        if (tipo_movimentacao_opcao == 1) {  // Crédito
            conta->conteudo.vl_saldo += valor_movimentacao;  // Adiciona o valor (crédito)
            gotoxy(33, 20);
            printf("%.2f", conta->conteudo.vl_saldo);  // Exibe o novo saldo após o crédito
        } 
        else if (tipo_movimentacao_opcao == 2) {  // Débito
            // Verifica se o saldo é suficiente para o débito
            if (conta->conteudo.vl_saldo >= valor_movimentacao) {
                conta->conteudo.vl_saldo -= valor_movimentacao;  // Subtrai o valor (débito)
                gotoxy(33, 20);
                printf("%.2f", conta->conteudo.vl_saldo);  // Exibe o novo saldo após o débito
            } else {
                gotoxy(7, 23);
                printf("Saldo insuficiente para essa operacao!");
                getch(); // Espera o usuário pressionar qualquer tecla para continuar
            }
        }

        // Pergunta ao usuário se ele deseja salvar a movimentação
        do {
            gotoxy(6, 23);
            printf("Deseja salvar a movimentacao? (1 - Sim / 2 - Nao): ");
            gotoxy(59, 23);
            scanf("%d", &salvar_movimentacao);

            if (salvar_movimentacao == 1) {
                // Aqui você adicionaria a lógica para salvar a movimentação
                // Exemplo: Adicionar a movimentação à lista ou banco de dados
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

        // Pergunta ao usuário se ele deseja cadastrar outra movimentação
        gotoxy(6, 23);
        printf("Deseja cadastrar outra movimentacao? (1 - Sim / 2 - Nao): ");
        gotoxy(59, 23);
        scanf("%d", &resp);
        gotoxy(6, 23);
    } while (resp == 1);  // Continua perguntando se deseja cadastrar outra movimentação
}
