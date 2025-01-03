/*Bài 1: (3 điểm) - Đảo ngược Stack
Cho một stack các số nguyên. Hãy viết chương trình C để đảo ngược thứ tự các phần tử trong stack đó. 
Yêu cầu sử dụng các thao tác cơ bản của stack (push, pop, isEmpty) và không được sử dụng bất kỳ cấu trúc dữ liệu nào khác để hỗ trợ (ví dụ như array, linked list). 
Sau khi đảo ngược, hãy in các phần tử của stack ra màn hình, mỗi phần tử trên một dòng.
Lưu ý:
Đầu vào sẽ là một chuỗi các lệnh push, mỗi lệnh push sẽ bao gồm từ khóa "push" và một số nguyên.
Việc đảo ngược stack phải được thực hiện sau khi đã nhận tất cả các lệnh push.
Đầu vào kết thúc bằng từ khóa "end".
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* top = NULL;

Node* makeNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;
    return p;
}

int isEmpty(){
    return top == NULL;
}

void push(int x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

int pop(){
    if(isEmpty())
        return -1;
    int x = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return x;
}

void reverseStack(){
    Node* p = top;
    Node* q = NULL;
    while(p != NULL){
        Node* temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    top = q;
    while(top != NULL){
        printf("%d\n", top->value);
        top = top->next;
    }
}

int main(){
    char cmd[10];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "end") == 0)
            break;
        else if(strcmp(cmd, "push") == 0){
            int v;
            scanf("%d", &v);
            push(v);
        }
    }
    reverseStack();
    return 0;
}
