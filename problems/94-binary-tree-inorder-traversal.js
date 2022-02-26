// Solved 2022-02-26
// Runtime: 56 ms (98.75%)
// Memory Usage: 42.1 MB (36.77%)

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
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    const result = [];
    traverse(root);
    return result;

    function traverse(node) {
        if (node === null) {
            return;
        }
        traverse(node.left);
        result.push(node.val);
        traverse(node.right);
    }
};

/*

Alternatively, using recursion and spread syntax:

var inorderTraversal = function (root) {
    if (root === null) {
        return [];
    }
    return [...inorderTraversal(root.left), root.val, ...inorderTraversal(root.right)];
};

*/
