package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ret int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func helper(t *TreeNode) int {
	if t == nil {
		return 0
	}
	var l, r int = helper(t.Left), helper(t.Right)
	ret = max(ret, l+r)
	return max(l, r) + 1
}

func diameterOfBinaryTree(root *TreeNode) int {
	ret = -1 << 31
	helper(root)
	return ret
}
