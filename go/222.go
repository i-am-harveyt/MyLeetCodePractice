package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hr(t *TreeNode) int {
	var ret int = 0
	for ; t != nil; t = t.Right {
		ret++
	}
	return ret
}

func hl(t *TreeNode) int {
	var ret int = 0
	for ; t != nil; t = t.Left {
		ret++
	}
	return ret
}

func sol(t *TreeNode) int {
	var l, r int = hl(t), hr(t)
	if l == r { // full BT
		return int(math.Pow(2, float64(l))) - 1
	}
	return 1 + sol(t.Left) + sol(t.Right) // not full, so keep doing
}

func countNodes(root *TreeNode) int {
	return sol(root)
}
