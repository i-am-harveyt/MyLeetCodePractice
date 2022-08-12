package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
  // init
  var ret []float64 = make([]float64, 0)
  var q []*TreeNode = make([]*TreeNode, 0)

  q = append(q, root)
  var size int
  // BFS method
  for len(q) > 0 {
    size = len(q)
    ret = append(ret, 0)
    for i := 0 ; i < size ; i++ {
      ret[len(ret)-1] += float64(q[0].Val)
      if q[0].Left !=nil {
        q = append(q, q[0].Left)
      }
      if q[0].Right != nil {
        q = append(q, q[0].Right)
      }
      q = q[1:]
    }
    ret[len(ret)-1] /= float64(size)
  }
  return ret
}
