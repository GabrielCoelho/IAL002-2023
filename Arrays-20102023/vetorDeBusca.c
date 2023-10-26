#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;
  printf("\n qual a dimensão do vetor: ");
  scanf("%d", &tamanho);
  int vetor[tamanho];
  int metade = if tamanho % 2 == 0 ? tamanho / 2 : tamanho / 2 + 1;

  return 0;
}
