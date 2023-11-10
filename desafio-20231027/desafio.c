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
  printf("\n5. Sair do programa\n");
  return 0;
}

int main(int argc, char *argv[]) {
  bool exit_menu = false, array_isnot_null = false,
       found_searched_number = false;
  int menu_option, array_position = 1, sub_menu_option, search,
                   found_searched_position, tmp_organizer;
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
        printf("Digite um número qualquer para inserirmos na posição %d do "
               "vetor: ",
               array_position);
        scanf("%d", &array[array_position - 1]);
        array_position++;
        array_isnot_null = true;
      }
      break;
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
      break;
    /* Consultar no vetor */
    case 3:
      if (array_isnot_null) {
        printf("Escolha uma opção:\n1. Pesquisa por número\n2. Pesquisa por "
               "posição\nOu qualquer outro número para voltar ao menu "
               "principal\n\n");
        scanf("%d", &sub_menu_option);
        switch (sub_menu_option) {
        case 1:
          printf("Digite um número para pesquisar no Vetor: ");
          scanf("%d", &search);
          for (int i = 0; i < (sizeof array / sizeof array[0]); i++) {
            found_searched_position = i + 1;
            if (array[i] == search) {
              found_searched_number = true;
              break;
            }
          }
          if (found_searched_number) {
            printf("\nO número %d foi encontrado no vetor na posição %d\n\n",
                   search, found_searched_position);
          } else {
            printf("\nO número %d não foi encontrado no vetor\n\n", search);
          }
          break;
        case 2:
          printf("Digite uma posição para retornarmos o valor existente "
                 "nela: ");
          scanf("%d", &search);
          if (search > 5 || search < 1) {
            printf("O Vetor tem posições de 1 a 5, por favor, insira um número "
                   "dentre estes\n");
          } else {
            printf("A posição %d escolhida possui o seguinte valor:\n "
                   "Vetor[%d]: %d\n\n",
                   search, search, array[search - 1]);
          }
          break;
        default:
          printf("Saindo deste sub-menu e retornando ao menu principal");
          break;
        }
      } else {
        printf("O vetor está vazio, não sendo possível pesquisar nele\n\n");
      }
      break;
    /* Ordenar o vetor */
    case 4:
      if (array_isnot_null) {
        if (array_position <= 5) {
          printf("Por favor, termine de inserir números no array, pois somente "
                 "\nserá possível ordená-lo caso ele esteja completo!\n");
        } else {
          for (int i = 0; i < (sizeof array / sizeof array[0]); i++) {
            for (int j = 0; j < (sizeof array / sizeof array[0]) - 1 - i; j++) {
              if (array[j] > array[j + 1]) {
                tmp_organizer = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp_organizer;
              }
            }
          }
          printf("O vetor foi ordenado! Deseja exibir?\n1. Sim\nOu qualquer "
                 "outro número para voltar ao menu principal\n");
          scanf("%d", &sub_menu_option);
          if (sub_menu_option == 1) {
            for (int i = 0; i < (sizeof array / sizeof array[0]); i++) {
              printf("Vetor[%d]: %d\n", i + 1, array[i]);
            }
          }
        }
      } else {
        printf("O vetor está vazio, não sendo possível ordená-lo\n\n");
      }
      break;
    /* sair do programa */
    case 5:
      printf("Saindo do programa...\n\n");
      exit_menu = true;
      break;
    /* Outros números digitados */
    default:
      printf("Por favor, digite um número que seja acessível no menu\n\n");
      break;
    }
  }

  return EXIT_SUCCESS;
}
