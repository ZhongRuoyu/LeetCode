// Solved 2021-01-08 07:55
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (71.43%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

inline void swap(struct TreeNode** x, struct TreeNode** y) {
    struct TreeNode* t = *x;
    *x = *y;
    *y = t;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        swap(&(root->left), &(root->right));
    }
    return root;
}
