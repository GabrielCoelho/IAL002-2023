#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Função para retornar o menu
 */
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
  /* Declaração de variáveis
   * VARIÁVEIS BOOLEANAS
   *  exit_menu para sair do programa;
   *  array_isnot_null para verificar se já inseriram algum valor no vetor;
   *  found_searched_number para verificar se o número pesquisado foi
   * encontrado;
   *
   * VARIÁVEIS INTEIRAS
   *  menu_option que o usuário irá selecionar no menu;
   *  array_position para informar o usuário qual posição ele está inserindo no
   * vetor, bem como mostrar quantos números já foram inseridos ao entrar na
   * segunda opção do menu;
   *
   *  sub_menu_option funciona como o menu_option mas para eventuais menus
   * internos;
   *
   *  search recebe o termo de pesquisa (número ou posição);
   *  found_searched_position recebe a posição do vetor em que o número
   * pesquisado foi encontrado;
   *
   *  tmp_organizer é uma variável temporária para armazenar o maior valor na
   *  hora de ordenar o vetor;
   *
   *  array[5] vetor de 5 posições (0-4) que será trabalhado durante o programa.
   */
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

  /* exit_menu recebe um valor falso assim que foi declarado. Assim, enquanto
   * ele for falso, isto é, enquanto o usuário não sair do menu, o código irá se
   * repetir.
   */
  while (!exit_menu) {
    menuMessage();             // Chama a função de exibir o menu
    scanf("%d", &menu_option); // recebe a opção desejada pelo usuário
    switch (menu_option) {
      /* Menu 1 - Inserir no vetor
       * O código abaixo verifica se o usuário já inseriu em todas as posições
       * disponíveis e, se não, passa a inserir um número por vez, sempre
       * retornando ao menu, dando a possibilidade do usuário verificar os
       * números inseridos.
       */
    case 1:
      if (array_position > 5) {
        printf("Você já inseriu itens em todas as posições do vetor.\nPor "
               "favor, escolha outra opção\n\n");
        break;
      } else {
        printf("Digite um número qualquer para inserirmos na posição %d do "
               "vetor: ",
               array_position);
        scanf("%d", &array[array_position -
                           1]); // array_position começa em 1, temos de tirar 1
                                // para inserir, pois o vetor começa em 0.
        array_position++;       // adicionamos um passo na posição
        array_isnot_null =
            true; // assim que entra aqui, liberamos os demais itens do menu
                  // para serem executados, pois já há um valor novo no vetor
                  // inserido pelo usuário
      }
      break;

      /* Menu 2 - Exibir o vetor
       * Verifica se o vetor já possui algum valor inserido pelo usuário. Caso
       * não, pede que seja inserido, pois não há vetor para exibir; caso sim,
       * exibe o vetor. Obs: os 0s nos locais em que o usuário não inseriu nada
       * é o padrão deste código, para não exibir nenhum "lixo" existente.
       */
    case 2:
      if (array_isnot_null) {
        printf(
            "Exibindo o vetor de 5 posições das quais você já inseriu: %d/5 "
            "números\n",
            array_position > 5
                ? 5
                : array_position -
                      1); // Operador condicional ternário, uma simplificação de
                          // um "if". O array_position, quando o usuário
                          // terminar de inserir em todas as posições, valerá
                          // "6". Assim, esta porção do código funciona da
                          // seguinte maneira: "se array_position for maior que
                          // 5, imprime 5; senão imprime array_position - 1".
        for (int i = 0; i < 5; i++) {
          printf("Vetor[%d]: %d\n", i + 1, array[i]);
        }
      } else {
        printf("Você ainda não inseriu nada no vetor. Por favor, passe pela "
               "opção de inserir\n");
      }
      break;

      /* Menu 3 - pesquisar
       * Implementei dois tipos de pesquisa: 1 - por número; 2 - por posição.
       * Assim o usuário pode decidir o que ele deseja pesquisar.
       *
       * POR NÚMERO:
       * solicito o número ao usuário e passo por todo o vetor checando se o
       * valor da posição "i" é igual ao número pesquisado. Caso seja um match
       * perfeito, o código quebra o laço armazenando, na variável
       * found_searched_number, o valor verdadeiro. Há também a variável
       * found_searched_position que sempre irá receber, no início do laço o
       * valor do iterador + 1, pois, assim que encontrar, ele será a posição
       * encontrada. No caso de não encontrar, apenas retorno que não foi
       * encontrado.
       *
       *
       * POR POSIÇÃO:
       * solicito ao usuário uma posição (1-5) a ser interpretada como 0-4 pelo
       * código e retorno o valor presente nela. Caso retorne 0 numa posição que
       * o usuário ainda não digitou, é pelo padrão escolhido para o programa a
       * fim de não retornar "lixo"
       */
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

      /* MENU 4 - Ordenar
       *
       * Fazemos duas verificações logo no início. A primeira para ver se o
       * usuário já digitou alguma informação no vetor; a segunda caso ele tenha
       * iniciado mas não tenha terminado de digitar todas as posições. Esta
       * segunda foi criada para evitar do usuário ordenar o vetor contendo 0
       * por padrão escolhido. Suponha que o usuário tenha entrado com 3 valores
       * de 5 e tenha ordenado. O resultado seria: "[0][0][x][y][z]". No
       * entanto, caso ele quisesse inserir mais números, a próxima posição para
       * inserir seria a posição 4, que já contém o valor y inserido pelo
       * usuário, causando a sobrescrita de valores.
       */
    case 4:
      if (array_isnot_null) {
        if (array_position <= 5) {
          printf("Por favor, termine de inserir números no array, pois somente "
                 "\nserá possível ordená-lo caso ele esteja completo!\n");
        } else {
          for (int i = 0; i < (sizeof array / sizeof array[0]); i++) {
            for (int j = 0; j < (sizeof array / sizeof array[0]) - 1 - i;
                 j++) { // A condicional deste laço funciona da seguinte
                        // maneira: eu irei passar por todas as posições do
                        // array - 1 - i. "-1" pois ao chegar na penúltima
                        // posição, estamos verificando ela e a próxima (linha
                        // do if abaixo). "-i" pois, uma vez que eu já tenha
                        // armazenado o maior valor na última posição, eu não
                        // preciso verificá-la novamente. Caso tenha dúvidas,
                        // verificar o exemplo abaixo.
              if (array[j] > array[j + 1]) {
                tmp_organizer = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp_organizer;
              }
              /* Exemplificando com o seguinte vetor: [4][5][2][3][1].
               * i= 0 (j vai de 0 a (4-1-0) = 3)
               *    j=0 › 4 é maior do que 5? não (next);
               *    j=1 › 5 é maior do que 2? sim, troca de lugar, array=
               * [4][2][5][3][1];
               *    j=2 › 5 é maior do que 3? sim, troca de lugar,
               * array= [4][2][3][5][1];
               *    j=3 › 5 é maior do que 1? sim, troca de
               * lugar, array= [4][2][3][1][5];
               *
               * i= 1 (j vai de 0 a (4-1-1) = 2)
               *    j=0 › 4 é maior do que 2? sim, troca de lugar, array=
               * [2][4][3][1][5];
               *    j=1 › 4 é maior do que 3? sim, troca de lugar,
               * array= [2][3][4][1][5];
               *    j=2 › 4 é maior do que 1? sim, troca de
               * lugar, array= [2][3][1][4][5];
               *
               * i= 2 (j vai de 0 a (4-1-2) = 1)
               *    j=0 › 2 é maior do que 3? não, (next);
               *    j=1 › 3 é maior do que 1? sim, troca de lugar, array=
               * [2][1][3][4][5];
               *
               * i=3 (j vai de 0 a (4-1-3) = 0 (rodará somente uma vez))
               *    j=0 › 2 é maior do que 1? sim, troca de lugar, array=
               * [1][2][3][4][5];
               *
               * i=4, for j não roda;
               * i=5, for j não roda;
               */
            }
          }
          /* Exibimos que o vetor foi ordenado e damos a opção do usuário já
           * mostrar ele ordenado
           */
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

      /* Sai do programa exibindo uma mensagem.
       */
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
