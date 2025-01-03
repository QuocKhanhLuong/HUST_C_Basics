
/* Bài 2: (3 điểm) - Quản lý Hàng Đợi Ưu Tiên (Priority Queue)

Một bệnh viện có các bệnh nhân đang chờ được khám. 
Mỗi bệnh nhân có một mã số (int) và mức độ ưu tiên (int). 
Hãy viết chương trình C để quản lý một hàng đợi ưu tiên, với mức độ ưu tiên cao hơn được khám trước.
Sử dụng cấu trúc dữ liệu hàng đợi ưu tiên để lưu trữ thông tin bệnh nhân.
Các thao tác bao gồm: "add <id> <priority>" để thêm bệnh nhân vào hàng đợi ưu tiên, 
"next" để lấy bệnh nhân tiếp theo (có độ ưu tiên cao nhất) ra khỏi hàng đợi và in ra thông tin bệnh nhân đó, 
"print" để in ra toàn bộ danh sách bệnh nhân còn lại trong hàng đợi theo thứ tự ưu tiên.
Nếu hàng đợi trống khi thực hiện thao tác "next", in ra "empty".

Lưu ý:
Đầu vào là chuỗi các lệnh, mỗi lệnh nằm trên một dòng.
Đầu vào kết thúc bằng từ khóa "end".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    int priority;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* makeNode(int id, int priority){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->priority = priority;
    p->next = NULL;
    return p;
}

void add(int id, int priority){
    Node *p = makeNode(id, priority);
    if(head == NULL){
        head = p;
        tail = p;
        return;
    } else {
        Node *tmp = head;
        Node *prev = NULL;
        while(tmp != NULL && tmp->priority >= priority){
            prev = tmp;
            tmp = tmp->next;
        }
        if(prev == NULL){
            p->next = head;
            head = p;
        } else {
            prev->next = p;
            p->next = tmp;
            if(tmp == NULL)     
                tail = p;
        }
        
    }
}

void next(){
    if(head == NULL){
        tail = NULL;
        return;
    }
    Node *tmp = head;
    printf("%d %d\n", tmp->id, tmp->priority);
    head = head->next;
    free(tmp);
}

void print(){
    Node *tmp = head;
    while(tmp != NULL){
        printf("%d %d\n", tmp->id, tmp->priority);
        tmp = tmp->next;
    }
}

int main(){
    char cmd[10];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "end") == 0)
            break;
        else if(strcmp(cmd, "add") == 0){
            int id, priority;
            scanf("%d %d", &id, &priority);
            add(id, priority);
        } else if(strcmp(cmd, "next") == 0){
            if(head == NULL){
                printf("empty\n");
            } else {
                next();
            }
        } else if(strcmp(cmd, "print") == 0){
            print();
        }
    }
    return 0;
}

