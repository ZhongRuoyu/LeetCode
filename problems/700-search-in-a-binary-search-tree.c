// Solved 2021-01-09 11:12
// Runtime: 24 ms (68.77%)
// Memory Usage: 15.1 MB (89.70%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
}
