#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool continuar(){
  int resposta=0;
  while (resposta==0) {
    printf("Deseja continuar o programa?\n1. SIM\n2. NÃO\n");
    scanf("%i",&resposta);
    switch (resposta) {
      case 1:
        return true;
        break;
      case 2:
        return false;
        break;
      default:
      printf("Escolha uma opção entre 1 e 2.\n");
      resposta = 0;
      break;
    }
  }
}

int exe01(){
  char nomeFunc[100];
  float salarioAtual, salarioAumentado, descontoINSSAtualizado, valorAumento, salarioFinal, aliquotaINSS;
  printf("Cálculo de Aumento Salarial\n");
  printf("Digite o nome do funcionáro:\n");
  scanf("%s", &nomeFunc);
  printf("Digite o salário do(a) Sr.(a) %s → \n", nomeFunc);
  scanf("%f",&salarioAtual);
  valorAumento = salarioAtual *0.1;
  salarioAumentado = salarioAtual * 1.10;
  if (salarioAumentado <= 1100) {
    aliquotaINSS = 0.08;  
  } else if (salarioAumentado >= 1101 && salarioAumentado <= 1890 ) {
    aliquotaINSS = 0.11;
  } else if (salarioAumentado >= 1891 && salarioAumentado <= 4200) {
    aliquotaINSS = 0.18;
  } else if (salarioAumentado > 4200) {
    aliquotaINSS = 0.19;
  }
  descontoINSSAtualizado = salarioAumentado * aliquotaINSS;
  salarioFinal = salarioAumentado - descontoINSSAtualizado;

  printf("Perfeito, fizemos os cálculos para você!\n\nNome do funcionário: %s\n\nSalário Anterior: R$ %.2f\nValor Aumento: R$ %.2f;\nSalário Bruto (Aumentado): R$ %.2f\nDesconto do INSS: R$ %.2f\nSalário Liquido Final: R$ %.2f\n\n\n", nomeFunc, salarioAtual, valorAumento, salarioAumentado, descontoINSSAtualizado, salarioFinal);
  
}

int exe02(){
  char nomeCandidato[200];
  int heigthCand;
  float weigthCand, notaCand;
  bool aprovado;
  printf("Ingresso na aeronáutica 2023 - Via FATEC\n");
  printf("Digite seu nome caro candidato: ");
  scanf("%s",&nomeCandidato);
  printf("Digite sua altura em centimetros (ex: 150cm = 1,5m): ");
  scanf("%i", &heigthCand);
  printf("Agora digite seu peso em Kg: ");
  scanf("%f",&weigthCand);
  printf("Por fim, informe-nos sua nota da prova: ");
  scanf("%f",&notaCand);

  if (heigthCand > 170 && weigthCand < 80 && notaCand >=9) {
    aprovado = true;
  } else if (notaCand == 10) {
    aprovado = true;
  } else {
    aprovado = false;
  }

  if (aprovado) {
    printf("Parabéns caro candidato %s, você foi APROVADO!\n", nomeCandidato);
  } else {
    printf("Infelizmente a candidatura de %s não passou nos requisitos necessários e você está DESQUALIFICADO\n", nomeCandidato);
  }
}

int exe03(){
  int pid;
  float aid, res;
  printf("Peso Ideal\n\n");
  printf("Digite seu Peso em Kg: ");
  scanf("%d", &pid);
  printf("\nAgora digite sua altura em metros: ");
  scanf("%f", &aid);
  res = (pid / (aid * aid));
  //printf("%f\n", res);
  if (res < 20) {
    printf("Você está abaixo do peso ideal\n");
  } else if (res>=20 && res < 25) {
    printf("Você está no Peso Ideal\n");
  } else if (res >=25) {
    printf("Você está acima do peso\n");
  }

}

int main(int argc, char *argv[])
{
  /* Declaração de Variáveis*/
  int menuExercicio;
  bool menu = true;

  /* Inicialização */
  printf("Exercícios do dia 01-09\n");
  printf("Criados por: Gabriel Coelho Soares\n\n");

  /* Loop de exercícios */
  while (menu) {
    printf("Digite o número do exercício que você deseja executar:\n");
    printf("1. Exercício 01\n2. Exercício 02\n3. Exercício 03\n\n0. Terminar o programa\n\nDigite sua escolha: ");
    scanf("%d", &menuExercicio);

    switch (menuExercicio) {
      case 1:
        exe01();
        menu = continuar();
        break;
      case 2:
        exe02();
        menu = continuar();
        break;
      case 3:
        exe03();
        menu = continuar();
        break;
      case 0:
        menu = false;
        break;
      default: printf("Escolha uma opção existente!\n"); break;
    }
  }
  /* Finalização */
  printf("Obrigado por utilizar nosso programa!\n");

  return EXIT_SUCCESS;
}
