package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	cur := root
	for cur != nil {
		if cur.Left != nil {
			pre := cur.Left
			for pre.Right != nil {
				pre = pre.Right
			}
			pre.Right = cur.Right
			cur.Right = cur.Left
			cur.Left = nil
		}
		cur = cur.Right
	}
}
