package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	var m map[int]int = make(map[int]int)
	for i, v := range inorder {
		m[v] = i
	}
	return helper(preorder, m, 0, 0, len(preorder)-1)
}

func helper(p []int, m map[int]int, root, l, r int) *TreeNode {
	if l > r {
		return nil
	}

	var pivot = m[p[root]]

	var ret TreeNode = TreeNode{Val: p[root]}
	ret.Left = helper(p, m, root+1, l, pivot-1)
	ret.Right = helper(p, m, root+pivot-l+1, pivot+1, r)

	return &ret
}
