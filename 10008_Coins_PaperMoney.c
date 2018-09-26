#include<stdio.h>
int main() {
	int a; 
	while(scanf("%d", &a) != EOF) {
		int onethousand = 0, fivehundred = 0, onehundred = 0, fifty = 0;
		int ten = 0, five = 0, one = 0;
		while(a > 0) {
			if(a >= 1000) {
				onethousand++; a-=1000;
			} else if(a >= 500) {
				fivehundred++; a-=500;
			} else if(a >= 100) {
				onehundred++; a-=100;
			} else if(a >= 50) {
				fifty++; a-=50;
			} else if(a >= 10) {
				ten++; a-=10;
			} else if(a >= 5) {
				five++; a-=5;
			} else if(a >= 1) {
				one++; a-=1;
			}
		}
		printf("%d %d %d %d %d %d %d\n", onethousand, fivehundred, onehundred, fifty, ten, five, one);
	}
	
	return 0;
}