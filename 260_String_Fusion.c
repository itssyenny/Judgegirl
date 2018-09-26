#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char ans[128], y[128];
    scanf("%s", ans);

    while(~scanf("%s", y)) {
        /* assign to the pointer to make it easy to change */
        char *ptrx = &ans[0];
        char *ptry = &y[0];

        while(*ptrx != '\0') {
            /* traverse the x to find y */
            if(strncmp(ptrx, ptry, strlen(ptrx)) == 0) {

                /* we find the matching one */
                ptry += strlen(ptrx);
                break;
            }
            ptrx++; 
        }

        /* concatenate y to x */
        strcat(ans,ptry);
    }

    printf("%s\n",ans);

    return 0;
}