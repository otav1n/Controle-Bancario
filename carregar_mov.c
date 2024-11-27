/* Autor......: Matheus Bezerra
   Data.......: 26/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para Carregar as movimentações da Conta
   Subfunção..: Função que carrega as movimentações cadastradas
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void carregarMovimentacoes(MoviLista *R)
{
    reg_movimentos reg_m; 
    FILE *ptr;
    char *arquivo = "movimentacoes.dat"; // Nome do arquivo que armazena as movimentações
    char *modo_leitura = "rb"; // Modo de leitura binária

    ptr = fopen(arquivo, modo_leitura);

    // Inicializando a lista
    R->Primeiro = NULL;
    R->Ultimo = NULL;

    // Verificando se o arquivo foi aberto corretamente
    if (ptr == NULL)
    {
        printf("Nenhum arquivo encontrado. Não há movimentações cadastradas.\n");
        return; // Retorna caso o arquivo não seja encontrado
    }

    // Lendo as movimentações do arquivo e populando a lista
    while (fread(&reg_m, sizeof(reg_movimentos), 1, ptr) == 1)
    {
        // Alocando memória para o novo nó
        MovimentacaoConta q = (MovimentacaoConta)malloc(sizeof(MoviProx)); 
        if (q == NULL)
        {
            printf("Erro ao alocar memória para nova movimentação.\n");
            fclose(ptr);
            return;
        }

        // Atribuindo os dados do registro lido para o nó
        q->conteudo = reg_m;
        q->proximo = NULL;
        q->anterior = NULL;  // Inicializando o ponteiro anterior

        // Inserindo o nó na lista
        if (R->Primeiro == NULL)
        {
            // Se a lista estiver vazia, o novo nó será o primeiro e último
            R->Primeiro = q;
            R->Ultimo = q;
        }
        else
        {
            // Se já houver elementos na lista, o novo nó será inserido no final
            R->Ultimo->proximo = q;  // Ajusta o ponteiro do último nó para o novo nó
            q->anterior = R->Ultimo;  // Ajusta o ponteiro anterior do novo nó para o último nó
            R->Ultimo = q;  // Atualiza o último nó para o novo nó
        }
    }

    // Fechando o arquivo
    fclose(ptr);

    // Mensagem de sucesso
    tela();
    gotoxy(6, 23);
    printf("Movimentacoes Bancarias Restauradas com Sucesso!");
    getch();
}
