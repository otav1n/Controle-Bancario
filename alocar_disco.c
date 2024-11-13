/* Autor......: Otávio Augusto
   Data.......: 12/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para salvar as movimentações e contas no disco
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

// Salvar contas no arquivo
void salvar_Arquivo(TipoLista *L)
{
    FILE *arq = fopen("folha.dat", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    ContaBancaria aux = L->Primeiro;
    while (aux != NULL)
    {
        fwrite(&aux->conteudo, sizeof(reg_conta), 1, arq);
        aux = aux->proximo;
    }

    fclose(arq);
}