#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* cur = head;
    while(cur != NULL && cur->next != NULL){
        if(cur->val == cur->next->val){
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
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
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 1;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 2;
    l1->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->next->val = 3;
    l1->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->next->next->val = 3;
    l1->next->next->next->next->next = NULL;
    struct ListNode *result = deleteDuplicates(l1);
    printList(result);
    return 0;
}
