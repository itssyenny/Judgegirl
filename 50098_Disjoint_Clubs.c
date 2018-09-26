#include <stdio.h>
int N, K;
int pick[101] = {0};
unsigned long long int member[101] = {0};
int __the_club(int id, int cnt, unsigned long long int common) {
	if(cnt == K) return 1;

	for(int i = id; i < N; i++) {
		if((common&member[i]) != 0) continue;
		if(__the_club(i+1, cnt+1, (common|member[i]))) {
			pick[i] = 1;
			return 1;
		} else pick[i] = 0;
	}
	return 0;

}
int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		int M; scanf("%d", &M);
		for(int j = 0; j < M; j++) {
			int a; scanf("%d", &a);
			member[i] |= (1ULL << a);
		}
	}

	if(__the_club(0, 0, 0ULL)) {
		for(int i = 0; i < N; i++) {
			if(pick[i] == 1) printf("%d\n",i);
		}
	}
	return 0;
}

// club0 : 6 7 9
// club1 : 11 13 17
// club2 : 6 13 15
// club3 : 0 4 5 8 33 63
// club4 : 10
