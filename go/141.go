package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	x, y := head, head
	for x != nil && y != nil {
		if y.Next != nil {
			y = y.Next.Next
		} else {
			break
		}
		x = x.Next
		if x == y {
			return true
		}
	}
	return false
}
