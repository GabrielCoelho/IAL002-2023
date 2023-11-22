#ifndef GERENCIA_H_INCLUDED
#define GERENCIA_H_INCLUDED
#include "Cliente.h" // recebe a struct
#include <stdio.h>

int exibe_inicio_banco();
int exibe_menu_gerente();
void atualiza_clientes(Cliente *c, int tamanho_agencia, FILE *file_agencia);
void exibe_saldo(Cliente *c, int indice_da_conta);
int verifica_cadastrados(FILE *file_agencia);
int encontrar_conta(Cliente *c, int conta_buscada, int tamanho_agencia);
int saque_deposito_conta(int operacao, Cliente *c, int indice_da_conta,
                         FILE *file_agencia, char *nome_do_arquivo);
int transferencia_entre_contas(Cliente *c, int indice_da_conta,
                               FILE *file_agencia, char *nome_do_arquivo);
int movimentar_conta(Cliente *c, int indice_da_conta, int tamanho_agencia,
                     FILE *file_agencia, char *nome_do_arquivo);
#endif // !GERENCIA_H_INCLUDED
