#include<stdio.h>

void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]) {
	int traversed[N+1][M+1];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			traversed[i][j] = 0;
		}
	}
	int dir[8][2] = {{0,1} , {0,-1} , {1,0} , {-1,0} , {1,1} , {-1,-1} , {-1,1} , {1,-1}};
	int A_stop = 0, B_stop = 0;
	int A_steps = 0, B_steps = 0;

	//we are now at (A_r, A_c) and (B_r, B_c) :
	traversed[A_r][A_c] = 1;
	traversed[B_r][B_c] = 1;

	while(A_stop == 0 || B_stop == 0) {
		int tmp_r, tmp_c;

		//traveller A and B don't move initially :
		int A_dir = -1, B_dir = -1;	

		if(!A_stop) {
			int max_height = map[A_r][A_c];
			for(int i = 0; i < 8; i++) {
				tmp_r = A_r + dir[i][0];
				tmp_c = A_c + dir[i][1];

				if(tmp_c < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= M) continue;
				if(map[tmp_r][tmp_c] > max_height) {max_height = map[tmp_r][tmp_c]; A_dir = i;}
			} //end for direction

			// printf("current height of A : %d , direction #%d\n",max_height, A_dir);

		//we get the new direction of A and the new height, so change the old version :
			directionA[A_steps] = A_dir;

			//cannot find the higher mountain, then stop :
			A_stop = (A_dir == -1) ? 1 : 0;
			A_steps++; 

			//change the POSITION of the row and column of A :
			A_r += (A_dir == -1) ? 0 : dir[A_dir][0];
			A_c += (A_dir == -1) ? 0 : dir[A_dir][1];

			//if the field has been travelled :
			if(traversed[A_r][A_c] == 1) {directionA[A_steps] = -1; A_stop = 1;} 
			else traversed[A_r][A_c] = 1; //has been travelled then

		} //end of if A

		if(!B_stop) {
			int min_height = map[B_r][B_c];

			for(int i = 0; i < 8; i++) {
				tmp_r = B_r + dir[i][0];
				tmp_c = B_c + dir[i][1];
				if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= M) continue;
				if(map[tmp_r][tmp_c] < min_height) {
					// printf("B : row %d col %d\n", tmp_r, tmp_c);
					min_height = map[tmp_r][tmp_c]; B_dir = i;}
			} //end for direction

			// printf("current height of B : %d , direction #%d\n",min_height, B_dir);

			directionB[B_steps] = B_dir;
			B_stop = (B_dir == -1) ? 1 : 0;
			B_steps++;

			//change the POSITION :
			B_r += (B_dir == -1) ? 0 : dir[B_dir][0];
			B_c += (B_dir == -1) ? 0 : dir[B_dir][1];

			if(traversed[B_r][B_c] == 1) {directionB[B_steps] = -1; B_stop = 1;} 
			else traversed[B_r][B_c] = 1;
		} //end if B

		//if they meet each other :
		if(A_r == B_r && A_c == B_c) {
			directionA[A_steps] = -1;
			directionB[B_steps] = -1;
			A_stop = 1, B_stop = 1;
		}
	}	
}

int main() {
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
 
    return 0;
}