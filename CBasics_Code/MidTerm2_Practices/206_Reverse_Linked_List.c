#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode *makeNode(int val){
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode *reverse(struct ListNode *head){
    struct ListNode *p = head;
    struct ListNode *pp = NULL;
    struct ListNode *np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
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
    l1->next->next = makeNode(3);
    l1->next->next->next = makeNode(4);
    l1->next->next->next->next = makeNode(5);
    struct ListNode *result = reverse(l1);
    printList(result);
    return 0;
}

