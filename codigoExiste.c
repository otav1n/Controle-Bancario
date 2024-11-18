/* Autor......: Matheus Bezerra
   Data.......: 16/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para verificador se o código já existente
   Subfunção..: Função que verifica se o codigo existe
*/


#include "funcoes.h"

//Função verificador do código já existente
int codigoExiste(TipoLista *L, int codigo){
    ContaBancaria p = L->Primeiro;
    while(p !=NULL){
        if(p->conteudo.codigo == codigo){
            return 1; //código já existe
        }
        p = p->proximo;
    }
    return 0; //código não existe
}
