#include <stdio.h>
int abs(int a) {return (a < 0) ? a * -1 : a;}
int distance(int px, int py, int pz, int qx, int qy, int qz) { return abs(px-qx) + abs(py-qy) + abs(pz-qz);}
int main () {
	int N, x0,y0,z0; scanf("%d%d%d", &x0,&y0,&z0);
	int mx,my,mz, bx,by,bz;
	scanf("%d%d%d", &mx,&my,&mz);
	scanf("%d%d%d", &bx, &by, &bz);
	scanf("%d", &N);

	int i = 1, ins, black_hole_disappeared = 0;
	while(i <= N && scanf("%d", &ins) != EOF) {
		if(ins == 1) x0++;
		else if(ins == 2) x0--;
		else if(ins == 3) y0++;
		else if(ins == 4) y0--;
		else if(ins == 5) z0++;
		else if(ins == 6) z0--;

		if(distance(x0,y0,z0,mx,my,mz) < 10) break;
		else if(!black_hole_disappeared && distance(x0,y0,z0,bx,by,bz) < 10) {
			x0 = bx, y0 = by, z0 = bz;
			black_hole_disappeared = 1;
		}
		else if(distance(x0,y0,z0,mx,my,mz) < 10 && distance(x0,y0,z0,bx,by,bz) < 10) break;

		/* print the result if i % 5 == 0 */
		if(i%5 == 0) printf("%d %d %d\n", x0,y0,z0);
		i++;
	}

}