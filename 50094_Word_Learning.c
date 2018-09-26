#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T; scanf("%d", &T);
	char word[128], used[26];
	int table[28][28];

    /* initializing */
	for(int i = 0; i < 26; i++) {
        used[i] = 0;
		for(int j = 0; j < 26; j++) {
			table[i][j] = 0;
		}
	}

    /* scanning and processing */
	while(~scanf("%s", word)) {
        //printf("%lu\n", strlen(word));
		for(int i = 0; i < strlen(word) && (word[i]-'a' >= 0 && word[i+1]-'a' >= 0); i++) {
			table[word[i]-'a'][word[i+1]-'a']++;
            // printf("word[%c][%c] = %d\n",word[i], word[i+1], table[word[i]-'a'][word[i+1]-'a'] );
        }
	}

    /* print the table */
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			printf("%d%c",table[i][j], " \n"[j == 25]);
		}
	}

	int max = T,x,y;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if(table[i][j] > max) {
				x = i; y = j;
				max = table[i][j];
			}	
		}
	}
    // puts("Start making new word");
	printf("%c%c", x+'a', y+'a'); 
    used[x] = 1, used[y] = 1, x = y;
	
    while(1) {
        // printf("x = %d\n", x);
        y = -1;
        max = T;

		for(int i = 0; i < 26; i++) {
			if(table[x][i] > max && used[i] == 0) {
				max = table[x][i];
                y = i;
                //printf("y = %d, %d\n",y, table[x][i]);
            }
		}
        if(table[x][y] == 0 || y == -1) break;
        //printf("out y %d\n", y );
		used[y] = 1;
		printf("%c", y+'a');
		x = y;
	} 

	return 0;
}