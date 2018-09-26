#include <stdio.h>
int main() {
	int M,N,X1,Y1,E1,N1,F1,X2,Y2,E2,N2,F2;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M,&N,&X1,&Y1,&E1,&N1,&F1,&X2,&Y2,&E2,&N2,&F2);
	int finish1 = E1 + N1, finish2 = E2 + N2, round = 0, explode = 0;
	while(F1 > 0 || F2 > 0) {
        if(F1 > 0) {
            if((round % finish1) < N1) Y1 = (Y1+1)%N;
            else if(N1 < (round%finish1) < E1) X1 = (X1+1)%M;
            F1--;
        }

        if(F2 > 0) {
            if((round % finish2) < E2) X2 = (X2+1)%M;
            else if(E2 < (round % finish2) < N2) Y2 = (Y2+1)%N;
            F2--;
        }

        round++;

        /* explode */
        if(X1 == X2 && Y1 == Y2) {
           printf("robots explode at time %d\n", round); break;
        } else if (!F1 && !F2) {
            printf("robots will not explode\n"); break;
        }

	}
    
	return 0;
}