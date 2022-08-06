package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(cur *TreeNode, curSum int, ret *int) {
  if cur == nil {
    return
  }
	curSum = 10*curSum + cur.Val
	if cur.Left == nil && cur.Right == nil {
	  *ret += curSum
	  return
	}
	dfs(cur.Left, curSum, ret)
	dfs(cur.Right, curSum, ret)
}

func sumNumbers(root *TreeNode) int {
	ret := 0
	dfs(root, 0, &ret)
	return ret
}
