#include "Cliente.h"  // Inclusão do Struct
#include "Gerencia.h" // Inclusão das funções
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Declaração das Variáveis
  Cliente clientes_agencia[10];
  char arquivo_nome[10] = "banco.tbd";
  int senha_banco_gerencia = 0, resp_menu_gerente = 0, menu_movimentacao = 0,
      clientes_cadastrados = verifica_cadastrados(), conta_buscada,
      indice_encontrado;
  atualiza_clientes(clientes_agencia, 10);

  // Início do Banco.
  while (senha_banco_gerencia == 0) {
    // Recebe o retorno do início e verifica se a agência está cadastrada
    senha_banco_gerencia = exibe_inicio_banco();
    switch (senha_banco_gerencia) {
    case 123:
    case 125:
    case 129:
    case 130:
      printf("Você está prestes a entrar no banco. Por favor, aguarde... \n\n");
      sleep(3);
      while (resp_menu_gerente == 0) {
        // recebe a resposta do menu de gerência
        resp_menu_gerente = exibe_menu_gerente();
        switch (resp_menu_gerente) {
          // Movimentação da conta
        case 1:
          printf("\nDigite o número da conta a ser movimentada: ");
          scanf("%d", &conta_buscada);
          indice_encontrado =
              encontrar_conta(clientes_agencia, conta_buscada, 10);
          if (indice_encontrado != 20) {
            printf("Conta encontrada em nosso sistema\nAguarde a leitura dos "
                   "dados\n\n");
            sleep(3);
            menu_movimentacao =
                movimentar_conta(clientes_agencia, indice_encontrado, 10);
            if (menu_movimentacao == 1) {
              resp_menu_gerente = 0;
            } else {
              printf(
                  "Pane no sistema, alguma coisa está desconfigurada\nSaindo "
                  "do programa com segurança...");
              sleep(4);
              return 0;
            }
          } else {
            printf("Conta não encontrada, por favor, tente novamente\n\n");
            resp_menu_gerente = 0;
          }
          break;
          // Criação de nova conta
        case 2:
          cria_conta_cliente(clientes_agencia, clientes_cadastrados);
          clientes_cadastrados++;
          printf("Conta cadastrada com sucesso!\n\n");
          sleep(1);
          resp_menu_gerente = 0;
          break;
          // Exibição do saldo da conta
        case 3:
          printf("Por favor, informe o número da conta: ");
          scanf("%d", &conta_buscada);
          indice_encontrado =
              encontrar_conta(clientes_agencia, conta_buscada, 10);
          if (indice_encontrado == 20) {
            printf("Conta não encontrada\nRetornando ao menu gerencial\n\n");
            sleep(2);
          } else {
            exibe_saldo(clientes_agencia, indice_encontrado);
          }
          resp_menu_gerente = 0;
          break;
          // Volta para o menu principal
        case 9:
          senha_banco_gerencia = 0;
          break;
          // Caso não tenha digitado entre 1-3 ou 9 para sair
        default:
          printf("Por favor digite um item do menu\n");
          resp_menu_gerente = 0;
          break;
        }
      }
      break;
      // 9 para sair do programa e imprimir no arquivo
    case 9:
      printf("Obrigado por utilizar nosso programa!\nSaindo com segurança...");
      FILE *file_agencia = fopen(arquivo_nome, "w");
      for (int i = 0; i < clientes_cadastrados; i++) {
        fprintf(file_agencia, "%d %d %s %s %d %.2lf %d\n",
                clientes_agencia[i].codigo_cliente,
                clientes_agencia[i].agencia_num,
                clientes_agencia[i].nome_cliente,
                clientes_agencia[i].sobrenome_cliente,
                clientes_agencia[i].conta_corrente,
                clientes_agencia[i].saldo_atual, clientes_agencia[i].chave_pix);
      }
      sleep(2);
      break;
      // Caso o usuário digite uma agência inexistente, retorna ao menu
      // principal
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
