#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showMenu() {
  printf("\n-------------------- MENU --------------------\n");
  printf("1 - Adicionar Pessoa (Nome, Idade, E-Mail)\n");
  printf("2 - Remover Pessoa\n");
  printf("3 - Buscar Pessoa\n");
  printf("4 - Listar Todos\n");
  printf("5 - Sair\n");
  printf("----------------------------------------------\n");
}

int main(int argc, char const *argv[]) {
  void *pBuffer, *endBuffer, *userOption, *counterPeoples, *peopleLenght;

  pBuffer = (void *)malloc(2 * sizeof(int) + sizeof(size_t));
  if (pBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  userOption = pBuffer;
  counterPeoples = pBuffer + sizeof(int);
  peopleLenght = pBuffer + sizeof(int) + sizeof(int);
  endBuffer = pBuffer + 2 * sizeof(int) + sizeof(size_t);

  *(size_t *)peopleLenght = 50 * sizeof(char) + sizeof(int) + 50 * sizeof(char);
  *(int *)counterPeoples = 0;

  do {
    showMenu();
    printf("Digite uma opção: ");
    scanf("%d", (int *)userOption);
    getchar();

    switch (*(int *)userOption) {
      case 1:
        printf("Adicionar Pessoa");
        break;
      case 2:
        printf("Remover Pessoa");
        break;
      case 3:
        printf("Buscar Pessoa");
        break;
      case 4:
        printf("Listar Pessoas");
        break;
      case 5:
        printf("\nSaindo...\n\n");
        break;
      default:
        printf("\nOpção Inválida!\n");
        break;
    }
  } while (*(int *)userOption != 5);

  return 0;
}
