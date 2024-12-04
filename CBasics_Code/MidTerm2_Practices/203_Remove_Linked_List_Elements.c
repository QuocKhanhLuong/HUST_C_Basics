#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* makeNode(int val){
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode *removeElements(struct ListNode *head, int val){
    struct ListNode *root = makeNode(0);
    root->next = head;
    struct ListNode *p = root;
    while(p->next != NULL){
        if(p->next->val == val){
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return root->next;
}

void printList(struct ListNode *root){
    struct ListNode *p = root;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *l1 = makeNode(1);
    l1->next = makeNode(2);
    l1->next->next = makeNode(6);
    l1->next->next->next = makeNode(3);
    l1->next->next->next->next = makeNode(4);
    l1->next->next->next->next->next = makeNode(5);
    l1->next->next->next->next->next->next = makeNode(6);
    struct ListNode *result = removeElements(l1, 6);
    printList(result);
    return 0;
}