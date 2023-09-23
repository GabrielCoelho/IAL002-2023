#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int quantityV, selectNumFrom, position;
  bool plausibleArray = false;
  while (!plausibleArray) {
  
    printf("Digite um número para o seu vetor: \n");
    scanf("%d", &quantityV);
    if (quantityV>10) 
    {
      printf("Escolha um número plausível para o Array (evite deixalo muito grande)\n\n");
    }else {
      plausibleArray = true;
    }
  }
  int dimensionalArray[quantityV];
  int midNumber; 
  if (quantityV%2 == 0) 
  {
    midNumber = quantityV/2;
  }
  else 
  {
    midNumber = (quantityV/2)+0.5; 
  }
  int i; 
  for (i=midNumber;i<quantityV;i++)
  {
    dimensionalArray[i] = rand()%(65)+25;
  }
  for(i=0;i<midNumber;i++)
  {
    dimensionalArray[i] = rand()%(25)+1;
  }
  printf("Seu array de %d posições retornou os seguintes números randômicos\n", quantityV);
  for (i=0;i<(sizeof dimensionalArray / sizeof dimensionalArray[0]);i++) 
  {
    if (i==(quantityV-1)) 
    {
      printf("%d\n", dimensionalArray[i]);
    }else 
    {

      printf("%d - ", dimensionalArray[i]);
    }
  }
  printf("\nAgora, nos informe um número inteiro e verificaremos se ele está presente no array randômico\n");
  scanf("%d",&selectNumFrom);
  for (i=0;i<(sizeof dimensionalArray / sizeof dimensionalArray[0]);i++) 
  {
    if (selectNumFrom == dimensionalArray[i]) 
    {
      printf("Encontramos o número!!!\n");
      position = i;
      
      printf("O número pesquisado (%d) está na %dª posição do seu array dinâmico\n", selectNumFrom, (position+0));
    }
    else if(!position)
    {
      printf("Não temos nenhum número %d em nosso array\n", selectNumFrom);

    }
  }
  if (!position) 
  {
    printf("Não foi encontrado o número procurado\nEncerrando o programa...");
  }
  return EXIT_SUCCESS;
}
