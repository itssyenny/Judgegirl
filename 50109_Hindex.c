#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Author {
	char name[16];
	int cited;
}Author;
Author data[20000];
int compare(const void *a, const void *b) {
	Author *pa = (Author *)a;
	Author *pb = (Author *)b;
	if(strcmp(pa->name, pb->name) < 0) return -1;
	if(strcmp(pa->name, pb->name) == 0) {
		if(pa->cited < pb->cited) return 1;
		else return -1;
	}
	else return 1;
}
int main() {
	int n = 0;
	while(~scanf("%s %d", data[n].name, &data[n].cited)) {n++;}
	for(int n = 0; n < 5; n++) {
		scanf("%s %d", data[n].name, &data[n].cited);
	}
	qsort(data, n, sizeof(Author), compare);
	for(int i = 0; i < n; ) {
		int pos = i, H_index = 1;
		while(i < n && !strcmp(data[i].name, data[pos].name)) {
			// printf("%s %d, %d\n", data[i].name, data[i].cited, H_index);
			if(data[i].cited >= H_index) {
				H_index++;
			}
			i++;
		}
		H_index--;
		printf("%s %d\n",data[pos].name, H_index);
	}
	return 0;
}