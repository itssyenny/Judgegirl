#include <stdio.h>
int map[501][501] = {};
void print_map(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) { printf("%d%c",map[i][j], " \n"[j==m-1]); }
    }
}
int main () {
    int n,m ; scanf("%d%d", &n, &m);
    int prow, pcol, penergy; scanf("%d%d%d", &prow, &pcol, &penergy); 
    map[prow][pcol] = penergy;
 
    int O; scanf("%d", &O);
    for(int i = 0; i < O; i++) {
        int srow, scol, senergy; scanf("%d%d%d", &srow, &scol, &senergy);
        map[srow][scol] = senergy;
    }
 
    int ins;
    while(scanf("%d", &ins) != EOF) {
        int stop, sum = 0, invalid = 0; /* stop to set the range to move the stones and player, sum to sum the weight of all stones */
        switch(ins) {
            case 0:
                print_map(n,m);
                break;
            case 1:    //x+1
                if(pcol+1 >= m) continue;
                for(int i = pcol+1; i < m; i++) {
                    if(map[prow][i] != 0) {
                        /* if there is a stone that out of the bound, break */
                        if(i+1 >= m) {invalid = 1; break;}
                        sum += map[prow][i];
                    } else {stop = i; break;}
                }
                /* if the points of people and stones are valid and weight >= sum */
                if(!invalid && map[prow][pcol] >= sum) {
                    for(int i = stop; i > pcol; i--) {
                        map[prow][i] = map[prow][i-1];
                    }
                    map[prow][pcol] = 0;
                    pcol++;
                    map[prow][pcol] -= sum;
                }
                break;
            case 2:    // y+1
                if(prow+1 >= n) continue;
                for(int i = prow+1; i < n; i++) {
                    if(map[i][pcol] != 0) {
                        if(i+1 >= n) {invalid = 1; break;}
                        sum += map[i][pcol];
                    } else {stop = i; break;}
                }
 
                if(!invalid && map[prow][pcol] >= sum) {
                    for(int i = stop; i > prow; i--) {
                        map[i][pcol] = map[i-1][pcol];
                    }
                    map[prow][pcol] = 0;
                    prow++;
                    map[prow][pcol] -= sum;
                }
                break;
            case 3: //x-1
                if(pcol-1 < 0) continue;
                for(int i = pcol-1; i >= 0; i--) {
                    if(map[prow][i] != 0) {
                        if(i-1 < 0) {invalid = 1; break;}
                        sum += map[prow][i];
                    } else {stop = i; break;}
                }
                if(!invalid && map[prow][pcol] >= sum) {
                    for(int i = stop; i < pcol; i++) {
                        map[prow][i] = map[prow][i+1];
                    }
                    map[prow][pcol] = 0;
                    pcol--;
                    map[prow][pcol] -= sum;
                }
                break;
            case 4: //y-1
                if(prow-1 < 0) continue;
                for(int i = prow-1; i >= 0; i--) {
                    if(map[i][pcol] != 0) {
                        if(i-1 < 0) {invalid = 1; break;}
                        sum += map[i][pcol];
                    } else {stop = i; break;}
                }
 
                if(!invalid && map[prow][pcol] >= sum) {
                    for(int i = stop; i < prow; i++) {
                        map[i][pcol] = map[i+1][pcol];
                    }
                    map[prow][pcol] = 0;
                    prow--;
                    map[prow][pcol] -= sum;
                }
                break;
            default:
                break;
        }
    }
}