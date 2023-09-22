#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arrayExample[5], i;
  int number;

  printf("Inform us an integer number\n");
  scanf("%d", &number);
  for (i=0;i<(sizeof arrayExample / sizeof arrayExample[0]);i++) 
  {
    arrayExample[i] = number -(i+1);
  }

  /** Older version of this example
   * printf("Inform us 5 numbers below\n");
  for (i=0;i<(sizeof arrayExample / sizeof arrayExample[0]);i++) 
  {
    scanf("%d", &arrayExample[i]);
  }*/
  printf("The result is:\n");
  for (i=0;i<(sizeof arrayExample / sizeof arrayExample[0]);i++) 
  {
    printf("%d \n", arrayExample[i]); 
  }

  return EXIT_SUCCESS;
}
