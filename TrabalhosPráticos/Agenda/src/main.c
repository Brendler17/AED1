#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updatePointers(void **pBuffer, void **userOption, void **counterPeoples, void **peopleLenght, void **peoplesBuffer, void **endBuffer, void **people) {
  *userOption = *pBuffer;
  *counterPeoples = *pBuffer + sizeof(int);
  *peopleLenght = *pBuffer + sizeof(int) + sizeof(int);
  *peoplesBuffer = *pBuffer + 2 * sizeof(int) + sizeof(size_t);
  *endBuffer = *peoplesBuffer + *((int *)(*counterPeoples)) * (*((size_t *)*(peopleLenght)));
  *people = *peoplesBuffer + (*((int *)*(counterPeoples)) - 1) * (*((size_t *)*(peopleLenght)));
}

int removeTrailingNewLine(char *string, void **pBuffer, void **counterPeoples, void **peopleLenght, void **userOption, void **peoplesBuffer, void **endBuffer, void **people) {
  void *len;

  void *tempBuffer = (void *)realloc(*pBuffer, 2 * sizeof(int) + sizeof(size_t) + (*((int *)*(counterPeoples))) * (*((size_t *)*(peopleLenght))) + sizeof(size_t));
  if (tempBuffer == NULL) {
    return 1;
  }

  *pBuffer = tempBuffer;
  updatePointers(pBuffer, userOption, counterPeoples, peopleLenght, peoplesBuffer, endBuffer, people);

  len = *endBuffer - sizeof(size_t);
  *(size_t *)len = strlen(string);
  if (*(size_t *)len > 0 && string[(*(size_t *)len) - 1] == '\n') {
    string[(*(size_t *)len) - 1] = '\0';
  }

  tempBuffer = (void *)realloc(*pBuffer, 2 * sizeof(int) + sizeof(size_t) + (*((int *)*counterPeoples)) * (*((size_t *)*peopleLenght)));
  if (tempBuffer == NULL) {
    return 1;
  }

  *pBuffer = tempBuffer;
  updatePointers(pBuffer, userOption, counterPeoples, peopleLenght, peoplesBuffer, endBuffer, people);

  return 0;
}

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
  void *pBuffer, *endBuffer, *tempBuffer, *userOption, *counterPeoples, *peopleLenght, *peoplesBuffer, *people;

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
        (*(int *)counterPeoples)++;
        tempBuffer = (void *)realloc(pBuffer, 2 * sizeof(int) + sizeof(size_t) + (*(int *)counterPeoples) * (*(size_t *)peopleLenght));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &peoplesBuffer, &endBuffer, &people);

        system("clear");
        printf("\n-------------- Adicionar Pessoa --------------\n");
        printf("Informe o nome: ");
        fgets(people, 50 * sizeof(char), stdin);
        if (removeTrailingNewLine(people, &pBuffer, &counterPeoples, &peopleLenght, &userOption, &peoplesBuffer, &endBuffer, &people)) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }
        printf("Informe a idade: ");
        scanf("%d", (int *)(people + 50 * sizeof(char)));
        getchar();
        printf("Informe o e-mail: ");
        fgets((people + 50 * sizeof(char) + sizeof(int)), 50 * sizeof(char), stdin);
        if (removeTrailingNewLine((people + 50 * sizeof(char) + sizeof(int)), &pBuffer, &counterPeoples, &peopleLenght, &userOption, &peoplesBuffer, &endBuffer, &people)) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        system("clear");
        printf("\nRegistro adicionado com sucesso!\n");

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
