#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* elements;
  char* top;
  char* base;
  int numberOfElements;
} Stack;

bool reset(Stack** stack) {
  *stack = (Stack*)malloc(sizeof(Stack));
  if (*stack == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*stack)->elements = NULL;
  (*stack)->top = NULL;
  (*stack)->base = NULL;
  (*stack)->numberOfElements = 0;

  return true;
}

bool empty(Stack* stack) { return stack->base == NULL; }

bool push(Stack* stack, char* bracket) {
  if (stack->elements == NULL) {
    char* elements = (char*)malloc(sizeof(char));
    if (elements == NULL) {
      printf("\nError allocating memory!\n");
      return false;
    }

    stack->elements = elements;
  } else {
    char* elements = (char*)realloc(stack->elements, (stack->numberOfElements + 1) * sizeof(char));
    if (elements == NULL) {
      printf("\nError allocating memory!\n");
      return false;
    }

    stack->elements = elements;
  }

  stack->elements[stack->numberOfElements] = *bracket;
  stack->numberOfElements++;
  stack->top = &stack->elements[stack->numberOfElements - 1];
  stack->base = stack->elements;

  return true;
}

bool pop(Stack* stack, char* bracket) {
  if (empty(stack)) {
    printf("Error! Empty stack.\n");
    return false;
  }

  *bracket = stack->elements[stack->numberOfElements - 1];
  stack->numberOfElements--;

  if (stack->numberOfElements == 0) {
    free(stack->elements);
    stack->elements = NULL;
    stack->top = NULL;
    stack->base = NULL;
    stack->numberOfElements = 0;
    return true;
  }

  stack->elements = (char*)realloc(stack->elements, stack->numberOfElements * sizeof(char));
  if (stack->elements == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  stack->top = &stack->elements[stack->numberOfElements - 1];
  stack->base = stack->elements;

  return true;
}

bool clear(Stack* stack) {
  if (stack->elements) {
    free(stack->elements);
    stack->elements = NULL;
  }

  stack->top = NULL;
  stack->base = NULL;
  stack->numberOfElements = 0;

  return true;
}

bool isValid(char* string) {
  Stack* stack = NULL;
  reset(&stack);

  size_t len = strlen(string);
  char bracket;

  if (len % 2 != 0) {
    return false;
  }

  for (int counter = 0; counter < len; counter++) {
    if (string[counter] == '(' || string[counter] == '[' || string[counter] == '{') {
      push(stack, &string[counter]);
    } else if (string[counter] == ')') {
      if (pop(stack, &bracket)) {
        if (bracket != '(') {
          return false;
        }
      } else {
        return false;
      }
    } else if (string[counter] == ']') {
      if (pop(stack, &bracket)) {
        if (bracket != '[') {
          return false;
        }
      } else {
        return false;
      }
    } else if (string[counter] == '}') {
      if (pop(stack, &bracket)) {
        if (bracket != '{') {
          return false;
        }
      } else {
        return false;
      }
    }
  }

  if (!empty(stack)) {
    return false;
  }

  clear(stack);
  free(stack);
  return true;
}

int main() {
  char string1[] = {"()"};
  char string2[] = {"()[]{}"};
  char string3[] = {"(]"};
  char string4[] = {"([])"};
  char string5[] = {"(("};

  isValid(string1) ? printf("True\n") : printf("False\n");
  isValid(string2) ? printf("True\n") : printf("False\n");
  isValid(string3) ? printf("True\n") : printf("False\n");
  isValid(string4) ? printf("True\n") : printf("False\n");
  isValid(string5) ? printf("True\n") : printf("False\n");

  return 0;
}
