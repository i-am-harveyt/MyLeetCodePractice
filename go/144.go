package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	var ret = make([]int, 0)
	if root == nil {
		return ret
	}
	var stack = make([]*TreeNode, 0)
	var cur *TreeNode = root

	for len(stack) > 0 || cur != nil {
		for cur != nil {
			ret = append(ret, cur.Val)
			stack = append(stack, cur)
			cur = cur.Left
		}

		cur = stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if cur != nil {
			cur = cur.Right
		}
	}

	return ret
}
