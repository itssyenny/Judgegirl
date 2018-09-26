#include <stdio.h>
int main() {
	int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
	scanf("%d%d%d%d%d%d%d%d", &Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy);
	int perimeter = (Dy-Ay)+(Bx-Ax)+(By-Ay)+(Cx-Bx)+(Cy-By)+(Cx-Dx)+(Cy-Dy)+(Dx-Ax);
	int area = (Bx-Ax)*(By-Ay)+(Cx-Dx)*(Cy-Dy)+(Cx-Ax)*(Dy-By);
	printf("%d\n%d\n", perimeter, area);
}