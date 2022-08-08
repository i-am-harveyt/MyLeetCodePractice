package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func idy(t *TreeNode, s *TreeNode) bool {
	if (t == nil) && (s == nil) {
		return true
	} else if (t == nil) || (s == nil) {
		return false
	}
	if t.Val != s.Val {
		return false
	}
	return idy(t.Left, s.Left) && idy(t.Right, s.Right)

}

func isSubtree(t *TreeNode, s *TreeNode) bool {
	if (t == nil) && (s == nil) {
		return true
	} else if (t == nil) || (s == nil) {
		return false
	}
	if t.Val == s.Val {
		if idy(t, s) {
			return true
		}
	}
	return isSubtree(t.Left, s) || isSubtree(t.Right, s)
}
