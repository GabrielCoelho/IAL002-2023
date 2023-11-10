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
  return 0;
}

int main(int argc, char *argv[]) {
  bool exit_menu = false, array_isnot_null = false;
  int menu_option, array_position = 1, sub_menu_search_option;
  int array[5];

  /* Inserindo valores "vazios" nas posições do vetor para caso o usuário queira
   * exibir antes de inserir todos os valores.
   */
  for (int i = 0; i < (sizeof array / sizeof array[0]); i++) {
    array[i] = 0;
  }

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
      if (array_isnot_null) {
        printf("Exibindo o vetor de 5 posições das quais você já inseriu: %d "
               "números\n",
               array_position > 5 ? array_position : array_position - 1);
        for (int i = 0; i < 5; i++) {
          printf("Vetor[%d]: %d\n", i + 1, array[i]);
        }
      } else {
        printf("Você ainda não inseriu nada no vetor. Por favor, passe pela "
               "opção de inserir\n");
      }
    /* Consultar no vetor */
    case 3:
      if (array_isnot_null) {
        printf("Escolha uma opção:\n1. Pesquisa por número\n2. Pesquisa por "
               "posição\nOu qualquer outro número para voltar ao menu "
               "principal\n\n");
        scanf("%d", &sub_menu_search_option);
        switch (sub_menu_search_option) {
        case 1:
        case 2:
        default:
        }
      }
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
