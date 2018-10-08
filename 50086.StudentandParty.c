#include <stdio.h>
int Relations[32770][258] = {};
int count[32770] = {}, visited[32770] = {};
int main () {
	int a,b,n,e; scanf("%d%d", &n, &e);
	for(int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		Relations[a][count[a]++] = b;
		Relations[b][count[b]++] = a;
	}

	int host;
	while(scanf("%d", &host) != EOF) {
		visited[host] = 1;
		for(int i = 0; i < count[host]; i++) {
			visited[Relations[host][i]] = 1;
			// printf("Relations %d\n", Relations[host][i]);
		}
	}

	for(int i = 0; i < n; i++) {
		// printf("visited[%d] = %d\n", Relations[host][i], visited[Relations[host][i]]);
		if(visited[i] == 0) printf("%d\n", i);
	}
	return 0;
}