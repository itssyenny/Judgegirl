#include<stdio.h>

int main() {
	char filename[16]; scanf("%s", filename);
	FILE *fin = fopen(filename, "rb");
	int type, param;
	char co[5], string;;
	while(fread(&type, 4, 1, fin)) {
		switch(type) {
			case 0:
				// puts("CASE 0");
				fread(&param, sizeof(int), 1, fin);
				printf("%d", param);
				break;
			case 1:
				// puts("CASE 1");
				fread(co, sizeof(char), 4, fin);
				co[4] = '\0';
				printf("%s",co);
				break;
			case 2:
				// puts("CASE 2");
				fread(&param, sizeof(int), 1, fin);
				
				while(1) {	/*read all the character after the parameter */
					fread(&string, sizeof(char), 1, fin);
					if(string == '\0') break;
					printf("%c",string); /*putchar(string); */
				}
				break;
			case 3:
				// puts("CASE 3");
				fread(&param, sizeof(int), 1, fin); 
				fseek(fin, -8, SEEK_CUR); //base
				fseek(fin, param, SEEK_CUR);
				break;
			case 4:
				// puts("CASE 4");
				fread(&param, sizeof(int), 1, fin);
				fseek(fin, param, SEEK_SET);
				break;
			case 5:
				// puts("CASE 5");
				fread(&param, sizeof(int), 1, fin);
				fseek(fin, param, SEEK_END);
				break;
			default:
				// puts("CASE #");
				puts("Seek end");
				fclose(fin);
				return 0;
		}
	}
	return 0;
}