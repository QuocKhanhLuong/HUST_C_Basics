#include <stdio.h>

int Fibonacci (int n){
    if(n <= 1) return n;
    return (Fibonacci(n-1) + Fibonacci(n-2)) % 1000000007;
}

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("So Fibonacci thu %d la: %d", n, Fibonacci(n));
    return 0;
}