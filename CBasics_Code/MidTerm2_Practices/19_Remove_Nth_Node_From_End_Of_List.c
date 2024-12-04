#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *makeNode(int x){
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = x; 
    p->next = NULL;
    return p;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *dummy = makeNode(0);
    dummy->next = head;
    struct ListNode *first = dummy;
    struct ListNode *second = dummy;
    for (int i = 1; i <= n + 1; i++){
        first = first->next;
    }
    while (first != NULL){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
}

void printList(struct ListNode *root){
    struct ListNode *p = root;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *l1 = makeNode(1);
    l1->next = makeNode(2);
    l1->next->next = makeNode(3);
    l1->next->next->next = makeNode(4);
    l1->next->next->next->next = makeNode(5);
    struct ListNode *result = removeNthFromEnd(l1, 2);
    printList(result);
    return 0;
}