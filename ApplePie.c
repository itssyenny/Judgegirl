#include <stdio.h>
int main() {
	int a,b; scanf("%d%d", &a, &b);
	int sum = 0, layer = 0;
	for(int i = a; i <= b; i++) {
		sum += i;
		if(i != a && i != b) layer++;
	}
	printf("%d\n%d\n",sum, a+b+2*layer);
	return 0;
}