#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
        for(int i = 0; i < a; i++) A[i] = NULL;
        for(int i = 0; i < b; i++) B[i] = NULL;
 
        char line[64];
        // char *token[5]; //if you use strtok, you need to transfer the result into char pointer.
        int bound[3] = {a,b,c};
        char token1[2] = {} , token2[2] = {}, trash[2] = {};
        int num1, num2;
        while(fgets(line, 64, stdin) != NULL) {
               int ant = sscanf(line, "%s%d%s%d%s", token1, &num1, token2, &num2, trash);
               // printf("%d\n",ant);
                if(ant != 4) {ant = 0; puts("0"); continue;}
                if(strlen(token1) == 0 || strlen(token2) == 0 || num1 < 0 || num2 < 0) {ant = 0; puts("0"); continue;}
                if(ant != 0) {
                        if(strcmp(token1, "A") == 0 && strcmp(token2, "B") == 0) {
                                if(num1 < 0 || num1 >= a || num2 < 0 || num2 >= b) {puts("0"); continue;}
                                A[num1] = &B[num2];
                                puts("1"); 
                                continue;
                        }
                        else if(strcmp(token1, "B") == 0 && strcmp(token2, "C") == 0) {
                                if(num1 < 0 || num1 >= b || num2 < 0 || num2 >= c) {puts("0"); continue;}
                                B[num1] = &C[num2];
                                puts("1"); 
                                continue;
                        } else {puts("0"); continue;}
                }
        }
        return;
}
int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}