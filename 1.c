#include <stdio.h>
#include <math.h>
int main () {
	int num;
	long long int ans = 0;
	scanf("%d", &num);
	ans = num;
	int tmp = num, count = 0;
	if(num == 0) count++;
	while(tmp > 0) {
		tmp /= 10;
		count++;
	}
	// count--;
	while(scanf("%d", &num) != EOF) {
		tmp = num;
		ans = ans+ num * pow(10,count);
		if(num == 0) count++;
		while(tmp > 0) {
			tmp /= 10;
			count++;
		} 
		
	}
	printf("%lld\n", ans);
}
// 1
// 2
// 3
// 4
// 5
// 54321