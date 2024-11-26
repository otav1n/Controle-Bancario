/* Autor......: Otávio Augusto
   Data.......: 12/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para salvar as movimentações em disco
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

// Salvar movimentações no arquivo
void salvar_Movimentacoes(MoviLista *R)
{
    FILE *arq = fopen("movimentacoes.dat", "wb"); // Abre o arquivo para gravação binária
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ponteiro auxiliar para percorrer a lista
    MovimentacaoConta aux = R->Primeiro;

    // Percorre a lista e grava cada nó no arquivo binário
    while (aux != NULL)
    {
        fwrite(&aux->conteudo, sizeof(reg_movimentos), 1, arq); // Grava os dados da movimentação
        aux = aux->proximo; // Avança para o próximo nó
    }

    fclose(arq); // Fecha o arquivo após a gravação
}

