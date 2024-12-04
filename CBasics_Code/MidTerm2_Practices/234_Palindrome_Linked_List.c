#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL) 
        return true;

    // Find middle using slow/fast pointers
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    struct ListNode *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare first half with reversed second half
    struct ListNode *first = head;
    struct ListNode *second = prev;
    bool isPal = true;
    while (second != NULL) {
        if (first->val != second->val) {
            isPal = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Restore the list (optional)
    curr = prev;
    prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = prev;

    return isPal;
}

// Helper function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct ListNode *l1 = makeNode(1);
    l1->next = makeNode(2);
    l1->next->next = makeNode(3);
    l1->next->next->next = makeNode(2);
    l1->next->next->next->next = makeNode(1);
    printList(l1);
    printf("Is palindrome: %s\n", isPalindrome(l1) ? "true" : "false");

    return 0;
}


