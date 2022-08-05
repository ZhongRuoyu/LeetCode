// Solved 2022-08-05
// Runtime: 108 ms (94.16%)
// Memory Usage: 61.8 MB (50.13%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int deepestLeavesSum(TreeNode *root) {
        queue<TreeNode *> queue;
        queue.push(root);
        int result = 0;
        while (!queue.empty()) {
            result = 0;
            auto queue_size = queue.size();
            for (decltype(queue_size) i = 0; i != queue_size; ++i) {
                auto node = queue.front();
                queue.pop();
                result += node->val;
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
        }
        return result;
    }
};
