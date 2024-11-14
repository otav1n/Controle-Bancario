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
    FILE *arq = fopen("folha.dat", "wb"); // Abre o arquivo
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ponteiro auxiliar para percorrer a lista
    ContaBancaria aux = L->Primeiro;

    // Percorre a lista e grava cada nó no arquivo binário
    while (aux != NULL)
    {
        fwrite(&aux->conteudo, sizeof(reg_conta), 1, arq); // Grava os dados da conta
        aux = aux->proximo;                                // Avança para o próximo nó
    }

    fclose(arq); // Fecha o arquivo após gravação
}