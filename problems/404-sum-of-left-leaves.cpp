// Solved 2021-04-03 09:50
// Runtime: 0 ms (100.00%)
// Memory Usage: 13.3 MB (97.18%)

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
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) return 0;
        return (isLeaf(root->left) ? root->left->val : 0) +
               sumOfLeftLeaves(root->left) +
               sumOfLeftLeaves(root->right);
    }

   private:
    inline bool isLeaf(TreeNode *root) {
        return (root && !(root->left) && !(root->right));
    }
};
