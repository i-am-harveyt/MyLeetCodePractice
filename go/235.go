package main


// Definition for a binary tree node.
 type TreeNode struct {
     Val   int
     Left  *TreeNode
     Right *TreeNode
 }


func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
  var ret *TreeNode = root
  var pv, qv int = p.Val, q.Val
  if pv > qv {
    pv, qv = qv, pv
  }

  for {
    if ret.Val < pv {
      ret = ret.Right
    } else if ret.Val > qv {
      ret = ret.Left
    } else {
      break
    }
  }
  return ret
}
