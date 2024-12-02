#include <stdio.h>
int n;// so thanh pho
int d[100][100];
int x[100];
int mark[100];
int f;// do dai cua lo trinh di duoc
int f_min;// do dai lo trinh ngan nhat (ky luc)
int Cm;

void Try(int k){
    for(int v = 1; v<= n; v++){
        if(mark[v]==0){
        x[k] = v;
        f = f + d[x[k-1]][v]; mark[v] = 1;
        if(k == n){
            if(f_min > f + d[x[n]][x[1]])
                f_min = f + d[x[n]][x[1]];
            }else{
                if (f + Cm*(n-k+1) < f_min)
                Try(k+1);
        }
        mark[v] = 0; f = f - d[x[k-1]][v];
        }
    }
}

void input(){
    scanf("%d",&n);
    Cm = 10000000;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            scanf("%d",&d[i][j]);
            if(i != j && d[i][j] < Cm) Cm = d[i][j];
        }
    }
}

int main(){
    input();
    for(int v = 1; v <= n; v++) mark[v] = 0;
    x[1] = 1; mark[1] = 1;
    f = 0; f_min = 10000000;
    Try(2);
    printf("%d",f_min);
    return 0;
}