#include <stdio.h>
#define swap(x,y,c,d) {int t; t = a[x][y], a[x][y] = a[c][d], a[c][d] = t;}
int a[101][101] = {};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) { scanf("%d", &a[i][j]);}
    }
 
    int move, win = 0;
    while(scanf("%d", &move) != EOF) {
        if(move == 0) break;
        else if(move >= 1 && move <= 15) { 
            /* check the pos of move */
            int i,j, found = 0;
            for(i = 0; i < 4; i++) {
                for(j = 0; j < 4; j++) {
                    if(a[i][j] == move) {found = 1; break;}
                }
                
                if(found) break;
            }
 
            /* check the neighbors */
            int newx, newy;
            for(int h = 0; h < 4; h++) {
                newx = i + dx[h], newy = j + dy[h];
                if(newx < 0 || newx > 3 || newy < 0 || newy > 3) continue;
                else if(a[newx][newy] == 0) {
                    swap(i,j,newx,newy);
                }
            }
            
            /* check the winning configuration */
            int num = 1, same = 0;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if(a[i][j] == num) same++;
                    num++;
                }
            }

            if(same == 15 && a[3][3] == 0) {win = 1;  break; }
        } 
    }
 
    /* print all the board */
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d%c", a[i][j], " \n"[j == 3]);
        }
    }
 
    /* print the winning configuration type and the last move */
    if(win) {
        printf("1 %d\n", move);
    } else printf("0\n");
 
}