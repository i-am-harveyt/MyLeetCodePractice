package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	prev, cur := head, head.Next
	for cur != nil {
		if cur.Val == prev.Val {
			cur = cur.Next
			prev.Next = cur
		} else {
			prev = cur
			cur = cur.Next
		}
	}

	return head
}
