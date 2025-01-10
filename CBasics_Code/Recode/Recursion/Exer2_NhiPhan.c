#include <stdio.h>

void NhiPhan(int n){
    int b;
    if(n ==0 ) return;
    b = n % 2;
    NhiPhan(n/2);
    printf("%d", b);
}

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    NhiPhan(n);
    return 0;
}