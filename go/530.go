package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ret int
var prev *TreeNode

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func helper(cur *TreeNode) {
	if cur == nil {
		return
	}
	helper(cur.Left)
	if prev != nil {
		ret = min(ret, int(math.Abs(float64(cur.Val-prev.Val))))
	}
	prev = cur
	helper(cur.Right)
}

func getMinimumDifference(root *TreeNode) int {
	ret = 1 << 31
	prev = nil
	helper(root)
	return ret
}
