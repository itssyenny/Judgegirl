#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100001
typedef struct Data {
	char name[64];
	int height;
	int weight;
	float BMI;
}Data;
Data person[MAX];
int compare(const void *a, const void *b) {
	Data *pa = (Data *)a;
	Data *pb = (Data *)b;
	if(pa->BMI < pb->BMI) return -1;
	else if(pa->BMI > pb->BMI) return 1;
	else {
		if(pa->weight == pb->weight) {
			if(pa->height == pb->height) {
				return strcmp(pa->name, pb->name);
			}
			else return ((pa->height < pb->height) ? (-1) : 1);
		}
		else return ((pa->weight < pb->weight) ? (-1) : 1);
	}
}
void calculate_the_BMI(int N, Data person[]) {
	for(int i = 0; i < N; i++) {
		float weight = (float)person[i].weight;
		float height = (float)pow((double)person[i].height, 2) / 10000;
		person[i].BMI = weight/height;
		// printf("BMI of %s = %f\n", person[i].name, person[i].BMI);
	}
}
int main () {
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s %d %d", person[i].name, &person[i].height, &person[i].weight);
	}

	calculate_the_BMI(N, person);
	qsort(person, N, sizeof(Data), compare);
	for(int i = 0; i < N; i++) {
		printf("%s %d %d\n", person[i].name, person[i].height, person[i].weight);
	}
	return 0;
}