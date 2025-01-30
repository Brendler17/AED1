#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  Node *pFirst;
  size_t nodeCount;
} List;

typedef struct {
  Data data;
  Node *pNext;
} Node;

typedef struct {
  int code;
  char name[30];
  float price;
} Data;

bool reset(List **list) {
  *list = (List *)malloc(sizeof(List));
  if (*list == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  (*list)->pFirst = NULL;
  (*list)->nodeCount = 0;

  return true;
}

bool empty(List *list) { return list->pFirst = NULL; }

bool push(List *list, Data *data, size_t position) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  newNode->data = data;
  newNode->pNext = NULL;

  if (list->pFirst == NULL) {
    list->pFirst = newNode;
  } else {
    if (position == 0) {
      newNode->pNext = list->pFirst;
      list->pFirst = newNode;
    } else {
      Node *current = list->pFirst;
      size_t counter = 0;

      while (current != NULL && counter < position - 1) {
        current = current->pNext;
        counter++;
      }

      if (current != NULL) {
        newNode->pNext = current->pNext;
        current->pNext = newNode;
      } else {
        current = list->pFirst;
        while (current->pNext != NULL) {
          current = current->pNext;
        }

        current->pNext = newNode;
      }
    }
  }

  list->nodeCount++;
  return true;
}

bool pop(List *list, Data *data, size_t position) {
  if (empty(list)) {
    printf("\nA lista está vazia!\n");
    return false;
  }

  Node *auxNode = list->pFirst;
  Node *previousNode = NULL;

  if (position == 0) {
    list->pFirst = auxNode->pNext;
    *data = auxNode->data;
    free(auxNode);
    list->nodeCount--;
    return true;
  }

  size_t counter = 0;
  while (auxNode != NULL && counter < position) {
    previousNode = auxNode;
    auxNode = auxNode->pNext;
    counter++;
  }

  if (auxNode == NULL) {
    printf("\nPosição Inválida!\n");
    return false;
  }

  previousNode->pNext = auxNode->pNext;
  *data = auxNode->data;
  free(auxNode);
  list->nodeCount--;

  return true;
}

bool clear(List *list) {
  Node *current = list->pFirst;
  Node *auxNode;

  while (current != NULL) {
    auxNode = current;
    current = current->pNext;
    free(auxNode);
  }
}

int main() {
  List *list;

  free(list);

  return 0;
}
