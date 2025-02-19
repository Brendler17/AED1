#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
} Data;

typedef struct Node {
  int identifier;
  Data data;
  struct Node *pLeft;
  struct Node *pRight;
} Node;

typedef struct {
  Node *pRoot;
  size_t nodeCounter;
} maxHeap;

int *convertNumberToBits(int number, size_t *size) {
  *size = (int)(log2(number)) + 1;
  int *bits = (int *)malloc(*size * sizeof(int));
  if (bits == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  for (int counter = 0; counter < *size; counter++) {
    bits[counter] = (number >> (*size - counter - 1)) & 1;
  }

  return bits;
}

Node *findParent(maxHeap *heap, int identifier) {
  if (identifier == 1) return NULL;

  size_t size;
  int *idInBits = convertNumberToBits(identifier, &size);
  if (idInBits == NULL) return NULL;

  Node *parent = heap->pRoot;

  for (int counter = 1; counter < size - 1; counter++) {
    if (idInBits[counter] == 1) {
      parent = parent->pRight;
    } else {
      parent = parent->pLeft;
    }
  }

  free(idInBits);
  return parent;
}

bool reset(maxHeap **heap) {
  *heap = (maxHeap *)malloc(sizeof(maxHeap));
  if (*heap == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*heap)->pRoot = NULL;
  (*heap)->nodeCounter = 0;

  return true;
}

bool push(maxHeap *heap, Data *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  newNode->identifier = heap->nodeCounter + 1;
  newNode->data = *data;
  newNode->pLeft = NULL;
  newNode->pRight = NULL;

  if (heap->nodeCounter == 0) {
    heap->pRoot = newNode;
    heap->nodeCounter++;
    return true;
  }

  Node *parent = findParent(heap, newNode->identifier);

  if (parent->pLeft == NULL) {
    parent->pLeft = newNode;
  } else {
    parent->pRight = newNode;
  }

  // heapifyUp(heap, newNode);

  heap->nodeCounter++;
  return true;
}

int main() { return 0; }
