#include <stdio.h>
    int F(int a, int b)
    {
        if(a == b) return a;
        if(a > b) return F(a-b, b);
        else return F(a, b-a);
    }
    
    int main(){
    int a,b; scanf("%d%d",&a,&b);
    printf("%d",F(a,b));
    return 0;
}