#include <stdio.h>

int Combination(int n, int k){
    if(k == 0 || k == n) return 1;
    return (Combination(n-1,k-1) +Combination(n-1,k)) % 1000000007;
}

int main(){
    int n, k;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap k: ");
    scanf("%d", &k);
    printf("To hop chap %d cua %d la: %d", k, n, Combination(n, k));
    return 0;
}