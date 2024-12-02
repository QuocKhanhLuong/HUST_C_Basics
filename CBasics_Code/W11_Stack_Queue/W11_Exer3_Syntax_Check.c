#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000000];

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

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}


int check(char* s) {
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        } else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(stackEmpty())
                return 0;
            char a = top->value;
            pop();
            if (!match(a, s[i]))
                return 0;
        }
    }
    return stackEmpty();
}

int main(){
    scanf("%s", s);
    printf("%d", check(s));
    return 0;
}