#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fptr[1024];
char *sptr[16384];
char word[10000000];

int main() {
    int N; scanf("%d", &N);
    int nW[N+1];    /* to store the length of every word in line i */
    int second = 0; /* to count the second ptr table */
    int cnt = 0;    /* to count the array word */
    
    for(int i = 0; i < N; i++) {
        char _t;
        nW[i] = 0, fptr[i] = &sptr[second];
        while(scanf("%s%c", &word[cnt], &_t) == 2) {
            sptr[second] = &word[cnt];
            second++;
            nW[i]++;
            cnt += strlen(&word[cnt]) + 1;
            if(_t == '\n') break;
        }
    }


    int M; scanf("%d", &M);
    int x_l, x_w, y_l, y_w;

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x_l, &x_w, &y_l, &y_w);
        char *tmp = fptr[x_l][x_w];
        fptr[x_l][x_w] = fptr[y_l][y_w];
        fptr[y_l][y_w] = tmp;
    }

    for(int i = 0; i < N; i++) {
        // printf("%d\n", nW[i]);
        for(int j = 0; j < nW[i]; j++) {
            printf("%s%c", fptr[i][j]," \n"[j == nW[i]-1]);
        }

    }
    return 0;
}