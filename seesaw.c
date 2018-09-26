#include<stdio.h>
#include<stdbool.h>
int n, seesaw[2048];
int function () {
	// puts("MASUK function");
	int index, left_sum, right_sum;
	bool mark = false;

	for(int i = 0; i < n-1; i++) {
		index = i, left_sum = 0, right_sum = 0;
		int pos;
		
		for(int j = 0; j < n; j++) {

			if((pos = index - j) < 0) pos *= -1;
			if(j < index) left_sum += (pos * seesaw[j]);
			else if(j > index) right_sum += (pos * seesaw[j]);
		}

		if(left_sum == right_sum) {mark = true; break;}
	}

	if(mark == false) return -1;
	else return index;

}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &seesaw[i]);
	}

	int index;
	for(int i = 0; i < n; i++) {
		index = function();
		if(index == -1) {
			int temp = seesaw[i];
			seesaw[i] = seesaw[n-i-1];
			seesaw[n-i-1] = temp;
		} 
		else break;
	}

	//here is the finishing moment :
	for(int i = 0; i < n; i++) {
		if(i == index) printf("v%c", " \n"[i == n-1]);
		else printf("%d%c",seesaw[i], " \n"[i == n-1]);
	}

	return 0;
}