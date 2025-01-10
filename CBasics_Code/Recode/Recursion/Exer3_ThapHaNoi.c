#include <stdio.h>

void ThapHaNoi(int n, int a, int b, int c){
    if (n ==1){
        printf("%d %d\n", a, b);
    } else {
        ThapHaNoi(n-1, a, c, b);
        ThapHaNoi(1, a, b, c);
        ThapHaNoi(n-1, c, b, a);
    }
}

int main(){
    int n, a,b,c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    ThapHaNoi(n, a, b, c);
    return 0;
}