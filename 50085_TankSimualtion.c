#include<stdio.h>
int map[500][500];
void fillzero(int N, int M);
void fillone(int L, int W);
void print(int N, int M);
int main() {
	int N, M, L, W, O; scanf("%d%d%d%d", &N, &M, &L, &W);
	fillzero(N,M);
	fillone(L,W);

	scanf("%d", &O);
	for(int i = 0; i < O; i++) {
		int x,y; scanf("%d%d", &x, &y);
		map[y][x] = 2;
	}

	int Ins, x = 0, y = 0;
	while(scanf("%d", &Ins) != EOF) {
		int obs = 0;
		switch(Ins) {
			case 0:
				print(N,M);
				break;
			case 1: //(x,y) -> (x+1,y)
				if(x+W < M) {
					for(int i = 0; i < L; i++) {
						if(map[y+i][x+W] == 2) obs++;
					}
					if(obs < 2) {
						for(int i = 0; i < L; i++) {
							map[y+i][x+W] = 1;
							map[y+i][x] = 0;
						}
						x++;
					}
				}
				break;
				case 2: //y++
					if(y+L < N) {
						for(int i = 0; i < W; i++) {
							if(map[y+L][x+i] == 2) obs++;
						}
						if(obs < 2) {
							for(int i = 0; i < W; i++) {
								map[y+L][x+i] = 1;
								map[y][x+i] = 0;
							}
							y++;
						}
					}
					break;
				case 3:
					if(x-1 >= 0) {
						for(int i = 0; i < L; i++) {
							if(map[y+i][x-1] == 2) obs++;
						}
						if(obs < 2) {
							for(int i = 0; i < L; i++) {
								map[y+i][x-1] = 1;
								map[y+i][x+W-1] = 0;
							}
							x--;
						}
					}
					break;
				case 4:
					if(y-1 >= 0) {
						for(int i = 0; i < W; i++) {
							if(map[y-1][x+i] == 2) obs++;
						}
						if(obs < 2) {
							for(int i = 0; i < W; i++) {
								map[y-1][x+i] = 1;
								map[y+L-1][x+i] = 0;
							}
							y--;
						}
					}
					break;
				case 5:
					if(x+W < M && y+L < N) {
						for(int i = 0; i < L; i++) {
							if(map[y+i+1][x+W] == 2) obs++;
						}
						for(int i = 0; i < W-1; i++) {
							if(map[y+L][x+i+1] == 2) obs++;
						}

						if(obs < 2) {
							for(int i = 0; i < L; i++) {
								map[y+i+1][x+W] = 1;
								map[y+i][x] = 0;
							}
							for(int i = 0; i < W; i++) {
								map[y+L][x+i+1] = 1;
								map[y][x+i] = 0;
							}
							x++; y++;
						}
					}
					break;
				default:
					break;
		}

	}
	// printf("\n");
	// print(N,M);
	return 0;
}

void fillzero(int N, int M) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			map[i][j] = 0;
		}
	}
	return;	
}
void fillone(int L, int W) {
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < W; j++) {
			map[i][j] = 1;
		}
	}
	return;
}
void print(int N, int M) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	return;
}