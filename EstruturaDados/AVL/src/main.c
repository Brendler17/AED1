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

int getHeight(Node *node) {
  if (node == NULL) return 0;

  int counterLeft = getHeight(node->pLeft);
  int counterRight = getHeight(node->pRight);

  return (counterLeft > counterRight ? counterLeft : counterRight) + 1;
}

int getBalancingFactor(Node *node) {
  if (node == NULL) return 0;

  return getHeight(node->pLeft) - getHeight(node->pRight);
}

Node *simpleLeftRotation(Node *pivot) {
  if (pivot == NULL || pivot->pRight == NULL) return pivot;

  Node *aux = pivot->pRight;
  pivot->pRight = aux->pLeft;
  aux->pLeft = pivot;

  return aux;
}

Node *simpleRightRotation(Node *pivot) {
  if (pivot == NULL || pivot->pLeft == NULL) return pivot;

  Node *aux = pivot->pLeft;
  pivot->pLeft = aux->pRight;
  aux->pRight = pivot;

  return aux;
}

Node *balanced(Node *node) {
  if (node == NULL) return NULL;

  int balancingFactor = getBalancingFactor(node);

  if (balancingFactor > 1) {
    if (getBalancingFactor(node->pLeft) < 0) {
      node->pLeft = simpleLeftRotation(node->pLeft);
    }
    return simpleRightRotation(node);
  } else if (balancingFactor < -1) {
    if (getBalancingFactor(node->pRight) > 0) {
      node->pRight = simpleRightRotation(node->pRight);
    }
    return simpleLeftRotation(node);
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

void treePreOrder(Node *node, int depth) {
  if (node == NULL) return;

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);

  treePreOrder(node->pLeft, depth + 1);
  treePreOrder(node->pRight, depth + 1);
}

void treePosOrder(Node *node, int depth) {
  if (node == NULL) return;

  treePosOrder(node->pLeft, depth + 1);
  treePosOrder(node->pRight, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);
}

void treeInOrder(Node *node, int depth) {
  if (node == NULL) return;

  treeInOrder(node->pLeft, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);

  treeInOrder(node->pRight, depth + 1);
}

void printTree(Tree *tree) {
  if (tree == NULL) return;

  treePreOrder(tree->pRoot, 0);
}

int main() {
  int number;

  Tree *tree;
  if (!(reset(&tree))) {
    return 1;
  }

  do {
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number == 0) {
      break;
    }

    Data data = {number};

    push(tree, &data);

    printTree(tree);

  } while (number != 0);

  return 0;
}
