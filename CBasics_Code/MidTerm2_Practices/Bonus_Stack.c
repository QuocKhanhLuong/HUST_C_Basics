#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[51];
    char time[9];
    struct Node* next;
} Node;

Node* top = NULL;

void createStack() {
    top = NULL;
    printf("Stack created\n");
}

void push(char *url, char *time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(newNode->url, url);
    strcpy(newNode->time, time);
    newNode->next = top;
    top = newNode;
    printf("Push: %s %s\n", url, time);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = top;
    printf("Pop: %s %s\n", top->url, top->time);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Peek: %s %s\n", top->url, top->time);
}

void print() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = top;
    while (current != NULL) {
        printf("%s %s\n", current->url, current->time);
        current = current->next;
    }
}

void clearStack() {
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
    printf("Cleared\n");
}

int main() {
    char cmd[10];
    createStack();
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) {
            break;
        } else if (strcmp(cmd, "Push") == 0) {
            char url[51], time[9];
            scanf("%s %s", url, time);
            push(url, time);
        } else if (strcmp(cmd, "Pop") == 0) {
            pop();
        } else if (strcmp(cmd, "Peek") == 0) {
            peek();
        } else if (strcmp(cmd, "Print") == 0) {
            print();
        } else if (strcmp(cmd, "ClearStack") == 0) {
            clearStack();
        } else if (strcmp(cmd, "createStack") == 0) {
            createStack();
        }
    }
    clearStack();
    return 0;
}
