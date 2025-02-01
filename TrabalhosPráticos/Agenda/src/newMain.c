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

void getCurrentPerson(void **userOption, void **counterPeoples, void **peoplesBuffer, void **currentPerson, void **name, void **email, void **counter) {
  *currentPerson = *peoplesBuffer;

  // if (*(int *)*(userOption) == 1) {
  *currentPerson += ((*(int *)*(counterPeoples)) - 1) * ((strlen((char *)*(name)) + 1) * sizeof(char) + (strlen((char *)*(email)) + 1) * sizeof(char) + sizeof(int));
  //}

  // else if (*(int *)*(userOption) == 4) {
  //   *currentPerson += (*(int *)*(counter)) * ((strlen((char *)*(name)) + 1) * sizeof(char) + (strlen((char *)*(email)) + 1) * sizeof(char) + sizeof(int));
  // }
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

  updatePointers(&pBuffer, &userOption, &counterPeoples, &name, &email, &age, &bufferSize, &peoplesBuffer);
  endBuffer = pBuffer + 3 * sizeof(int) + sizeof(size_t) + 100 * sizeof(char);

  *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);
  *(int *)counterPeoples = 0;

  do {
    showMenu();
    printf("Digite uma opção: ");
    scanf("%d", (int *)userOption);
    getchar();

    switch (*(int *)userOption) {
      case 1: {
        (*(int *)counterPeoples)++;
        system("clear");
        printf("\n-------------- Adicionar Pessoa --------------\n");
        printf("Informe o nome: ");
        scanf("%[^\n]", (char *)name);
        printf("Informe o e-mail: ");
        scanf("%[^\n]", (char *)email);
        printf("Informe a idade: ");
        scanf("%d", (int *)age);

        tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + sizeof(strlen(name)) + sizeof(strlen(email)) + sizeof(int));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória!\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        tempBuffer = NULL;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &name, &email, &age, &bufferSize, &peoplesBuffer);
        endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof(strlen(name)) + sizeof(strlen(email)) + sizeof(int);
        *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

                break;
      }
      case 2: {
        if (*(int *)counterPeoples != 0) {
          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória! 2.1\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peoplesBuffer);
          endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

          position = endBuffer - sizeof(int);

          system("clear");
          printf("\n-------------- Remover Pessoa --------------\n");
          *(int *)counterPeoples == 1 ? printf("Digite o nº de registro para remover (1): ") : printf("Digite o nº de registro para remover (1 a %d): ", *(int *)counterPeoples);
          scanf("%d", (int *)position);
          if (*(int *)position <= 0 || *(int *)position > *(int *)counterPeoples) {
            system("clear");
            printf("\nPosição Inválida!\n");
            return 1;
          }

          removedPeople = peoplesBuffer + ((*(int *)position) - 1) * (*(size_t *)peopleLenght);

          memmove(removedPeople, removedPeople + (*(size_t *)peopleLenght), ((*(int *)counterPeoples) - (*(int *)position)) * (*(size_t *)peopleLenght));

          (*(int *)counterPeoples)--;

          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize - (*(size_t *)peopleLenght) - sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória! 2.2\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peoplesBuffer);
          endBuffer = pBuffer + (*(size_t *)bufferSize) - (*(size_t *)peopleLenght) - sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

          system("clear");
          printf("\nRegistro removido com sucesso!\n");

        } else {
          system("clear");
          printf("\nAgenda Vazia!\n");
        }

        break;
      }
      case 3: {
        tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize + 50 * sizeof(char) + sizeof(int) + sizeof(size_t));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória! 3.1\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peoplesBuffer);
        endBuffer = pBuffer + (*(size_t *)bufferSize) + 50 * sizeof(char) + sizeof(int) + sizeof(size_t);
        *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

        offset = endBuffer - sizeof(size_t);
        searchName = endBuffer - sizeof(size_t) - sizeof(int) - sizeof(char) * 50;

        system("clear");
        printf("\n-------------- Buscar Pessoa --------------\n");
        printf("Digite o nome que deseja buscar: ");
        fgets(searchName, 50 * sizeof(char), stdin);
        *(size_t *)offset = (size_t)(searchName - pBuffer);

        if (removeTrailingNewLine(&pBuffer, &counterPeoples, &peopleLenght, &userOption, &peoplesBuffer, &endBuffer, &bufferSize, &offset, &people)) {
          printf("\nErro ao alocar memória! 3.2\n");
          free(pBuffer);
          return 1;
        }

        counter = endBuffer - sizeof(size_t) - sizeof(int);
        searchName = endBuffer - sizeof(size_t) - sizeof(int) - sizeof(char) * 50;

        for (*(int *)counter = 0; *(int *)counter < *(int *)counterPeoples; (*(int *)counter)++) {
          people = peoplesBuffer + (*(int *)counter) * (*(size_t *)peopleLenght);

          if (strcmp(people, searchName) == 0) {
            system("clear");
            printf("\n----------- Registro Encontrado -----------\n");
            printf("Nome: %s\n", (char *)people);
            printf("Idade: %d\n", *(int *)(people + 50 * sizeof(char)));
            printf("E-Mail: %s\n", (char *)(people + 50 * sizeof(char) + sizeof(int)));
            printf("----------------------------------------------\n");
            break;
          } else {
            system("clear");
            printf("\nRegistro não encontrado!\n");
          }
        }

        tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize - 50 * sizeof(char) - sizeof(int) - sizeof(size_t));
        if (tempBuffer == NULL) {
          printf("\nErro ao alocar memória! 3.3\n");
          free(pBuffer);
          return 1;
        }

        pBuffer = tempBuffer;
        updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peoplesBuffer);
        endBuffer = pBuffer + (*(size_t *)bufferSize) - 50 * sizeof(char) - sizeof(int) - sizeof(size_t);
        *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

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
          updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peoplesBuffer);
          endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

          counter = endBuffer - sizeof(int);

          system("clear");
          printf("\n--------------- Listar Agenda ---------------\n");
          for (*(int *)counter = 0; *(int *)counter < *(int *)counterPeoples; (*(int *)counter)++) {
            people = peoplesBuffer + (*(int *)counter) * (*(size_t *)peopleLenght);
            printf("Nome: %s\n", (char *)people);
            printf("Idade: %d\n", *(int *)(people + 50 * sizeof(char)));
            printf("E-Mail: %s\n", (char *)(people + 50 * sizeof(char) + sizeof(int)));
            printf("----------------------------------------------\n");
          }

          tempBuffer = (void *)realloc(pBuffer, *(size_t *)bufferSize - sizeof(int));
          if (tempBuffer == NULL) {
            printf("\nErro ao alocar memória! 4.2\n");
            free(pBuffer);
            return 1;
          }

          pBuffer = tempBuffer;
          updatePointers(&pBuffer, &userOption, &counterPeoples, &peopleLenght, &bufferSize, &peopleLenght);
          endBuffer = pBuffer + (*(size_t *)bufferSize) - sizeof(int);
          *(size_t *)bufferSize = (size_t)(endBuffer - pBuffer);

        } else {
          system("clear");
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