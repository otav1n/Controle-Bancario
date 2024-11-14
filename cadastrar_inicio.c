/* Autor......: Otávio Augusto
   Data.......: 12/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para Cadastrar conta no Inicio da Lista
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void cadastrar_Inicio(TipoLista *L)
{

    // declarando variaveis

    reg_conta reg_c; // conteudo das contas
    ContaBancaria p;
    int resp;

    do
    {
        tela();
        tela_contas();

        gotoxy(54, 03);
        printf("INSERINDO CONTA NO INICIO");

        // SCANFS PARA LEITURA DOS DADOS

        gotoxy(31, 6);
        scanf("%d", &reg_c.codigo);
        getchar(); // Limpa o buffer após a leitura da resposta

        gotoxy(31, 8);
        fflush(stdin);
        fgets(reg_c.banco, 50, stdin);

        gotoxy(31, 10);
        fflush(stdin);
        fgets(reg_c.agencia, 10, stdin);

        gotoxy(31, 12);
        fflush(stdin);
        fgets(reg_c.numero_conta, 20, stdin);

        gotoxy(31, 14);
        fflush(stdin);
        fgets(reg_c.tipo_conta, 20, stdin);

        gotoxy(31, 16);
        scanf("%lf", &reg_c.vl_saldo);

        gotoxy(31, 18);
        scanf("%lf", &reg_c.vl_limite);

        gotoxy(31, 20);
        fflush(stdin);
        fgets(reg_c.status, 10, stdin);

        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(6, 23);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao) ");
        scanf("%d", &resp);

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
            p->proximo = L->Primeiro;
            L->Primeiro = p;

            if (L->Ultimo == NULL)
            {
                L->Ultimo = p;
            }

            gotoxy(7, 23);
            printf("                                             ");
            gotoxy(7, 23);
            printf("Cadastrado com sucesso");
        }
        gotoxy(6, 23);
        printf("                                             ");
        gotoxy(6, 23);
        printf("Cadastrar novo funcionario (1.Sim / 2.Nao): ");
        scanf("%d", &resp);
    } while (resp == 1);
}
