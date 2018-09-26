#include <stdio.h>
int main () {
	int n, count = 0, zero = 0;
	int even = 0, eleven = 0;
	int oddsum = 0, evensum = 0;
	while(~scanf("%d", &n)) {
		count++;
		even = (n%2 == 0) ? 1 : 0;
		if(n == 0) zero++;
		if(count % 2 == 0) evensum += ;
		else oddsum += n;
	}

	if((evensum-oddsum) % 11 == 0) eleven = 1;
	else eleven = 0;

	printf("%d\n%d\n%d\n%d\n", count, even, zero, eleven);
	return 0;
}


