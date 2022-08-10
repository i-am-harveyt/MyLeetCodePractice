package main

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil { // root is nil
		return nil
	}
	// look for target
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
	} else if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	} else { // root is target
		if root.Left == root.Right { // root is leaf
			return nil
		} else if root.Left == nil { // has right child
			return root.Right
		} else if root.Right == nil { // has left child
			return root.Left
		}
		// have two childs, replace root.Val by largest in left subtree
		var n *TreeNode = root.Left
		for n.Right != nil {
		    n = n.Right
		}
		root.Val = n.Val
		root.Left = deleteNode(root.Left, n.Val)
	}
	return root
}
