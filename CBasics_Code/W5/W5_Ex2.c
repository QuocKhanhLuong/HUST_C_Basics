#include <stdio.h>
#define MAX_LEN 81
enum { SUCCESS, FAIL };
int LineReadWrite(FILE* fin)
{
    char buff[MAX_LEN]; int count = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL) 
    {
        count++; printf("%s", buff);
    }
    return count;
}

main() {
    FILE* fptr1; int c = 0;
    char filename1[] = "haiku.txt";
    int reval = SUCCESS;
    if (fptr1 = fopen(filename1, "r") == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else 
    {
        printf("Reading file % s … done!\n", filename1);
        c = LineReadWrite(fptr1);
        printf("The file has % d lines.\n", c);
        fclose(fptr1);
    }
    return reval;
}