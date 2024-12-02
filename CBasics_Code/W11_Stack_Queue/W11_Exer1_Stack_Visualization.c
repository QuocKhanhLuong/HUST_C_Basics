#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* top;

Node* makeNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x; p->next = NULL;
    return p;
}

void initStack(){
    top = NULL;
    }

int stackEmpty(){
    return top == NULL;
}

int pop(){
    //if(stackEmpty()) return ' ';  Có thể bỏ do ở hàm main đã có
    int x = top->value;
    Node* p = top; top = top->next;
    free(p);
    return x;
}

void push(int x){
    Node* p = makeNode(x);
    p->next = top; top = p;
}

void Empty(){
    while(!stackEmpty()){
        Node* p = top;
        top = top->next;
        free(p);
    }
}

int main(){
    char cmd[10];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0){
            break;
        } else if(strcmp(cmd,"PUSH")==0) {
            int v; scanf("%d",&v);
            push(v);
        } else if(strcmp(cmd,"POP")==0) {
            if(stackEmpty()){
                printf("NULL\n");
            } else {
                int v = pop();
                printf("%d\n",v);
            }
        }
    }
    Empty();
    return 0;
}