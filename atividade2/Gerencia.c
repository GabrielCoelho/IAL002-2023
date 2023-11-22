#include "Gerencia.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int exibe_inicio_banco() {
  int recebe_agencia;
  system("clear");
  printf("----------------------------------------\n");
  printf("------ Banco do Batata - v1.0.0 --------\n");
  printf("----------------------------------------\n\n\n");
  printf("Agências em toda a região da Baixa Mogiana \n123 - Mogi Guaçu\t125 "
         "- Mogi Mirim\n129 - Itapira\t130 - Estiva Gerbi\n9 - Para sair do "
         "programa\n");
  printf("\n\nDigite o número da agência que você deseja controlar: ");
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
         "Consultar saldo de conta\n9. Escolher outra agência: ");
  scanf("%d", &recebe_menu);
  return recebe_menu;
}

void atualiza_clientes(Cliente *c, int tamanho_agencia, FILE *file_agencia) {
  c = (Cliente *)malloc(sizeof(Cliente));
  rewind(file_agencia);
  for (int i = 0; i < tamanho_agencia; i++) {
    fscanf(file_agencia, "%d %d %s %s %d %lf %d", &(c + i)->codigo_cliente,
           &(c + i)->agencia_num, (c + i)->nome_cliente,
           (c + i)->sobrenome_cliente, &(c + i)->conta_corrente,
           &(c + i)->saldo_atual, &(c + i)->chave_pix);
  }
}

void exibe_saldo(Cliente *c, int indice) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Saldo da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n", (c + indice)->agencia_num,
         (c + indice)->conta_corrente);
  printf("--------- Cliente %s %s   \n", (c + indice)->nome_cliente,
         (c + indice)->sobrenome_cliente);
  printf("--------- SALDO: R$ %.2lf\n", (c + indice)->saldo_atual);
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

int encontrar_conta(Cliente *c, int conta_buscada, int tamanho_agencia) {
  bool conta_encontrada = false;
  for (int i = 0; i < tamanho_agencia; i++) {
    if (conta_buscada == (c + i)->conta_corrente) {
      conta_encontrada = true;
      return i; // Retorna o indice do struct em qual a conta buscada está
                // armazenado
    }
  }
  return 20; // se retornar 20, é porque não foi encontrada
}

int movimentar_conta(Cliente *c, int indice_da_conta, int tamanho_agencia,
                     FILE *file_agencia, char *nome_do_arquivo) {
  system("clear");
  printf("----------------------------------------\n");
  printf("--------- Movimentação da Conta: -------\n");
  printf("---- Ag: %d -------- Conta: %d ----\n",
         (c + indice_da_conta)->agencia_num,
         (c + indice_da_conta)->conta_corrente);
  printf("--------- Cliente %s %s   \n", (c + indice_da_conta)->nome_cliente,
         (c + indice_da_conta)->sobrenome_cliente);
  printf("----------------------------------------\n");
  printf("----------------------------------------\n");
  printf("----------------------------------------\n\n\n");
}
