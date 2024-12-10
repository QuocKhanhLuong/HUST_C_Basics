#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char customerID[6];
    char customerName[31];
    float amount;
    struct Node *next;
}Node;

Node *front = NULL, *rear = NULL;

Node *makeNode(char *x, char *y, float z){
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->customerID, x);
    strcpy(p->customerName, y);
    p->amount = z;
    p->next = NULL;
    return p;
}

void createQueue(){
    Node *front = NULL;
    Node *rear = NULL;
}

int queueEmpty(){
    return front == NULL && rear == NULL;
}

void enqueue(char *customerID, char *customerName, float amount){
    Node *p = makeNode(customerID, customerName, amount);
    if(queueEmpty()){
        front = p;
        rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
}

void dequeue(){
    if (front == NULL) {
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

void peek(){
    if(queueEmpty()) 
        return;
    printf("%s %s %.2f\n", front->customerID, front->customerName, front->amount);
}

void print(){
    if(queueEmpty()) 
        return;
    Node *tmp = front;
    while(tmp != NULL){
        printf("Thong tin hanh khach: \n");
        printf("%s %s %.2f\n", tmp->customerID, tmp->customerName, tmp->amount);
        tmp = tmp->next;
    }
}

void clearQueue(){
    while(!queueEmpty()){
        Node *tmp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        free(tmp);    
    }
}

int main(){
    char cmd[20];
    createQueue();
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0){
            break;
        } else if(strcmp(cmd,"Enqueue") == 0){
            char customerID[6], customerName[31];
            float amount;
            scanf("%s %s %f", customerID, customerName, &amount);
            enqueue(customerID, customerName, amount);
        } else if(strcmp(cmd,"Dequeue") == 0){
            dequeue();
        } else if(strcmp(cmd,"Peek") == 0){
            peek();
        } else if(strcmp(cmd,"Print") == 0){
            print();
        }
    }
    clearQueue();
    return 0;
}