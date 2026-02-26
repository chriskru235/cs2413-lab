// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "student.h"

int middleNodeValue(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    // Fast will reach null the soonest (only check fast)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Slow moves one node
        fast = fast->next->next; // Fast moves two nodes
    }
    return slow->val; // Return value of slow (middle or second middle)
}