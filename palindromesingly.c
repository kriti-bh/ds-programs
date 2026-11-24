#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;


    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }


    while (slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }


    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

