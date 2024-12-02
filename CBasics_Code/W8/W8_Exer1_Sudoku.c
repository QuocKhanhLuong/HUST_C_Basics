#include <stdio.h>
int X[9][9];
int markR[9][10];
int markC[9][10];
int markS[3][3][10];
int cnt;

int check(int v, int r, int c){
    if(markR[r][v]) return 0;
    if(markC[c][v]) return 0;
    if(markS[r/3][c/3][v]) return 0;
    return 1;
}
void Try(int r, int c){
    if(X[r][c] > 0){
        if(r == 8 && c == 8) cnt++;
        else{ if(c == 8) Try(r+1,0); else Try(r,c+1); }
        return;
    }
    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            X[r][c] = v;
            markR[r][v] = 1; markC[c][v] = 1; markS[r/3][c/3][v] = 1;
            if(r == 8 && c == 8) cnt++;
            else{ if(c == 8) Try(r+1,0); else Try(r,c+1); }
            markR[r][v] = 0; markC[c][v] = 0; markS[r/3][c/3][v] = 0;
            X[r][c] = 0;
        }
    }
}

void init(){
    for(int v = 1; v <= 9; v++){
        for(int r = 0; r <= 8; r++)
            markR[r][v] = 0;
        for(int c = 0; c <= 8; c++)
            markC[c][v] = 0;
        for(int i = 0; i <= 2; i++)
            for(int j = 0; j <= 2; j++)
                markS[i][j][v] = 0;
    }
}
int main(){
    init();
    for(int r = 0;r <= 8; r++){
        for(int c = 0; c <= 8; c++){
            int v; scanf("%d",&v);
            X[r][c] = v;
            if(v > 0){
                markR[r][v] = 1; markS[r/3][c/3][v] = 1;
                markC[c][v] = 1;
            }
        }
    }
    cnt = 0;
    Try(0,0);
    printf("%d",cnt);
    return 0; 
}