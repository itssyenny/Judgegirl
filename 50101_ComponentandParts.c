#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _COMPONENTPART_H
#define MAXLENGTH 16
#define MAXCOMPONENT 64
typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;

typedef struct {
    char *name;
    int totalPrice;
    int valid;
}Component;

Component newlist[MAXCOMPONENT];

int compare(const void *a, const void *b) {
    Component *pa = (Component *)a;
    Component *pb = (Component *)b;
    return strcmp(pa->name, pb->name);
}
void findPrice(int N,ComponentPart list[]) {
    
    for(int i = 0; i < N; i++) {
        newlist[i].valid = 0;
    }

    int count = 0;
    while(count < N) {
        for(int i = 0; i < N; i++) {
            if(list[i].numComponent != 0 && newlist[i].valid == 0) {
                newlist[i].totalPrice = 0;
                newlist[i].valid = 1;
                newlist[i].name = list[i].name;
                // printf("Component %s, valid = %d \n", list[i].name, newlist[i].valid );
                for(int j = 0; j < list[i].numComponent; j++) {
                    if(list[list[i].componentPartList[j]].price == 0) {
                        newlist[i].valid = 0; 
                        newlist[i].totalPrice = 0;
                        list[i].price = 0;
                        count--;
                        break;
                    }
                    else {
                        // printf("    %d, %s, price = %d \n", j, list[list[i].componentPartList[j]].name,list[list[i].componentPartList[j]].price );
                        newlist[i].totalPrice += list[list[i].componentPartList[j]].price;
                    }
                }
                list[i].price = newlist[i].totalPrice;
            }
            else if(list[i].numComponent == 0 && newlist[i].valid == 0) {
                // printf("%d, %s, price = %d\n", i, list[i].name, list[i].price);
                newlist[i].name = list[i].name;
                newlist[i].totalPrice = list[i].price;
                newlist[i].valid = 1;
            }
            else continue;
            count++;
        }
        // printf("count %d\n", count );
    }

    qsort(newlist, N, sizeof(Component), compare);
    /* print */
    for(int i = 0; i < N; i++) {
        printf("%s %d\n", newlist[i].name, newlist[i].totalPrice);
    }
    return;
}
int main(){
    int N;
    scanf("%d",&N);
    ComponentPart list[N];
    for(int i=0;i<N;i++){
        scanf("%s%d",list[i].name,&list[i].numComponent);
        if(list[i].numComponent){
            for(int j=0;j<list[i].numComponent;j++)
                scanf("%d",&list[i].componentPartList[j]);
            list[i].price=0;
        }
        else
            scanf("%d",&list[i].price);
    }
    findPrice(N,list);
    return 0;
}