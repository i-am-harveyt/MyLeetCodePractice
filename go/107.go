package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrderBottom(root *TreeNode) [][]int {
	var ret [][]int = make([][]int, 0)
	if root == nil {
		return ret
	}
	var q []*TreeNode = make([]*TreeNode, 0)
	q = append(q, root)
	for len(q) > 0 {
		var size int = len(q)
		ret = append(ret, []int{})
		for i := 0; i < size; i++ {
			ret[len(ret)-1] = append(ret[len(ret)-1], q[0].Val)
			if q[0].Left != nil {
				q = append(q, q[0].Left)
			}
			if q[0].Right != nil {
				q = append(q, q[0].Right)
			}
			q = q[1:]
		}
	}
	for i, j := 0, len(ret)-1; i < j; i, j = i+1, j-1 {
		ret[i], ret[j] = ret[j], ret[i]
	}

	return ret

}
