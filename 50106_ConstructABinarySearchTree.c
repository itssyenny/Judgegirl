#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXN 1024
char name[MAXN][16];
int height[MAXN];
int weight[MAXN];
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
Node *MakeTree(Node *root, char name[][16], int height[], int weight[], int pos) {
    if(root == NULL) {
        Node *current = (Node *)malloc(sizeof(Node));
        assert(current != NULL);
        strcpy(current->name,name[pos]);
        current->height = height[pos];
        current->weight = weight[pos];
        current->left = NULL;
        current->right = NULL;
        return current;
    } 
    #ifdef HEIGHT
        if(height[pos] < root->height) 
    #endif
    #ifdef WEIGHT
        if(weight[pos] < root->weight)
    #endif
        root->left = MakeTree(root->left, name, height, weight, pos);
        else root->right = MakeTree(root->right, name, height, weight, pos);
    return root;
}
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]) {
    Node *root = NULL;
    for(int i = 0; i < N; i++) {
        root = MakeTree(root, name, height, weight, i);
    }
    return root;
}
void PrintBSTree( Node *root ){
    if (root == NULL)
        return;
    printf("%s\n", root->name);
    PrintBSTree(root->left);
    PrintBSTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
    Node *tree = ConstructBSTree( N, name, height, weight );
 
    PrintBSTree( tree );
    return 0;
}