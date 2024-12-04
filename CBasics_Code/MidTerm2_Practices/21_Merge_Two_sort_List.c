#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    while(list1 != NULL && list2 !=NULL){
        if(list1->val <= list2->val){
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if(list1 != NULL){
        cur->next = list1;
    } else {
        cur->next = list2;
    }
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
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = NULL;
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;
    struct ListNode *result = mergeTwoLists(l1, l2);
    printList(result);
    return 0;
}