#include <stdio.h>
int mat[1001][1001];
int checkHalmiton(int N,int count,int now, int ans[], int visit[]) {
	if(count == N) {
		if(mat[now][0] == 1) {
			for(int i = 0; i < N; i++) {
				printf("%d ", ans[i]);
			} 
			puts("0");
			return 1;
		} else return 0;
	}
	for(int i = 0; i < N; i++) {
		if(!visit[i] && mat[now][i]) {
			visit[i] = 1;
			ans[count] = i;
			if(checkHalmiton(N, count+1, i, ans, visit)) return 1;
			else visit[i] = 0;
		}
	}
	return 0;
}
int main () {
	int N,E,x,y; scanf("%d%d", &N, &E);
	for(int i = 0; i < E; i++) {
		scanf("%d%d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	int ans[1001] = {0}, visit[1001] = {0};
	ans[0] = 0, visit[0] = 1; 
	/* count starts from 1 coz of the initial source = 0 */
	if(!checkHalmiton(N, 1, 0, ans, visit)) puts("NO SOLUTION");
	return 0;
}