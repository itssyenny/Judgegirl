#include<stdio.h>
#include<stdlib.h>
#define MAXN 65536

int main(){
    FILE *fin = fopen("test", "rb");
    if(fin == NULL) puts("There is an error input")

    FILE *fout = fopen("test.enc", "wb");
	if(fout == NULL) puts("There is an error output")
    int key, size_n;
    char buf[MAXN];
 
    scanf("%d", &key);
 
    while ((size_n = fread(buf, 1, MAXN, fin)) != 0) {
        for (int i = 0; i < size_n; i++)
            buf[i] ^= key;
        fwrite(buf, sizeof(char), size_n, fout);
    }
    fclose(fout);
    fclose(fin);
    return 0;
}