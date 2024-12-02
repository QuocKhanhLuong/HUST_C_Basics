#include <stdio.h>
#define P 1000000007
#define N 1000

int M[N][N] ={0};

int C(int k, int n)
{
    if(k == 0 || k == n) 
        M[k][n] = 1;
    else{
        if(M[k][n] == 0)
        {
            M[k][n] = (C(k-1,n-1) + C(k,n-1))%P;
        }
    }
    return M[k][n];
    }

int main()
{
    int k,n; scanf("%d %d",&k,&n); printf("%d",C(k,n));
    return 0;
}