#include <stdio.h>
int days[32];
int main() {
    int leap_year, year, month, day; scanf("%d%d%d", &year, &month, &day);
    int num_days = 0;
    if(month < 1 || month > 12 || day < 0 || day > 6) puts("invalid");
    else {
        switch(month) {
            case 1:
                num_days = 31;
                break;
            case 2 :
                //check whether it is leap year or not
                if(year%4 == 0) {
                    if(year%100 == 0) {
                        if(year%400 == 0) leap_year = 1;
                        else leap_year = 0;
                    }else leap_year = 1;
                } else leap_year = 0;
     
                //judge the day
                num_days = (leap_year) ? 29 : 28;
                break;
            case 3 :
                num_days = 31;
                break;
            case 4 :
                num_days = 30;
                break;
            case 5 :
                num_days = 31;
                break;
            case 6 :
                num_days = 30;
                break;
            case 7 : 
                num_days = 31;
                break;
            case 8 :
                num_days = 31;
                break;
            case 9 :
                num_days = 30;
                break;
            case 10 :
                num_days = 31;
                break;
            case 11 :
                num_days = 30;
                break;
            case 12 :
                num_days = 31;
                break;
            default : break;
        }
 
        int i,j,spa;
    
        puts(" Su Mo Tu We Th Fr Sa");
        puts("=====================");
        for(i = 1; i <= num_days && day <= 6; i++) {
            if(i == 1) {
                for(spa = 0; spa < 3*day; spa++) printf(" ");
            }
            if(day == 6 || i == num_days) {
                printf("%3d\n",i);
                day = 0; //reset
            }
            else {
                printf("%3d", i);
                day++;
            }
        }
        puts("=====================");
    }

    return 0; 
}