// Solved 2021-04-24 09:08
// Runtime: 0 ms (100.00%)
// Memory Usage: 16.7 MB (68.19%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int sumRootToLeaf(TreeNode *root, int result = 0) {
        if (root == nullptr) return 0;
        result = (result << 1) + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            // leaf reached
            return result;
        }
        return sumRootToLeaf(root->left, result) + sumRootToLeaf(root->right, result);
    }
};
