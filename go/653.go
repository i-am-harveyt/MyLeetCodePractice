package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTarget(root *TreeNode, k int) bool {
  var m map[int]int = make(map[int]int)
  var dfs func(t *TreeNode, k int, m *map[int]int) bool
  dfs = func(t *TreeNode, k int, m *map[int]int) bool {
    if t == nil {
      return false
    }
    if (*m)[t.Val] == 1 {
      return true
    }
    (*m)[k - t.Val] = 1
    return dfs(t.Left, k, m) || dfs(t.Right, k, m)
  }
  return dfs(root, k, &m)
}
