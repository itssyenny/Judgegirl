#include <stdio.h>
int array[101][101] = {};
int abs(int num) { return (num < 0) ? num * (-1) : num;}
int diagonal(int x1, int y1, int x2, int y2) {
    int r = abs(y1-y2) / abs(x1-x2) , m = (y1-y2) % (x1-x2);
    return ((m == 0) && (r == 1));
}
int main () {
	int l, x, y; scanf("%d%d%d", &l, &x, &y);
    int n, a, b, prev_a, prev_b;
	for(int i = 0; i < l; i++) {
		scanf("%d", &n);
		for(int j = 0; j < n; j++) {
			scanf("%d %d", &a, &b);
            if(j == 0) {
                array[a][b] = 1;
            } else {
				if(a == prev_a) { /* horizontal */
					int left, right;
                    if(b < prev_b) left = b, right = prev_b;
                    else left = prev_b, right = b;
                    for(int k = left; k <= right; k++) { array[a][k] = 1; }
				} 
				else if(b == prev_b) { /* vertical */
					int top, bottom;
                    if(a < prev_a) top = a, bottom = prev_a;
                    else top = prev_a, bottom = a;
                    for(int k = top; k <= bottom; k++) { array[k][b] = 1; }
				}
				else if(diagonal(prev_a, prev_b, a, b)) { /* 45o diagonal */
					int min_x, min_y, max_x, max_y;
                    if(a < prev_a) min_x = a, max_x = prev_a;
                    else min_x = prev_a, max_x = a;
                    if(b < prev_b)  min_y = b, max_y = prev_b;
                    else min_y = prev_b, max_y = b;

                    array[a][b] = 1, array[prev_a][prev_b] = 1;
                    for(int k = min_x; k <= max_x; k++) {
                        for(int h = min_y; h <= max_y; h++) {
                            if(a != k && prev_a != k && diagonal(prev_a, prev_b, k, h) && diagonal(a, b, k, h)) {
                                array[k][h] = 1;
                            }
                        }
                    }
				}
				else {
                    printf("ERROR %d %d\n", i+1, j+1);
                    return 0;
                }
            }
			prev_a = a, prev_b = b;
		}
	}
    for(int i = x-1; i >= 0; i--) {
	  for(int j = 0; j < y; j++) {
		printf("%d", array[j][i]);
	  }
	  printf("\n");
    }

	return 0;
}