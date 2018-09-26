/*
	fread(place to store the string, size of string [int/short/etc.], # of string, file to read)
	32,768 + 32,767 = 65,535.
	sizeof(short int) = 2 bytes.
	sizeof(int) = 4 bytes.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int frequency[65536] = {0};

int main(){
	char filename[200]; scanf("%s", filename);
	FILE *fin = fopen(filename, "rb");
	assert(fin != NULL);
	int n; fread(&n, 4, 1, fin);
	short int k;
	for(int i = 0; i < n; i++) {
		fread(&k, sizeof(short int), 1, fin);
		frequency[k+32768]++;
	}

	int max_k, maxfrequency = 0;
	for(int i = 0; i < 65536; i++) { //in increasing order
		if(frequency[i] >= maxfrequency) {
			maxfrequency = frequency[i];
			max_k = i;
			// printf("%d %d\n", max_k-32768, maxfrequency );
		}
	}

	printf("%d\n%d\n", max_k-32768, maxfrequency);
	fclose(fin);
	return 0;
}