#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main () {
    int N, M, P; scanf("%d %d %d", &N, &M, &P);

    uint64_t num[16]; /* max = (4/24)*64-bit = 10.667 */ 
    for(int i = 0; i < M; i++) {
        scanf("%llu", &num[i]); /* M nums with 64-bit */
    }

    uint8_t in;
    for(int i = 0; i < P; i++) {
        scanf("%hhu", &in);
        // printf("%hhu\n", in );
        /* process */
        for(int box = 0; box < N; box++) {
            uint8_t tmp = (num[box/8]>>(56 - 8*(box%8))) & 255;  /* we use bitwise left shift to get the valid code and & it with 255 (11111111) so that we get all the 8 bits */
            if(__builtin_popcount(tmp^in) <= 1) { printf("%hhu\n", tmp); break; }
        }
    }

    return 0;
}