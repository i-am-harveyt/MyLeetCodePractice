package main

// Definition for a binary tree node.
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func postorderTraversal(root *TreeNode) []int {
	var ret = make([]int, 0)
	var st = make([]*TreeNode, 0)
	var cur *TreeNode = root

	for len(st) > 0 || cur != nil {
		for cur != nil {
			st = append(st, cur)
			st = append(st, cur)
			cur = cur.Left
		}

		cur = st[len(st)-1]
		st = st[:len(st)-1]

		if len(st) > 0 && st[len(st)-1] == cur {
			cur = cur.Right
		} else {
			ret = append(ret, cur.Val)
			cur = nil
		}
	}

	return ret
}
