#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE* f1 = fopen(argv[1], "a");
    if (f1 == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    FILE* f2 = fopen(argv[2], "r");
    if (f2 == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }

    char c;
    while (c = fgetc(f2), c != EOF) {
        fputc(c, f1);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}