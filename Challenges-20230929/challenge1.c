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
  float round[3][3], podium[3];
  int motorcycles[3];
  int avaliation=1, option; 
  bool notAvailable[3];
  char moto1[], moto2[], moto3[];
  moto1[] = 'Suzuki Hayabusa';
  moto2[] = 'Honda CBR 1000RR-R Fireblade';
  moto3[] = 'BMW S1000 RR';

  for (int i=0;i<3;i++) 
  {
    notAvailable[i] = true;
  } 

  printf("Seja bem-vindo à Vistoria do Indiano\nAqui analisamos as três melhores motos do mercado.\n\n");
  printf("Nossas motos:\n1.Suzuki Hayabusa\n2.Honda CBR 1000RR-R Fireblade\n3.BMW S1000 RR\n");
  while (avaliation<=3) 
  {
    printf("\nDigite qual dessas motos você quer analisar: ");
    scanf("%d", &option);
    if (option==1) 
    {
      if (notAvailable[0]) 
      {
        notAvailable[0] = false;
        printf("Analisando a moto: Suzuki Hayabusa\n");
        for (int i=0;i<3;i++) 
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
        notAvailable[1] = false;
        printf("Analisando a moto: Honda CBR 1000RR-R Fireblade\n");
        for (int i=0;i<3;i++) 
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
    }
    else if (option==3) 
    {
      if (notAvailable[2]) 
      {
        notAvailable[2] = false;
        printf("Analisando a moto: BMW S1000 RR\n");
        for (int i=0;i<3;i++) 
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
    }
    else
    {
      printf("Por favor, digite um número de um a três, conforme descrito\n");
    }
  }

  
  float lessTime[3][2];
  for (int i=0;i<3;i++) 
  {
    if (round[i][0] > round[i][1] && round[i][0]>round[i][2]) 
    {
      lessTime[i][0] = round[i][1];
      lessTime[i][1] = round[i][2];
    }
    else if (round[i][1] > round[i][0] && round[i][1]>round[i][2]) 
    {
      lessTime[i][0] = round[i][0];
      lessTime[i][1] = round[i][2];
    }
    else 
    {
      lessTime[i][0] = round[i][0];
      lessTime[i][1] = round[i][1];
    }
  }
  

  float media[3];
  for (int i=0;i<3;i++) 
  {
    media[i] = (lessTime[i][0] + lessTime[i][1])/2;
  }

  if (media[0] < media[1] && media[0] < media[2]) {
    podium[0] = media[0];
    motorcycles[0] = 1;
    if (media[1] < media[2]) {
      podium[1] = media[1];
      podium[2] = media[2];
      motorcycles[1] = 2;
      motorcycles[2] = 3;
    }else {
      motorcycles[1] = 3;
      motorcycles[2] = 2;
      podium[1] = media[2];
      podium[2] = media[1];
    }
  }
  else if (media[1] < media[0] && media[1] < media[2]) {
    motorcycles[0] = 2;
    podium[0] = media[1];
    if (media[0] < media[2]) {
      podium[1] = media[0];
      podium[2] = media[2];
      motorcycles[1] = 1;
      motorcycles[2] = 3;
    }else {
      podium[1] = media[2];
      podium[2] = media[0];
      motorcycles[1] = 3;
      motorcycles[2] = 1;
    }
  }else if (media[2] < media[1] && media[2] < media[0]) {
    podium[0] = media[2];
    motorcycles[0] = 3;
    if (media[1] < media[0]) {
      podium[1] = media[1];
      podium[2] = media[0];
      motorcycles[1] = 2;
      motorcycles[2] = 1;
    }else {
      podium[1] = media[0];
      podium[2] = media[1];
      motorcycles[1] = 1;
      motorcycles[2] = 2;
    }
  }

  printf("Com base nos dados das voltas apresentados, chegamos à seguinte conclusão:\n\nEm primeiro lugar ficou a %dª moto, com média de %.3f segundos\nEm segundo lugar ficou a %dª moto com média de %.3f segundos\nEm terceiro lugar ficou a %dª moto com média de %.3f segundos\n\n", motorcycles[0], podium[0], motorcycles[1], podium[1], motorcycles[2], podium[2]);
  return EXIT_SUCCESS;
}
