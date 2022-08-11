package main

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findBottomLeftValue(root *TreeNode) int {
	var ret int = 0
	var q []*TreeNode = make([]*TreeNode, 0)
	var size int
	q = append(q, root)

	// a BFS method
	for len(q) > 0 {
	  // get the leftest of this layer
		ret = q[0].Val
		for size = len(q) ; size > 0; size-- {
			if q[0].Left != nil {
				q = append(q, q[0].Left)
			}
			if q[0].Right != nil {
				q = append(q, q[0].Right)
			}
			q = q[1:]
		}
	}
	return ret
}
