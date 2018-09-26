#include <stdio.h>
int a[16][16] = {}, b[16][16] = {};
int abs(int a) { return (a < 0) ? a * -1 : a; }
int main() {
	int n,k,m,d; scanf("%d %d %d %d", &n, &k, &m, &d);

	/* scanf the array */
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	/* scanf the pattern */
	int sump = 0;
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			scanf("%d", &b[i][j]);
			sump += b[i][j];
		}
	}

	int row = -1, col = -1;
	/* you need to count how many times it needs to loop = n-k+1 */
	for(int i = 0; i < n-k+1; i++) {
		for(int j = 0; j < n-k+1; j++) {

			/* count the mismatch */
			int mismatch = 0, summ = 0;
			for(int c = i, x = 0; x < k; c++, x++) {
				for(int d = j, y = 0; y < k; d++, y++) {
					summ += a[c][d];
					if(b[x][y] != a[c][d]) mismatch++;
				}
			}

			if(abs(summ-sump) <= d && mismatch <= m) {
				if(i > row) row  = i, col = j;
				else if(i == row && j > col) row = i, col = j;
			}

		}
	}

	/* printf the upper left row and col of the last matching matrix in the array */
	printf("%d %d\n", row, col);
	return 0;
}