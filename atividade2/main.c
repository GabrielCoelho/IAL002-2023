#include "addClient.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Integrantes: Gabriel Coelho Soares
 */

struct Cliente {
  int codigo_cliente;     // Código automático
  int agencia_num;        // Número da agência setado no início do programa
  char nome_cliente[140]; // String
  char conta_corrente[8]; // String de 6 números, um traço e um dígito final
  double saldo_atual;
};

int main(int argc, char *argv[]) {
  struct Cliente *clientes;
  int agencia, num_clientes, iterador_cod = 1;

  printf("Banco do Batata - v1.0.0");
  printf("\n\nDigite o número da agência que você deseja controlar: ");
  scanf("%d", &agencia);

  // Procurar pelo arquivo de mesmo nome. Caso não exista, criar nova agência
  // Checar quantidade de linhas no arquivo para gerar o número de clientes a
  // partir da seguinte fórmula: num_clientes = (50-nlinhas) + nlinhas;

  printf("Digite a quantidade de clientes cadastrados nessa agência: ");
  scanf("%d", &num_clientes);
  // Alocando um espaço de memória de acordo com o número de clientes
  clientes = (struct Cliente *)malloc(num_clientes * sizeof(struct Cliente));

  printf("Cadastro de Cliente número");
  for (iterador_cod; iterador_cod <= num_clientes; iterador_cod++) {
    printf("Digite o nome do cliente e em seguida o número da conta corrente "
           "com o dígito: ");
    scanf("%s %s", &(clientes + (iterador_cod - 1))->nome_cliente,
          &(clientes + (iterador_cod - 1))->conta_corrente);
  }
  return EXIT_SUCCESS;
}