package main

import "strconv"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func binaryTreePaths(root *TreeNode) []string {
  ret := make([]string, 0)
  stn, stp := make([]*TreeNode, 0), make([]string, 0)
  stn = append(stn, root)
  stp = append(stp, strconv.Itoa(root.Val))
  for len(stn) > 0 {
    cur := stn[len(stn)-1]
    stn = stn[:len(stn)-1]
    path := stp[len(stp)-1]
    stp = stp[:len(stp)-1]
    if cur.Left == nil && cur.Right == nil {
      ret = append(ret, path)
    }
    if  cur.Left != nil {
      stn = append(stn, cur.Left)
      stp = append(stp, path + "->" + strconv.Itoa(cur.Left.Val))
    }
    if cur.Right != nil {
      stn = append(stn, cur.Right)
      stp = append(stp, path + "->" + strconv.Itoa(cur.Right.Val))
    }
  }
  return ret
}
