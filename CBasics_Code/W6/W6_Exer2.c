#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_RADIUS 100
#define MAX_COORDINATE 1000

typedef struct {
    double x;
    double y;
    double radius;
} Circle;

bool doCirclesIntersect(Circle c1, Circle c2) {
    double distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    return distance <= (c1.radius + c2.radius);
}

void inputCircle(Circle *c) {
    printf("Nhap toa do x: ");
    scanf("%lf", &c->x);
    printf("Nhap toa do y: ");
    scanf("%lf", &c->y);
    printf("Nhap ban kinh: ");
    scanf("%lf", &c->radius);
}

void generateRandomCircle(Circle *c) {
    c->x = (double)(rand() % MAX_COORDINATE);
    c->y = (double)(rand() % MAX_COORDINATE);
    c->radius = (double)(rand() % MAX_RADIUS) + 1;
}

void printCircle(Circle c) {
    printf("Tam (%.2f, %.2f), Ban kinh: %.2f\n", c.x, c.y, c.radius);
}

int main() {
    srand(time(NULL));
    int n, choice;
    Circle *circles;

    printf("So hinh tron: ");
    scanf("%d", &n);

    circles = (Circle *)malloc(n * sizeof(Circle));

    printf("Chon cach nhap:\n");
    printf("1. Nhap thu cong\n");
    printf("2. Sinh ngau nhien\n");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++) {
        if (choice == 1) {
            printf("Nhập thong tin hinh tron %d:\n", i + 1);
            inputCircle(&circles[i]);
        } else {
            generateRandomCircle(&circles[i]);
        }
    }

    printf("\nThong tin cac hinh tron:\n");
    for (int i = 0; i < n; i++) {
        printf("Hinh tron %d: ", i + 1);
        printCircle(circles[i]);
    }

    int maxIntersections = 0;
    int maxIntersectionIndex = -1;
    int *intersections = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (doCirclesIntersect(circles[i], circles[j])) {
                intersections[i]++;
                intersections[j]++;
            }
        }
        if (intersections[i] > maxIntersections) {
            maxIntersections = intersections[i];
            maxIntersectionIndex = i;
        }
    }

    printf("\nHinh tron giao voi nhieu hinh tron nhat:\n");
    printf("Hinh tron %d: ", maxIntersectionIndex + 1);
    printCircle(circles[maxIntersectionIndex]);
    printf("So luong giao: %d\n", maxIntersections);
    printf("Giao voi cac hinh tron: ");
    for (int i = 0; i < n; i++) {
        if (i != maxIntersectionIndex && doCirclesIntersect(circles[maxIntersectionIndex], circles[i])) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    free(circles);
    free(intersections);
    return 0;
}