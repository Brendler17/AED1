#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[30];
  int age;
} Element;

typedef struct {
  Element *elements;
  Element *top;
  Element *base;
  int limit;
} Stack;

void removeTrailingNewLine(char *string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

void showMenu() {
  printf("\n-------------------- MENU --------------------\n");
  printf("0 - Adicionar Pessoa (Nome, Idade)\n");
  printf("1 - Remover Pessoa\n");
  printf("2 - Remover Pessoa por Nome\n");
  printf("3 - Limpar\n");
  printf("4 - Listar Pessoas\n");
  printf("5 - Sair\n");
  printf("----------------------------------------------\n");
}

// RESET, EMPTY, FULL, PUSH, POP, CLEAR

bool reset(Stack *stack) {
  stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  stack->elements = NULL;
  stack->top = NULL;
  stack->base = NULL;
  stack->limit = 0;

  return true;
}

bool empty(Stack *stack) { return stack->top == 0; }

bool full(Stack *stack) { return false; }

bool push(Stack *stack, Element *element) {
  Element *elements;

  stack->limit++;
  elements = (Element *)malloc(stack->limit * sizeof(Element));
  if (elements == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  memcpy(elements, stack->elements, stack->limit * sizeof(Element));  // ??

  if (stack->elements) {
    free(stack->elements);
  }

  stack->elements = elements;
  stack->elements[stack->limit - 1] = *element;
  stack->top = &stack->elements[stack->limit - 1];
  stack->base = stack->elements;

  return true;
}

bool pop(Stack *stack, Element *element) {
  if (empty(stack)) {
    return false;
  }

  Element *elements;
  element = stack->top;

  stack->limit--;

  if (stack->limit == 0) {
    free(stack->elements);
    reset(stack);
    return false;
  }

  elements = (Element *)malloc(stack->limit * sizeof(Element));
  if (elements == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  memcpy(elements, stack->elements, (stack->limit + 1) * sizeof(Element));

  if (stack->elements) {
    free(stack->elements);
  }

  stack->elements = elements;
  stack->top = &stack->elements[stack->limit - 1];
  stack->base = stack->elements;
  return true;
}

bool clear(Stack *stack) {
  if (empty(stack)) {
    return false;
  }

  free(stack->elements);
  free(stack);

  return true;
}

int main() {
  Stack *stack = NULL;
  Element *element;
  int userOption;
  // char removedName[30];

  if (!(reset(stack))) {
    return 1;
  }

  do {
    showMenu();
    printf("Digite uma opção: ");
    scanf("%d", &userOption);

    switch (userOption) {
      case 0:
        element = (Element *)malloc(sizeof(Element));
        if (element == NULL) {
          printf("\nErro ao alocar memória!\n");
          return 1;
        }

        printf("Digite o nome: ");
        getchar();
        fgets(element->name, 30 * sizeof(char), stdin);
        removeTrailingNewLine(element->name);
        printf("Digite a idade: ");
        scanf("%d", &element->age);

        if (!(push(stack, element))) {
          return 1;
        }

        free(element);

        break;
      case 1:
        element = (Element *)malloc(sizeof(Element));
        if (element == NULL) {
          printf("\nErro ao alocar memória!\n");
          return 1;
        }

        if (pop(stack, element)) {
          printf("\nElemento removido\n");
          printf("Nome: %s\n", element->name);
          printf("Idade: %d\n", element->age);

          free(element);
        } else {
          printf("\nErro ao remover!\n");
          free(element);
        }
        break;
      case 5:
        printf("\nSaindo...\n");
        break;

      default:
        break;
    }
  } while (userOption != 5);

  return 0;
}
