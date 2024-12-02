#include <stdio.h>
#define N 20
int n, M;
int x[N];
int T;

int check(int v, int k){
    if(k < n) return 1;
    return T + v == M;
}

void solution(){
    for(int i = 1 ; i <= n; i++)
    printf("%d ",x[i]);
    printf("\n");
}

void Try(int k){
    for(int v = 1; v <= M - T - n + k; v++){
        if(check(v,k)){
            x[k] = v;
            T = T + v; // update status of T
            if(k == n) solution();
            else Try(k+1);
            T = T - v; // recover status when backtracking
        }
    }
}

int main(){
    scanf("%d%d",&n, &M);
    T = 0;
    Try(1);
    return 0;
}