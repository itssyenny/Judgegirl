#include <stdio.h> 
#include <stdlib.h>
#include <string.h>    // strlen(s)
#include <ctype.h>
int main() {
    char s[1024];
    
    while (scanf("%s", s) == 1) {
        int a[100000] = {0};
        int num[100000] = {0};
        // scanf("%s", s);
        int count = 0;
        int n = (int) strlen(s);    // strlen("CSIE") = 4, actually use "CSIE\0" in memory.
        for (int i = 0; i < n; i++) {
            char c = s[i];    
            /*
                input "CSIE", 
                s[0] = 'C', s[1] = 'S', ...
            */
            /* add you code here */
            if(!isdigit(c)) continue;
            else {
                char tmp[10000] = {};
                int cnt = 0;
                while(isdigit(s[i])) {
                    tmp[cnt] = s[i];
                    cnt++; i++;
                }
                i--;
                num[count] = atoi(tmp);
                count++;
            }
        }
        /* add you code here */
        for(int i = 0; i < count; i++) {
            printf("%d\n",num[i]);
        }
        
    }
    return 0;
}