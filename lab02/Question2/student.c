// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    // TODO:
    // - Allocate MyCircularQueue
    // - Allocate the internal buffer `data` of length k
    // - Initialize capacity, head, tail, size

    MyCircularQueue* out = malloc(sizeof(MyCircularQueue)); // Allocate Queue
    out->data = malloc(sizeof(int) * k); // Allocate Data
    
    // initialize values
    out->capacity = k;
    out->head = 0;
    out->tail = 0;
    out->size = 0;

    return out;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // TODO:
    // - If full, return false
    // - Write value at tail, advance tail (wrap), size++

    // Check if Queue is at capacity
    if (obj->size == obj->capacity) return false; // EnQueue Failed

    // Add value to queue
    obj->data[obj->tail] = value; // Write value at tail
    obj->tail = (obj->tail + 1) % obj->capacity; // advance and wrap tail
    obj->size++; // track current size of queue

    return true; // EnQueue Successful
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // TODO:
    // - If empty, return false
    // - Advance head (wrap), size--

    // Check if Queue is empty
    if (obj->size == 0) return false; // DeQueue Failed

    // Remove head from queue
    obj->head = (obj->head + 1) % obj->capacity; // Increase and wrap head
    obj->size--; // track current size of queue 

    return true; // DeQueue Successful
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return data[head]

    // Check if there can be a value at front
    if (obj->size == 0) return -1; // Queue empty, Failed
    else return obj->data[obj->head]; // Return value at front
}

int myCircularQueueRear(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return the last inserted element
    //   (tail points to next insertion position)

    // Check if there can be a value at rear
    if (obj->size == 0) return -1; // Queue empty, Failed
    else {
        int rear = (obj->tail-1); // get rear position (-1 from tail)
        if(rear < 0) rear = obj->capacity-1; // wrap rear position
        return obj->data[rear]; // return rear value

    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == 0
    if (obj->size == 0) return true; // Queue is empty
    return false; // Queue is not empty
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == capacity
    if (obj->size == obj->capacity) return true; // Queue is full
    return false; // Queue is not full (or empty)
 
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // TODO:
    // - Free internal buffer then free obj
    free(obj->data); // free data buffer
    free(obj); // free queue  
}
