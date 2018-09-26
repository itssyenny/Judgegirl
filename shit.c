#include <stdio.h>
int main () {
	int k; scanf("%d", &k);
	int n, ans = 0, valid = 0;
	while(~scanf("%d", &n)) {
		ans += n;
		if(valid || (ans/k)) {
			printf("%d\n", ans/k);
			valid = 1;
		}
		ans = (ans % k) * 10;
	}
	return 0;
}