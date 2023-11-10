#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int array_length_desired;
  printf("Inform a number to be the total Length of the array: ");
  scanf("%d", &array_length_desired);

  int array_to_be_ordered[array_length_desired],
      ordered_array[array_length_desired];
  for (int i = 0;
       i < (sizeof array_to_be_ordered / sizeof array_to_be_ordered[0]); i++) {
    array_to_be_ordered[i] = (rand() % (100)) + 1;
    ordered_array[i] = array_to_be_ordered[i];
    if (i == (0 + ((sizeof ordered_array / sizeof ordered_array[0]) - 1))) {
      printf("%d\n", array_to_be_ordered[i]);
    } else {
      printf("%d - ", array_to_be_ordered[i]);
    }
  }

  int tmp = 0;
  for (int i = 0; i < (sizeof ordered_array / sizeof ordered_array[0]); i++) {
    for (int j = i + 1; i < (sizeof ordered_array / sizeof ordered_array[0]);
         j++) {
      if (ordered_array[i] > ordered_array[j]) {
        tmp = ordered_array[i];
        ordered_array[i] = ordered_array[j];
        ordered_array[j] = ordered_array[i];
      }
    }
  }

  for (int i = 0; i < (sizeof ordered_array / sizeof ordered_array[0]); i++) {
    if (i == ((sizeof ordered_array / sizeof ordered_array[0]) - 1))
      printf("%d \n", ordered_array[i]);
    else
      printf("%d -", ordered_array[i]);
  }

  return EXIT_SUCCESS;
}
