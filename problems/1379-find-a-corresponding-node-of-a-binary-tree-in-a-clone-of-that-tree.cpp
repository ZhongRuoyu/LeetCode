// Solved 2022-08-03
// Runtime: 687 ms (79.25%)
// Memory Usage: 163.8 MB (81.84%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target) {
        if (original == nullptr || cloned == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode *left_result =
            getTargetCopy(original->left, cloned->left, target);
        if (left_result != nullptr) {
            return left_result;
        }
        TreeNode *right_result =
            getTargetCopy(original->right, cloned->right, target);
        if (right_result != nullptr) {
            return right_result;
        }
        return nullptr;
    }
};
