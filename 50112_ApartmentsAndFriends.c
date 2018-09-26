#include <stdio.h>
#include <stdlib.h>
int a[16][16] = {};
int min;
void dfs(int n, int pos, int visited[], int ans[], int count) {
	if(count >= min) return;
	if(pos == n) {
		min = (count < min) ? count : min;
		return;
	}
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			visited[i] = 1;
			ans[pos] = i;
			int tmp = count;
			// printf("ans[%d] = %d\n", pos, ans[pos]);
			/* we start from i and traverse to all the nodes. */
			for(int j = 0; j < pos; j++) {
				if(a[i][ans[j]]) tmp += (pos-j);
				// printf("dist %d\n", count );
			}
			dfs(n, pos+1, visited, ans, tmp);
			visited[i] = 0; /* finish traversing & reset the visited to 0. */
		}
	}
}
void initialize(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	return;	
}
int main() {
	int n,m,x,y; scanf("%d%d", &n, &m);
	initialize(n);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	int visited[16] = {0}, ans[16];
	min = 0x3f3f3f3f;
	dfs(n, 0, visited, ans, 0);
	printf("%d\n",min);

	return 0;
}