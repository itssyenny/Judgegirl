#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main() {
    int a, k; scanf("%d", &k);
    int len = 0, track = 0, countThePos = 0, max = INT_MIN;
    bool isPos = true;
    while(scanf("%d", &a) && a != 0) {
        if((a > 0 && isPos) || (a < 0 && !isPos)) {
            len++, track++;
            countThePos = (isPos) ? countThePos+1 : 0;
        }
        else {
            if(a > 0) { /* positive */
                countThePos++; /* 1 1 1 (1 1 -1 -1 ...) */
                countThePos = (countThePos >= k) ? k : countThePos;
            }
            else countThePos = 0;
            printf("Num entering %d\n",a);
            len = countThePos, track = countThePos, isPos = true;
        }

        if(track == k) { /* reset */
            if(isPos && len > max) max = len;
            track = 0;
            isPos = (isPos) ? false : true;
        }
    }
    if(max == k) max = 0;
    printf("%d\n", max);
    return 0;
}