/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int treeHeight(struct TreeNode* root) {
    if (root == NULL) return -1;
    int leftH = treeHeight(root->left) + 1; 
    int rightH = treeHeight(root->right) + 1;

    if (leftH > rightH) return leftH; // left is deeper than right
    else return rightH; // right is deeper, or they are equivalent
}


bool validBST(struct TreeNode* node, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (node == NULL) return true; // base case
    if ((minNode != NULL && node->val <= minNode->val)) return false; // is not valid
    if ((maxNode != NULL && node->val >= maxNode->val)) return false; // is not valid
    return validBST(node->left, minNode, node) && validBST(node->right, node, maxNode); // continue searching tree
}

bool validAVL(struct TreeNode* root) {
    if (root == NULL) return true; // DNE

    int balance = 0;
    balance = treeHeight(root->left) - treeHeight(root->right);
    if (balance < -1 || balance > 1) return false; // Invalid AVL tree
    return validAVL(root->left) && validAVL(root->right); // continue searching, until valid or not
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    (void)root;
    if (root == NULL) return true; // empty

    // begin validating
    return validBST(root->left, NULL, root) && validBST(root->right, root, NULL) && validAVL(root);
}
