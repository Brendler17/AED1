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

void pushCase1(Tree *tree, Node *node);

Node *getGrandParent(Node *node) {
  if (node != NULL && node->pParent != NULL) {
    return node->pParent->pParent;
  }

  return NULL;
}

Node *getUncle(Node *node) {
  Node *grandParent = getGrandParent(node);
  if (grandParent == NULL) return NULL;

  if (node->pParent == grandParent->pLeft) {
    return grandParent->pRight;
  } else {
    return grandParent->pLeft;
  }
}

Node *simpleRotationLeft(Tree *tree, Node *pivot) {
  if (pivot == NULL || pivot->pRight == NULL) return NULL;

  Node *aux = pivot->pRight;
  pivot->pRight = aux->pLeft;
  aux->pLeft = pivot;

  return aux;
}

Node *simpleRotationRight(Tree *tree, Node *pivot) {
  if (pivot == NULL || pivot->pLeft == NULL) return NULL;

  Node *aux = pivot->pLeft;
  pivot->pLeft = aux->pRight;
  aux->pRight = pivot;

  return aux;
}

void pushCase5(Tree *tree, Node *node) {
  Node *grandParent = getGrandParent(node);

  if ((node == node->pParent->pLeft) && (node->pParent == grandParent->pLeft)) {
    simpleRotationRight(tree, grandParent);
  } else {
    simpleRotationLeft(tree, grandParent);
  }

  node->pParent->color = BLACK;
  grandParent->color = RED;
}

void pushCase4(Tree *tree, Node *node) {
  Node *grandParent = getGrandParent(node);

  if ((node == node->pParent->pRight) && (node->pParent == grandParent->pLeft)) {
    node->pLeft = simpleRotationLeft(tree, node->pParent);
  } else if ((node == node->pParent->pLeft) && (node->pParent == grandParent->pRight)) {
    node->pRight = simpleRotationRight(tree, node->pParent);
  }

  pushCase5(tree, node->pParent);
}

void pushCase3(Tree *tree, Node *node) {
  Node *uncle = getUncle(node);

  if (uncle != NULL && uncle->color == RED) {  // 1ª Correção -> Se o tio do elemento inserido é VERMELHO.
    Node *grandParent = getGrandParent(node);

    node->pParent->color = BLACK;
    uncle->color = BLACK;
    grandParent->color = RED;
    if (grandParent != NULL) {
      pushCase1(tree, grandParent);
    }
  } else {
    pushCase4(tree, node);
  }
}

void pushCase2(Tree *tree, Node *node) {
  if (node->pParent->color == BLACK) {  // Se tiver nó pai preto, não precisa de correção. Novo nó = VERMELHO.
    return;
  } else {
    pushCase3(tree, node);  // Se tiver o nó pai vermelho, precisará de correção - ambos filhos de todos nós vermelhos são PRETOS.
  }
}

void pushCase1(Tree *tree, Node *node) {
  if (node->pParent == tree->pNil) {  // Se não tiver nó pai, significa que ele será o nó pai = PRETO.
    node->color = BLACK;
  } else {  // Se não for o nó pai, passa para o segundo caso.
    pushCase2(tree, node);
  }
}

Node *push(Tree *tree, Data *data) {}

bool reset(Tree **tree) {
  *tree = (Tree *)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pNil = (Node *)malloc(sizeof(Node));
  if ((*tree)->pNil == NULL) {
    printf("\nError allocating memory!\n");
    free(*tree);
    return false;
  }

  (*tree)->pNil->color = BLACK;
  (*tree)->pNil->pLeft = (*tree)->pNil;
  (*tree)->pNil->pRight = (*tree)->pNil;
  (*tree)->pNil->pParent = (*tree)->pNil;

  (*tree)->pRoot = (*tree)->pNil;

  return true;
}

int main() { return 0; }
