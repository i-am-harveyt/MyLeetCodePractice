package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(t *TreeNode) int {
	if t == nil {
		return 0
	}
	ls, rs := helper(t.Left), helper(t.Right)
	ret += int(math.Abs(float64(ls - rs)))
	return t.Val + ls + rs
}

var ret int

func findTilt(root *TreeNode) int {
	ret = 0
	helper(root)
	return ret
}
