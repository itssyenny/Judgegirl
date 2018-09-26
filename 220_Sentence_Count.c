#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[1<<20] = {};
int main() {
	fread(s, 1, 1<<20, stdin);
	int count = 0;
	for(int i = 0; s[i]; i++) {
		if(s[i] == '.') {
			if(s[i+1] == ' ' && s[i+2] == ' ') count++;
			else if(s[i+1] == '\n' || s[i+1] == '\0') count++;
		}
	}
	printf("%d\n",count);
	return 0;
}