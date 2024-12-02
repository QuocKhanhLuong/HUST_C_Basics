#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "r+");
    if (f == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    char c;
    while ((c = fgetc(f)) != EOF) {
        fseek(f, -1, SEEK_CUR);
        if (islower(c)) c = toupper(c);
        fputc(c, f);
    }

    fclose(f);

    return 0;
}