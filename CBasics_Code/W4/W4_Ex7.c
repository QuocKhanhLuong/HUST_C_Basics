#include <stdio.h>

enum {SUCCESS, FAIL};

void mycp(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
    }
}

int main(int argc, char *argv[])
{
    int reval = SUCCESS;
    if (argc != 3)
    {
        printf("Wrong number of arguments.\n");
        printf("CORRECT SYNTAX: mycp <fileName1> <fileName2>\n");
        reval = FAIL;
        return reval;
    }

    FILE *source = fopen(argv[1], "r");
    FILE *destination = fopen(argv[2], "w");
    if (source == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    }
    else if (destination == NULL)
    {
        printf("Cannot open %s.\n", argv[2]);
        reval = FAIL;
    }
    else
    {
        mycp(source, destination);
        fclose(source);
        fclose(destination);
    }
    return reval;
}