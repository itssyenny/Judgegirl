#include <stdio.h>
int w[2050] = {};
void swap(int a, int b) {int tmp; tmp = w[a], w[a] = w[b], w[b] = tmp;}
int main () {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}

	int pivot, finished = 0; 
	for(int x = 0; x < n; x++) {

		/* search the pivot one by one */
		for(pivot = 0; pivot < n; pivot++) {
			
			int left = 0, right = 0;
			for(int i = 0; i < n; i++) {
				if(i < pivot) left += (w[i] * (i-pivot));
				else right += (w[i] * (i-pivot));
			}

			if(left+right == 0) {
				finished = 1;
				break;
			}
		}

		if(finished) break;
		else {
			// swap(x, n-x-1);
			w[x] ^= w[n-x-1] ^= w[x] ^= w[n-x-1];
		}
	}

	for(int i = 0; i < n; i++) {
		if(pivot == i) {
			printf("v");
			if(i == n-1) printf("\n");
			else printf(" ");
		}
		else printf("%d%c", w[i], " \n"[i==n-1]);
	}
}