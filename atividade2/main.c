#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

/* Integrantes: Gabriel Coelho Soares
 */
int exibeMenuGerente() {
  system("clear");
  printf("----------------------------------------\n");
  printf("-------- Menu Gerencial do Banco -------\n");
  printf("----------------------------------------\n\n\n");
  printf("Movimentação de conta\t\tAbrir nova Conta\t\tExibir Saldo\n   - "
         "Sacar quantia\t\t- Cadastro de novo cliente\t- Exibe na tela o "
         "saldo atual\n   - Depositar quantia\n   - Efetuar PIX\n   - "
         "Transferência\n\n");
  return 0;
}
int inicioBanco() {
  system("clear");
  printf("----------------------------------------\n");
  printf("------ Banco do Batata - v1.0.0 --------\n");
  printf("----------------------------------------\n\n\n");
  printf("Agências em toda a região da Baixa Mogiana \n123 - Mogi Guaçu\t125 "
         "- Mogi Mirim\t129 - Itapira\t130 - Estiva Gerbi\n");
  return 0;
}

struct Cliente {
  int codigo_cliente; // Código automático
  int agencia_num;    // Número da agência setado no início do programa
  char nome_cliente[15];
  char sobrenome_cliente[20]; // String
  int conta_corrente;         // Conta com 6 digitos
  double saldo_atual;
  int chave_pix; // numero da agencia + codigo_cliente
};

int movimentacaoConta(struct Cliente *conta, int indice, FILE *f) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Movimentação da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n", (conta + indice)->agencia_num,
         (conta + indice)->conta_corrente);
  printf("--------- Cliente %s %s   \n", (conta + indice)->nome_cliente,
         (conta + indice)->sobrenome_cliente);
  printf("----------------------------------------\n\n\n");
  int opcao = 0;
  double saque_deposito;
  while (opcao == 0) {
    printf("Selecione a partir do menu abaixo: \n1. Saque\t2. Depósito\t3. "
           "Pix\t4. Transferência\n9. Voltar ao menu principal\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      printf("Digite a quantidade que deseja sacar: ");
      scanf("%lf", &saque_deposito);
      if (saque_deposito > (conta + indice)->saldo_atual) {
        printf("Quantia desejada maior que saldo disponível, por favor, "
               "escolha um valor entre: R$0.00 - R$%.2lf\n\n",
               (conta + indice)->saldo_atual);
        sleep(1);
        opcao = 0;
      } else {
        printf("Preparando para realizar o saque...");
        sleep(2);
        rewind(f);
        FILE *tmp_file = fopen("agency_copy.txt", "w");
        char c;
        bool passou = false;
        int tmp_count = 0;
        c = getc(f);
        while (c != EOF) {
          if (c == '\n') {
            tmp_count++;
            passou = false;
          }
          if (tmp_count != indice) {
            if (!passou) {
              putc(c, tmp_file);
            }
          } else {
            if (indice != 1) {
              putc(c, tmp_file);
            }
            fprintf(tmp_file, "%d %d %s %s %d %.2lf %d",
                    (conta + indice)->codigo_cliente,
                    (conta + indice)->agencia_num,
                    (conta + indice)->nome_cliente,
                    (conta + indice)->sobrenome_cliente,
                    (conta + indice)->conta_corrente,
                    (conta + indice)->saldo_atual - saque_deposito,
                    (conta + indice)->chave_pix);
            tmp_count++;
            passou = true;
          }
          c = getc(f);
        }
        fclose(f);
        fclose(tmp_file);
        remove("123.txt");
        rename("agency_copy.txt", "123.txt");
      }
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 9:
      return 1;
      break;
    default:
      printf("Por favor, selecione um item existente no menu");
      opcao = 0;
      break;
    }
  }
  return 0;
}

double exibeSaldoConta(struct Cliente *conta, int indice) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Saldo da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n", (conta + indice)->agencia_num,
         (conta + indice)->conta_corrente);
  printf("--------- Cliente %s %s   \n", (conta + indice)->nome_cliente,
         (conta + indice)->sobrenome_cliente);
  printf("--------- SALDO: R$ %.2lf\n", (conta + indice)->saldo_atual);
  printf("----------------------------------------\n\n\n");
  printf("Retornando ao menu gerencial em 5 segundos...\n\n");
  sleep(5);
  return 0;
}

int main(int argc, char *argv[]) {
  struct Cliente *clientes;
  clientes = (struct Cliente *)malloc(10 * sizeof(struct Cliente));
  bool conta_encontrada = false;
  int agencia = 0, num_clientes, iterador_cod = 1, line_break, linhas_dbo = 0,
      menu_gerente = 0, sub_menu, indice_movimentacao_conta = 0;
  FILE *arquivo_agencia;

  inicioBanco();
  while (agencia == 0) {
    printf("\n\nDigite o número da agência que você deseja controlar: ");
    scanf("%d", &agencia);

    switch (agencia) {
    case 123:
      printf("Você escolheu a agência de Mogi Guaçu (123)");
      arquivo_agencia = fopen("123.txt", "a+");
      break;
    case 125:
      printf("Você escolheu a agência de Mogi Mirim (125)");
      arquivo_agencia = fopen("125.txt", "a+");
      break;
    case 129:
      printf("Você escolheu a agência de Itapira (129)");
      arquivo_agencia = fopen("129.txt", "a+");
      break;
    case 130:
      printf("Você escolheu a agência de Estiva Gerbi (130)");
      arquivo_agencia = fopen("130.txt", "a+");
      break;
    default:
      printf("Você não selecionou nenhuma agência existente!\nPor favor, "
             "selecione corretamente!");
      agencia = 0;
      break;
    }
  }
  if (arquivo_agencia == NULL) {
    printf("Arquivo de dados corrompido, por favor, ligue para os "
           "desenvolvedores urgentemente:\nGabriel Coelho: 1970707070\nIan "
           "Camargo: 1970207020\nMarcos Moreira: +9122132488\n");
    return 0;
  }

  for (line_break = getc(arquivo_agencia); line_break != EOF;
       line_break = getc(arquivo_agencia)) {
    if (line_break == '\n')
      linhas_dbo++;
  }
  num_clientes = (10 - linhas_dbo);
  rewind(arquivo_agencia);
  for (int i = 0; i < linhas_dbo; i++) {
    fscanf(arquivo_agencia, "%d %d %s %s %d %lf %d",
           &(clientes + i)->codigo_cliente, &(clientes + i)->agencia_num,
           (clientes + i)->nome_cliente, (clientes + i)->sobrenome_cliente,
           &(clientes + i)->conta_corrente, &(clientes + i)->saldo_atual,
           &(clientes + i)->chave_pix);
  }
  printf("\n\n Agência %d\nNúmero de Clientes cadastrados %d/10\nNúmero de "
         "vagas %d/10",
         agencia, linhas_dbo, num_clientes);
  while (menu_gerente == 0) {
    exibeMenuGerente();
    printf("Escolha uma opção:\n1. Movimentar uma Conta\n2. Abrir Conta\n3. "
           "Consultar saldo de conta\n9. Sair do programa: "); // OU voltar ao
                                                               // menu principal
                                                               // (de agências)
    scanf("%d", &menu_gerente);
    switch (menu_gerente) {
    case 1:
      printf("\n\nDigite o número da conta desejada: ");
      scanf("%d", &sub_menu);
      for (int i = 0; i < linhas_dbo; i++) {
        if (sub_menu == (clientes + i)->conta_corrente) {
          printf("A conta desejada consta em nosso banco de dados\nVocê será "
                 "direcionado para a movimentação da mesma em breve\n\n");
          conta_encontrada = true;
          indice_movimentacao_conta = i;
        }
      }
      if (!conta_encontrada) {
        printf("A conta digitada não foi encontrada, certifique-se de que o "
               "cliente informou a conta certa\nAguarde enquanto retornamos ao "
               "menu de gerência...\n\n");
        sleep(5);
        sub_menu = 0;
        menu_gerente = 0;
      } else {
        sleep(2);
        sub_menu = movimentacaoConta(clientes, indice_movimentacao_conta,
                                     arquivo_agencia);
        if (sub_menu == 1) {
          menu_gerente = 0;
          sub_menu = 0;
        }
      }
      break;
    case 2:
      break;
    case 3:
      printf("\n\nDigite o número da conta desejada: ");
      scanf("%d", &sub_menu);
      for (int i = 0; i < linhas_dbo; i++) {
        if (sub_menu == (clientes + i)->conta_corrente) {
          printf("A conta desejada consta em nosso banco de dados\nVocê será "
                 "direcionado para a movimentação da mesma em breve\n\n");
          conta_encontrada = true;
          indice_movimentacao_conta = i;
        }
      }
      if (!conta_encontrada) {
        printf("A conta digitada não foi encontrada, certifique-se de que o "
               "cliente informou a conta certa\nAguarde enquanto retornamos ao "
               "menu de gerência...\n\n");
        sleep(5);
        sub_menu = 0;
        menu_gerente = 0;
      } else {
        sleep(2);
        exibeSaldoConta(clientes, indice_movimentacao_conta);
        menu_gerente = 0;
        sub_menu = 0;
      }
      break;
    case 9:
      printf("Saindo do programa\n\n");
      return 0;
    default:
      printf("Opção Inexistente\n\n");
      menu_gerente = 0;
      break;
    }
  }

  // printf("Digite a quantidade de clientes cadastrados nessa agência: ");
  // scanf("%d", &num_clientes);
  // // Alocando um espaço de memória de acordo com o número de clientes
  // clientes = (struct Cliente *)malloc(num_clientes * sizeof(struct Cliente));
  //
  // printf("Cadastro de Cliente número");
  // for (iterador_cod; iterador_cod <= num_clientes; iterador_cod++) {
  //   printf("Digite o nome do cliente e em seguida o número da conta corrente
  //   "
  //          "com o dígito: ");
  //   scanf("%s %s", &(clientes + (iterador_cod - 1))->nome_cliente,
  //         &(clientes + (iterador_cod - 1))->conta_corrente);
  // }
  return EXIT_SUCCESS;
}
