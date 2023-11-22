#include "Cliente.h"
#include "Gerencia.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  Cliente clientes_agencia[10];
  Cliente *c = clientes_agencia;
  char arquivo_nome[10] = "banco.tbd";
  FILE *arquivo_agencia = fopen(arquivo_nome, "a+");
  int senha_banco_gerencia = 0, resp_menu_gerente = 0, menu_movimentacao = 0,
      clientes_cadastrados = verifica_cadastrados(arquivo_agencia),
      conta_buscada, indice_encontrado;

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
          menu_movimentacao = movimentar_conta(&c, clientes_cadastrados, 10,
                                               arquivo_agencia, arquivo_nome);
          if (menu_movimentacao == 1) {
            resp_menu_gerente = 0;
          } else {
            printf("Pane no sistema, alguma coisa está desconfigurada\nSaindo "
                   "do programa com segurança...");
            sleep(4);
            return 0;
          }
          break;
        case 2:
          break;
        case 3:
          printf("Por favor, informe o número da conta: ");
          scanf("%d", &conta_buscada);
          indice_encontrado = encontrar_conta(&c, conta_buscada, 10);
          if (indice_encontrado == 20) {
            printf("Conta não encontrada\nRetornando ao menu gerencial\n\n");
            sleep(2);
          } else {
            exibe_saldo(&c, indice_encontrado);
          }
          resp_menu_gerente = 0;
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
             "sistema, entre com um número de nossas agências\nLevando você de "
             "volta ao início...\n\n");
      sleep(2);
      senha_banco_gerencia = 0;
      break;
    }
  }
  return EXIT_SUCCESS;
}
