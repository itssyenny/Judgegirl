/*
	Count the number of digits, letters, vowels, and consonants in a string s.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
	char s[100]; scanf("%s", s);
	int digits = 0, letters = 0, vowels = 0, consonants = 0;
	int len = strlen(s);

	for(int i = 0; i < len; i++) {
		if(s[i] == '\0') break;
		else {

			if(isdigit(s[i])) digits++;
			else if(isalpha(s[i])) {
				letters++;
                
				if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')|| (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')) vowels++;
				else consonants++;
			} 
			
		}
	}

	printf("%d %d %d %d\n", digits, letters, vowels, consonants);
	return 0;
}