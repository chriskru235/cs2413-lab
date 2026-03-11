/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    (void)root;
    (void)target;
    
    while (root != NULL) {
        if (root->val == target) return root; // Nodes value is the target, return current node

        if(target < root->val) root = root->left; // Target is less than nodes value, go to left subtree
        else root = root->right; // Target is greater than node value, go to right subtree
    }
    
    return NULL; // Value is not found in BST, return NULL
}
