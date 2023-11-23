#include "Gerencia.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int exibe_inicio_banco() {
  int recebe_agencia;
  system("clear");
  printf("----------------------------------------\n");
  printf("------ Banco do Batata - v1.1.9 --------\n");
  printf("----------------------------------------\n\n\n");
  printf("Agências em toda a região da Baixa Mogiana \n123 - Mogi Guaçu\t125 "
         "- Mogi Mirim\n129 - Itapira\t130 - Estiva Gerbi\n9 - Para sair do "
         "programa\n");
  printf("\n\nDigite qualquer número de agência para entrar no sistema: ");
  scanf("%d", &recebe_agencia);
  return recebe_agencia;
}

int exibe_menu_gerente() {
  int recebe_menu;
  system("clear");
  printf("\n----------------------------------------\n");
  printf("-------- Menu Gerencial do Banco -------\n");
  printf("----------------------------------------\n\n\n");
  printf("Movimentação de conta\t\tAbrir nova Conta\t\tExibir Saldo\n   - "
         "Sacar quantia\t\t- Cadastro de novo cliente\t- Exibe na tela o "
         "saldo atual\n   - Depositar quantia\n   - Efetuar PIX\n   - "
         "Transferência\n\n");
  printf("Escolha um menu:\n1. Movimentar uma Conta\n2. Abrir Conta\n3. "
         "Consultar saldo de conta\n9. Voltar ao Início: ");
  scanf("%d", &recebe_menu);
  return recebe_menu;
}

void atualiza_clientes(Cliente c[], int tamanho_agencia, FILE *file_agencia) {
  // c = (Cliente **)malloc(sizeof(Cliente *));
  rewind(file_agencia);
  for (int i = 0; i < tamanho_agencia; i++) {
    fscanf(file_agencia, "%d %d %s %s %d %lf %d", &c[i].codigo_cliente,
           &c[i].agencia_num, c[i].nome_cliente, c[i].sobrenome_cliente,
           &c[i].conta_corrente, &c[i].saldo_atual, &c[i].chave_pix);
  }
}

void exibe_saldo(Cliente c[], int indice_da_conta) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Saldo da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n",
         c[indice_da_conta].agencia_num, c[indice_da_conta].conta_corrente);
  printf("--------- Cliente %s %s   \n", c[indice_da_conta].nome_cliente,
         c[indice_da_conta].sobrenome_cliente);
  printf("--------- SALDO: R$ %.2lf\n", c[indice_da_conta].saldo_atual);
  printf("----------------------------------------\n\n\n");
  printf("Retornando ao menu gerencial em 5 segundos...\n\n");
  sleep(5);
}

int verifica_cadastrados(FILE *file_agencia) {
  char c;
  int quantidade_cadastrado = 0;
  for (c = getc(file_agencia); c != EOF; c = getc(file_agencia)) {
    // Percorre cada caractere dentro do arquivo
    if (c == '\n')             // ao se deparar com uma quebra de linha
      quantidade_cadastrado++; // adiciona 1 ao contador
  }
  return quantidade_cadastrado; // retornando a quantidade cadastrada
}

int encontrar_conta(Cliente c[], int conta_buscada, int tamanho_agencia) {
  bool conta_encontrada = false;
  for (int i = 0; i < tamanho_agencia; i++) {
    if (conta_buscada == c[i].conta_corrente) {
      conta_encontrada = true;
      return i; // Retorna o indice do struct em qual a conta buscada está
                // armazenado
    }
  }
  return 20; // se retornar 20, é porque não foi encontrada
}

int saque_deposito_conta(int operacao, Cliente c[], int indice_da_conta,
                         FILE *file_agencia, char *nome_do_arquivo) {
  double valor_saque_dep;
  char mensagem_inicio[11], mensagem_operacao[11],
      tmp_file_agencia_name[16] = "agency_copy.tbd";

  if (operacao == 1) {
    strcpy(mensagem_inicio, "sacar");
    strcpy(mensagem_operacao, "saque");
  } else if (operacao == 2) {
    strcpy(mensagem_inicio, "depositar");
    strcpy(mensagem_operacao, "depósito");
  }

  printf("Digite a quantidade que deseja %s: ", mensagem_inicio);
  scanf("%lf", &valor_saque_dep);
  if (valor_saque_dep > c[indice_da_conta].saldo_atual) {
    printf("Quantia desejada maior que saldo disponível, por favor, "
           "escolha um valor entre: R$0.00 - R$%.2lf\n\n",
           c[indice_da_conta].saldo_atual);
    sleep(1);
    return saque_deposito_conta(operacao, c, indice_da_conta, file_agencia,
                                nome_do_arquivo);
  } else {
    printf("Preparando para realizar o %s...\n\n", mensagem_operacao);
    sleep(2);
    rewind(file_agencia);
    FILE *tmp_file = fopen(tmp_file_agencia_name, "w");
    char x;
    bool passou = false;
    int tmp_count = 0;
    x = getc(file_agencia);
    while (x != EOF) {
      if (x == '\n') {
        tmp_count++;
        passou = false;
      }
      if (tmp_count != indice_da_conta) {
        if (!passou) {
          putc(x, tmp_file);
        }
      } else {
        if (x == '\n') {
          putc(x, tmp_file);
        }
        fprintf(tmp_file, "%d %d %s %s %d %.2lf %d",
                c[indice_da_conta].codigo_cliente,
                c[indice_da_conta].agencia_num, c[indice_da_conta].nome_cliente,
                c[indice_da_conta].sobrenome_cliente,
                c[indice_da_conta].conta_corrente,
                operacao == 1
                    ? c[indice_da_conta].saldo_atual - valor_saque_dep
                    : c[indice_da_conta].saldo_atual + valor_saque_dep,
                c[indice_da_conta].chave_pix);
        tmp_count++;
        passou = true;
      }
      x = getc(file_agencia);
    }
    fclose(file_agencia);
    fclose(tmp_file);
    remove(nome_do_arquivo);
    rename(tmp_file_agencia_name, nome_do_arquivo);
    file_agencia = fopen(nome_do_arquivo, "a+");
    return 0;
  }
}

int transferencia_entre_contas(Cliente c[], int indice_da_conta,
                               FILE *file_agencia, char *nome_do_arquivo) {
  double valor_transferencia;
  char tmp_file_agencia_name[16] = "agency_copy.tbd";
  int conta_destino;

  printf("A taxa de transferência entre contas é de R$ 22.50\n\nDigite a "
         "quantidade que deseja transferir: ");
  scanf("%lf", &valor_transferencia);
  if (valor_transferencia > c[indice_da_conta].saldo_atual - 22.50) {
    printf("Quantia desejada maior que saldo disponível, por favor, "
           "escolha um valor entre: R$0.00 - R$%.2lf\n\n",
           c[indice_da_conta].saldo_atual - 22.50);
    sleep(1);
    return transferencia_entre_contas(c, indice_da_conta, file_agencia,
                                      nome_do_arquivo);
  } else {
    printf("Informe a conta que receberá este valor: ");
    scanf("%d", &conta_destino);
    int indice_conta_destino;
    indice_conta_destino = encontrar_conta(c, conta_destino, 10);
    if (indice_conta_destino == 20) {
      printf("A conta informada não existe! \nRetornando ao menu gerencial");
      return 0;
    } else {
      printf("Preparando para realizar a transferência...\n\n");
      sleep(2);
      rewind(file_agencia);
      FILE *tmp_file = fopen(tmp_file_agencia_name, "w");
      char x;
      bool passou = false;
      int tmp_count = 0;
      x = getc(file_agencia);
      while (x != EOF) {
        if (x == '\n') {
          tmp_count++;
          passou = false;
        }
        if (tmp_count != indice_da_conta) {
          if (!passou) {
            putc(x, tmp_file);
          }
        } else if (tmp_count == indice_da_conta) {
          if (x == '\n') {
            putc(x, tmp_file);
          }
          fprintf(tmp_file, "%d %d %s %s %d %.2lf %d",
                  c[indice_da_conta].codigo_cliente,
                  c[indice_da_conta].agencia_num,
                  c[indice_da_conta].nome_cliente,
                  c[indice_da_conta].sobrenome_cliente,
                  c[indice_da_conta].conta_corrente,
                  c[indice_da_conta].saldo_atual - valor_transferencia - 22.50,
                  c[indice_da_conta].chave_pix);
          tmp_count++;
          passou = true;
        } else if (tmp_count == indice_conta_destino) {
          if (x == '\n') {
            putc(x, tmp_file);
          }
          fprintf(tmp_file, "%d %d %s %s %d %.2lf %d",
                  c[indice_conta_destino].codigo_cliente,
                  c[indice_conta_destino].agencia_num,
                  c[indice_conta_destino].nome_cliente,
                  c[indice_conta_destino].sobrenome_cliente,
                  c[indice_conta_destino].conta_corrente,
                  c[indice_conta_destino].saldo_atual + valor_transferencia,
                  c[indice_conta_destino].chave_pix);
          tmp_count++;
          passou = true;
        }
        x = getc(file_agencia);
      }
      fclose(file_agencia);
      fclose(tmp_file);
      remove(nome_do_arquivo);
      rename(tmp_file_agencia_name, nome_do_arquivo);
      file_agencia = fopen(nome_do_arquivo, "a+");
    }
    return 0;
  }
}

int movimentar_conta(Cliente c[], int indice_da_conta, int tamanho_agencia,
                     FILE *file_agencia, char *nome_do_arquivo) {
  int opcao = 0;
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Movimentação da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n",
         c[indice_da_conta].agencia_num, c[indice_da_conta].conta_corrente);
  printf("--------- Cliente %s %s   \n", c[indice_da_conta].nome_cliente,
         c[indice_da_conta].sobrenome_cliente);
  printf("----------------------------------------\n");
  printf("----------------------------------------\n");
  printf("----------------------------------------\n\n\n");
  while (opcao == 0) {
    printf("Selecione a partir do menu abaixo: \n1. Saque\t2. Depósito\n3. "
           "Pix\t\t4. Transferência\n9. Voltar ao menu gerencial\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
    case 2:
      saque_deposito_conta(opcao, c, indice_da_conta, file_agencia,
                           nome_do_arquivo);
      // atualiza_clientes(c, 10, file_agencia);
      opcao = 0;
      break;
    case 3:
      break;
    case 4:
      transferencia_entre_contas(c, indice_da_conta, file_agencia,
                                 nome_do_arquivo);
      opcao = 0;
      break;
    case 9:
      printf("Retornando ao menu gerencial");
      sleep(2);
      return 1;
    }
  }
  return 1;
}
