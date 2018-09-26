#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main() {
	char filename[3][200];
	for(int i = 0; i < 3; i++) {
		scanf("%s", filename[i]);
	}

	FILE *fin1 = fopen(filename[0], "rb");
	FILE *fin2 = fopen(filename[1], "rb");
	FILE *fout = fopen(filename[2], "wb");

	assert(fin1 != NULL);
	assert(fin2 != NULL);
	fseek(fin1, 0, SEEK_END);
	fseek(fin2, 0, SEEK_END);
	long len1 = ftell(fin1);
	long len2 = ftell(fin2);

	if(len1 < len2) { /* swap */
		FILE *tmp = fin1;
		fin1 = fin2;
		fin2 = tmp;
		long *tmp_len = &len1;
		len1 = len2;
		len2 = *tmp_len;
	}

	int carry = 0, sum;
	for(int i = 0; i < len1; i++) {
		unsigned char p1, p2;
		fseek(fin1, len1-i-1, SEEK_SET);
		fread(&p1, sizeof(unsigned char),1, fin1);

		if(i<len2) {
			fseek(fin2, len2-i-1, SEEK_SET);
			fread(&p2, sizeof(unsigned char),1,fin2); /* p2 = fgetc(fin2); */
		}
		else p2 = 0;

		sum = p1+p2+carry;
		if(sum > 255) carry = 1;
		else carry = 0;
		/* change the inidcator of the output file to the corresponding pos */
		fseek(fout, len1-i-1, SEEK_SET);
		/* write the sum of the two bytes to the output file */
		fwrite(&ans, sizeof(unsigned char),1, fout); /* fputc(ans, fout); */
	}
	fclose(fin1);
	fclose(fin2);
	fclose(fout);
	return 0;
}
