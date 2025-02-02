#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updatePointers(void **pBuffer, void **userOption, void **counterPeoples, void **bufferSize, void **peoplesBuffer, void **name, void **email, void **age) {
  *userOption = *pBuffer;
  *counterPeoples = *pBuffer + sizeof(int);
  *bufferSize = *pBuffer + 2 * sizeof(int);
  *peoplesBuffer = *pBuffer + sizeof(int) * 3 + sizeof(size_t) + 100 * sizeof(char);
  *name = *pBuffer + 2 * sizeof(int) + sizeof(size_t);
  *email = *pBuffer + 2 * sizeof(int) + sizeof(size_t) + 50 * sizeof(char);
  *age = *pBuffer + 2 * sizeof(int) + sizeof(size_t) + 100 * sizeof(char);
}

int getCurrentPerson(void **pBuffer, void **userOption, void **counterPeoples, void **bufferSize, void **peoplesBuffer, void **currentPerson, void **name, void **email, void **age) {
  void *tempBuffer, *endBuffer, *counter, *offset;

  tempBuffer = (void *)realloc(*pBuffer, *(size_t *)*(bufferSize) + sizeof(int));
  if (tempBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  *pBuffer = tempBuffer;
  tempBuffer = NULL;
  updatePointers(pBuffer, userOption, counterPeoples, bufferSize, peoplesBuffer, name, email, age);
  endBuffer = *pBuffer + (*(size_t *)*(bufferSize)) + sizeof(int);
  *(size_t *)*(bufferSize) = (size_t)(endBuffer - *pBuffer);

  counter = endBuffer - sizeof(int);
  offset = *age;

  if (*(int *)*(counterPeoples) == 0) {
    *currentPerson = NULL;
    return 1;
  }

  *(int *)offset = 0;
  for (*(int *)counter = 0; *(int *)counter < (*(int *)*(counterPeoples)-1); (*(int *)counter)++) {
    *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
    *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
    *(int *)offset += sizeof(int);
  }

  tempBuffer = (void *)realloc(*pBuffer, *(size_t *)*(bufferSize) - sizeof(int));
  if (tempBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  *pBuffer = tempBuffer;
  tempBuffer = NULL;
  updatePointers(pBuffer, userOption, counterPeoples, bufferSize, peoplesBuffer, name, email, age);
  endBuffer = *pBuffer + (*(size_t *)*(bufferSize)) - sizeof(int);
  *(size_t *)*(bufferSize) = (size_t)(endBuffer - *pBuffer);

  offset = *age;
  *currentPerson = *peoplesBuffer + *(int *)offset;

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
  void *pBuffer, *endBuffer, *bufferSize, *tempBuffer, *userOption, *counterPeoples, *peoplesBuffer, *currentPerson, *name, *email, *age, *counter;

  pBuffer = (void *)malloc(3 * sizeof(int) + sizeof(size_t) + 100 * sizeof(char));
  if (pBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
  endBuffer = pBuffer + 3 * sizeof(int) + sizeof(size_t) + 100 * sizeof(char);

  *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);
  *(int *)counterPeoples = 0;

  // printf("\nBufferSize Inicial: %zu\n", *(size_t *)bufferSize);

  do {
    showMenu();
    printf("Digite uma opção: ");
    scanf("%d", (int *)userOption);
    getchar();

    switch (*(int *)userOption) {
      case 1: {
        (*(int *)counterPeoples)++;
        // system("clear");
        printf("\n-------------- Adicionar Pessoa --------------\n");
        printf("Informe o nome: ");
        scanf(" %50[^\n]", (char *)name);
        getchar();
        printf("Informe o e-mail: ");
        scanf(" %50[^\n]", (char *)email);
        getchar();

        // printf("\nIdade: %d\n", *(int *)age);

        tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + (strlen((char *)name) + 1) * sizeof(char) + (strlen((char *)email) + 1) * sizeof(char) + sizeof(int));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        tempBuffer = NULL;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
        endBuffer = pBuffer + (*(size_t *)bufferSize) + (strlen(name) + 1) * sizeof(char) + (strlen(email) + 1) * sizeof(char) + sizeof(int);
        *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);
        printf("\nBufferSize ao adicionar pessoa: %zu\n", *(size_t *)bufferSize);

        getCurrentPerson(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age);
        printf("Informe a idade: ");
        scanf("%d", (int *)age);
        memcpy(currentPerson, name, (strlen(name) + 1) * sizeof(char));
        printf("Nome: %s\n", (char *)currentPerson);
        currentPerson += (strlen(name) + 1) * sizeof(char);

        memcpy(currentPerson, email, (strlen(email) + 1) * sizeof(char));
        printf("E-Mail: %s\n", (char *)currentPerson);
        currentPerson += (strlen(email) + 1) * sizeof(char);

        memcpy(currentPerson, age, sizeof(int));
        printf("Idade: %d\n", *(int *)currentPerson);
        currentPerson += sizeof(int);

        // system("clear");
        printf("\nRegistro adicionado com sucesso!\n");

        break;
      }
      case 4: {
        if (*(int *)counterPeoples != 0) {
          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória! 4.1\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          tempBuffer = NULL;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
          endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);
          printf("\nBufferSize ao listar pessoa: %zu\n", *(size_t *)bufferSize);

          counter = endBuffer - sizeof(int);

          // system("clear");
          printf("\n--------------- Listar Agenda ---------------\n");
          currentPerson = peoplesBuffer;
          for (*(int *)counter = 0; *(int *)counter < *(int *)counterPeoples; (*(int *)counter)++) {
            printf("Nome: %s\n", (char *)currentPerson);
            currentPerson += (strlen(currentPerson) + 1) * sizeof(char);
            printf("E-Mail: %s\n", (char *)currentPerson);
            currentPerson += (strlen(currentPerson) + 1) * sizeof(char);
            printf("Idade: %d\n", *(int *)currentPerson);
            currentPerson += sizeof(int);
            printf("----------------------------------------------\n");
          }
          currentPerson = NULL;

          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize - sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória! 4.2\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          tempBuffer = NULL;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
          endBuffer = pBuffer + (*(size_t *)bufferSize) - sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

        } else {
          // system("clear");
          printf("\nAgenda Vazia!\n");
        }

        break;
      }
      case 5:
        printf("\nSaindo...\n\n");
        break;
      default:
        printf("\nOpção Inválida!\n");
        break;
    }
  } while (*(int *)userOption != 5);

  free(pBuffer);

  return 0;
}