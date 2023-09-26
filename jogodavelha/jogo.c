#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char jogador, velha[3][3];
  int rodada = 1; 
  bool jogo = true;

  for (int x;x<3;x++) {
    for (int y;y<3;y++) {
      velha[x][y] = ' ';
    }
  }
  printf("Bem vindo ao jogo da velha\n");
  printf("   1   |    2   |    3    \n");
  printf("       |        |        1 \n");
  printf("--------------------------\n");
  printf("       |        |        2 \n");
  printf("--------------------------\n");
  printf("       |        |        3 \n");
  int linha, coluna;
  while (jogo) 
  {
    if (rodada%2!=0) 
    {
      jogador = 'X';
    }else 
    {
      jogador = 'O';
    }
    linha = 0; 
    coluna = 0; 
    while (linha==0) 
    {
    printf("\n\n Por favor, digite uma posição para o jogador %c \nDigite o valor da linha: ", jogador);
    scanf("%d", &linha);
      if(linha > 3 || linha <= 0)
      {
        printf("Informe a linha dentro do padrão disposto, isto é, 1 - 2 ou 3!\n");
        linha = 0;
      }
    }
    while(coluna==0)
    {
      printf("Agora informe o valor da coluna\n");
      scanf("%d", &coluna);
      if(coluna > 3 || linha <= 0)
      {
        printf("Informe a coluna dentro do padrão disposto, isto é, 1 - 2 ou 3!\n");
        coluna = 0; 
      }
    }
    linha -=1;
    coluna -=1;
    if(!velha[linha][coluna])
    {
      velha[linha][coluna] = jogador;
    }
    for (int i=0;i<3;i++) 
    {
      for (int j=0;j<3;j++) {
        if(j==2){
          printf("   %c   \n", velha[i][j]);
        }else{
          printf("   %c   |", velha[i][j]);
        }
      }
    }
    if (rodada <9) 
    {
      rodada++;
      if(rodada >=6)
      {
        for (int i=0;i<3;i++) 
        {
          if (((velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2]) && velha[i][1] == velha[i][2])) 
          {
            jogo = false;
            printf("o Jogador %c ganhou a partida (primeiro if)\n", jogador);
            return 0;
          }
          else if ((velha[0][i] == velha[1][i] && velha[0][i] == velha[2][i]) && velha[1][i] == velha[2][i]) 
          {
            jogo = false;
            printf("o Jogador %c ganhou a partida (segundo if)\n", jogador);
            return 0;
          }
          else if (velha[0][0] == velha[1][1] && velha[0][0] == velha[2][2]) 
          {
            jogo = false;
            printf("o Jogador %c ganhou a partida (terceiro if)\n", jogador);
            return 0;
          }
          else if (velha[0][2] == velha[1][1] && velha[0][2] == velha[2][0]) 
          {
            jogo = false; 
            printf("o Jogador %c ganhou a partida (quarto if)\n", jogador);
            return 0;
          }
        }
      }
    }
    else 
    {
      printf("Deu velha\n");
      jogo = false;
    }
  }
  return EXIT_SUCCESS;
}
