#include <stdio.h>
#include <stdlib.h>
int w[16384];
void __balancing_points(int l, int r) {
    int len = r-l+1;
    /* base case */
    if(len < 3) return;
    
    int com = -1;
    for(int i = l; i <= r; i++) {
        // printf("com %d\n",i );
        long long int left = 0, right = 0;
        for(int a = l; a < i; a++) 
            left += (w[a]*(i-a));

        for(int b = i+1; b < r+1; b++)
            right += (w[b]*(b-i));

        // printf("left %lld right %lld\n",left, right );
        if(left == right) {
            com = i; 
            break;
        }
    }
    if(com == -1) return;
    
    __balancing_points(l,com-1);
    printf("%d\n",com);
    __balancing_points(com+1,r);
        // printf("%lld\n",com);
}
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    __balancing_points(0,n-1);
    return 0;
}