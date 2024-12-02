#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_PHONE 10

typedef struct {
    int stt;
    char mssv[10];
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    float score;
} Student;

Student* readStudentsFromFile(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file %s\n", filename);
        return NULL;
    }

    Student* students = NULL;
    *count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        (*count)++;
        students = (Student*)realloc(students, (*count) * sizeof(Student));
        sscanf(line, "%d %s %s %s", &students[*count - 1].stt, 
               students[*count - 1].mssv, students[*count - 1].name, 
               students[*count - 1].phone);
        students[*count - 1].score = -1; 
    }

    fclose(file);
    return students;
}

void inputAdditionalStudents(Student** students, int* count) {
    int additionalCount;
    printf("Nhap so luong sinh vien can bo sung: ");
    scanf("%d", &additionalCount);

    int newCount = *count + additionalCount;
    *students = (Student*)realloc(*students, newCount * sizeof(Student));

    for (int i = *count; i < newCount; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
        (*students)[i].stt = i + 1;
        printf("MSSV: ");
        scanf("%s", (*students)[i].mssv);
        printf("Ho va ten: ");
        scanf("%s", (*students)[i].name);
        printf("SDT: ");
        scanf("%s", (*students)[i].phone);
        (*students)[i].score = -1; 
    }

    *count = newCount;
}

void inputScores(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Nhap diem cho sinh vien %s: ", students[i].name);
        scanf("%f", &students[i].score);
    }
}

void writeTranscriptToFile(const char* filename, Student* students, int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file %s de ghi\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", students[i].stt, students[i].mssv,
                students[i].name, students[i].phone, students[i].score);
    }

    fclose(file);
    printf("Da ghi bang diem vao file %s\n", filename);
}

int main() {
    int count = 0;
    Student* students = readStudentsFromFile("danhsachlop.txt", &count);
    
    if (students == NULL) {
        return 1;
    }

    printf("Da doc %d sinh vien tu file.\n", count);

    inputAdditionalStudents(&students, &count);
    inputScores(students, count);
    writeTranscriptToFile("bangdiem.txt", students, count);

    free(students);
    return 0;
}