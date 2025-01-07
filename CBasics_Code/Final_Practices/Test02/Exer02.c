/*Bài toán: Phân Tích Văn Bản và Đếm Tần Suất Từ

Cho một đoạn văn bản đầu vào (gồm nhiều dòng), bạn hãy viết chương trình C để thực hiện các công việc sau:
Đọc văn bản: Đọc văn bản từ đầu vào. Văn bản có thể chứa nhiều dòng, các dòng có thể chứa ký tự in hoa, in thường, chữ số và các ký tự đặc biệt khác. Đọc cho đến khi gặp dòng chứa ký tự # thì dừng.
Chuẩn hóa văn bản: Chuyển tất cả các ký tự in hoa thành chữ thường, loại bỏ các ký tự không phải chữ cái hoặc chữ số (các ký tự đặc biệt), và thay thế các dấu cách liền nhau bằng một dấu cách duy nhất.
Tách từ: Tách các từ trong văn bản (mỗi từ được ngăn cách bởi dấu cách).
Đếm tần suất: Đếm số lần xuất hiện của mỗi từ trong văn bản.
In kết quả: In ra danh sách các từ và số lần xuất hiện tương ứng, mỗi từ trên một dòng, theo thứ tự từ điển (từ A-Z).

Lưu ý:
Bạn có thể sử dụng mảng ký tự (char array) hoặc string để lưu trữ văn bản và các từ.
Bạn có thể sử dụng thư viện string.h cho các thao tác trên chuỗi.
Bạn có thể sử dụng thư viện ctype.h cho các thao tác kiểm tra ký tự (ví dụ: isalpha(), isdigit(), tolower()).
Các từ sẽ được in theo thứ tự từ điển.
Nếu một từ xuất hiện nhiều lần, bạn chỉ in ra từ đó một lần, kèm theo tần suất xuất hiện của từ đó.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100
#define MAX_WORDS 10000

// Struct để lưu từ và số lần xuất hiện
typedef struct {
    char word[MAX_LENGTH];
    int frequency;
} WordFreq;

// Hàm để chuyển chữ hoa thành chữ thường và loại bỏ ký tự không phải chữ hoặc số
void normalize(char *str) {
    int i, j = 0;
    char temp[MAX_LENGTH];

    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            temp[j++] = tolower(str[i]);
        } else if (isspace(str[i])) {
            if (j > 0 && temp[j - 1] != ' ') {
                temp[j++] = ' ';
            }
        }
    }

    // Xóa khoảng trắng dư ở cuối
    if (j > 0 && temp[j - 1] == ' ') {
        j--;
    }
    temp[j] = '\0';

    strcpy(str, temp);
}

// Hàm tách từ và đếm tần suất
int splitAndCountWords(char *text, WordFreq *words, int *wordCount) {
    char *token;
    token = strtok(text, " ");

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[*wordCount].word, token);
            words[*wordCount].frequency = 1;
            (*wordCount)++;
        }

        token = strtok(NULL, " ");
    }
    return *wordCount;
}

// Hàm so sánh để sắp xếp từ theo thứ tự từ điển
int compareWords(const void *a, const void *b) {
    return strcmp(((WordFreq *)a)->word, ((WordFreq *)b)->word);
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    char text[MAX_LINES * MAX_LENGTH] = "";
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    // Đọc đầu vào
    printf("Nhập văn bản (kết thúc bằng dòng chứa ký tự #):\n");
    int lineCount = 0;
    while (fgets(lines[lineCount], MAX_LENGTH, stdin)) {
        if (lines[lineCount][0] == '#' && lines[lineCount][1] == '\n') {
            break;
        }
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';  // Loại bỏ ký tự xuống dòng
        strcat(text, lines[lineCount]);
        strcat(text, " ");
        lineCount++;
    }

    // Chuẩn hóa văn bản
    normalize(text);

    // Tách từ và đếm tần suất
    splitAndCountWords(text, words, &wordCount);

    // Sắp xếp từ theo thứ tự từ điển
    qsort(words, wordCount, sizeof(WordFreq), compareWords);

    // In kết quả
    printf("\nKết quả:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}




