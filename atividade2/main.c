#include "addClient.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Integrantes: Gabriel Coelho Soares
 */
int inicioBanco() {
  system("clear");
  printf("----------------------------------------\n");
  printf("------ Banco do Batata - v1.0.0 --------\n");
  printf("----------------------------------------\n\n\n");
  printf("Agências em toda a região da Baixa Mogiana \n123 - Mogi Guaçu    125 "
         "- Mogi Mirim    129 - Itapira    130 - Estiva Gerbi\n");
  return 0;
}

struct Cliente {
  int codigo_cliente;     // Código automático
  int agencia_num;        // Número da agência setado no início do programa
  char nome_cliente[140]; // String
  char conta_corrente[8]; // String de 6 números, um traço e um dígito final
  double saldo_atual;
  int chave_pix;
};

int main(int argc, char *argv[]) {
  struct Cliente *clientes;
  int agencia = 0, num_clientes, iterador_cod = 1, line_break, linhas_dbo;
  FILE *fro;
  FILE *fwr;

  inicioBanco();
  while (agencia == 0) {
    printf("\n\nDigite o número da agência que você deseja controlar: ");
    scanf("%d", &agencia);

    switch (agencia) {
    case 123:
      printf("Você escolheu a agência de Mogi Guaçu (123)");
      fro = fopen("123.txt", "r");
      fwr = fopen("123.txt", "wb");
      break;
    case 125:
      printf("Você escolheu a agência de Mogi Mirim (125)");
      fro = fopen("125.txt", "r");
      fwr = fopen("125.txt", "wb");
      break;
    case 129:
      printf("Você escolheu a agência de Itapira (129)");
      fro = fopen("129.txt", "r");
      fwr = fopen("129.txt", "wb");
      break;
    case 130:
      printf("Você escolheu a agência de Estiva Gerbi (130)");
      fro = fopen("130.txt", "r");
      fwr = fopen("130.txt", "wb");
      break;
    default:
      printf("Você não selecionou nenhuma agência existente!\nPor favor, "
             "selecione corretamente!");
      agencia = 0;
      break;
    }
  }

  do {
    line_break = fgetc(fro);
    if (line_break == '\n')
      linhas_dbo++;
  } while (line_break != EOF);
  printf("Linhas no arquivo teste %d", linhas_dbo);
  // Procurar pelo arquivo de mesmo nome. Caso não exista, criar nova agência
  // Checar quantidade de linhas no arquivo para gerar o número de clientes a
  // partir da seguinte fórmula: num_clientes = (50-nlinhas) + nlinhas;

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
