#include "Cliente.h"
#include "Gerencia.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  Cliente clientes_agencia[10];
  int senha_banco_gerencia = 0, resp_menu_gerente = 0, menu_movimentacao = 0;
  while (senha_banco_gerencia == 0) {
    senha_banco_gerencia = exibe_inicio_banco();
    switch (senha_banco_gerencia) {
    case 123:
    case 125:
    case 129:
    case 130:
      printf("Você está prestes a entrar no banco. Por favor, aguarde... \n\n");
      sleep(3);
      resp_menu_gerente = exibe_menu_gerente();
      senha_banco_gerencia = 0;
      break;
    case 9:
      printf("Obrigado por utilizar nosso programa!\nSaindo com segurança...");
      sleep(1);
      break;
    default:
      printf("Não temos nenhuma agência com este número.\nPara entrar no "
             "sistema, entre com um número de nossas agências\nLevando você de "
             "volta ao início...\n\n");
      sleep(2);
      senha_banco_gerencia = 0;
      break;
    }
  }
  return EXIT_SUCCESS;
}
