#include <stdio.h>
#include <limits.h>
int distance(long long int x, long long int y, long long int a, long long int b, long long int r) {
	return ((x-a)*(x-a) + (y-b)*(y-b) <= r*r) ? 1 : 0;
}
int main () {
	int test; scanf("%d", &test);
	while(test--) {
		long long int x[3], y[3], r[3];
		for(int i = 0; i < 3; i++) {
			scanf("%lld%lld%lld", &x[i], &y[i], &r[i]);
		}
		
		/* check in each circle */
		int in1 = 0, inthree = 0;
		for(int i = 0; i < 3; i++) {
			for(int a = x[i]-r[i]; a <= x[i]+r[i]; a++) {

				for(int b = y[i]-r[i]; b <= y[i]+r[i]; b++) {

					/* check the point towards every circle */
					// int circle = 0;
					// for(int sh = 0; sh < 3; sh++) {
					// 	if(distance(x[sh], y[sh], a, b, r[sh])) circle++;
					// }
					if (distance(x[i], y[i], a, b, r[i]) && !distance(x[(i+1)%3], y[(i+1)%3], a, b, r[(i+1)%3]) && !distance(x[(i+2)%3], y[(i+2)%3], a, b, r[(i+2)%3])) in1++;
					if (distance(x[i], y[i], a, b, r[i]) && distance(x[(i+1)%3], y[(i+1)%3], a, b, r[(i+1)%3]) && distance(x[(i+2)%3], y[(i+2)%3], a, b, r[(i+2)%3])) inthree++;

					// if(circle == 1) in1++;
					// else if(circle == 3) inthree++;
					// printf("point (%d, %d) in %d circles\n", a, b, circle);
				}
			}


		}
		// printf("in 1 = %d, in 3 = %d\n", in1, inthree);
		printf("%d\n", in1 + inthree/3);

	}
}