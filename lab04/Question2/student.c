#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool compareNodes(struct TreeNode* leftSTNode, struct TreeNode* rightSTNode) {
  if(leftSTNode == NULL || rightSTNode == NULL)
    return (leftSTNode == NULL && rightSTNode == NULL); // returns false [one is null] or true [both are null]
  
  // visit nodes
  if (leftSTNode->val != rightSTNode->val) return false; // values do not match

  // visit left and right subtrees
  return compareNodes(leftSTNode->left, rightSTNode->right) && compareNodes(leftSTNode->right, rightSTNode->left);
}


bool isSymmetric(struct TreeNode* root) {
  if (root == NULL) return true;
  // compare subtrees 
  // preorder traversal on left anr right subtree concurrently
  return compareNodes(root->left, root->right);
}