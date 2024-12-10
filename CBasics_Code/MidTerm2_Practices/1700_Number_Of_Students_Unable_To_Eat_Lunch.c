#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countStudents(int *students, int studentsSize, int *sandwiches, int sandwichesSize)
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < studentsSize && j < sandwichesSize)
    {
        if (students[i] == sandwiches[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            count++;
        }
    }
    return studentsSize - j;
}

int main()
{
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int studentsSize = sizeof(students) / sizeof(students[0]);
    int sandwichesSize = sizeof(sandwiches) / sizeof(sandwiches[0]);
    int result = countStudents(students, studentsSize, sandwiches, sandwichesSize);
    printf("Result is %d\n", result);
    return 0;
}