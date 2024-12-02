#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct Student {
    int stt;
    char mssv[20];
    char name[MAX_NAME_LENGTH];
    char phone[15];
    float grade;
};

int read_students(struct Student students[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở file %s\n", filename);
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%d %s %s %s", &students[count].stt, students[count].mssv, 
                  students[count].name, students[count].phone) == 4) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }
    fclose(file);
    return count;
}

void input_grades(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Nhập điểm cho sinh viên %s: ", students[i].name);
        scanf("%f", &students[i].grade);
    }
}

void write_transcript(struct Student students[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Không thể tạo file %s\n", filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", students[i].stt, students[i].mssv, 
                students[i].name, students[i].phone, students[i].grade);
    }
    fclose(file);
    printf("Đã ghi kết quả vào file %s\n", filename);
}
int main() {
    struct Student students[MAX_STUDENTS];
    int count;
    count = read_students(students, "danhsachlop.txt");
    if (count == 0) {
        printf("Không có dữ liệu sinh viên. Chương trình kết thúc.\n");
        return 1;
    }

    printf("Đã đọc %d sinh viên từ file.\n", count);
    input_grades(students, count);
    write_transcript(students, count, "bangdiem.txt");
    return 0;
}