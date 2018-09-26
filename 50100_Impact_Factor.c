#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXP 1024
typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;
typedef struct {
    char *name;
    int num_of_papers, num_of_citations;
} table;
table Table[MAXP];
char *listofJournals[MAXP];
int itself[MAXP] = {0}, citations[MAXP] = {0}, valid[MAXP] = {0};
int idx[MAXP];
/* COMPARE FUNCTION FOR QSORT */
int compare(const void *a, const void *b) {
    table *pa = (table *)a;
    table *pb = (table *)b;
    return strcmp(pa->name, pb->name);
}
void compute(paper P[], int N) {
    /* to count the number of a journal appear in papers */
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if(valid[i] == 0) {
            for(int j = i; j < N; j++) {
                if(strcmp(P[i].journalName, P[j].journalName) == 0) {
                    listofJournals[count] = P[i].journalName;
                    // printf("List of Journal %s\n", listofJournals[count] );
                    itself[count]++;
                    valid[j] = 1;
                    idx[j] = count;
                }
            }
            // printf("Journal %s, itself %d, valid[%d] %d, idx %d\n", listofJournals[count], itself[count], i, valid[i],idx[i]);
            valid[i] = 1;
            count++;
        }
    }
    /* to count the number of citations of every journal */
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P[i].numCitedPaper; j++) {
            citations[idx[P[i].citedPaperIndex[j]]]++;
        }
    }
    for(int i = 0; i < count; i++) {
        Table[i].name = listofJournals[i];
        Table[i].num_of_papers = itself[i];
        Table[i].num_of_citations = citations[i];
    }
    /* sort the name of journals and print them out alphabetically */
    qsort(Table, count, sizeof(table), compare);
    for(int i = 0; i < count; i++) {
        printf("%s %d/%d\n", Table[i].name, Table[i].num_of_citations, Table[i].num_of_papers);
    }
    return;
}

int main() {
    int N;
    paper P[MAXP] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}