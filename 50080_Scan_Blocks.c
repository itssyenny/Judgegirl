#include<stdio.h>
#include<stdlib.h>

int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		int x, max = -10001, min = 10001, count = 0;
		while(count < N && scanf("%d", &x) != EOF) {
			max = (x >= max) ? x : max;
			min = (x < min) ? x : min;
			count++;
		}

		if(count == N) printf("%d\n",max);
		else printf("%d\n",min);
	}
		return 0;
}