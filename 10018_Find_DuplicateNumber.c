#include<stdio.h>
int a[10000];
int main () {
	int N; scanf("%d", &N);
	int count = 0, seq = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	} 
	int last = a[0];
	for(int i = 0; i < N; i++) {
		if(last == a[i]) {
			count++;
			last = a[i];
			continue;
		} else {
			// printf("%d\n",count);
			if(count >= 2) {
				seq++;
			}
			last =a[i];
			count = 1;
		}
	}
	printf("%d\n",seq);

	return 0;
}