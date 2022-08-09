package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	var ret []int = make([]int, 0)
	if root == nil {
		return ret
	}
	var q []*TreeNode = make([]*TreeNode, 0)
	q = append(q, root)
	for len(q) > 0 {
		var size int = len(q)
		ret = append(ret, q[0].Val)
		for ; size > 0; size-- {
		  if q[0].Right != nil {
		    q = append(q, q[0].Right)
		  }
		  if q[0].Left != nil {
		    q = append(q, q[0].Left)
		  }
		  q = q[1:]
		}
	}
	return ret
}
