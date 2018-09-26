#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[1024]; scanf("%s", str);
	char command[1024] = {};
	while(~scanf("%s", command)) {
		if(command[0] == 'p') {printf("%s\n", str);} 
        else if(command[0] == 's') {
            char delim[2] = {command[1], '\0'};
            /* strtok returns a pointer so your ans needs to be so */
            char *A = strtok(&command[2], delim);   //&command[2] == command+2 == qwer
            char *B = strtok(NULL, delim);
            // printf("A %s B %s\n", A, B );
            // printf("%s\n",&command[2] );
            /* strstr is to find a substring in a string */
            char *ret = strstr(str,A);
            if(ret != NULL) {
                if(strlen(A) == strlen(B)) {
                    strncpy(ret, B, strlen(B));
                } else {
                    // printf("ret %s\n", ret);
                    /* move forward the remaining chars */
                    char *tmp = ret;
                    for(int i = 0; i < strlen(ret); i++) {
                        ret[i+strlen(B)] = tmp[i+strlen(A)];
                    }
                    ret[strlen(ret)] = '\0';
                    strncpy(ret, B, strlen(B));
                }
            } else continue;
        }	
	}
	return 0;
}