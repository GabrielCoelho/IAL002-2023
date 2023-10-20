#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Cópia do código escrito na prova
int exercicio05() {
  int numero;
  printf("Digite um número: ");
  scanf("%d", &numero);
  for (int i = 1; i < numero; i++) {
    if (i % 2 == 0) {
      printf("\n %d", i);
    }
  }
  return 0;
}

// Cópia do código escrito na prova
int exercicio06() {
  int qntVd, qntComp;
  char nomeProduto[100];
  float valorUnit, valorTot = 0;
  printf("Informe a quantidade de produtos vendidos:");
  scanf("%d", &qntVd);
  float valorSub[qntVd];
  for (int i = 0; i < qntVd; i++) {
    printf("%d Produto", (i + 1));
    printf("digite o nome do produto");
    scanf("%s", &nomeProduto);
    printf("Agora informe o valor unitário do %s", nomeProduto);
    scanf("%", &valorUnit);
    printf("por fim, informe a quantidade adiquirida do %s", nomeProduto);
    scanf("%d", &qntComp);

    valorSub[i] = qntComp * valorUnit;
    printf("O produto %s de valor unitário %.2f, sendo comprado em %d "
           "unidades, resultou no sub total de %.2f\n",
           nomeProduto, valorUnit, qntComp, valorSub[i]);
    valorTot = valorTot + valorSub[i];
  }
  printf("\n\nO valor total da compra dos %d itens foi de:\n R$.2f", qntVd,
         valorTot);
  return 0;
}

int main(int argc, char *argv[]) {
  exercicio05();
  exercicio06();
  return EXIT_SUCCESS;
}
