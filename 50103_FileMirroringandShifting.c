#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main() {
	char filename[2][20];
	for(int i = 0; i < 2; i++) {
		scanf("%s", filename[i]);
	}
	FILE *fin = fopen(filename[0], "rb");
	FILE *fout = fopen(filename[1], "wb");
	assert(fin != NULL && fout != NULL);

	int N; scanf("%d", &N);
	fseek(fin, 0, SEEK_END);
	long len = ftell(fin);

	for(int i = 0; i < len; i++) {
		fseek(fin, len-i-1, SEEK_SET);
		unsigned char c = fgetc(fin);
		/* reverse runs O(log n) */
		unsigned char ret = 0;
		for(int j = 0; j < 8; j++) {
			if(c & (1 << j)) {	/* to know at what pos the bit is */
				ret |= 1 << (8-j-1);
			}
		}
		/* shift N bytes = curpos + N */
		long shift = (i-N) < 0 ? i-N+len : i-N; 
		shift %= len;
		fseek(fout, shift, SEEK_SET);
		fwrite(&ret, sizeof(unsigned char),1,fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}