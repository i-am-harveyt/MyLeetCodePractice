package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func build(arr []int, l, r int) *TreeNode {
  if l > r {
    return nil
  }
  var mid int = l + (r-l)/2
  return &TreeNode{
    Val: arr[mid],
    Left: build(arr, l, mid-1),
    Right: build(arr, mid+1, r),
  }
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	var arr []int = make([]int, 0)
	for n := head ; n != nil ; n=n.Next {
	  arr = append(arr, n.Val)
	}
	return build(arr, 0, len(arr)-1)
}
