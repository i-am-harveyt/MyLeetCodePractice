package main

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(t *TreeNode, m map[int]int, l *int) int {
  if t == nil {
    return 0
  }
  var sum int = t.Val + helper(t.Left, m, l) + helper(t.Right, m, l)
  m[sum]++
  if m[sum] > *l {
    *l = m[sum]
  }
  return sum
}

func findFrequentTreeSum(root *TreeNode) []int {
  var ret []int = make([]int, 0)
  var m map[int]int = make(map[int]int)
  var largest int = 0
  helper(root, m, &largest)
  for k, v := range m {
    if v == largest {
      ret = append(ret, k)
    }
  }
  return ret
}
