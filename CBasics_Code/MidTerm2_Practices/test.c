//De 2: Bank Queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    char customerID[6];
    char customerName[31];
    float amount;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL; // Con trỏ đầu và cuối của hàng đợi

// Tạo một node mới
Node *makeNode(char *id, char *name, float amount) {
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->customerID, id);
    strcpy(p->customerName, name);
    p->amount = amount;
    p->next = NULL;
    return p;
}

// Tạo hàng đợi rỗng
void createQueue() {
    front = NULL;
    rear = NULL;
    printf("Queue created successfully.\n");
}

// Kiểm tra hàng đợi rỗng
void queueEmpty() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

// Thêm phần tử vào hàng đợi
void enqueue(char *id, char *name, float amount) {
    Node *p = makeNode(id, name, amount);
    if (front == NULL) { // Hàng đợi rỗng
        front = p;
        rear = p;
    } else { // Thêm vào cuối hàng đợi
        rear->next = p;
        rear = p;
    }
    printf("Enqueued: %s %s %.2f\n", id, name, amount);
}

// Xóa phần tử đầu tiên khỏi hàng đợi
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    Node *tmp = front;
    printf("Dequeued: %s %s %.2f\n", front->customerID, front->customerName, front->amount);
    front = front->next;
    if (front == NULL) { // Nếu hàng đợi trống
        rear = NULL;
    }
    free(tmp);
}

// Lấy thông tin phần tử đầu tiên
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front: %s %s %.2f\n", front->customerID, front->customerName, front->amount);
}

// In toàn bộ hàng đợi
void printQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *p = front;
    printf("Queue contents:\n");
    while (p != NULL) {
        printf("%s %s %.2f\n", p->customerID, p->customerName, p->amount);
        p = p->next;
    }
}

// Xóa toàn bộ hàng đợi
void clearQueue() {
    while (front != NULL) {
        Node *tmp = front;
        front = front->next;
        free(tmp);
    }
    rear = NULL;
    printf("Queue cleared.\n");
}

// Hàm chính
int main() {
    char cmd[20];

    createQueue(); // Tạo hàng đợi rỗng

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "#") == 0) { // Thoát chương trình
            break;
        } else if (strcmp(cmd, "Enqueue") == 0) {
            char id[6], name[31];
            float amount;
            scanf("%s %s %f", id, name, &amount);
            enqueue(id, name, amount);
        } else if (strcmp(cmd, "Dequeue") == 0) {
            dequeue();
        } else if (strcmp(cmd, "Peek") == 0) {
            peek();
        } else if (strcmp(cmd, "Print") == 0) {
            printQueue();
        } else if (strcmp(cmd, "Empty") == 0) {
            queueEmpty();
        }
    }

    clearQueue(); // Giải phóng bộ nhớ trước khi kết thúc chương trình
    return 0;
}


//De 3: 