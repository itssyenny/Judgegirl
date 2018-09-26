#include <stdio.h>
int main(void) {
	int num, tmp = 0; scanf("%d", &num);
	printf("The number is %d\n", num);
	while(num > 0) {
		tmp = tmp * 10 + num % 10;
		printf("%d\n", tmp);
		num /= 10;
		tmp /= 10;
	}
	return 0;
}
