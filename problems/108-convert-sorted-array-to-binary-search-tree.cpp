// Solved 2021-04-05 09:16
// Runtime: 8 ms (96.15%)
// Memory Usage: 21.3 MB (79.87%)

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

   private:
    TreeNode *sortedArrayToBST(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) return nullptr;
        const int half = (end - begin) / 2;
        TreeNode *root = new TreeNode(*(begin + half));
        root->left = sortedArrayToBST(begin, begin + half);
        root->right = sortedArrayToBST(begin + half + 1, end);
        return root;
    }
};
