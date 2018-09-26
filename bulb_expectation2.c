//bulb_expectation2.c
// this code is for task two with task one strategy
// it calculates the expected rounds needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TEST_TIMES 1000

int n, switches[100], idx = 0, all_off = 0;

int row_bulbs_on_num(int *p, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(p[i] == 1) count++;
	}
	return count;
}

int col_bulbs_on_num(int p[][n], int n, int j){
	/*for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++)
			printf(k != n-1 ? "%d ":"%d\n",p[i][k]);
	}*/
	int count = 0;
	for(int i = 0; i < n; i++){
		if(p[i][j] == 1) count++;
	}
	return count;
}

void check_row(int a[][n], int x){
	for(int i = 0; i < n; i++){
		if(i == x){
			if(a[i][0] == 1) continue;
			else {
				all_off++;
				switches[idx] = i;
				idx++;
			}
		}
		else{
			int b = a[i][0];
			for(int j = 1; j < n; j++){
				if(a[i][j] != b){
					printf("Unsolvable!!!\n");
					return;
				}
			}
			if(b == 1) continue;
			else{
				all_off++;
				switches[idx] = i;
				idx++;
			}
		}
	}
	printf("Press switches: ");
	for(int i = 0; i < idx; i++){
		printf(i != idx - 1 ? "%d ":"%d\n", switches[i]);
	}
	return;
}

void check_col(int a[][n], int x){
	for(int i = 0; i < n; i++){
		if(i == x){
			if(a[0][i] == 1) continue;
			else{
				all_off++;
				switches[idx] = i + n;
				idx++;
			}
		}
		else{
			int b = a[0][i];
			for(int j = 1; j < n; j++){
				if(a[j][i] != b){
					printf("Unsolvable!!!\n");
					return;
				}
			}
			if(b == 1) continue;
			else{
				all_off++;
				switches[idx] = i + n;
				idx++;
			}
		}
	}
	printf("Press switches: ");
	for(int i = 0; i < idx; i++){
		printf(i != idx - 1 ? "%d ":"%d\n", switches[i]);
	}
	return;
}

int check(int *p, int *q){
	int flag = 1;
	for(int i = 0; i < n; i++){
		if(p[i] != q[i]){
			flag = 0;
			break;
		}
	}
	if(flag == 1) return 0;
	else return 1;
}

int check2(int *a, int n){
	int flag = 1;
	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			flag = 0;
			break;
		}
	}
	if(flag == 1) return 0;
	else return 1;
}

int main(){
	double p, num;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter p: ");
	scanf("%lf", &p);
	int a[n][n];
	int init[n][n], final[n][n], buf_idx = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 && j == 0) printf("\t");
			else if(i == 0) printf(j != n ? "%d\t":"%d\n",j + n - 1);
			else if(j == 0) printf("%d\t",i - 1);
			else printf(j != n ? "l\t":"l\n");
		}
	}
	printf("--------------------\nEnter initial state:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max_on_num = -1, max_on_row_idx = -1, max_on_col_idx = 0, Is_row = 1;
	int flags = 1;
	for(int i = 0; i < n; i++){
		int tmp = row_bulbs_on_num(a[i],n);
		if(tmp == n){
			check_row(a,i);
			flags = 0;
			break;
			//return 0;
		}
		else if(tmp > max_on_num && tmp != n){
			max_on_num = tmp;
			max_on_row_idx = i;
		}
	}
	
	
	for(int j = 0; j < n; j++){
		int tmp = col_bulbs_on_num(a,n,j);
		//printf("tmp = %d, j = %d\n",tmp,j);
		if(tmp == n){
			check_col(a,j);
			flags = 0;
			break;
			//return 0;
		}
		else if(tmp > max_on_num && tmp != n){
			Is_row = 0;
			max_on_num = tmp;
			max_on_col_idx = j;
		}
	}
	//printf("max_on_num = %d\n",max_on_num);
	//printf("%d\n",max_on_col_idx);
	//printf("%d",Is_row);
	if(Is_row && flags){
		for(int j = 0; j < n; j++){
			if(a[max_on_row_idx][j] == 0){
				switches[idx] = j + n;
				idx++;
				for(int i = 0; i < n; i++){
					init[buf_idx][i] = a[i][j];
					if(a[i][j] == 0) a[i][j] = 1;
					else a[i][j] = 0;
					final[buf_idx][i] = a[i][j];
				}
				buf_idx++;
			}
		}
		check_row(a,max_on_row_idx);
	}
	else if(flags){
		for(int i = 0; i < n; i++){
			if(a[i][max_on_col_idx] == 0){
				switches[idx] = i;
				idx++;
				for(int j = 0; j < n; j++){
					init[buf_idx][j] = a[i][j];
					if(a[i][j] == 0) a[i][j] = 1;
					else a[i][j] = 0;
					final[buf_idx][j] = a[i][j];
				}
				buf_idx++;
			}
		}
		check_col(a,max_on_col_idx);
	}

	printf("\nbrute force pressing:\n");
	for(int i = 0; i < buf_idx; i++){
		printf("initial: ");
		for(int j = 0; j < n; j++){
			printf(j != n-1 ? "%d ":"%d ",init[i][j]);
		}
		printf("final: ");
		for(int j = 0; j < n; j++){
			printf(j != n-1 ? "%d ":"%d\n",final[i][j]);
		}
	}
	for(int i = 0; i < all_off; i++){
		printf("initial: ");
		for(int j = 0; j < n; j++) printf(j != n-1 ? "0 ":"0 ");
		printf("final: ");
		for(int j = 0; j < n; j++) printf(j != n-1 ? "1 ":"1\n");
	}
	
	int tmp[n];
	srand(time(NULL));
	double expected_rounds = 0.0;
	for(int k = 0; k < buf_idx; k++){
		for(int c = 0; c < n; c++) tmp[c] = init[k][c];
		int sum = 0;
		for(int x = 0; x < TEST_TIMES; x++){
			int counter = 0;
				while(check(init[k],final[k])){
					counter ++;
					for(int i = 0; i < n; i++){
						num = (double)rand()/RAND_MAX;
						//printf("num = %lf\n",num);
						if(num > p){
							if(init[k][i] == 0) init[k][i] = 1;
							else init[k][i] = 0;
							//printf(i != n - 1 ? "%d ":"%d\n",init[i]);
						}
						else{
							//printf(i != n - 1 ? "%d ":"%d\n",init[i]);
							continue;
						}
						
					}

				}
			sum += counter;
			for(int c = 0; c < n; c++) init[k][c] = tmp[c];
		}
		expected_rounds += (double)sum/TEST_TIMES;
	}

	int zero[n], one[n];
	memset(zero,0,sizeof(zero));
	for(int i = 0; i < n; i++) one[i] = 1;
	for(int i = 0; i < all_off; i++){
		int sum2 = 0;
		for(int x = 0; x < TEST_TIMES; x++){
			int counter = 0;
			while(check2(zero, n)){
				counter ++;
				for(int i = 0; i < n; i++){
					num = (double)rand()/RAND_MAX;
					if(num > p){
						if(zero[i] == 0) zero[i] = 1;
						else zero[i] = 0;
					}
					else continue;
				}

			}
			sum2 += counter;
			memset(zero,0,sizeof(zero));
		}
		expected_rounds += (double)sum2/TEST_TIMES;
	}
	printf("expected rounds: %lf\n", expected_rounds);
}