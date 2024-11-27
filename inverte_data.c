/* Autor......: Matheus Bezerra
   Data.......: 27/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer uma Função para Inverter data
   Subfunção..: Função que Inverter data
*/

#include "funcoes.h"

// Função para inverter a data de "DD/MM/AAAA" para "AAAA-MM-DD"
char* inverte_data(char* data) {
    // Buffer estático para armazenar a data invertida
    static char data_invertida[11];  

    // Usando sscanf para validar o formato "DD/MM/AAAA"
    int dia, mes, ano;
    while (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
        gotoxy(7, 23);
        printf("Formato invalido. Use DD/MM/AAAA.");
        gotoxy(33, 16);
        printf("              ");  // Limpa a linha onde o usuário deve digitar a data
        gotoxy(33, 16);
        fflush(stdin);
        fgets(data, 11, stdin);  // Lê novamente a data do usuário
    }

    // Se a data for válida, formate a data invertida
    sprintf(data_invertida, "%4d-%02d-%02d", ano, mes, dia);

    return data_invertida;  // Retorna o ponteiro para a string invertida
}
