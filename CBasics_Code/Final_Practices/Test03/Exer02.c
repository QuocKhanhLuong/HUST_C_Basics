/*Bài 2: Đệ Quy - Tính Tổng Các Chữ Số

Cho một số nguyên dương n. Viết chương trình C sử dụng đệ quy để tính tổng các chữ số của số n này.

Yêu cầu:
Viết hàm đệ quy sumDigits(int n) để tính tổng các chữ số của số n.
Đọc số nguyên n từ đầu vào.
In ra tổng các chữ số của số n.
Đầu vào kết thúc bằng ký tự '#'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int n){
    if (n == 0)
        return 0;
    return n % 10 + sum(n /10);
}

int main(){
    int n;
    while (1){
        scanf("%d", &n);
        if (n == '#')
            break;
        printf("%d\n", sum(n));
    }
    return 0;
}
