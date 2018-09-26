/*
	while (!feof(fin)) { feof : to find the end of file.
	To find the n -> int n = fread(stu, sizeof(Student), 32767, fin);
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main() {
	char in[80], out[80]; scanf("%s %s", in, out);
	FILE *fin = fopen(in, "rb");
	FILE *fout = fopen(out, "wb");

	Student person;
	fprintf(fout, "<table border=\"1\">\n");
    fprintf(fout, "<tbody>\n");
	while(fread(&person, 1, sizeof(Student), fin)) {
		fprintf(fout, "<tr>\n");
        fprintf(fout, "<td>%s</td>\n", person.name);
        fprintf(fout, "<td>%d</td>\n", person.id);
        fprintf(fout, "<td>%s</td>\n", person.phone);
        fprintf(fout, "<td>%f, %f, %f, %f</td>\n", person.grade[0], person.grade[1], person.grade[2], person.grade[3]);
        fprintf(fout, "<td>%d, %d, %d</td>\n", person.birth_year, person.birth_month, person.birth_day);
        fprintf(fout, "</tr>\n");
	}
	fprintf(fout, "</tbody>\n");
    fprintf(fout, "</table>");

    fclose(fin);
    fclose(fout);
	return 0;
}