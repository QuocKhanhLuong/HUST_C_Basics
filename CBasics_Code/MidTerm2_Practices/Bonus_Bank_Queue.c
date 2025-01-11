#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Customer
typedef struct Customer {
    char id[8];     // Mã khách hàng
    char name[21];  // Tên khách hàng
    char level[7];  // Hạng khách hàng ("VIP", "GOLD", "SILVER")
    struct Customer *next;
} Customer;

Customer *head = NULL, *tail = NULL;

// Tạo hàng đợi rỗng
void CreateQueue() {
    head = NULL;
    tail = NULL;
}

// Kiểm tra hàng đợi rỗng
int isEmpty() {
    return head == NULL;
}

// Thêm khách hàng vào hàng đợi
void Insert(const char *id, const char *name, const char *level) {
    // Tạo một khách hàng mới
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    if (!newCustomer) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newCustomer->id, id);
    strcpy(newCustomer->name, name);
    strcpy(newCustomer->level, level);
    newCustomer->next = NULL;

    // Thêm vào cuối hàng đợi
    if (isEmpty()) {
        head = newCustomer;
        tail = newCustomer;
    } else {
        tail->next = newCustomer;
        tail = newCustomer;
    }
}

// In toàn bộ hàng đợi
void Print() {
    if (isEmpty()) {
        printf("EMPTY\n");
        return;
    }
    Customer *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->id, current->name, current->level);
        current = current->next;
    }
}

// Loại bỏ tất cả khách hàng hạng "VIP"
void Vip() {
    while (head != NULL && strcmp(head->level, "VIP") == 0) {
        Customer *temp = head;
        head = head->next;
        free(temp);
    }

    Customer *current = head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->next->level, "VIP") == 0) {
            Customer *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    if (head == NULL) {
        tail = NULL;
    }
}

// Đếm số lượng khách hạng "GOLD"
void Gold() {
    int count = 0;
    Customer *current = head;
    while (current != NULL) {
        if (strcmp(current->level, "GOLD") == 0) {
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        printf("NO GOLD\n");
    } else {
        printf("%d\n", count);
    }
}

// Phục vụ khách hàng đầu tiên trong hàng đợi
void Serve() {
    if (isEmpty()) {
        printf("EMPTY\n");
        return;
    }
    Customer *temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

// Giải phóng bộ nhớ của hàng đợi
void FreeQueue() {
    while (head != NULL) {
        Customer *temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

int main() {
    char command[100];
    CreateQueue();

    while (1) {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "*") == 0) {
            break;
        }

        if (strcmp(command, "CreateQueue") == 0) {
            CreateQueue();
        } else if (strcmp(command, "Print") == 0) {
            Print();
        } else if (strcmp(command, "Vip") == 0) {
            Vip();
        } else if (strcmp(command, "Gold") == 0) {
            Gold();
        } else if (strcmp(command, "Serve") == 0) {
            Serve();
        } else if (strncmp(command, "Insert", 6) == 0) {
            char id[8], name[21], level[7];
            sscanf(command + 7, "%s %s %s", id, name, level);
            Insert(id, name, level);
        } else {
            printf("Invalid command.\n");
        }
    }

    FreeQueue();
    return 0;
}