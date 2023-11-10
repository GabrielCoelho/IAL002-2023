#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char menuMessage() {
  printf("***************************\n");
  printf("******* MENU ARRAY ********\n");
  printf("***************************\n");
  printf("\n1. Inserir número no vetor");
  printf("\n2. Exibir/Listar o vetor");
  printf("\n3. Consultar no vetor");
  printf("\n4. Ordenar o vetor (ascendente)");
  printf("\n5. Sair do programa");
}

int main(int argc, char *argv[]) {
  bool exit_menu = false, array_isnot_null = false;
  int menu_option, array_position = 1;
  int array[5];

  while (!exit_menu) {
    menuMessage();
    scanf("%d", &menu_option);
    switch (menu_option) {
    /* Inserir números no vetor */
    case 1:
      if (array_position > 5) {
        printf("Você já inseriu itens em todas as posições do vetor.\nPor "
               "favor, escolha outra opção\n\n");
        break;
      } else {
        printf(
            "Digite um número qualquer para inserirmos na posição %d do vetor",
            array_position);
        scanf("%d", &array[array_position]);
        array_position++;
        array_isnot_null = true;
      }
    /* Exibir o vetor */
    case 2:
    /* Consultar no vetor */
    case 3:
    /* Ordenar o vetor */
    case 4:
    /* sair do programa */
    case 5:
    /* Outros números digitados */
    default:
      printf("Por favor, digite um número que seja acessível no menu\n\n");
      break;
    }
  }

  return EXIT_SUCCESS;
}
