#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

void computePrefix(char prefix[]){
    initStack();
    int length = strlen(prefix);

    for(int i = length - 1; i >= 0; i--){
        char c = prefix[i];

        if(isdigit(c)){
            push(c - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch(c){
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }

    printf("Result of prefix expression is %d\n", prefix, pop());
}
void computePostfix(char postfix[]){
    initStack();
    int length = strlen(postfix);

    for(int i = 0; i < length; i++){
        char c = postfix[i];

        if(isdigit(c)){
            push(c - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch(c){
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }

    printf("Result of postfix expression is %d\n", postfix, pop());
}

int main() {
    char prefix[1000], postfix[1000];
    int n;
    scanf("%d", &n);
    if(n == 1){ //Compute Prefix Mode
        scanf("%s", prefix);
        computePrefix(prefix);
    } else if(n == 2){ //Compute Postfix Mode
        scanf("%s", postfix);
        computePrefix(postfix);
    }
    return 0;
}