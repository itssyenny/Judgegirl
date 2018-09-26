#include <stdio.h>
int main(int argc, char const *argv[]) {
	int N, M, R, ball;
	int remainsA = 0, remainsB = 0;
	scanf("%d %d %d", &N, &M, &R);
	if(R == 0) {
		while(~scanf("%d", &ball)) {
			if(N >= ball) N = N - ball;
			else if(M >= ball) M = M - ball;
			printf("%d %d\n", N, M );
		}
	}
	else if(R == 1) {
		while(~scanf("%d", &ball)) {
			remainsA = N - ball, remainsB = M - ball;
			if(remainsA >= 0 && remainsB >= 0) {
				if(remainsA <= remainsB) N = N - ball;
				else M = M - ball;
			}
			else if(remainsA >= 0 || remainsB >= 0) {
				if(remainsA <= -1) M = M - ball;
				else N = N - ball;
			}
			printf("%d %d\n", N, M );
		}
	}

	return 0;
}