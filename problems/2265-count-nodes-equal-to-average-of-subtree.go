// Solved 2022-08-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 4.3 MB (80.95%)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfSubtree(root *TreeNode) int {
	result := dfs(root)
	return result.count
}

type result struct {
	sum   int
	n     int
	count int
}

func dfs(root *TreeNode) result {
	if root == nil {
		return result{}
	}

	leftResult := dfs(root.Left)
	rightResult := dfs(root.Right)

	rootResult := result{
		sum:   leftResult.sum + rightResult.sum + root.Val,
		n:     leftResult.n + rightResult.n + 1,
		count: leftResult.count + rightResult.count,
	}
	if root.Val == rootResult.sum/rootResult.n {
		rootResult.count++
	}

	return rootResult
}
