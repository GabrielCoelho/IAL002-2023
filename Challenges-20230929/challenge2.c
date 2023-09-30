#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Segundo Desafio
 * Campeonato de futebol, a partir de 2 vetores onde cada posição equivale ao mesmo jogo. 
 * Ou seja, a posiçao 0 para o vetor TIME1 e posição 0 do vetor TIME2 é o jogo 0 entre os dois times. 
 * O objetivo é gerar a tabela de pontuação a partir da seguinte tabela: 
 * - Vitória 3 pontos; Empate 1 ponto; Derrota 0 pontos. 
 * Após realizar a tabela, mostrar o ganhador, perdedor ou se deu empate. 
*/

int main(int argc, char *argv[]) { 
  printf("Campeonato de Futebol - Final\nTimes: Lancha Preta FC x Academia do Marcão");
  printf("\n");

  int lp[3], am[3];
  int pontLP=0, pontAM=0;

  for (int i=0;i<3;i++) {
    lp[i] = 0;
    am[i] = 0;
  }

  for (int i=0;i<3;i++) 
  {
    printf("digite o placar do %dº jogo:\nLancha Preta FC: ", (i+1));
    scanf("%d", &lp[i]);

    printf("\nAcademia do Marcão: ");
    scanf("%d", &am[i]);
  }

  for (int i=0;i<3;i++) 
  {
    if (lp[i] == am[i]) {
      pontLP = pontLP + 1;
      pontAM = pontAM + 1;
    }
    else if (lp[i] > am[i]) {
      pontLP = pontLP + 3;
    }else if (lp[i] < am[i]) {
      pontAM = pontAM + 3;
    }
  }

  if (pontLP > pontAM) {
    printf("O Vencedor da Grande Final foi o Lancha Preta FC com %d pontos\n", pontLP);
    printf("Academia do Marcão ficou com %d pontos\n", pontAM);
  }else if (pontLP<pontAM) {
    printf("O Vencedor da Grande Final foi a Academia do Marcão com %d pontos\n", pontAM);
    printf("Lancha Preta FC ficou com %d pontons\n", pontLP);
  }else if (pontLP == pontAM) {
    printf("Ambas as equipes empataram com %d pontos\n", pontLP);
  }
  return EXIT_SUCCESS; 
}
