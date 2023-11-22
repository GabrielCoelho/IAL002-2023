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
      while (resp_menu_gerente == 0) {
        resp_menu_gerente = exibe_menu_gerente();
        switch (resp_menu_gerente) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 9:
          break;
        default:
          break;
        }
      }
      break;
    case 9:
      printf("Obrigado por utilizar nosso programa!\nSaindo com segurança...");
      sleep(1);
      break;
    default:
      printf("Não temos nenhuma agência com este número.\nPara entrar no "
             "sistema, entre com um número de nossas agências");
      senha_banco_gerencia = 0;
      break;
    }
  }
  return EXIT_SUCCESS;
}
