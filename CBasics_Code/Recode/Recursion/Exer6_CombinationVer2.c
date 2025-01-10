#include <stdio.h>

int M[1000][1000];

int C(int n, int k){
    if(k == 0 || k == n){
        return 1;
    } else {
        if (M[k][n] == 0) {
            M[k][n] = (C(n-1,k-1) + C(n-1,k)) % 1000000007;
        }
    return M[k][n];
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", C(n, k));
    return 0;
}