package main

// Definition for a binary tree node.
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func iot(root *TreeNode, ret *[]int) {
	if root == nil {
		return
	}
	iot(root.Left, ret)
	*ret = append(*ret, root.Val)
	iot(root.Right, ret)
}

func inorderTraversal(root *TreeNode) []int {
	var ret []int = make([]int, 0)
	iot(root, &ret)
	return ret
}
