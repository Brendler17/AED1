#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct {
  size_t identifier;
} Data;

typedef struct Node {
  Data data;
  Color color;
  struct Node *pLeft;
  struct Node *pRight;
  struct Node *pParent;
} Node;

typedef struct {
  Node *pRoot;
  Node *pNil;
} Tree;

bool reset(Tree **tree) {
  *tree = (Tree *)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pRoot = NULL;
  (*tree)->pNil = NULL;

  return true;
}

int main() { return 0; }
