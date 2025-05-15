/* Autor......: Matheus Bezerra
   Data.......: 13/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para Carregar os Arquivos da Conta
   Subfunção..: Função que carrega os dados das contas cadastradas
*/


#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

// Função para carregar contas do arquivo
void carregarContas(TipoLista *L)
{
    reg_conta reg_c;
    FILE *ptr;
    char *arquivo = "folha.dat";
    char *modo_leitura = "rb"; // Modo de leitura binária
   
    ptr = fopen(arquivo, modo_leitura);



   
    // Inicializando a lista
    L->Primeiro = NULL;
    L->Ultimo = NULL;

    // Verificando se o arquivo foi aberto corretamente
    if (ptr == NULL)
    {
        printf("Nenhum arquivo encontrado. Não há contas cadastradas.\n");
        return; // Retorna caso o arquivo não seja encontrado
    }

    // Lendo as contas do arquivo e populando a lista
    while (fread(&reg_c, sizeof(reg_conta), 1, ptr) == 1)
    {
        // Alocando memória para o novo nó
        ContaBancaria p = (ContaBancaria)malloc(sizeof(prox));
        if (p == NULL)
        {
            printf("Erro ao alocar memória para nova conta.\n");
            fclose(ptr);
            return;
        }

        // Atribuindo os dados do registro lido para o nó
        p->conteudo = reg_c;
        p->proximo = NULL;

        // Inserindo o nó na lista
        if (L->Primeiro == NULL)
        {
            // Se a lista estiver vazia, o novo nó será o primeiro e último
            L->Primeiro = p;
            L->Ultimo = p;
        }
        else
        {
            // Se já houver elementos na lista, o novo nó será inserido no final
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }
    }

    // Fechando o arquivo
    fclose(ptr);

    // Mensagem de sucesso
    tela();
    gotoxy(6, 23);
    printf("Contas Bancarias Restauradas com Sucesso!");
    getch();
}
