#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 80
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Sử dụng: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        fprintf(stderr, "Không thể mở file %s\n", argv[1]);
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char new_line[MAX_LINES + 1] = {0};  
    int line_count = 0;

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file) && line_count < MAX_LINES) {
        new_line[line_count] = lines[line_count][0];
        line_count++;
    }

    if (line_count == MAX_LINES) {
        fprintf(stderr, "Cảnh báo: File có thể chứa hơn %d dòng\n", MAX_LINES);
    }

    strcat(new_line, "\n");
    fseek(file, 0, SEEK_END);
    fputs(new_line, file);
    fclose(file);
    printf("Đã thêm dòng mới vào cuối file: %s\n", new_line);
    return 0;
}