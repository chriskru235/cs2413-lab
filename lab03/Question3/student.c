// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement

    struct ListNode *slow = head, *fast = head;

    // If the list is not cycled, fast will reach null the soonest (only check fast)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Slow moves one node
        fast = fast->next->next; // Fast moves two nodes

        if (slow == fast) return true; // Slow and Fast points at the same node, cycle exists, return true
    }

    return false; // Exits loop, cycle does not exists or list is empty, return false
}