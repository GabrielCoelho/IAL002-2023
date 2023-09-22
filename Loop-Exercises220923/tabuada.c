#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i, tabuada;
  printf("Please, inform a number to our Multiplication Table\n");
  scanf("%d", &tabuada);

  for(i=0;i<=10;i++)
  {
    printf("%d x %d = %d\n", i, tabuada, (i*tabuada));
  }

  return EXIT_SUCCESS;
}
