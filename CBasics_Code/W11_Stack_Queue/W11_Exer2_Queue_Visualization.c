#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode{
    int value;
    struct TNode* next;
}Node;

Node* head;
Node* tail;

Node* makeNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x; 
    p->next = NULL;
    return p;
}

void initQueue(){
    head = NULL;
    tail = NULL;
}

int queueEmpty(){
    return head == NULL && tail == NULL;
}
void push(int v) {
    Node* p = makeNode(v);
    if(queueEmpty()){
        head = p;
        tail = p;
        return;
    }
    tail->next = p;
    tail = p;
}

int pop(){
    //if(queueEmpty()) return -1; Trường hợp đặc biệt, check dưới hàm main()
    Node* tmp = head;
    int v = head->value;
    head = head->next;
    if(head == NULL) tail = NULL;
    free(tmp);
    return v;
}

void freeQueue(){
    while(!queueEmpty()){
        Node* tmp = head;
        head = head->next;
        if(head == NULL) tail = NULL;
        free(tmp);
    }
}

int main() {
    char cmd[10];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0){
            break;
        } else if(strcmp(cmd,"PUSH")==0) {
            int v; scanf("%d",&v);
            push(v);
        } else if(strcmp(cmd,"POP")==0) {
            if(queueEmpty()){
                printf("NULL\n");
            } else {
                int v = pop();
                printf("%d\n",v);
            }
        }
    }
    freeQueue();
    return 0;
}


