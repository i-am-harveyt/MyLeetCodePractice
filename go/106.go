package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree1(inorder []int, postorder []int) *TreeNode {
	var m map[int]int = make(map[int]int)
	for i, v := range inorder {
		m[v] = i
	}
	var root = len(postorder) - 1
	return helper(postorder, m, &root, 0, len(postorder)-1)
}

func helper(p []int, m map[int]int, root *int, l int, r int) *TreeNode {
	if r < l {
		return nil
	}
	var pivot int = m[p[*root]]
	var cur TreeNode = TreeNode{Val: p[*root]}
	*root--
	cur.Right = helper(p, m, root, pivot+1, r)
	cur.Left = helper(p, m, root, l, pivot-1)
	return &cur
}

// other's solution, just incredible, fully perfomed the manipution of slice
func buildTree2(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 {
		return nil
	}

	lastIndex := len(postorder) - 1
	root := &TreeNode{Val: postorder[lastIndex]}

	i := search(inorder, postorder[lastIndex])
	root.Left = buildTree2(inorder[:i], postorder[:i])
	root.Right = buildTree2(inorder[i+1:], postorder[i:lastIndex])

	return root
}

func search(data []int, target int) (result int) {
	for ; data[result] != target; result++ {
	}

	return result
}
