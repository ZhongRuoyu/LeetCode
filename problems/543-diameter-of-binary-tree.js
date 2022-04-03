// Solved 2022-04-03
// Runtime: 68 ms (95.34%)
// Memory Usage: 47 MB (7.77%)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
    return traverse(root)[0];

    function traverse(root) {
        if (root === null) {
            return [0, 0];
        }
        const [leftResult, leftDepth] = traverse(root.left);
        const [rightResult, rightDepth] = traverse(root.right);
        const result = Math.max(Math.max(leftResult, rightResult), leftDepth + rightDepth);
        const depth = Math.max(leftDepth, rightDepth) + 1;
        return [result, depth];
    }
};
