/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isBalanced(root.Left) &&
		isBalanced(root.Right) &&
		abs(height(root.Left)-height(root.Right)) <= 1
}

func height(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return max(height(root.Left), height(root.Right)) + 1
}

func abs(x int) int {
	if x < 0 {
		return -1 * x
	}
	return x
}

func max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}
