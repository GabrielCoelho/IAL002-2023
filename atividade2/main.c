#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Integrantes: Gabriel Coelho Soares
 */
// int movimentacaoConta(struct *conta) {}
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

int main(int argc, char *argv[]) {
  struct Cliente *clientes;
  clientes = (struct Cliente *)malloc(10 * sizeof(struct Cliente));
  bool conta_encontrada = false;
  int agencia = 0, num_clientes, iterador_cod = 1, line_break, linhas_dbo = 0,
      menu_gerente = 0, sub_menu;
  FILE *fro;
  FILE *fwr;

  inicioBanco();
  while (agencia == 0) {
    printf("\n\nDigite o número da agência que você deseja controlar: ");
    scanf("%d", &agencia);

    switch (agencia) {
    case 123:
      printf("Você escolheu a agência de Mogi Guaçu (123)");
      fro = fopen("123.txt", "a+");
      break;
    case 125:
      printf("Você escolheu a agência de Mogi Mirim (125)");
      fro = fopen("125.txt", "a+");
      break;
    case 129:
      printf("Você escolheu a agência de Itapira (129)");
      fro = fopen("129.txt", "a+");
      break;
    case 130:
      printf("Você escolheu a agência de Estiva Gerbi (130)");
      fro = fopen("130.txt", "a+");
      break;
    default:
      printf("Você não selecionou nenhuma agência existente!\nPor favor, "
             "selecione corretamente!");
      agencia = 0;
      break;
    }
  }
  if (fro == NULL) {
    printf("Arquivo de dados corrompido, por favor, ligue para os "
           "desenvolvedores urgentemente:\nGabriel Coelho: 1970707070\nIan "
           "Camargo: 1970207020\nMarcos Moreira: +9122132488\n");
    return 0;
  }

  for (line_break = getc(fro); line_break != EOF; line_break = getc(fro)) {
    if (line_break == '\n')
      linhas_dbo++;
  }
  int cod_teste;
  num_clientes = (10 - linhas_dbo);
  for (int i = 0; i < linhas_dbo; i++) {
    fscanf(fro, "%d", &(clientes + i)->codigo_cliente);
    fscanf(fro, "%d", &(clientes + i)->agencia_num);
    fscanf(fro, "%s", (clientes + i)->nome_cliente);
    fscanf(fro, "%s", (clientes + i)->sobrenome_cliente);
    fscanf(fro, "%d", &(clientes + i)->conta_corrente);
    fscanf(fro, "%lf", &(clientes + i)->saldo_atual);
    fscanf(fro, "%d", &(clientes + i)->chave_pix);
    printf("Cod: %d\nAgencia %d\nNome %s %s\nConta %d\nSaldo %lf\nPIX %d\n\n",
           (clientes + i)->codigo_cliente, (clientes + i)->agencia_num,
           (clientes + i)->nome_cliente, (clientes + i)->sobrenome_cliente,
           (clientes + i)->conta_corrente, (clientes + i)->saldo_atual,
           (clientes + i)->chave_pix);
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
                 "direcionado para a movimentação da mesma em breve");
          conta_encontrada = true;
        }
      }
      if (!conta_encontrada) {
        printf("A conta digitada não foi encontrada, certifique-se de que o "
               "cliente informou a conta certa\n\n");
        sub_menu = 0;
        menu_gerente = 0;
      }
      // movimentacaoConta();
      break;
    case 2:
      break;
    case 3:
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
