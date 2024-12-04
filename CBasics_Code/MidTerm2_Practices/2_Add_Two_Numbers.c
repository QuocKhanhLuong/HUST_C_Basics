#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2){
    struct ListNode *dummy = makeNode(0);
    struct ListNode *p = l1, *q = l2, *curr = dummy;
    int carry = 0;
    while (p != NULL || q != NULL){
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = makeNode(sum % 10);
        curr = curr->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    if (carry > 0){
        curr->next = makeNode(carry);
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
    struct ListNode *l1 = makeNode(2);
    l1->next = makeNode(4);
    l1->next->next = makeNode(3);
    struct ListNode *l2 = makeNode(5);
    l2->next = makeNode(6);
    l2->next->next = makeNode(4);
    struct ListNode *result = addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}
