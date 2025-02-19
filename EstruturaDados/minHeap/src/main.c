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
} minHeap;

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

Node *findParent(minHeap *heap, int identifier) {
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

void heapifyUp(minHeap *heap, Node *node) {
  if (node == heap->pRoot) return;

  Node *parent = findParent(heap, node->identifier);
  while (parent != NULL && node->data.number < parent->data.number) {
    Data temp = node->data;
    node->data = parent->data;
    parent->data = temp;

    node = parent;
    parent = findParent(heap, node->identifier);
  }
}

bool reset(minHeap **heap) {
  *heap = (minHeap *)malloc(sizeof(minHeap));
  if (*heap == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*heap)->pRoot = NULL;
  (*heap)->nodeCounter = 0;

  return true;
}

bool empty(minHeap *heap) { return heap->nodeCounter == 0; }

bool push(minHeap *heap, Data *data) {
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

  return true;
}

bool pop(minHeap *heap, Data *data) {
  if (empty(heap)) {
    printf("\nError! Empty List!\n");
    return false;
  }

  *data = heap->pRoot->data;

  if (heap->nodeCounter == 1) {
    free(heap->pRoot);
    heap->pRoot = NULL;
    heap->nodeCounter = 0;
  }

  Node *lastParent = findParent(heap, heap->nodeCounter);
  Node *lastNode;

  if (lastParent->pRight != NULL) {
    lastNode = lastParent->pRight;
    lastParent->pRight = NULL;
  } else {
    lastNode = lastParent->pLeft;
    lastParent->pLeft = NULL;
  }

  heap->pRoot->data = lastNode->data;
  free(lastNode);
  heap->nodeCounter--;

  heapifyDown(heap, heap->pRoot);

  return true;
}

int main() {
  minHeap *heap;

  if (!reset(&heap)) {
    return 1;
  }

  return 0;
}
