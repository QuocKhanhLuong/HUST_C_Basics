/*Bài 1: Danh Sách Liên Kết - Tìm và Xóa Phần Tử

Cho một danh sách liên kết đơn các số nguyên. Bạn hãy viết chương trình C để thực hiện các thao tác sau:
Đọc danh sách: Đọc các số nguyên từ đầu vào để tạo một danh sách liên kết đơn. Số nguyên đầu tiên là số lượng phần tử của danh sách, sau đó là các phần tử của danh sách.
Tìm phần tử: Đọc một số nguyên value từ đầu vào.
Xóa phần tử: Tìm tất cả các phần tử có giá trị bằng value và xóa chúng khỏi danh sách.
In danh sách: In ra các phần tử còn lại của danh sách liên kết, mỗi phần tử cách nhau bởi dấu cách. Nếu danh sách rỗng, in ra "empty".

Lưu ý:
Bạn cần tự định nghĩa cấu trúc Node cho danh sách liên kết.
Thao tác xóa phải xóa tất cả các phần tử có giá trị value.
Đảm bảo giải phóng bộ nhớ của các node đã bị xóa.
Đầu vào kết thúc bằng ký tự '#'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
}Node;

Node *root = NULL;
Node *cur = NULL;
Node *prev = NULL;

Node *makeNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int value){
    Node *new = makeNode(value);
    if (root == NULL){
        root = new;
        cur = root;
    } else {
        cur->next = new;
        cur = new;
    }
}

int findNode(int value){
    Node *temp = root;
    while (temp != NULL){
        if(temp->value == value) 
            return 1;
            temp = temp->next;
    }
    return 0;
}

void deleteNode(int value){
    Node *temp = root;
    Node *prev = NULL;
    while (temp != NULL){
        if (temp->value == value){
            if (prev == NULL){
                root = temp->next;
                free(temp);
                temp = root;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void printList(){
    Node *temp = root;
    if(temp == NULL){
        printf("empty\n");
        return;
    } else {
        while (temp != NULL){
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeList(){
    Node *temp = root;
    while (temp != NULL){
        Node *del = temp;
        temp = temp->next;
        free(del);
    }
}

int main(){
    int value;
    char c;
    while (1){
        scanf("%d", &value);
        if (value == '#') break;
        insertNode(value);
    }
    scanf("%d", &value);
    deleteNode(value);
    printList();
    freeList();
    return 0;
}

