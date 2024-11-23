/* Autor......: Otávio Augusto
   Data.......: 13/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para cadastrar no final da lista
   Subfunção..: Função que Cadastrar no final da lista
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void cadastrar_Final(TipoLista *L)
{

    reg_conta reg_c; // conteudo das contas
    ContaBancaria p;
    int resp;
    int tipo_conta_opcao;

    do
    {
        tela();
        tela_contas();

        gotoxy(55, 03);
        printf("INSERINDO CONTA NO FINAL");

        // SCANFS PARA LEITURA DOS DADOS

        gotoxy(31, 6);
        scanf("%d", &reg_c.codigo);
        getchar(); // Limpa o buffer após a leitura da resposta

        // Verificação o código já foi digitado
        while (codigoExiste(L, reg_c.codigo))
        {
            gotoxy(7, 23);
            printf("Codigo ja existe!, Digite um novo codigo: ");
            gotoxy(31, 6);
            printf("  ");
            gotoxy(31, 6);
            scanf("%d", &reg_c.codigo);
        }

        gotoxy(7, 23);
        printf("                                              ");
        gotoxy(31, 8);
        fflush(stdin);
        fgets(reg_c.banco, 50, stdin);

        gotoxy(31, 10);
        fflush(stdin);
        fgets(reg_c.agencia, 10, stdin);

        gotoxy(31, 12);
        fflush(stdin);
        fgets(reg_c.numero_conta, 20, stdin);
        do
        {
            gotoxy(6, 23);
            printf("                                                          ");
            gotoxy(6, 23);
            printf("Utilizar: 1=Corrente / 2=Poupanca / 3=Cartao Credito: ");

            scanf("%d", &tipo_conta_opcao);

            // Switch case para definir o tipo de conta
            switch (tipo_conta_opcao)
            {
            case 1:
                strcpy(reg_c.tipo_conta, "Corrente");
                gotoxy(31, 14);
                printf("1 - Corrente");
                break;
            case 2:
                strcpy(reg_c.tipo_conta, "Poupanca");
                gotoxy(31, 14);
                printf("2 - Poupanca");
                break;
            case 3:
                strcpy(reg_c.tipo_conta, "Cartao Credito");
                gotoxy(31, 14);
                printf("3 - Cartao Credito");
                break;
            default:

                gotoxy(6, 23);
                printf("                                                          ");
                gotoxy(6, 23);
                printf("Opcao invalida. Tente novamente.");
                getch();
                break;
            }
        } while (tipo_conta_opcao < 1 || tipo_conta_opcao > 3);

        gotoxy(31, 16);
        scanf("%lf", &reg_c.vl_saldo);

        gotoxy(31, 18);
        scanf("%lf", &reg_c.vl_limite);

        gotoxy(31, 20);
        fflush(stdin);
        fgets(reg_c.status, 10, stdin);

        gotoxy(6, 23);
        printf("                                                          ");
        gotoxy(6, 23);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao) ");
        scanf("%d", &resp);
        getchar();

        if (resp == 1) // if se quiser gravar os dados
        {

            p = (ContaBancaria)malloc(sizeof(prox)); // utilizando o comando m-alloc para reserver memoria para o conteudo
            if (p == NULL)
            {
                gotoxy(6, 23);
                printf("                                             ");
                gotoxy(6, 23);
                printf("Erro ao alocar memoria.");
                getch();
                return;
            }

            p->conteudo = reg_c;
            p->proximo = NULL;

            if (L->Primeiro == NULL) // Se a lista estiver vazia
            {
                L->Primeiro = p;
                L->Ultimo = p;
            }
            else // se tiver elementos na lista
            {
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }

            gotoxy(6, 23);
            printf("                                                          ");
            gotoxy(6, 23);
            printf("Cadastrado com sucesso ");
            getch();
        }
        gotoxy(6, 23);
        printf("                                                 ");
        gotoxy(6, 23);
        printf("Cadastrar novo funcionario (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
    } while (resp == 1);
}