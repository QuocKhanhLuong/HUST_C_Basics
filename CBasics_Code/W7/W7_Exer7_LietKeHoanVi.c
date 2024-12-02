#include <stdio.h>
#define N 51
int n;
int x[N];
int mark[N];

int check(int v, int k){
    return mark[v] == 0;
}

void solution(){
    for(int i =1 ; i <= n; i++)
        printf("%d ",x[i]);
        printf("\n");
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            mark[v] = 1; // update status of v
            if(k == n) solution();
            else Try(k+1);
            mark[v] = 0; // recover status when backtracking
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int v = 1; v <= n; v++) mark[v] = 0;
    Try(1);
    return 0;
}
