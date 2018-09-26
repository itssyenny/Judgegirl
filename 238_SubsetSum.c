#include <stdio.h>
#include <stdlib.h>
int a[16], ans = 0;
void xe(int n,int idx,int after,int sum) {
    // printf("ans %d , idx %d , after %d\n", ans, idx, after );
    if(after > sum) return;
    if(idx == n) {  /* after coming to end, see the sum */
        if(after == sum) ans++;
        return;
    }
    xe(n, idx+1, after, sum);
    xe(n, idx+1, after+a[idx], sum);
}
int main() {
    int n, k; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while(~scanf("%d", &k)) {
        ans = 0;
        xe(n,0,0,k);
        printf("%d\n", ans);
    }
 
    return 0;
}