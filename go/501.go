package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ret []int
var maxFreq, curVal, curFreq int

func helper(cur *TreeNode)  {
  if cur == nil {
    return
  }
  helper(cur.Left)

  if cur.Val == curVal {
    curFreq++
  } else {
    curVal = cur.Val
    curFreq = 1
  }

  if curFreq == maxFreq {
    ret = append(ret, curVal)
  } else if curFreq > maxFreq {
    ret = nil
    ret = append(ret, curVal)
    maxFreq = curFreq
  }

  helper(cur.Right)
}

func findMode(root *TreeNode) []int {
	ret = nil
	maxFreq, curVal, curFreq = 0, math.MinInt32, 0
	helper(root)
	return ret
}
