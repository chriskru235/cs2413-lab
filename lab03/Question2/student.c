// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement

      if (head == NULL || head->next == NULL) return head; // Single element or empty list, return ListNode;

      struct ListNode *pairA=NULL, *pairB=NULL, *nextPair = head, *prev = NULL;
      head = head->next; // The head becomes the next node
      while (nextPair != NULL && nextPair->next != NULL) { // Do until at a element without a pair or NULL pointer            
            // Set values to the next pairings
            pairA = nextPair;
            pairB = pairA->next;
            nextPair = pairB->next; 

            // Set next values to swap pairs
            pairA->next = pairB->next;
            pairB->next = pairA;
            if (prev != NULL) prev->next = pairB; // Point to the new front value of the pair if there is a prev
            prev = pairA;
      }

      return head;
}