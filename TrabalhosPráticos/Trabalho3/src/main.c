#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode* getDepht(struct TreeNode* node, int* depht) {
  if (node == NULL) {
    *depht = 0;
    return NULL;
  }

  int dephtLeft = 0, dephtRight = 0;
  struct TreeNode* left = getDepht(node->left, &dephtLeft);
  struct TreeNode* right = getDepht(node->right, &dephtRight);

  *depht = 1 + (dephtLeft > dephtRight ? dephtLeft : dephtRight);

  if (dephtLeft == dephtRight) return node;
  return (dephtLeft > dephtRight) ? left : right;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
  int depht = 0;

  return getDepht(root, &depht);
}

int main() { return 0; }
