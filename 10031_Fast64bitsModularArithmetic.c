#include <stdio.h>
 
int main()
{
    long long a, b, n, ans;
 
    while(scanf("%lld %lld %lld",&a,&b,&n) != EOF)
    {
        if(a >= n)
            a %= n;
        if(b >= n)
            b %= n;
 
        for(ans=0; b!=0; b>>=1) {
            printf("a %lld b %lld\n", a, b);
            if(b & 1)
            {
                ans += a;
                if(ans >= n)
                    ans -= n;
            }
 
            a <<= 1;
            if(a >= n)
                a -= n;
        }
 
        printf("%lld\n",ans);
    }
 
    return 0;
}