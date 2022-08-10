package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(t *TreeNode, target int64) int {
  if t == nil {
    return 0
  }
  target -= int64(t.Val)
  if target == 0 {
    return 1 + helper(t.Left, target) + helper(t.Right, target)
  }
  return helper(t.Left, target) + helper(t.Right, target)
}

func pathSum(root *TreeNode, targetSum int) int {
	var ret int = 0
	var cur *TreeNode = root
	var st []*TreeNode = make([]*TreeNode, 0)
	for cur != nil || len(st) > 0 {
		for cur != nil {
			st = append(st, cur)
			cur = cur.Left
		}

		cur = st[len(st)-1]
		st = st[:len(st)-1]
		ret  += helper(cur, int64(targetSum))

		cur = cur.Right
	}
	return ret
}
