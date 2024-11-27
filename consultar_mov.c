/* Autor......: Otávio Augusto
   Data.......: 27/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Fazer as Perguntas das Contas
   Subfunção..: Função para consultar as movimentações debito e credito
*/

#include "funcoes.h" //Onde esta armazenado nossa estrutura de dados

#include "funcoes.h" // Onde está armazenado nossa estrutura de dados

void consultar_movi(TipoLista *L, MoviLista *R)
{
   int codigo;
   ContaBancaria p;
   MovimentacaoConta mov;
   int resp;
   reg_conta reg_c;
   reg_movimentos reg_m;

   do
   {
      system ("cls");
      tela();
      tela_movi();

      gotoxy(7, 23);
      printf("DIGITE 0 PARA SAIR");

      gotoxy(9, 5);
      scanf("%d", &codigo);

      // Verificação de código "0" para sair
      if (codigo == 0)
      {
         return;
      }

      p = L->Primeiro;

      // percorre a lista até o código digitado
      while (p != NULL && p->conteudo.codigo != codigo)
      {
         p = p->proximo;
      }

      if (p == NULL)
      {
         gotoxy(6, 23);
         printf("Esse codigo de conta nao existe.");
         getch();
      }
      else
      {
         // Exibindo informações da conta
         reg_c.codigo = p->conteudo.codigo;

         gotoxy(12, 5);
         printf("- %s", p->conteudo.banco);

         gotoxy(31, 5);
         printf("Agencia: %s", p->conteudo.agencia);

         gotoxy(48, 5);
         printf("Cta: %s", p->conteudo.numero_conta);

         gotoxy(61, 5);
         printf("Tp: %s", p->conteudo.tipo_conta);

         // Inicia a lista de movimentações dessa conta
         mov = R->Primeiro;                             // Inicializando as movimentações na primeira posição
         int linha = 9;                                 // Começando na linha 9
         mov->conteudo.vl_saldo = p->conteudo.vl_saldo; // atribundo saldo certo

         while (mov != NULL)
         {
            if (mov->conteudo.codigo_conta == codigo) // Verifica se a movimentação corresponde a conta
            {
               gotoxy(2, linha);
               printf("%s", mov->conteudo.dt_movimentacao);

               gotoxy(13, linha);
               printf("%s", mov->conteudo.ds_favorecido);

               gotoxy(43, linha);
               printf("%s", mov->conteudo.tp_movimentacao);

               gotoxy(57, linha);
               printf("%.2f", mov->conteudo.vl_movimentacao);

               gotoxy(69, linha);
               printf("%.2f", mov->conteudo.vl_saldo);

               linha++; // Incrementa a linha para a próxima movimentação

               if (linha >= 21) // Se ultrapassar o limite da tela
               {
                  gotoxy(6, 23);
                  printf("Aperte qualquer tecla para continuar...");
                  getch();
                  linha = 9; // Reinicia a linha após o "pause"
               }
            }
            mov = mov->proximo; // Avança para a próxima movimentação
         }
      }

      gotoxy(6, 23);
      printf("                                                          ");
      gotoxy(6, 23);
      printf("Deseja Procurar outra Movimentacao (1.Sim / 2.Nao): ");
      scanf("%d", &resp);

   } while (resp == 1);
}
