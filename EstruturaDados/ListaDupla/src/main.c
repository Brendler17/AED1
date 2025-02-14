#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int registration;
} Data;

typedef struct Node {
  Data data;
  Node *pNext;
  Node *pPrev;
} Node;

typedef struct {
  Node *pFirst;
  Node *pLast;
  size_t nodeCounter;
} DoubleList;

Node *getCurrentNode(DoubleList *list, int position) {
  if (position >= list->nodeCounter) {
    return list->pLast;
  }

  bool isHead = position <= (list->nodeCounter - 1) / 2;
  Node *currentNode;
  size_t counter;

  if (isHead) {
    currentNode = list->pFirst;

    counter = 0;
    while (currentNode->pNext != NULL && counter < position) {
      currentNode = currentNode->pNext;
      counter++;
    }

  } else {
    currentNode = list->pLast;

    counter = list->nodeCounter - 1;
    while (currentNode->pPrev != NULL && counter > position) {
      currentNode = currentNode->pPrev;
      counter--;
    }
  }

  return currentNode;
}

bool reset(DoubleList **list) {
  *list = (DoubleList *)malloc(sizeof(DoubleList));
  if (*list == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*list)->pFirst = NULL;
  (*list)->pLast = NULL;
  (*list)->nodeCounter = 0;

  return true;
}

bool empty(DoubleList *list) { return list->nodeCounter == 0; }

bool push(DoubleList *list, Data *data, int position) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  if (position < 0) {
    printf("\nError! Invalid Position.\n");
    return false;
  }

  newNode->data = *data;
  newNode->pNext = NULL;
  newNode->pPrev = NULL;

  if (list->pFirst == NULL) {  // Lista Vazia
    list->pFirst = newNode;
    list->pLast = newNode;
  } else if (position == 0) {  // Inserir no inicio
    newNode->pNext = list->pFirst;
    list->pFirst->pPrev = newNode;
    list->pFirst = newNode;
  } else if (position >= list->nodeCounter) {  // Inserir no final
    list->pLast->pNext = newNode;
    newNode->pPrev = list->pLast;
    list->pLast = newNode;
  } else {  // Inserir no meio
    Node *currentNode = getCurrentNode(list, position);

    newNode->pNext = currentNode;
    newNode->pPrev = currentNode->pPrev;
    currentNode->pPrev->pNext = newNode;
    currentNode->pPrev = newNode;
  }

  list->nodeCounter++;
  return true;
}

bool pop(DoubleList *list, Data *data, int position) {
  if (empty(list)) {
    printf("\nError! Empty List!\n");
    return false;
  }

  if (position < 0) {
    printf("\nError! Invalid Position.\n");
    return false;
  }

  Node *removedNode;

  if (list->nodeCounter == 1) {  // Apenas um nó na lista
    removedNode = list->pFirst;
    list->pFirst = NULL;
    list->pLast = NULL;
  } else if (position == 0) {  // Remover do inicio
    removedNode = list->pFirst;
    list->pFirst = removedNode->pNext;
    removedNode->pNext->pPrev = NULL;          // ?
  } else if (position >= list->nodeCounter) {  // Remover do final
    removedNode = list->pLast;
    list->pLast = removedNode->pPrev;
    removedNode->pPrev->pNext = NULL;  // ?
  } else {                             // Remover do meio
    removedNode = getCurrentNode(list, position);
    removedNode->pPrev->pNext = removedNode->pNext;
    removedNode->pNext->pPrev = removedNode->pPrev;
  }

  *data = removedNode->data;
  free(removedNode);
  list->nodeCounter--;
  return true;
}

bool clear(DoubleList *list) {
  Node *currentNode = list->pFirst;
  Node *auxNode;

  while (currentNode != NULL) {
    auxNode = currentNode;
    currentNode = currentNode->pNext;
    free(auxNode);
  }

  list->pFirst = NULL;
  list->pLast = NULL;
  list->nodeCounter = 0;

  return true;
}

int main(int argc, char const *argv[]) {
  printf("Hello World!\n");

  return 0;
}
