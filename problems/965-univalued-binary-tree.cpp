// Solved 2021-04-04 13:12
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.8 MB (93.36%)

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
    bool isUnivalTree(TreeNode *root) {
        if (root == nullptr) return true;
        return isUnivalTree(root, root->val);
    }

   private:
    bool isUnivalTree(TreeNode *root, int val) {
        if (root == nullptr) return true;
        if (root->val != val) return false;
        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};
