#include<stdio.h>
int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		int a, last = -1, frag = 0;
		for(int i = 0; i < N; i++) {
			scanf("%d", &a);
			if(last == a) continue;
			else {
				frag++; last = a;
			}
		}
		printf("%d\n", frag);

	}
	return 0;
}