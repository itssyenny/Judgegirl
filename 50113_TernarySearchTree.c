#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXN 32768
typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
}Node;
int sequence[MAXN];
Node *MakeTree(Node *root, int data) {
    if(root == NULL) {
        Node *current = (Node *)malloc(sizeof(Node));
        assert(current != NULL);
        current->large = data;
        current->small = -1;
        current->left = NULL;
        current->mid = NULL;
        current->right = NULL;
        return current;
    }
    if(root->small == -1) {
        if(data < root->large) {
            root->small = data;
        } else if(data > root->large) {
            int tmp = root->large;
            root->large = data;
            root->small = tmp;
        }
        return root;
    }
    if(data < root->small) {
        root->left = MakeTree(root->left, data);
    } else if(root->large < data) {
        root->right = MakeTree(root->right, data);
    }  else if(root->small < data < root->large) {
        root->mid = MakeTree(root->mid, data);
    }

    return root;
}
Node*ConstructTree(int sequence[],int N) {
    Node *root = NULL;
    for(int i = 0; i < N; i++) {
        root = MakeTree(root, sequence[i]);
    }
    return root;
}
void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d %d\n", root->small, root->large);
    PrintTree(root->left);
    PrintTree(root->mid);
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