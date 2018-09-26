#include <stdio.h>
int main() {
	int readyA = 0, readyB = 0, arrival = 0, onA, onB;
	while(~scanf("%d %d %d", &arrival, &onA, &onB)) {
		if(arrival >= readyA) {
			arrival = arrival + onA;
			readyA = arrival;
		} 
		else if(arrival < readyA) {
			arrival = readyA + onA;
			readyA = arrival;
		}

		if(arrival >= readyB) {
			arrival = arrival + onB;
			readyB = arrival;
		}
		else {
			arrival = readyB + onB;
			readyB = arrival;
		}

		printf("%d\n", readyB);
	}
	return 0;
}