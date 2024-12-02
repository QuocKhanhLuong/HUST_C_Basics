#include <stdio.h>
void move(int number, int tower1, int tower2, int tower3)
{
    if (number == 1)
        printf("%d %d\n", tower1, tower2);
    else
    {
        move(number - 1, tower1, tower3, tower2);
        move(1, tower1, tower2, tower3);
        move(number - 1, tower3, tower2, tower1);
    }
}
int main()
{
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int count = (1 << n) - 1;
    printf("%d\n", count);
    move(n, a, b, c);
    return 0;
}
