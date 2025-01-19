#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updatePointers(void **pBuffer, void **userOption, void **counterPeoples, void **peopleLenght, void **bufferSize, void **peoplesBuffer) {
  *userOption = *pBuffer;
  *counterPeoples = *pBuffer + sizeof(int);
  *peopleLenght = *pBuffer + sizeof(int) + sizeof(int);
  *bufferSize = *pBuffer + sizeof(int) + sizeof(int) + sizeof(size_t);
  *peoplesBuffer = *pBuffer + 2 * sizeof(int) + 2 * sizeof(size_t);
}

int removeTrailingNewLine(char *string, void **pBuffer, void **counterPeoples, void **peopleLenght, void **userOption, void **peoplesBuffer, void **endBuffer, void **bufferSize) {
  void *len;

  void *tempBuffer = (void *)realloc(*pBuffer, *(size_t *)*(bufferSize) + sizeof(size_t));
  if (tempBuffer == NULL) {
    return 1;
  }

  *pBuffer = tempBuffer;
  updatePointers(pBuffer, userOption, counterPeoples, peopleLenght, bufferSize, peoplesBuffer);
  *endBuffer = *pBuffer + *(size_t *)*(bufferSize) + sizeof(size_t);
  *(size_t *)*(bufferSize) = (size_t)(*endBuffer - *pBuffer);

  len = *endBuffer - sizeof(size_t);
  *(size_t *)len = strlen(string);
  if (*(size_t *)len > 0 && string[(*(size_t *)len) - 1] == '\n') {
    string[(*(size_t *)len) - 1] = '\0';
  }

  tempBuffer = (void *)realloc(*pBuffer, *(size_t *)*(bufferSize) - sizeof(size_t));
  if (tempBuffer == NULL) {
    return 1;
  }

  *pBuffer = tempBuffer;
  updatePointers(pBuffer, userOption, counterPeoples, peopleLenght, bufferSize, peoplesBuffer);
  *endBuffer = *pBuffer + *(size_t *)*(bufferSize) - sizeof(size_t);
  *(size_t *)*(bufferSize) = (size_t)(*endBuffer - *pBuffer);

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
  void *pBuffer, *endBuffer, *bufferSize, *tempBuffer, *userOption, *counterPeoples, *peopleLenght, *peoplesBuffer, *people, *searchName, *counter;

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
        tempBuffer = (void *)realloc(pBuffer, 2 * sizeof(int) + sizeof(size_t) + (*(int *)counterPeoples) * (*(size_t *)peopleLenght) + sizeof(int));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &peoplesBuffer, &endBuffer, &people);
        counter = endBuffer - sizeof(int);

        system("clear");
        printf("\n-------------- Listar Agenda --------------\n");
        for (*(int *)counter = 0; *(int *)counter < *(int *)counterPeoples; (*(int *)counter)++) {
          people = peoplesBuffer + (*(int *)counter) * (*(size_t *)peopleLenght);
          printf("Nome: %s\n", (char *)people);
          printf("Idade: %d\n", *(int *)(people + 50 * sizeof(char)));
          printf("E-Mail: %s\n", (char *)(people + 50 * sizeof(char) + sizeof(int)));
          printf("----------------------------------------------\n");
        }
        printf("\n");

        tempBuffer = (void *)realloc(pBuffer, 2 * sizeof(int) + sizeof(size_t) + (*(int *)counterPeoples) * (*(size_t *)peopleLenght));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &peopleLenght, &endBuffer, &people);

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