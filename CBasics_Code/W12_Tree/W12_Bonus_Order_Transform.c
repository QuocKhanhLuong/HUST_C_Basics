#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    if(stackEmpty()) return ' ';  
    int x = top->value;
    Node* p = top; top = top->next;
    free(p);
    return x;
}

void push(int x){
    Node* p = makeNode(x);
    p->next = top; top = p;
}

int uutien(char c){
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void infixToPrefix(char infix[], char prefix[]){
    char c;
    int i = strlen(infix) - 1;  // Start from end
    int j = 0;
    
    while(i >= 0){
        c = infix[i];
        if(c == ')'){  // Note: Swapped ( with )
            push(c);
        } else if(c == '('){ // Note: Swapped ) with (
            while(top != NULL && top->value != ')'){
                prefix[j++] = pop();
            }
            pop();
        } else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(top != NULL && uutien(top->value) > uutien(c)){ // Note: Changed >= to >
                prefix[j++] = pop();
            }
            push(c);
        } else {
            prefix[j++] = c;
        }
        i--;
    }
    
    while(top != NULL){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    
    // Reverse the result
    int start = 0;
    int end = strlen(prefix) - 1;
    while(start < end){
        c = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = c;
        start++;
        end--;
    }
}

void infixToPostfix(char infix[], char postfix[]){
    char c;
    int i = 0, j = 0;
    while((c = infix[i++]) != '\0'){
        if(c == '('){
            push(c);
        } else if(c == ')'){
            while(top != NULL && top->value != '('){
                postfix[j++] = pop();
            }
            pop();
        } else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(top != NULL && uutien(top->value) >= uutien(c)){
                postfix[j++] = pop();
            }
            push(c);
        } else {
            postfix[j++] = c;
        }
    }
    while(top != NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[100], prefix[100], postfix[100];
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("%s\n", prefix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}