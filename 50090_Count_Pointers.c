#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
typedef struct {
  int count;
  int value;
  int *address;
} Things;

Things num[MAX_NUM_INTVAR];


int cmp(const void *a, const void *b) {
  Things *l = (Things *)a;
  Things *r = (Things *)b;
  if(l->count > r->count) return 1;
  if(l->count < r->count) return -1;
  if(l->count == r->count) {
    if(l->value > r->value) return 1;
    else return -1;
  }
  return 0;
}

void count(int **p[]) {
  int num_count = 0;
  for(int i = 0; p[i]; i++) {
    int duplicated = 0;
    for(int j = 0; j < num_count; j++) {
      if(&(**p[i]) == num[j].address) {     //if it points to the number that has been through, then ...
        duplicated = 1;
        num[j].count++;
        break;
      }
    }
    if(!duplicated) {
      num[num_count].count = 1;
      num[num_count].value = **p[i];        //save the value of **p[i]
      num[num_count].address = &(**p[i]);   // save the address of &(**p[i])
      num_count++;    // increment the num_count
    } 
    // printf("when i = %d , value = %d, address = %p\n", i, **p[i], &(**p[i]));
  }
  /* sort in an increasing order */
  qsort(num, num_count, sizeof(num[0]), cmp);

  for(int k = 0; k < num_count; k++) {
    printf("%d %d\n", num[k].value, num[k].count);
  }
}

int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}