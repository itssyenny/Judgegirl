#include <stdio.h>
int main () {
	int M; scanf("%d", &M);
	if(M > 0 && M%2 == 0 && (M < 1000 || M >10000)) puts("1");
	else puts("0");
	return 0;
}