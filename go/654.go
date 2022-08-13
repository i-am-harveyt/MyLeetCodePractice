package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	var build func(nums *[]int, l, r int) *TreeNode
	build = func(nums *[]int, l, r int) *TreeNode {
		if l > r {
			return nil
		}
		var m = l // maxValue index
		for i := l + 1; i <= r; i++ { // find max value
			if (*nums)[i] > (*nums)[m] {
				m = i
			}
		}

		// build
		var ret *TreeNode = &TreeNode{Val: (*nums)[m]}
		ret.Left = build(nums, l, m-1)
		ret.Right = build(nums, m+1, r)
		return ret
	}
	return build(&nums, 0, len(nums)-1)
}
