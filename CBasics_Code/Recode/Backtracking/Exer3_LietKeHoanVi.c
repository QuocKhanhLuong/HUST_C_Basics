#include <stdio.h>

int X[100], n;
int mark[100];

int check(int v, int k){
    if (mark[v] == 1)
        return 0;
    return 1;
}

