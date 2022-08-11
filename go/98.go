package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// use left bound and right bound to test
func helper(t *TreeNode, l, r int) bool {
	if t == nil {
		return true
	}
	if t.Val > r || t.Val < l {
		return false
	}
	return helper(t.Left, l, t.Val) && helper(t.Right, t.Val, r)
}

func isValidBST(root *TreeNode) bool {
	return helper(root, -1<<32, 1<<32)
}
