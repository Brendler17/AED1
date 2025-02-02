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
  void *tempBuffer, *endBuffer, *counter, *offset, *position;

  tempBuffer = (void *)realloc(*pBuffer, *(size_t *)*(bufferSize) + 2 * sizeof(int));
  if (tempBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  *pBuffer = tempBuffer;
  tempBuffer = NULL;
  updatePointers(pBuffer, userOption, counterPeoples, bufferSize, peoplesBuffer, name, email, age);
  endBuffer = *pBuffer + (*(size_t *)*(bufferSize)) + 2 * sizeof(int);
  *(size_t *)*(bufferSize) = (size_t)(endBuffer - *pBuffer);

  counter = endBuffer - sizeof(int);
  position = counter - sizeof(int);
  offset = *age;

  if (*(int *)*(counterPeoples) == 0) {
    *currentPerson = NULL;
    return 1;
  }

  *(int *)offset = 0;
  if (*(int *)*(userOption) == 1) {
    for (*(int *)counter = 0; *(int *)counter < ((*(int *)*(counterPeoples)) - 1); (*(int *)counter)++) {
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += sizeof(int);
    }
  } else if (*(int *)*(userOption) == 2) {
    *(int *)*(counterPeoples) == 1 ? printf("\nDigite o nº de registro para remover (1): ") : printf("Digite o nº de registro para remover (1 a %d): ", *(int *)*(counterPeoples));
    scanf("%d", (int *)position);
    if (*(int *)position <= 0 || *(int *)position > *(int *)*(counterPeoples)) {
      system("clear");
      printf("\nPosição Inválida!\n");
      return 1;
    }

    for (*(int *)counter = 0; *(int *)counter < (*(int *)position) - 1; (*(int *)counter)++) {
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += sizeof(int);
    }
  } else if (*(int *)*(userOption) == 3) {
    printf("Digite o nome que deseja buscar: ");
    scanf(" %50[^\n]", (char *)name);
    getchar();

    for (*(int *)counter = 0; *(int *)counter < *(int *)*(counterPeoples); (*(int *)counter)++) {
      if (strcmp((char *)(*peoplesBuffer + *(int *)offset), (char *)name) == 0) {
        *currentPerson = *peoplesBuffer + *(int *)offset;
        printf("\n----------- Registro Encontrado -----------\n");
        printf("Nome: %s\n", (char *)*currentPerson);
        *currentPerson += (strlen((char *)*currentPerson) + 1) * sizeof(char);
        printf("E-Mail: %s\n", (char *)*currentPerson);
        *currentPerson += (strlen((char *)*currentPerson) + 1) * sizeof(char);
        printf("Idade: %d\n", *(int *)*currentPerson);
        *currentPerson += sizeof(int);
        printf("-------------------------------------------\n");
        return 0;
      }
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += strlen((char *)(*peoplesBuffer) + *(int *)offset) + 1;
      *(int *)offset += sizeof(int);
    }

    printf("\nRegistro não encontrado!\n");
  }

  tempBuffer = (void *)realloc(*pBuffer, (*(size_t *)*(bufferSize)) - 2 * sizeof(int));
  if (tempBuffer == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  *pBuffer = tempBuffer;
  tempBuffer = NULL;
  updatePointers(pBuffer, userOption, counterPeoples, bufferSize, peoplesBuffer, name, email, age);
  endBuffer = *pBuffer + (*(size_t *)*(bufferSize)) - 2 * sizeof(int);
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
  void *pBuffer, *endBuffer, *bufferSize, *tempBuffer, *userOption, *counterPeoples, *peoplesBuffer, *currentPerson, *name, *email, *age, *counter, *auxPerson, *offset;

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

        if (getCurrentPerson(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age)) {
          free(pBuffer);
          return 1;
        }

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
      case 2: {
        if (*(int *)counterPeoples != 0) {
          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória!\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          tempBuffer = NULL;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
          endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

          counter = endBuffer - sizeof(int);

          // system("clear");
          printf("\n-------------- Remover Pessoa --------------\n\n");
          currentPerson = peoplesBuffer;

          for (*(int *)counter = 0; *(int *)counter < *(int *)counterPeoples; (*(int *)counter)++) {
            printf("----------------- Registro %d ---------------\n", (*(int *)counter) + 1);
            printf("Nome: %s\n", (char *)currentPerson);
            currentPerson += (strlen(currentPerson) + 1) * sizeof(char);
            printf("E-Mail: %s\n", (char *)currentPerson);
            currentPerson += (strlen(currentPerson) + 1) * sizeof(char);
            printf("Idade: %d\n", *(int *)currentPerson);
            currentPerson += sizeof(int);
          }

          currentPerson = NULL;

          getCurrentPerson(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age);
          auxPerson = currentPerson;
          printf("----------------- Registro Removido ---------------\n");
          printf("Nome: %s\n", (char *)auxPerson);
          auxPerson += (strlen(auxPerson) + 1) * sizeof(char);
          printf("E-Mail: %s\n", (char *)auxPerson);
          auxPerson += (strlen(auxPerson) + 1) * sizeof(char);
          printf("Idade: %d\n", *(int *)auxPerson);
          auxPerson += sizeof(int);

          offset = age;
          *(int *)offset = (strlen((char *)currentPerson) + 1) + (strlen((char *)(currentPerson + strlen((char *)currentPerson) + 1)) + 1) + sizeof(int);

          memmove(currentPerson, currentPerson + *(int *)offset, *(size_t *)bufferSize - ((currentPerson - pBuffer) + *(int *)offset));

          (*(int *)counterPeoples)--;

          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize - *(int *)offset - sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória!\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          tempBuffer = NULL;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age);
          offset = age;
          endBuffer = pBuffer + (*(size_t *)bufferSize) - *(int *)offset - sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

          // system("clear");
          printf("\nRegistro removido com sucesso!\n");

        } else {
          // system("clear");
          printf("\nAgenda Vazia!\n");
        }

        break;
      }
      case 3: {
        if (*(int *)counterPeoples != 0) {
          system("clear");
          printf("\n-------------- Buscar Pessoa --------------\n");

          getCurrentPerson(&pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age);

        } else {
          system("clear");
          printf("\nAgenda Vazia!\n");
        }
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