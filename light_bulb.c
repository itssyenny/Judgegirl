//light_bulb.c

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
	int n, x;
	printf("Enter n:");
	scanf("%d",&n);
	int a[n][n];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 && j == 0) printf("  ");
			else if(i == 0) printf(j != n ? "%d ":"%dee\n",j + n - 1);
			else if(j == 0) printf("%d ",i - 1);
			else printf(j != n ? "l ":"l\n");
		}
	}
	printf("Enter 1 for all ones, 2 for customized initial state: \n");
	scanf("%d",&x);
	if(x == 1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				printf(j != n-1 ? "%d ":"%d\n",1);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				a[i][j] = 1;
		}
	}
	else if(x == 2){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				scanf("%d",&a[i][j]);
		}
		printf("---------------------------\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				printf(j != n-1 ? "%d ":"%d\n",a[i][j]);
		}
	}
	int op[1000], idx = 0, operator;
	while(scanf("%d", &operator) != EOF){
		if(operator < 0 || operator >= 2*n){
			printf("Invalid Switch!!\n");
		}
		else{
			op[idx] = operator;
			idx ++;
			if(operator < n){ // row
				for(int j = 0; j < n; j++){
					if(a[operator][j] == 0) a[operator][j] = 1;
					else a[operator][j] = 0;
				}
			}
			else{ // column
				for(int i = 0; i < n; i++){
					if(a[i][operator%n] == 0) a[i][operator%n] = 1;
					else a[i][operator%n] = 0;
				}
			}
			printf("---------------------------\n");
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)
					printf(j != n-1 ? "%d ":"%d\n",a[i][j]);
			}
		}
	}
	return 0;
}