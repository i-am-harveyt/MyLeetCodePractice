package main

// Definition for a binary tree node.
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func insert(nums []int, l int, r int) *TreeNode {
	if l > r {
		return nil
	}
	var mid int = l + (r-l)/2
	cur := TreeNode{
		Val:   nums[mid],
		Left:  nil,
		Right: nil,
	}
	cur.Left = insert(nums, l, mid-1)
	cur.Right = insert(nums, mid+1, r)
	return &cur
}

func sortedArrayToBST(nums []int) *TreeNode {
	return insert(nums, 0, len(nums)-1)
}
