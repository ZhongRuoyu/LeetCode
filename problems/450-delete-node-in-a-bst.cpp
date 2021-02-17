// Solved 2021-02-17 08:42
// Runtime: 24 ms (98.81%)
// Memory Usage: 32.5 MB (95.85%)

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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr || root->right == nullptr) {
                TreeNode *nodeToDelete = (root->left == nullptr) ? root->right : root->left;
                root->val = nodeToDelete->val;
                root->left = nodeToDelete->left;
                root->right = nodeToDelete->right;
                delete nodeToDelete;
            } else {
                TreeNode *p = findMax(root->left);
                root->val = p->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }

   private:
    TreeNode *findMax(TreeNode *root) {
        if (root == nullptr || root->right == nullptr) return root;
        return findMax(root->right);
    }
};
