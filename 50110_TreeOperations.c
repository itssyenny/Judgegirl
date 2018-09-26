#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node{
    int n;
    struct Node *left, *right;
} Node;
 int count = 0;
Node *FlipTree(Node *root) {
  if(root == NULL) return NULL;
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->n = root->n;
  new->left = FlipTree(root->right);
  new->right = FlipTree(root->left);
  return new;
}
int isIdentical(Node *tree1, Node *tree2) {
  if(tree1 == NULL && tree2 == NULL) return 1;
  if(tree1 == NULL || tree2 == NULL) return 0;
  if(tree1->n != tree2->n) return 0;
  if(tree1->n == tree2->n) {
    if(isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right) == 1) return 1;
    else return 0;
  }
  else return 0;
}
void countThedepth(Node *root, int pos, int *sum_depth, int *leaves) {
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL) {
    *sum_depth += pos;
    (*leaves)++;
    return;
  }
  countThedepth(root->left, pos+1, sum_depth, leaves);
  countThedepth(root->right, pos+1, sum_depth, leaves);
  return;
}
void depthAvg(Node *root) {
  int sum_depth = 0, leaves = 0; /* IMPORTANT */
  countThedepth(root, 0, &sum_depth, &leaves);
  printf("%d/%d\n", sum_depth, leaves);
  return;
}

void printTree(Node *root) {
  if (root == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d\n", root->n);
  if (root->left == NULL && root->right == NULL) return;
  printTree(root->left);
  printTree(root->right);
}
 
int main() {
  Node tree1[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[2].right = &tree1[8];
  tree1[4].left = &tree1[6];
  tree1[6].right = &tree1[7];
 
  depthAvg(&tree1[0]);
 
  return 0;
}