#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Primeiro Desafio
 * 3 motos e 3 voltas cada motos
 * temos um start e um fim em cada corrida. O que vai valer é o tempo de cada uma
 * o tempo será em segundos. 
 * (atribuir um tamanho do percurso e gerar números randomicos para cada moto?)
 * Objetivo Classificar as motos a partir da média dos dois melhores tempos dela. 
 * */

int main(int argc, char *argv[])
{
  //Variable Declaration
  float round[3][3];
  int motorcycles[3][3];
  int avaliation=1, option; 
  bool notAvailable[3];

  for (int x=0;i<3;i++) 
  {
    notAvailable[i] = true;
  } 

  printf("Seja bem-vindo à Vistoria do Indiano\nAqui analisamos as três melhores motos do mercado.\n\n");
  printf("Nossas motos:\n1.Suzuki Hayabusa\n2.Honda CBR 1000RR-R Fireblade\n3.BMW S1000 RR\n");
  while (avaliation<=3) 
  {
    printf("\nDigite qual dessas motos você quer analisar primeiro: ");
    scanf("%d", &option);
    notAvailable[option-1] = false;
    if (option==1) 
    {
      if (notAvailable[0]) 
      {
        printf("Analisando a moto: Suzuki Hayabusa\n");
        for (int i=0;i<3;int++) 
        {
          printf("Digite o tempo da %dª volta: \n", i+1);
          scanf("%f", &round[0][i]);
        }
        avaliation++;
      }
      else 
      {
        printf("Moto já analisada\n");
      }
    }
    else if (option==2) 
    {
      if (notAvailable[1]) 
      {
        printf("Analisando a moto: Honda CBR 1000RR-R Fireblade\n");
        for (int i=0;i<3;int++) 
        {
          printf("Digite o tempo da %dª volta: \n", i+1);
          scanf("%f", &round[1][i]);
        }
        avaliation++;
      }
      else 
      {
        printf("Moto já analisada\n");
      }
    else if (option==3) 
    {
      if (notAvailable[2]) 
      {
        printf("Analisando a moto: BMW S1000 RR\n");
        for (int i=0;i<3;int++) 
        {
          printf("Digite o tempo da %dª volta: \n", i+1);
          scanf("%f", &round[2][i]);
        }
        avaliation++;
      }
      else 
      {
        printf("Moto já analisada\n");
      }

    else
    {
      printf("Por favor, digite um número de um a três, conforme descrito\n");
    }
  }

   
  return EXIT_SUCCESS;
}
