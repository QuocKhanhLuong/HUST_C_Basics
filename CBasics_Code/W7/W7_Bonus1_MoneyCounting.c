#include <stdio.h>
#include <stdlib.h>

// Mảng lưu combination hiện tại
int current[1000];
// Mảng mệnh giá
int denominations[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
int n_denominations = 3;

// Hàm in ra một combination
void printCombination(int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", current[i]);
    }
    printf("\n");
}

// Hàm đệ quy quay lui
int findCombinations(int target, int start_idx, int curr_idx) {
    // Nếu target = 0, tìm thấy một cách đổi tiền hợp lệ
    if(target == 0) {
       
        return 1;
    }
    
    // Nếu target < 0, không tìm được cách đổi tiền
    if(target < 0) {
        return 0;
    }
    
    int count = 0;
    // Thử từng mệnh giá từ vị trí start_idx
    for(int i = start_idx; i < n_denominations; i++) {
        // Thêm mệnh giá hiện tại vào combination
        current[curr_idx] = denominations[i];
        
        // Đệ quy với số tiền còn lại
        count += findCombinations(target - denominations[i], i, curr_idx + 1);
    }
    
    return count;
}

int main() {
    int target;
    printf("Nhap so tien can doi (VND): ");
    
    // Kiểm tra đầu vào hợp lệ
    if(scanf("%d", &target) != 1 || target <= 0) {
        printf("Vui long nhap so tien hop le!\n");
        return 1;
    }
    
    int total = findCombinations(target, 0, 0);
    
    if(total == 0) {
        printf("Khong the doi so tien %d VND voi cac menh gia cho truoc\n", target);
    } else {
        printf("Tong cong co %d cach doi tien\n", total);
    }
    
    return 0;
}