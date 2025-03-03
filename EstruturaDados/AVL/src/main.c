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
  int nodeCounter;
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

int getBalancingFactor(Node *node) {
  if (node == NULL) return 0;

  return getHeight(node->pLeft) - getHeight(node->pRight);
}

int getHeight(Node *node) {
  if (node == NULL) return 0;

  int counterLeft = getHeight(node->pLeft);
  int counterRight = getHeight(node->pRight);

  return (counterLeft > counterRight ? counterLeft : counterRight) + 1;
}

Node *simpleLeftRotation(Node *pivot) {
  Node *aux = pivot->pRight;
  pivot->pRight = aux->pLeft;
  aux->pLeft = pivot;

  return aux;
}

Node *simpleRightRotation(Node *pivot) {
  Node *aux = pivot->pLeft;
  pivot->pLeft = aux->pRight;
  aux->pRight = pivot;

  return aux;
}

Node *balanced(Node *node) {
  int balancingFactor = getBalancingFactor(node);

  if (balancingFactor > 1) {
    if (getBalancingFactor(node->pLeft) < 0) {
      node->pLeft = simpleLeftRotation(node->pLeft);
    }
    node = simpleRightRotation(node);

  } else if (balancingFactor < -1) {
    if (getBalancingFactor(node->pRight) > 0) {
      node->pRight = simpleRightRotation(node->pRight);
    }
    node = simpleLeftRotation(node);
  }

  return node;
}

Node *pushRecursive(Node *node, Data *data) {
  if (node == NULL) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
      printf("\nError allocating memory!\n");
      return NULL;
    }

    newNode->data = *data;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
  }

  if (data->identifier < node->data.identifier) {
    node->pLeft = pushRecursive(node->pLeft, data);
  } else {
    node->pRight = pushRecursive(node->pRight, data);
  }

  return balanced(node);
}

bool push(Tree *tree, Data *data) {
  Node *newRoot = pushRecursive(tree->pRoot, data);
  if (newRoot == NULL) return false;

  tree->pRoot = newRoot;
  tree->nodeCounter++;

  return true;
}

int main() { return 0; }
