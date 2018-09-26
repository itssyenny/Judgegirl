#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 16384
typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;
int T[MAXN]; 
Node *link_the_Nodes(int T[], int a, int b) {
    if(a <= b) {
        Node *root = (Node *)malloc(sizeof(Node));
        root->value = T[b];
        root->left = link_the_Nodes(T,a,b-1);
        root->right = NULL;
        return root;
    }
    return NULL;
}
Node *MakeTree(int T[], int a, int b) {
    if(b-a+1 < 3) return link_the_Nodes(T,a,b);
 
    int set_balance;
    bool mark = false;
    for(int i = a; i <= b; i++) {
        int totalsum = 0, left_sum = 0, right_sum = 0, pos;
        set_balance = i;

        for(int j = a; j <= b; j++) {
            if((pos = set_balance - j) < 0) pos *= -1;
            if(j < set_balance) left_sum += (pos * T[j]);
            else if(j > set_balance) right_sum += (pos * T[j]);
        }
        if(left_sum == right_sum) {mark = true; break;}
    }
 
    if(mark == false) return link_the_Nodes(T,a,b);
    else {
        Node *root = (Node *)malloc(sizeof(Node));
        root->value = T[set_balance];
        root->left = MakeTree(T,a,set_balance-1);
        root->right = MakeTree(T, set_balance+1, b);
        return root;
    }
}
Node *ConstructTree(int T[], int N) {
    return MakeTree(T,0,N-1);
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
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}