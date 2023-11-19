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
  printf("\n----------------------------------------\n");
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
         "- Mogi Mirim\n129 - Itapira\t130 - Estiva Gerbi\n9 - Para sair do "
         "programa\n");
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

void atualizaClientes(struct Cliente *c, int max_line, FILE *f) {
  for (int i = 0; i < max_line; i++) {
    fscanf(f, "%d %d %s %s %d %lf %d", &(c + i)->codigo_cliente,
           &(c + i)->agencia_num, (c + i)->nome_cliente,
           (c + i)->sobrenome_cliente, &(c + i)->conta_corrente,
           &(c + i)->saldo_atual, &(c + i)->chave_pix);
  }
}

int movimentacaoConta(struct Cliente *conta, int indice, FILE *f,
                      char *file_name) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Movimentação da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n", (conta + indice)->agencia_num,
         (conta + indice)->conta_corrente);
  printf("--------- Cliente %s %s   \n", (conta + indice)->nome_cliente,
         (conta + indice)->sobrenome_cliente);
  printf("----------------------------------------\n");
  printf("----------------------------------------\n");
  printf("------ Por questões de Segurança, ------\n"
         "------ após qualquer movimentação ------\n"
         "------ o Gerente precisará relogar -----\n"
         "-------------- no sistema --------------\n");
  printf("----------------------------------------\n\n\n");
  printf("----------------------------------------\n\n\n");
  int opcao = 0, inf_agencia, inf_num_conta, indice_movimentacao_conta;
  bool conta_encontrada;
  double saque_deposito;
  while (opcao == 0) {
    printf("Selecione a partir do menu abaixo: \n1. Saque\t2. Depósito\n3. "
           "Pix\t\t4. Transferência\n9. Voltar ao menu gerencial\n");
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
        printf("Preparando para realizar o saque...\n\n");
        sleep(2);
        rewind(f);
        FILE *tmp_file = fopen("agency_copy.tbd", "w");
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
            if (c == '\n') {
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
        remove(file_name);
        rename("agency_copy.tbd", file_name);
      }
      printf("O Banco do Batata agradece a utilização!\n\t\t Volte sempre!");
      break;
    case 2:
      printf("Digite a quantidade que deseja depositar: ");
      scanf("%lf", &saque_deposito);
      if (saque_deposito == 0) {
        printf("Não é possível depositar R$ 0.00 na conta\n");
        sleep(1);
        opcao = 0;
      } else {
        printf("Preparando para realizar o deposito...\n");
        sleep(2);
        rewind(f);
        FILE *tmp_file = fopen("agency_copy.tbd", "w");
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
            if (c == '\n') {
              putc(c, tmp_file);
            }
            fprintf(tmp_file, "%d %d %s %s %d %.2lf %d",
                    (conta + indice)->codigo_cliente,
                    (conta + indice)->agencia_num,
                    (conta + indice)->nome_cliente,
                    (conta + indice)->sobrenome_cliente,
                    (conta + indice)->conta_corrente,
                    (conta + indice)->saldo_atual + saque_deposito,
                    (conta + indice)->chave_pix);
            tmp_count++;
            passou = true;
          }
          c = getc(f);
        }
        fclose(f);
        fclose(tmp_file);
        remove(file_name);
        rename("agency_copy.tbd", file_name);
      }
      printf("O Banco do Batata agradece a utilização!\n\t\t Volte sempre!");
      break;
    case 3:
      // Pix
      break;
    case 4:
      // Transferência
      printf("Informe-nos a agência na qual a conta está cadastrada: ");
      scanf("%d", &inf_agencia);
      switch (inf_agencia) {
      case 123:
        printf("Agora, por favor, nos informe o número da conta: ");
        scanf("%d", &inf_num_conta);
        if (inf_num_conta == (conta + indice)->conta_corrente) {
          printf("Você não pode transferir para a sua própria conta\n");
          sleep(1);
          opcao = 0;
        } else {
          for (int i = 0; i < 10; i++) {
            if (inf_num_conta == (conta + i)->conta_corrente) {
              printf(
                  "A conta desejada consta em nosso banco de dados\nVocê será "
                  "direcionado para a movimentação da mesma em breve\n\n");
              conta_encontrada = true;
              indice_movimentacao_conta = i;
            }
          }
          if (conta_encontrada) {
            printf("Digite a quantidade que deseja transferir: ");
            scanf("%lf", &saque_deposito);
            if (saque_deposito == 0) {
              printf("Não é possível depositar R$ 0.00 na conta\n");
              sleep(1);
              opcao = 0;
            } else if (saque_deposito >=
                       (conta + indice)->saldo_atual - 21.50) {
              printf("Você não tem limite suficiente para fazer essa "
                     "transferência\nCusto da transferência: R$21.50\n\n");
              sleep(1);
              opcao = 0;
            }
          } else {
            printf("Não encontramos a conta informada nesta agência!\n\nPor "
                   "favor, certifique-se de que ela existe\n");
            sleep(1);
            opcao = 0;
          }
        }
        break;
      case 125:
        break;
      case 129:
        break;
      case 130:
        break;
      default:
        printf("Agência não encontrada!\n\n");
        opcao = 0;
        break;
      }
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
  char nome_agencia[8];
  int agencia = 0, num_clientes, iterador_cod = 1, line_break, linhas_dbo = 0,
      menu_gerente, sub_menu, indice_movimentacao_conta = 0;
  FILE *arquivo_agencia;

  while (agencia == 0) {
    inicioBanco();
    printf("\n\nDigite o número da agência que você deseja controlar: ");
    scanf("%d", &agencia);

    switch (agencia) {
    case 123:
      printf("Você escolheu a agência de Mogi Guaçu (123)");
      strcpy(nome_agencia, "123.tbd");
      arquivo_agencia = fopen(nome_agencia, "a+");
      break;
    case 125:
      printf("Você escolheu a agência de Mogi Mirim (125)");
      strcpy(nome_agencia, "125.tbd");
      arquivo_agencia = fopen(nome_agencia, "a+");
      break;
    case 129:
      printf("Você escolheu a agência de Itapira (129)");
      strcpy(nome_agencia, "129.tbd");
      arquivo_agencia = fopen(nome_agencia, "a+");
      break;
    case 130:
      printf("Você escolheu a agência de Estiva Gerbi (130)");
      strcpy(nome_agencia, "130.tbd");
      arquivo_agencia = fopen(nome_agencia, "a+");
      break;
    case 9:
      printf("Saindo do programa\n\n");
      return 0;
    default:
      printf("Você não selecionou nenhuma agência existente!\nPor favor, "
             "selecione corretamente!");
      agencia = 0;
      break;
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
    atualizaClientes(clientes, linhas_dbo, arquivo_agencia);
    menu_gerente = 0;
    sub_menu = 0;
    while (menu_gerente == 0) {
      exibeMenuGerente();
      printf("Escolha uma opção:\n1. Movimentar uma Conta\n2. Abrir Conta\n3. "
             "Consultar saldo de conta\n9. Escolher outra agência: ");
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
          printf(
              "A conta digitada não foi encontrada, certifique-se de que o "
              "cliente informou a conta certa\nAguarde enquanto retornamos ao "
              "menu de gerência...\n\n");
          sleep(5);
          sub_menu = 0;
          menu_gerente = 0;
        } else {
          sleep(2);
          sub_menu = movimentacaoConta(clientes, indice_movimentacao_conta,
                                       arquivo_agencia, nome_agencia);
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
          printf(
              "A conta digitada não foi encontrada, certifique-se de que o "
              "cliente informou a conta certa\nAguarde enquanto retornamos ao "
              "menu de gerência...\n\n");
          sleep(5);
          sub_menu = 0;
          menu_gerente = 0;
        } else {
          rewind(arquivo_agencia);
          atualizaClientes(clientes, linhas_dbo, arquivo_agencia);
          sleep(2);
          exibeSaldoConta(clientes, indice_movimentacao_conta);
          menu_gerente = 0;
          sub_menu = 0;
        }
        break;
      case 9:
        agencia = 0;
        break;
      default:
        printf("Opção Inexistente\n\n");
        menu_gerente = 0;
        break;
      }
    }
  }
  return EXIT_SUCCESS;
}
