#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
    char name[21];
    struct TNode* next;
} Node;

Node* maleHead = NULL;
Node* maleTail = NULL;
Node* femaleHead = NULL;
Node* femaleTail = NULL;

Node* makeNode(char* name) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->next = NULL;
    return p;
}

int queueEmpty(Node* head) {
    return head == NULL;
}

void enqueue(int gender, char* name) {
    Node* p = makeNode(name);
    if (gender == 0) { // Nam
        if (queueEmpty(maleHead)) {
            maleHead = maleTail = p;
        } else {
            maleTail->next = p;
            maleTail = p;
        }
    } else if (gender == 1) { // Nữ
        if (queueEmpty(femaleHead)) {
            femaleHead = femaleTail = p;
        } else {
            femaleTail->next = p;
            femaleTail = p;
        }
    }
}

void dequeue(int gender) {
    Node* tmp;
    char name[21]; // Biến tạm để lưu tên

    if (gender == 0) { // Nam
        if (queueEmpty(maleHead)) {
            printf("NULL\n");
            return;
        }
        tmp = maleHead;
        strcpy(name, maleHead->name); // Sao chép tên trước khi giải phóng
        maleHead = maleHead->next;
        if (maleHead == NULL) maleTail = NULL;
    } else { // Nữ
        if (queueEmpty(femaleHead)) {
            printf("NULL\n");
            return;
        }
        tmp = femaleHead;
        strcpy(name, femaleHead->name); // Sao chép tên trước khi giải phóng
        femaleHead = femaleHead->next;
        if (femaleHead == NULL) femaleTail = NULL;
    }

    free(tmp);
    printf("Welcome %s\n", name); // In thông báo chào mừng
}

void freeQueue(Node* head) {
    while (!queueEmpty(head)) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    char cmd[100];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) {
            break;
        } else if (strcmp(cmd, "ENQUEUE") == 0) {
            int gender;
            char name[21];
            scanf("%d %s", &gender, name);
            enqueue(gender, name);
        } else if (strcmp(cmd, "DEQUEUE") == 0) {
            int gender;
            scanf("%d", &gender);
            dequeue(gender);
        }
    }
    freeQueue(maleHead);
    freeQueue(femaleHead);
    return 0;
}