#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#define MAXN 16384
int sequence[MAXN], B[MAXN];
typedef struct node{
    int value;
    struct node *left, *right;
} Node;
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
Node *makelist(Node *root, int sequence[], int a) {
    if(a >= 0) {
        root = (Node *)malloc(sizeof(Node));
        assert(root != NULL);
        root->value = sequence[a];
        root->left = makelist(root->left, sequence, a-1); 
        root->right = NULL; 
        return root;
    }
    return NULL;
}
Node *ConstructTree(int sequence[], int N) {
    if(N == 0) return NULL;
    
    Node *root = NULL;
    if(N < MAXLENGTH) {
        root = makelist(root, sequence, N-1);
        return root;
    }
    memcpy(B, sequence, sizeof(sequence[0])*N);
    qsort(B, N, sizeof(sequence[0]), compare);
    int pos, theroot = B[MAXLENGTH-1];
    for(int i = 0; i < N; i++) {
        if(sequence[i] == theroot) {
            pos = i; break;
        }
    }
    root = (Node *)malloc(sizeof(Node));
    assert(root != NULL);
    root->value = theroot;
    root->left = ConstructTree(sequence, pos);
    root->right = ConstructTree((sequence+pos+1), N-pos-1);
    return root;
}
void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}