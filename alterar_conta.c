/* Autor......: Otávio Augusto
   Data.......: 24/11/2024
   Equipe.....: 159752-2023 - Otávio Augusto
                166479-2024 - Matheus Bezerra
   Objetivo...: Função para alterar dados de uma conta
*/

#include "funcoes.h" // Onde está armazenada nossa estrutura de dados

void alterar_cadastro(TipoLista *L)
{
   int codigo;
   ContaBancaria p;
   int msg;
   int campo_alterar;
   int tipo_conta_opcao;
   reg_conta reg_c;

   tela();
   tela_contas();
   gotoxy(48, 03);
   printf("ALTERAR CADASTRO DE FUNCIONARIO");

   gotoxy(7, 23);
   printf("DIGITE 0 PARA SAIR");

   gotoxy(31, 6);
   scanf("%d", &codigo);

   // Verificação de código "0" para sair
   if (reg_c.codigo == 0)
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
      printf("                                                     ");
      gotoxy(6, 23);
      printf("Esse codigo de conta nao existe.");
      getch();
      return;
   }

   // Exibe as informações da conta para o usuário
   gotoxy(31, 6);
   printf("%d", p->conteudo.codigo);

   gotoxy(30, 8);
   printf(" %s", p->conteudo.banco);

   gotoxy(30, 10);
   printf(" %s", p->conteudo.agencia);

   gotoxy(30, 12);
   printf(" %s", p->conteudo.numero_conta);

   gotoxy(30, 14);
   printf(" %s", p->conteudo.tipo_conta);

   gotoxy(31, 16);
   printf("%.2lf", p->conteudo.vl_saldo);

   gotoxy(31, 18);
   printf("%.2lf", p->conteudo.vl_limite);

   gotoxy(30, 20);
   printf(" %s", p->conteudo.status);

   // Pergunta qual campo o usuário deseja alterar
   do
   {
      gotoxy(6, 23);
      printf("                                                     ");
      gotoxy(6, 23);
      printf("Digite a opcao desejada (1-7) DIGITE 0 PARA SAIR: ");
      scanf("%d", &campo_alterar);

      // Verificação de código "0" para sair
      if (campo_alterar == 0)
      {
         return;
      }

      switch (campo_alterar)
      {
      case 1:
         gotoxy(30, 8);
         printf("                                        ");
         gotoxy(31, 8);
         fflush(stdin);
         fgets(p->conteudo.banco, sizeof(p->conteudo.banco), stdin);
         break;
      case 2:
         gotoxy(30, 10);
         printf("                                        ");
         gotoxy(31, 10);
         fflush(stdin);
         fgets(p->conteudo.agencia, sizeof(p->conteudo.agencia), stdin);
         break;
      case 3:
         gotoxy(30, 12);
         printf("                                         ");
         gotoxy(31, 12);
         fflush(stdin);
         fgets(p->conteudo.numero_conta, sizeof(p->conteudo.numero_conta), stdin);
         break;
      case 4:
         gotoxy(6, 23);
         printf("                                                                ");
         gotoxy(6, 23);
         printf("Utilizar: 1=Corrente / 2=Poupanca / 3=Cartao Credito: ");

         scanf("%d", &tipo_conta_opcao);

         // Switch case para definir o tipo de conta
         switch (tipo_conta_opcao)
         {
         case 1:
            strcpy(p->conteudo.tipo_conta, "Corrente");
            gotoxy(31, 14);
            printf("                             ");
            gotoxy(31, 14);
            printf("1 - Corrente");
            break;
         case 2:
            strcpy(p->conteudo.tipo_conta, "Poupanca");
            gotoxy(31, 14);
            printf("                             ");
            gotoxy(31, 14);
            printf("2 - Poupanca");
            break;
         case 3:
            strcpy(p->conteudo.tipo_conta, "Cartao Credito");
            gotoxy(31, 14);
            printf("                             ");
            gotoxy(31, 14);
            printf("3 - Cartao Credito");
            break;
         default:
            gotoxy(6, 23);
            printf("                                                          ");
            gotoxy(6, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            break;
         }
         break;
      case 5:
         gotoxy(6, 23);
         printf("                                                 ");
         gotoxy(6, 23);
         printf("Este campo nao pode ser alterado.");
         getch();
         break;
      case 6:
         gotoxy(6, 23);
         printf("                                                 ");
         gotoxy(6, 23);
         printf("Este campo nao pode ser alterado.");
         getch();
         break;
      case 7:
         gotoxy(6, 23);
         printf("                                                 ");
         gotoxy(6, 23);
         printf("Este campo nao pode ser alterado.");
         getch();
         break;
      default:
         gotoxy(6, 23);
         printf("                                                          ");
         gotoxy(6, 23);
         printf("Opcao invalida. Tente novamente.");
         getch();
         break;
      }

      gotoxy(6, 23);
      printf("                                                                ");
      gotoxy(6, 23);
      printf("Deseja alterar outro campo? (1 - Sim, 2 - Nao): ");
      scanf("%d", &msg);

   } while (msg == 1);

   system("cls");
   tela();
   gotoxy(6, 23);
   printf("                                                     ");
   gotoxy(6, 23);
   printf("Cadastro alterado com sucesso!");
   getch();
}
