#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct person {
    unsigned int id;
    char name[32];
}person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
}friends;

person P[10000];
friends F[10000];

int getID(int n, char name[]) { /* n people to check */
	for(int i = 0; i < n; i++) {
		if(strcmp(name, P[i].name) == 0) return P[i].id;
	}
	return 0;
}
int are_they_Friends(int m, int first_person,int second_person) {
	for(int i = 0; i < m; i++) {
		if((F[i].id1 == first_person && F[i].id2 == second_person) || (F[i].id1 == second_person && F[i].id2 == first_person)) return 1;
	}
	return 0;
}

int main() {
	FILE *fin = fopen("friends", "rb");
	int n;
	/* There are n people inside the file */
	fread(&n, sizeof(int), 1, fin);
	fread(P, sizeof(person), n, fin);

	/* There are m pairs inside the file */
	int m; 
	fread(&m, sizeof(int), 1, fin);
	fread(F, sizeof(friends), m, fin);

	char name1[32], name2[32];
	while (scanf("%s%s", name1, name2) == 2) {
		if(are_they_Friends(m, getID(n, name1), getID(n, name2))) puts("yes");
		else puts("no");
	}
	fclose(fin);
	return 0;
}