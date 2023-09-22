#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int peopleQuantity, age, i;
  double avAge, sumAge;
  sumAge=0;

  printf("Please, inform the quantity of peoples to get the Ages\n");
  scanf("%d", &peopleQuantity);

  for (i=0;i<peopleQuantity;i++) 
  {
    printf("\nInform us the age of the person %d: ", i+1);
    scanf("%d", &age);
    sumAge = sumAge+age;
  }
  avAge = sumAge/peopleQuantity;

  printf("The average age is: %.2f\n", avAge);
  return EXIT_SUCCESS;
}
