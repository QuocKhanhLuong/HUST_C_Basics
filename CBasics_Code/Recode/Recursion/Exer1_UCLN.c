#include <stdio.h>

int UCLN(int a, int b){
    if(a == b) return a;
    if(a > b) return UCLN(a-b, b);
    else return UCLN(a, b-a);
}

int main(){
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("UCLN cua %d va %d la: %d", a, b, UCLN(a, b));
    return 0;
}