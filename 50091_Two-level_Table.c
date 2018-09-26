#include <stdio.h>
#include <stdlib.h>
int **fptr[500];
int *sptr[500][500];
int ***constructTable(int A[], int B[]) {
    int i, bcount = 0;
    for(i = 0; A[i] != 0; i++) {
        fptr[i] = &sptr[i][0];
        for(int j = 0; j < A[i]; j++) {
            sptr[i][j] = &B[bcount];
            while(B[bcount++] != 0);
        }
        sptr[i][A[i]] = NULL;
    }
    fptr[i] = NULL;

    int ***ptr = &(fptr[0]);
    
    return ptr;
}
int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    
    return 0;
}