package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ret [][]int
var cur []int

func helper(t *TreeNode, s, target int) {
	if t == nil {
		return
	}
	s += t.Val
	cur = append(cur, t.Val)
	if s == target && t.Left == t.Right {
		// I assume that,
		// there will not be a condition that left == right != nil, haha
		var tmp []int = make([]int, len(cur))
		copy(tmp, cur)
		ret = append(ret, tmp)
	}
	helper(t.Left, s, target)
	helper(t.Right, s, target)
	cur = cur[:len(cur)-1]
}

func pathSum(root *TreeNode, targetSum int) [][]int {
	ret = make([][]int, 0)
	cur = make([]int, 0)
	helper(root, 0, targetSum)
	return ret
}
