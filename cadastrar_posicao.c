/* Autor......: Otávio Augusto
   Data.......: 14/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para Cadastrar em posição na lista
   Subfunção..: Função que Cadastrar em posição na lista
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

void cadastrar_Posicao(TipoLista *L)
{
    reg_conta reg_c; // Conteúdo das contas
    ContaBancaria p, r;
    int pos, i;
    int resp;
    int num_elementos = 0;

    // Caso a lista esteja vazia
    if (L->Primeiro == NULL)
    {
        gotoxy(6, 23);
        printf("Lista vazia! Nao e possivel inserir.");
        getch();
        return;
    }

    // Solicita a posição para inserção
    // Solicita a posição para inserção
    while (1)
    {
        system("cls");
        tela(); // Atualiza a tela

        gotoxy(24, 13);
        printf("Informe a posicao para inserir:");
        scanf("%d", &pos);

        // Se o usuário digitar 0
        if (pos == 0)
        {
            gotoxy(6, 23);
            printf("0 nao e uma opcao, utilize os numeros naturais nao nulos.");
            getch();  // Espera o usuário pressionar qualquer tecla para continuar
            continue; // Continua o loop e pede novamente a posicao
        }

        // Verifica o número de elementos da lista
        p = L->Primeiro;
        num_elementos = 0;
        while (p != NULL)
        {
            num_elementos++;
            p = p->proximo;
        }

        // Verifica se a posição é válida
        if (pos > num_elementos + 1)
        {
            gotoxy(6, 23);
            printf("Posicao invalida. Lista tem %d elementos.", num_elementos);
            getch();  // Espera o usuário pressionar qualquer tecla para continuar
            continue; // Continua o loop e pede novamente a posicao
        }
        else
        {
            break; // Se a posição for valida, sai do loop
        }
    }

    system("cls"); // limpa a tela
    tela();        // chama tela de novo
    tela_contas(); // chama a tela de cadastro

   // SCANFS PARA LEITURA DOS DADOS

        gotoxy(31, 6);
        scanf("%d", &reg_c.codigo);
        getchar(); // Limpa o buffer após a leitura da resposta

         //Verificação o código já foi digitado
        while(codigoExiste(L, reg_c.codigo)){
            gotoxy(7,23);
            printf("Codigo ja existe!, Digite um novo codigo: ");
            gotoxy(31,6);
            printf("  ");
            gotoxy(31,6);
            scanf("%d", &reg_c.codigo);
        }

        gotoxy(7,23);
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

    // Se o usuario deseja gravar
    if (resp == 1)
    {
        // Aloca memória para o novo nó
        r = (ContaBancaria)malloc(sizeof(prox));
        if (r == NULL)
        {
            gotoxy(6, 23);
            printf("Erro ao alocar memoria.");
            return;
        }

        r->conteudo = reg_c;
        r->proximo = NULL;

        // Inserção no início da lista
        if (pos == 1)
        {
            r->proximo = L->Primeiro;
            L->Primeiro = r;
            if (L->Ultimo == NULL)
            {
                L->Ultimo = r;
            }
        }
        else // Inserção em qualquer outra posição
        {
            p = L->Primeiro;
            for (i = 1; i < pos - 1; i++)
            {
                p = p->proximo;
            }

            r->proximo = p->proximo;
            p->proximo = r;

            if (r->proximo == NULL)
            {
                L->Ultimo = r;
            }
        }
        system("cls");
        tela();

        gotoxy(6, 23);
        printf("Conta inserida com sucesso.");
        getch();
    }
}