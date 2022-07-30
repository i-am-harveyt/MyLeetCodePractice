package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}

	var cur *ListNode = head.Next
	var st []*ListNode = make([]*ListNode, 0)

	for cur != nil {
		st = append(st, cur)
		cur = cur.Next
	}

	cur = head
	for len(st) > 1 {
		cur.Next = st[len(st)-1]
		cur = cur.Next
		cur.Next = st[0]
		st = st[1 : len(st)-1]
		cur = cur.Next
	}
	if len(st) == 1 {
		cur.Next = st[0]
		cur = cur.Next
	}
	cur.Next = nil

}
