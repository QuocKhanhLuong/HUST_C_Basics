#include <stdio.h>
#include <string.h>

#define NUMBERLINEOFPAGE 2

void showAll(FILE *inputFile)
{
    char line[256];
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        printf("%s", line);
    }
}

void showPage(FILE *inputFile)
{
    char line[256];
    int numberOfLine = 0;

    while(fgets(line, sizeof(line), inputFile) != NULL)
    {
        printf("%s", line);
        numberOfLine++;
        if (numberOfLine >= NUMBERLINEOFPAGE)
        {
            getchar();
            numberOfLine = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
    {
        printf("Wrong number of arguments.\n");
        return 1;
    }

    FILE *fptr1 = fopen(argv[1], "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    }
    if (argc == 2)
        showAll(fptr1);
    else if (argc == 3 && strcmp(argv[2], "-p") == 0)
        showPage(fptr1);
    else
    {
        printf("Error!\n");
        fclose(fptr1);
        return 1;
    }
}