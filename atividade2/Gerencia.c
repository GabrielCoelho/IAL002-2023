#include "Gerencia.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/** Exibe Início Banco()
 * Retorna o valor digitado do menu exibido no terminal
 */
int exibe_inicio_banco() {
  int recebe_agencia;
  system("clear");
  printf("----------------------------------------\n");
  printf("------ Banco do Batata - v1.1.9 --------\n");
  printf("----------------------------------------\n\n\n");
  printf("Agências em toda a região da Baixa Mogiana \n123 - Mogi Guaçu\t125 "
         "- Mogi Mirim\n129 - Itapira\t\t130 - Estiva Gerbi\n9 - Para sair do "
         "programa\n");
  printf("\n\nDigite qualquer número de agência para entrar no sistema: ");
  scanf("%d", &recebe_agencia);
  return recebe_agencia;
}

/** Exibe Menu Gerente()
 * Retorna o valor digitado do menu exibido no terminal
 */
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

/** Atualiza Clientes
 * Abre o arquivo do banco de dados para inserir no struct os clientes
 * cadastrados
 * @see verifica_cadastrados()
 * @param c[] um array da struct Cliente
 * @param tamanho_agencia um inteiro contendo os clientes já cadastrados.
 */
void atualiza_clientes(Cliente c[], int tamanho_agencia) {
  FILE *file_agencia = fopen("banco.tbd", "r");
  int contagem_clientes = 0;
  while (fscanf(file_agencia, "%d %d %s %s %d %lf %d",
                &c[contagem_clientes].codigo_cliente,
                &c[contagem_clientes].agencia_num,
                c[contagem_clientes].nome_cliente,
                c[contagem_clientes].sobrenome_cliente,
                &c[contagem_clientes].conta_corrente,
                &c[contagem_clientes].saldo_atual,
                &c[contagem_clientes].chave_pix) != EOF) {
    /* Imprime na tela o cliente recebido
     * funcionalidade de teste somente
    printf("Código: %d\nAgência: %d\nNome: %s %s\nConta: %d\nSaldo: "
    "%.2lf\nPIX: %d\n\n",
    c[contagem_clientes].codigo_cliente,
    c[contagem_clientes].agencia_num, c[contagem_clientes].nome_cliente,
    c[contagem_clientes].sobrenome_cliente,
    c[contagem_clientes].conta_corrente,
    c[contagem_clientes].saldo_atual, c[contagem_clientes].chave_pix);
     */
    contagem_clientes++;
    if (contagem_clientes == 10) {
      break;
    }
  }
  fclose(file_agencia);
}

/** Exibe Saldo
 * Durante 5 segundos, exibe o saldo da conta digitada. Após o tempo
 * estabelecido, retorna ao menu anterior
 * @param c[] um array do struct Cliente
 * @param indice_da_conta um inteiro contendo o índice do array para o outro
 * @see encontrar_conta()
 * parâmetro
 */
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

/** Verifica cadastrados()
 * Passa pelo arquivo do banco de dados recebendo a quantidade de clientes
 * cadastrados
 */
int verifica_cadastrados() {
  char c;
  int quantidade_cadastrado = 0;
  FILE *file_agencia = fopen("banco.tbd", "r");
  for (c = getc(file_agencia); c != EOF; c = getc(file_agencia)) {
    // Percorre cada caractere dentro do arquivo
    if (c == '\n')             // ao se deparar com uma quebra de linha
      quantidade_cadastrado++; // adiciona 1 ao contador
  }
  fclose(file_agencia);
  return quantidade_cadastrado; // retornando a quantidade cadastrada
}

/** Encontrar Conta()
 * Retorna o índice da conta buscada caso ela exista no banco de dados
 * @param c[] array do struct Cliente
 * @param conta_buscada inteiro com a conta digitada pelo usuário
 * @param tamanho_agencia inteiro com a quantidade de clientes cadastrados
 */
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

/** Encontrar PIX()
 * Retorna o índice da conta em que a chave PIX está cadastrada, caso exista no
 * banco de dados
 * @param c[] array do struct Cliente
 * @param conta_buscada inteiro com a chave PIX digitada pelo usuário
 * @param tamanho_agencia inteiro com a quantidade de clientes cadastrados
 */
int encontrar_pix(Cliente c[], int conta_buscada, int tamanho_agencia) {
  bool conta_encontrada = false;
  for (int i = 0; i < tamanho_agencia; i++) {
    if (conta_buscada == c[i].chave_pix) {
      conta_encontrada = true;
      return i; // Retorna o indice do struct em qual o pix buscado está
                // armazenado
    }
  }
  return 20; // se retornar 20, é porque não foi encontrada
}

/** Saque ou Depósito na Conta()
 * Realiza saque ou depósito a partir de uma conta existente.
 * @see movimentar_conta()
 * @param operacao inteiro contendo qual operação será realizada:
 *    1: saque    2: depósito
 * @param c[] array do struct Cliente
 * @param indice_da_conta inteiro contendo o índice da conta a ser movimentada
 * está no array
 * @see encontrar_conta()
 */
int saque_deposito_conta(int operacao, Cliente c[], int indice_da_conta) {
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
  if (valor_saque_dep > c[indice_da_conta].saldo_atual && operacao == 1) {
    printf("Quantia desejada maior que saldo disponível, por favor, "
           "escolha um valor entre: R$0.00 - R$%.2lf\n\n",
           c[indice_da_conta].saldo_atual);
    sleep(1);
    return saque_deposito_conta(operacao, c, indice_da_conta);
  } else {
    printf("Preparando para realizar o %s...\n\n", mensagem_operacao);
    sleep(2);
    if (operacao == 1) {
      c[indice_da_conta].saldo_atual =
          c[indice_da_conta].saldo_atual - valor_saque_dep;
    } else {
      c[indice_da_conta].saldo_atual =
          c[indice_da_conta].saldo_atual + valor_saque_dep;
    }
    return 0;
  }
}

/** Transferência entre Contas()
 * Realiza a transferência de dinheiro para outra conta cadastrada. Esta função
 * tem uma taxa fixa de R$ 22.50 a ser paga no momento da transferência
 * @param c[] array da struct Cliente
 * @param indice_da_conta inteiro contendo o indice da conta em movimentação no
 * array
 * @see movimentar_conta
 * @see encontrar_conta
 */
int transferencia_entre_contas(Cliente c[], int indice_da_conta) {
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
    return transferencia_entre_contas(c, indice_da_conta);
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
      c[indice_da_conta].saldo_atual =
          c[indice_da_conta].saldo_atual - valor_transferencia - 22.50;
      c[indice_conta_destino].saldo_atual =
          c[indice_conta_destino].saldo_atual + valor_transferencia;
    }
    return 0;
  }
}

/** Pix entre contas()
 * Função para transferir dinheiro entre contas sem taxas a pagar. É necessário
 * saber o pix da conta destino
 * @see encontrar_pix()
 * @param c[] array do struct Cliente
 * @param indice_da_conta inteiro contendo o indice da conta movimentada no
 * array
 */
int pix_entre_contas(Cliente c[], int indice_da_conta) {
  double valor_pix;
  char tmp_file_agencia_name[16] = "agency_copy.tbd";
  int pix_destino;
  printf("\nDigite a quantidade que deseja transferir: ");
  scanf("%lf", &valor_pix);
  if (valor_pix > c[indice_da_conta].saldo_atual) {
    printf("Quantia desejada maior que saldo disponível, por favor, "
           "escolha um valor entre: R$0.00 - R$%.2lf\n\n",
           c[indice_da_conta].saldo_atual);
    sleep(1);
    return transferencia_entre_contas(c, indice_da_conta);
  } else {
    printf("Informe o pix da conta que receberá este valor: ");
    scanf("%d", &pix_destino);
    int indice_pix_destino;
    indice_pix_destino = encontrar_pix(c, pix_destino, 10);
    if (indice_pix_destino == 20) {
      printf("Não existe nenhuma chave PIX como a informada! \nRetornando ao "
             "menu gerencial");
      return 0;
    } else {
      printf("Preparando para realizar o PIX...\n\n");
      sleep(2);
      c[indice_da_conta].saldo_atual =
          c[indice_da_conta].saldo_atual - valor_pix;
      c[indice_pix_destino].saldo_atual =
          c[indice_pix_destino].saldo_atual + valor_pix;
    }
    return 0;
  }
}

/** Movimentar Conta()
 * Menu de movimentação da conta, podendo escolher 4 opções de movimentação ou
 * voltar ao menu anterior
 * @param c[] array do struct Cliente
 * @param indice_da_conta inteiro com o índice da conta a ser movimentada
 * @param tamanho_agencia inteiro contendo a quantidade total de clientes
 * cadastrados
 */
int movimentar_conta(Cliente c[], int indice_da_conta, int tamanho_agencia) {
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
      saque_deposito_conta(opcao, c, indice_da_conta);
      opcao = 0;
      break;
    case 3:
      pix_entre_contas(c, indice_da_conta);
      break;
    case 4:
      transferencia_entre_contas(c, indice_da_conta);
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

/** Cria conta Cliente()
 * Função para a criação de uma nova conta e seu armazenamento diretamente no
 * struct na próxima posição vazia
 * @param c[] array do struct Cliente
 * @param tamanho_agencia inteiro contendo a quantidade de clientes cadastrados
 */
void cria_conta_cliente(Cliente *c, int tamanho_agencia) {
  int verifica_conta = 0, verifica_agencia = 0, chave_pix = 0;
  if (tamanho_agencia == 10) {
    printf("A agência está cheia e, infelizmente, não comportamos mais "
           "clientes.\nMas não fique chateado, estamos em constante "
           "crescimento e em breve teremos mais espaço em nossos cofres\n\n ");
  } else {
    c[tamanho_agencia].codigo_cliente = tamanho_agencia + 1;
    printf("Muito bem, precisaremos de alguns dados do cliente\nPor favor, "
           "digite o Primeiro nome do Cliente\nObs: Se for nome composto, "
           "indique só o primeiro. (Ex: Ana Júlia, indique só Ana)\nNome: ");
    scanf("%s", c[tamanho_agencia].nome_cliente);
    printf("Agora, escreva o último sobrenome do cliente: ");
    scanf("%s", c[tamanho_agencia].sobrenome_cliente);
    printf("Digite o número da conta: ");
    while (verifica_conta == 0) {
      scanf("%d", &verifica_conta);
      if (encontrar_conta(c, verifica_conta, tamanho_agencia) == 20) {
        c[tamanho_agencia].conta_corrente = verifica_conta;
      } else {
        if (encontrar_conta(c, verifica_conta + 123, tamanho_agencia) == 20) {
          c[tamanho_agencia].conta_corrente = verifica_conta + 123;
          printf("A conta indicada já existe.\nPor padrão, adicionamos 123"
                 "unidades ao valor inserido\nNúmero da Conta Corrente do "
                 "cliente %s %s: %d \n",
                 c[tamanho_agencia].nome_cliente,
                 c[tamanho_agencia].sobrenome_cliente,
                 c[tamanho_agencia].conta_corrente);
        } else {
          printf("Conta já existente e o padrão não pode ser aplicado\nDigite "
                 "outro número da conta");
          verifica_conta = 0;
        }
      }
    }
    while (verifica_agencia == 0) {
      printf("por fim, indique a agência na qual a conta será criada, "
             "lembrando:\n123 - Mogi Guaçu\t\t125 - Mogi Mirim\n129 - "
             "Itapira\t\t\t130 - Estiva Gerbi\n\n Agência: ");
      scanf("%d", &verifica_agencia);
      switch (verifica_agencia) {
      case 123:
      case 125:
      case 129:
      case 130:
        c[tamanho_agencia].agencia_num = verifica_agencia;
        break;
      default:
        printf("Por favor, digite uma agência existente\n\n");
        sleep(1);
        verifica_agencia = 0;
        break;
      }
    }
    printf("Agora iremos criar a chave pix para esta conta!\nO padrão são "
           "quatro números, podendo inserir mais ou menos\n");
    printf("Informe a chave desejada: ");
    while (chave_pix == 0) {
      scanf("%d", &chave_pix);
      if (encontrar_pix(c, chave_pix, tamanho_agencia) == 20) {
        c[tamanho_agencia].chave_pix = chave_pix;
      } else {
        if (encontrar_pix(c, chave_pix + 130, tamanho_agencia) == 20) {
          c[tamanho_agencia].chave_pix = chave_pix + 130;
          printf(
              "Tal chave já consta em nosso sistema\nPor padrão adicionamos "
              "130 unidades à chave pix informada para criar uma nova\nChave "
              "PIX da conta do cliente %s %s: %d",
              c[tamanho_agencia].nome_cliente,
              c[tamanho_agencia].sobrenome_cliente,
              c[tamanho_agencia].chave_pix);
        } else {
          printf("Chave PIX já consta no sistema e o padrão não pôde ser "
                 "aplicado\nPor favor, digite uma chave diferente: ");
          chave_pix = 0;
        }
      }
    }
  }
}
