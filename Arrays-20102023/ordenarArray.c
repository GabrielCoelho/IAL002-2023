#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int vetor[5];
  srand(time(NULL));
  printf("IREMOS ORDENAR O SEGUINTE VETOR\n");
  int vetor_ordenado[5], organizador, menor = 0;
  for (int i = 0; i < (sizeof vetor / sizeof vetor[0]); i++) {
    vetor[i] = (rand() % (25)) + 1;
    printf("[%d] -", vetor[i]);
    vetor_ordenado[i] = vetor[i];
    if (i == 4)
      printf("\n");
  }

  for (int i = 0; i < (sizeof vetor / sizeof vetor[0]); i++) {
    for (int j = 0; j < 5 - 1 - i; j++) {
      if (vetor_ordenado[j] > vetor_ordenado[j + 1]) {
        organizador = vetor_ordenado[j];
        vetor_ordenado[j] = vetor_ordenado[j + 1];
        vetor_ordenado[j + 1] = organizador;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    printf("- %d", vetor_ordenado[i]);
    if (i == 4)
      printf("\n");
  }
  return EXIT_SUCCESS;
}
