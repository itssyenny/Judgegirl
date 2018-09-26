#include <stdio.h>
#include <limits.h>
int x[16], y[16], c[16], new[16] = {};
int abs(int a) {
	return (a < 0) ? a * (-1) : a;
}
int main(){
	int n,m; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
	}
	scanf("%d", &m);
	while(m-- > 0) {
		int a,b; scanf("%d%d", &a, &b);
		// printf("\n(%d, %d)\n",a, b );
		int idx, dist, min = INT_MAX, xx_temp = INT_MAX, yy_temp = INT_MAX;
		for(int i = 0; i < n; i++) {
			dist = abs(x[i]-a) + abs(y[i]-b);
			// printf("dist %d, min %d\n", dist, min);
			// printf("now (%d, %d) and temp (%d, %d) \n", x[i], y[i], xx_temp, yy_temp );
			if(dist < min) {
				if(new[i]+1 <= c[i]) {
					// puts("MASUK DIST < MIN");
					idx = i, xx_temp = x[i], yy_temp = y[i], min = dist;
				}
			} 
			else if(dist == min) {
				if(new[i]+1 <= c[i]) {
					if(x[i] < xx_temp) {
						// puts("MASUK X < xx_temp");
						idx = i, xx_temp = x[i], yy_temp = y[i];
					} else if(x[i] == xx_temp) {
						// puts("MASUK X == xx_temp");
						idx = i, xx_temp = x[i], yy_temp = y[i];
					}
				}
				
			} else continue;
			// printf("new[%d] = %d , c[%d] = %d\n",idx, new[idx], idx, c[idx]);
		}
		new[idx]++;
	}

	for(int i = 0; i < n; i++) {
		printf("%d\n", new[i] );
	}
	return 0;
}