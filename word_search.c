#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stress(int rt, int ct, char **grid, char *word, int r, int c) {
	// puts("hey");
	int found = 0;
	if(r >= 0 && r <= rt && c >= 0 && c <= ct && *word == grid[r][c]) {
		char matched = *(word++);
		grid[r][c] = 0;
		if(*word == 0) found = 1;
		else {
			found += stress(rt, ct, grid,word, r,c+1);
			found += stress(rt, ct, grid, word, r,c-1);
			found += stress(rt, ct, grid,word, r+1,c);
			found += stress(rt, ct, grid,word, r-1,c);

			found += stress(rt, ct, grid,word, r-1,c-1);
			found += stress(rt, ct, grid,word, r-1,c+1);
			
			found += stress(rt, ct, grid,word, r+1,c-1);
			found += stress(rt, ct, grid,word, r+1,c+1);
		}
		grid[r][c] = matched;
	}
	return found;
}
int search(int rt, int ct, char **grid, char *word) {
	int found = 0;
	for(int i = 0; i < rt; i++) {
		for(int j = 0; j < ct; j++) {
			found += stress(rt-1, ct-1, grid, word, i, j);
		}
	}
	return found;
}
int main() {
	int t; scanf("%d", &t);
	int k = 0;
	
	while(k < t) {
		int n, m; scanf("%d%d", &n, &m);
		char *grid[1000];
		for(int r = 0; r < n; r++) {
			grid[r] = malloc(m+1);
			scanf("%s", grid[r]);
			
		}

		char s[1000]; scanf("%s", s);
		printf("Case %d: %d\n", k+1, search(n, strlen(grid[0]), grid, s));
		k++;
	}
	return 0;
}