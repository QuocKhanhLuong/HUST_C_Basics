#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

char* subStr(char* s1, int offset, int number) {
    int len = strlen(s1);
    
    if (offset < 0 || offset >= len) {
        return NULL;
    }
    
    if (number > len - offset) {
        number = len - offset;
    }
    
    char* result = (char*)malloc((number + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; 
    }
    
    strncpy(result, s1 + offset, number);
    result[number] = '\0'; 
    
    return result;
}

int main() {
    char s1[MAX_LENGTH];
    int offset, number;
    
    printf("Nhập xâu gốc (tối đa %d ký tự): ", MAX_LENGTH - 1);
    fgets(s1, MAX_LENGTH, stdin);
    s1[strcspn(s1, "\n")] = 0;
    
    printf("Xâu gốc: %s\n", s1);
    
    printf("Nhập offset: ");
    scanf("%d", &offset);
    
    printf("Nhập số ký tự cần lấy: ");
    scanf("%d", &number);
    
    char* sub = subStr(s1, offset, number);
    
    if (sub != NULL) {
        printf("Xâu con: %s\n", sub);
        free(sub); 
    } else {
        printf("Không thể tạo xâu con (offset không hợp lệ hoặc lỗi cấp phát bộ nhớ).\n");
    }
    
    return 0;
}