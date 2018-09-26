#include <stdio.h>
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int abs(int a) { return (a < 0) ? a*(-1) : a;}
int main() {
	int a,b,c,d,e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int p,q,r,s; scanf("%d%d%d%d", &p, &q, &r, &s);
	int x,y, F; scanf("%d%d%d", &x, &y, &F);
	int move, gold = abs(c*x+d*y) % e;
	while(F > 0) {
		F--;
		move = abs(a*x + b*y) % 4;
		x += dx[move], y += dy[move];
		if(x == p && y == q) { x = r, y = s; continue;}
		else if(x == r && y == s) { x = p, y = q; continue;}
		gold += abs(c*x+d*y) % e;
	}
	printf("%d\n%d %d\n", gold, x, y);
	return 0;
}