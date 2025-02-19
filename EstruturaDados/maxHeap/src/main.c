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

int main() { return 0; }
