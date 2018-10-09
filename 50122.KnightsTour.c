#include <stdio.h>
#include <limits.h>
long long int map[101][101] = {};
int y[10001] = {}, x[10001]={};
int dx[8]= {-2,-1,1,2,2,1,-1,-2};
int dy[8]= {1,2,2,1,-1,-2,-2,-1};
int stepcount[10001]={}, notmove[10001] = {};
int check(int x, int y, int n) {
	int move = 0;
	for(int k = 0; k < 8; k++) {
		int px = x+dx[k];
		int py = y+dy[k];
		if((px >= 0 && px < n) && (py >= 0 && py < n) && map[px][py] == 0) move++;
		else continue;
	}

	return move;
}
void print_map(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%lld%c", map[i][j], " \n"[j==n-1]);
		}
	}
}
int main () {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int krow,kcol; scanf("%d%d", &krow, &kcol);
		x[i] = krow, y[i]= kcol;
		map[krow][kcol] = 10000*(i+1) + stepcount[i];
		stepcount[i] = 1;
	}
	
	int square = m, stop = 0;
	while(stop < m) {
		/* each player's turn */
		for(int i = 0; i < m; i++) {
			if(notmove[i] == 1) continue;
			int minx, miny, min = INT_MAX, valid = 0, move;
			/* check the possible move */
			for(int j = 0; j < 8; j++) {
				int px = x[i] + dx[j], py = y[i] + dy[j];

				if( (px >= 0 && px < n) && (py >= 0 && py < n) && map[px][py] == 0) {
					move = check(px, py, n);
					if(move < min) {
						min = move;
						minx = px, miny = py;
						valid = 1; 
					}
				}
			}
			/* change the position */
			if(!valid) {stop++; notmove[i] = 1;}
			else if(valid) {
				x[i] = minx, y[i] = miny;
				map[minx][miny] = 10000*(i+1) + stepcount[i];
				stepcount[i]++;
			}
		}
	}
	print_map(n);
	return 0;
}