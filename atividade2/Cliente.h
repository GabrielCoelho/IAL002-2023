#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
  int codigo_cliente; // Código será automático
  int agencia_num;    // Número da agência setado no início do programa
  char nome_cliente[15];
  char sobrenome_cliente[20]; // String
  int conta_corrente;         // Conta com 6 digitos
  double saldo_atual;
  int chave_pix; // numero da agencia + codigo_cliente
} Cliente;

#endif // !CLIENTE_H
