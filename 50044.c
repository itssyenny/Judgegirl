#include <stdio.h>
#include <stdlib.h>
int a[1024][1024] = {}, row[1024], col[1024];
int main () {
	int N, M, Q; scanf("%d%d", &N, &M);
	int sx,sy, ex, ey; 
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	int num, len = abs(sx-ex) + abs(sy-ey) + 1;

	/* check the initial pos */
	if(sx == ex) { 
		/* horizontal */
		for(int i = 0; i < len; i++) row[i] = sx;
		num = sy;
		if(sy < ey) { for(int i = 0; i < len; i++) {col[i] = num; num++;} }
		else { for(int i = 0; i < len; i++) {col[i] = num; num--;} }
	}
	else {	
		/* vertical */
		for(int i = 0; i < len; i++) col[i] = sy;
		num = sx;
		if(sx < ex) { for(int i = 0; i < len; i++) {row[i] = num; num++;} }
		else { for(int i = 0; i < len; i++) {row[i] = num; num--;}}
	}

	// printf("\n");
	// for(int i = 0; i < len; i++) {
	// 	printf("%d |", row[i]);
	// }

	// printf("\n");
	// for(int i = 0; i < len; i++) {
	// 	printf("%d |", col[i]);
	// }

	scanf("%d", &Q);
	int hidx = 0, tidx = len-1;
	while(Q--) {
		/* reset all the variables */
		int ins, error = 0;
		int hx = row[hidx], hy = col[hidx];
		scanf("%d", &ins);

		if(ins == 0) hx++;
		else if(ins == 1) hx--;
		else if(ins == 2) hy++;
		else if(ins == 3) hy--;

		if(hx < 0 || hx >= N || hy < 0 || hy >= M) break;
		for(int i = 0; i < len; i++) {
			if(i == hidx || i == tidx) continue;
			else if(hx == row[i] && hy == col[i]) {
				/* if the head touches the body , then break */
				error = 1;
				break;
			}
		}

		if(error) break;

		/* change the head index */
		hidx = tidx;
		row[hidx] = hx, col[hidx] = hy;

		/* change the tail index */
		tidx = (tidx == 0) ? len-1 : tidx-1;
	}

	/* set the snake to 1 in the board array */
	for(int i = 0; i < len; i++) {
		a[row[i]][col[i]] = 1;
	}

	/* printf the board array */
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}