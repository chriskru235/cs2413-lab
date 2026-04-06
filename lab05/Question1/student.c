/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

/*
Optional helper structure for a hash table entry.

You may use this structure if you want to build your own hash table.
key   -> the number from the array
value -> the index of that number
*/
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/*
Optional table size for a simple hash table implementation.
You may change this value if needed.
*/
#define TABLE_SIZE 1009

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

/*
Return an array of size 2 containing the indices of the two numbers
whose sum equals target.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* Write your code here */
    int *indices = NULL;
    *returnSize = 0;
    Node* hash_table[TABLE_SIZE]; //F Create Hash Table
    for (int i=0; i<TABLE_SIZE; i++) hash_table[i] = NULL;

    for (int i=0; i<numsSize; i++)  // Insert into Hash Table
        insert(hash_table, nums[i], i);

    // Search for indices
    int value1, value2;
    for (int i=TABLE_SIZE-1; i>=0; i--) { // Decrement through table
        // Check each possible pair,
        if(find(hash_table, i, &value1)) {
            for(int j=i; j>=0;j--) {
                int isDuplicate = 0;
                // check for duplicates
                if(find(hash_table, j, &value2)) {
                    Node *curNode = hash_table[j];
                    if(value2 == value1) {
                        isDuplicate = 1;
                        while(curNode->next != NULL) {
                            isDuplicate = 0;
                            curNode = curNode->next;
                            value2 = curNode -> value;
                        } 
                    }
                    // Compare
                    if(hash_table[i]->key + curNode->key == target && !isDuplicate) {
                        *returnSize = 2;
                        indices = calloc(2, sizeof(int));
                        indices[0] = value2;
                        indices[1] = value1;
                        break; // Successfully found indices pair
                    }
                }
            }
        }

    }

    freeTable(hash_table);
    return indices;
}

/*
Optional helper: compute a hash index for a key.
*/
static int hash(int key) {
    // Allows for negative values to be stored
    return (key+(TABLE_SIZE/2))%TABLE_SIZE;
}

/*
Optional helper: insert (key, value) into the hash table.
*/
static void insert(Node* table[], int key, int value) {
    Node* me = malloc(sizeof(Node));
    me->value = value;
    me->key = key;
    if (table[hash(key)] == NULL) {
        table[hash(key)] = me; 
    } else {
        Node *parent = table[hash(key)];
        while(parent->next != NULL) parent = parent->next;
        parent->next = me;
    }
}

/*
Optional helper: search for key in the hash table.
If found, store the associated value in *value and return 1.
Otherwise return 0.
*/
static int find(Node* table[], int key, int* value) {
    if(table[key] == NULL) return 0;
    if (value != NULL) *value = table[key]->value;
    return 1;
}

/*
Optional helper: free all memory used by the hash table.
*/
static void freeTable(Node* table[]) {
    for (int i=0; i<TABLE_SIZE; i++) {
        if(find(table, i, NULL)) {
            Node *prev = NULL, *cur = table[i];
            while (cur != NULL) {
                prev = cur;
                cur = prev->next;
                free(prev);
            }
        }
    }
}