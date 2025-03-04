#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t identifier;
} Data;

typedef struct Node {
  Data data;
  struct Node *pLeft;
  struct Node *pRight;
} Node;

typedef struct {
  Node *pRoot;
  size_t nodeCounter;
} Tree;

bool reset(Tree **tree) {
  *tree = (Tree *)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pRoot = NULL;
  (*tree)->nodeCounter = 0;

  return true;
}

int main() { return 0; }
