/*Bài 3: Quay Lui - Tìm Các Tổ Hợp Số

Cho một tập các số nguyên dương (có thể chứa các số trùng nhau), và một số nguyên dương S. 
Hãy viết chương trình C để tìm tất cả các tổ hợp các số trong tập đó có tổng bằng S. 
Mỗi số có thể được sử dụng nhiều lần trong một tổ hợp, các tổ hợp có thứ tự khác nhau được tính là 1 tổ hợp 
(ví dụ: {1, 2, 1} và {1, 1, 2} được tính là 1).

Yêu cầu:
Đọc số nguyên N từ đầu vào, là số lượng số trong tập.
Đọc N số nguyên dương từ đầu vào, là các số trong tập.
Đọc số nguyên S từ đầu vào, là tổng cần tìm.
In ra tất cả các tổ hợp có tổng bằng S, mỗi tổ hợp trên một dòng, các số trong tổ hợp được phân tách bởi dấu cách, 
các tổ hợp được in theo thứ tự từ điển tăng dần. Nếu không có tổ hợp nào thỏa mãn, in ra "no solution".
Đầu vào kết thúc bằng ký tự '#'.

Lưu ý:
Bạn có thể dùng giải thuật quay lui để giải quyết bài toán này.
Bạn có thể cần sắp xếp các số đầu vào trước khi tìm các tổ hợp để đảm bảo in ra kết quả theo thứ tự từ điển.
Bạn có thể lưu trữ một tổ hợp các số trong một mảng hoặc danh sách.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,S;
int *arr;
int *result;
int count = 0;

void printResult(){
    for (int i = 0; i < count; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
}

void findCombination(int index, int sum){
    if (sum == S){
        printResult();
        return;
    }
    if (sum > S || index == N){
        return;
    }
    for (int i = index; i < N; i++){
        result[count++] = arr[i];
        findCombination(i, sum + arr[i]);
        count--;
    }
}

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(){
    while (1){
        scanf("%d", &N);
        if (N == '#')
            break;
        arr = (int *)malloc(N * sizeof(int));
        result = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
        }
        scanf("%d", &S);
        qsort(arr, N, sizeof(int), compare);
        findCombination(0, 0);
        if (count == 0)
            printf("no solution\n");
        count = 0;
        free(arr);
        free(result);
    }
    return 0;
}