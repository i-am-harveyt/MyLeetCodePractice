package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func right(t *TreeNode, v, d int) *TreeNode { // for right subtree
	if d == 1 { // target depth
		var ret *TreeNode = &TreeNode{Val: v, Left: nil, Right: t}
		return ret
	}
	if t == nil { // under leaf, but not reach target depth
		return nil
	}
	d-- // update height
	t.Left = left(t.Left, v, d) // recursive
	t.Right = right(t.Right, v, d) // recursive
	return t
}

func left(t *TreeNode, v, d int) *TreeNode { // for left subtree
	if d == 1 {
		var ret *TreeNode = &TreeNode{Val: v, Left: t, Right: nil}
		return ret
	}
	if t == nil {
		return nil
	}
	d--
	t.Left = left(t.Left, v, d)
	t.Right = right(t.Right, v, d)
	return t
}

func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	return left(root, val, depth) // treat root as left subtree case
}
