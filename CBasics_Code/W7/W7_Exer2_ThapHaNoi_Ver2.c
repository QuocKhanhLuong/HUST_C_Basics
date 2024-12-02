#include <stdio.h>
 
int count = 0;
 
int listSize;
int helperProd(int list[], int k)
{
    if (k == listSize - 1) return list[k];
    else
        return list[k] * helperProd(list, k+1);
}
 
int sum(int array[], int k)
{
    if (k == 1) return array[0];
    else
        return sum(array, k - 1) + array[k-1];
}
 
void HanoiTower(int n, char a, char c, char b)
{
    if (n == 1)
    {
        count++;
        printf("%d) Chuyen dia tu coc %c sang coc %c\n", count, a, c);
    }  
    else
    {
        HanoiTower(n-1, a, b, c);
        HanoiTower(1, a, c, b);
        HanoiTower(n-1, b, c, a);
    }
}
 
int main()
{
    int list[] = {1, 3, 3, 4};
    listSize = 4;
    int result = helperProd(list, 0);
    int tinhtong = sum(list, 4);
    printf("%d\n%d\n", result, tinhtong);
    int n;
    scanf("%d", &n);
    HanoiTower(n, 'a', 'c', 'b');
    return 0;
}