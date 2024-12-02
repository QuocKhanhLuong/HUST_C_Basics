#include <stdio.h>
#define P 1000000007

int F(int n)
{
    if(n <= 1) return n;
    return (F(n-1) + F(n-2))%P;
}

int main()
{
    int n; scanf("%d",&n);
    printf("%d",F(n));
    return 0;
}